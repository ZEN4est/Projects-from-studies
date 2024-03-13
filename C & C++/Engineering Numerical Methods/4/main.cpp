#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <thread>

double p1(double x, double xmax, double sigmax, double y, double ymax, double sigmay){
    return (exp(((-1.0)*(pow(x-0.35*xmax,2)))/(pow(sigmax,2)) - (pow(y-0.5*ymax,2))/(pow(sigmay,2))))+((-1.0)*exp(((-1.0)*(pow(x-0.65*xmax,2)))/(pow(sigmax,2)) - (pow(y-0.5*ymax,2))/(pow(sigmay,2))));
}


void globalna(FILE *fp, FILE *blad, double eps, double delta, int nx, int ny, double V1, double V2,double omega,double TOL){
    double xmax = delta*nx;
    double ymax = delta*ny;
    double sigmax = 0.1*xmax;
    double sigmay = 0.1*ymax;
    double Sit=0.0;
    double Sit2=0.0;
    double Vs[nx+1][ny+1];
    double Vn[nx+1][ny+1];
    int t=1;
    for(int i =0;i<nx+1;i++){
        for(int j=0;j<ny+1;j++){
            Vs[i][j] =0;
            Vn[i][j] = 0;
        }
    }
    for(int i =0;i<=nx;i++){
        Vs[i][0] = V1;
        Vn[i][0] = V1;
    }

do{
    for(int i =1;i<nx;i++){
        for(int j=1;j<ny;j++){
            Vn[i][j] = 0.25*(Vs[i+1][j] + Vs[i-1][j] + Vs[i][j+1] + Vs[i][j-1]+ (delta*delta*p1(i*delta,xmax,sigmax,j*delta,ymax,sigmay))/(eps));
        }
    }

    for(int j =1;j<ny;j++){
        Vn[0][j] = Vn[1][j];
        Vn[nx][j] = Vn[nx-1][j];
    }
    for(int i=0;i<=nx;i++){
        for(int j=0;j<=ny;j++){
            Vs[i][j] = (1.0-omega)*Vs[i][j]+omega*Vn[i][j];
        }
    }
    Sit=Sit2;
    Sit2=0.0;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            Sit2+= std::pow(delta,2)*(0.5*std::pow((Vs[i+1][j] - Vs[i][j])/(delta),2) + 0.5*std::pow((Vs[i][j+1] - Vs[i][j])/(delta),2) - p1(i*delta,xmax,sigmax,j*delta,ymax,sigmay)*Vs[i][j]);           
        }
        
        
    }
    fprintf(fp,"%d\t%.16lf\n",t,Sit2);
    t++;
}while(std::fabs((Sit2-Sit)/Sit)>=TOL);

double Blad;        

for(int i=1;i<nx;i++){
    for(int j=1;j<ny;j++){
        Blad = (Vn[i+1][j] -2.0*Vn[i][j] + Vn[i-1][j])/(std::pow(delta,2)) + (Vn[i][j+1] - 2.0*Vn[i][j] + Vn[i][j-1])/(std::pow(delta,2)) +(p1(i*delta,xmax,sigmax,j*delta,ymax,sigmay))/(eps);
        fprintf(blad,"%lf\t%lf\t%lf\n",i*delta,j*delta,Blad);
    }
}

}

void lokalna(FILE *fp,  double eps, double delta, int nx, int ny, double V1, double V2,double omega,double TOL){
    double xmax = delta*nx;
    double ymax = delta*ny;
    double sigmax = 0.1*xmax;
    double sigmay = 0.1*ymax;
    double Sit=0.0;
    double Sit2=0.0;
    double Vn[nx+1][ny+1];
    int t=1;
  
    for(int i =0;i<nx+1;i++){
        for(int j=0;j<ny+1;j++){
            Vn[i][j] = 0;
        }
    }
    for(int i =0;i<=nx;i++){
        Vn[i][0] = V1;
    }
    do{
        for(int i =1;i<nx;i++){
            for(int j=1;j<ny;j++){
                Vn[i][j] = (1.0-omega)*Vn[i][j] + (omega/4)*(Vn[i+1][j] + Vn[i-1][j] + Vn[i][j+1] + Vn[i][j-1] + (std::pow(delta,2)/eps)*p1(i*delta,xmax,sigmax,j*delta,ymax,sigmay));
            }
        }
        for(int j=0;j<ny;j++){
            Vn[0][j] = Vn[1][j];
            Vn[nx][j] = Vn[nx-1][j];
        }
        Sit=Sit2;
        Sit2=0.0;

        
        for(int i = 0; i < nx; i++) {
            for(int j = 0; j < ny; j++) {
                Sit2 += std::pow(delta, 2) * (0.5 * std::pow((Vn[i + 1][j] - Vn[i][j]) / delta, 2) + 0.5 * std::pow((Vn[i][j + 1] - Vn[i][j]) / delta, 2) - p1(i * delta, xmax, sigmax, j * delta, ymax, sigmay) * Vn[i][j]);
            }
        }
        fprintf(fp,"%d\t%lf\n",t,Sit2);
        t++;
        
    }while(std::fabs((Sit2-Sit)/Sit)>=TOL);
}


int main(){
FILE *glob1 = fopen("globalna1.dat","w");
FILE *globBlad1 = fopen("globalnaBlad1.dat","w");

FILE *glob2 = fopen("globalna2.dat","w");
FILE *globBlad2 = fopen("globalnaBlad2.dat","w");

FILE *lok = fopen("lokalna.dat","w");
FILE *lok2 = fopen("lokalna2.dat","w");
FILE *lok3 = fopen("lokalna3.dat","w");
FILE *lok4 = fopen("lokalna4.dat","w");




std::thread thread1(globalna,glob1,globBlad1,1.0,0.1,150,100,10,0,0.6,10E-9);
std::thread thread2(globalna,glob2,globBlad2,1.0,0.1,150,100,10,0,1.0,10E-9);
std::thread thread3(lokalna,lok,1.0,0.1,150,100,10,0,1.0,10E-9);
std::thread thread4(lokalna,lok2,1.0,0.1,150,100,10,0,1.4,10E-9);
std::thread thread5(lokalna,lok3,1.0,0.1,150,100,10,0,1.8,10E-9);
std::thread thread6(lokalna,lok4,1.0,0.1,150,100,10,0,1.9,10E-9);
thread1.join();
thread2.join();
thread3.join();
thread4.join();
thread5.join();
thread6.join();



}
