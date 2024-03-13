#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <thread>
#include <fstream>


double VB1(double y, double ymax){
    return sin(M_PI*y/ymax);
}
double VB2(double x, double xmax){
    return (-1)*sin(2*M_PI*x/xmax);
}
double VB3(double y, double ymax){
    return sin(M_PI*y/ymax);
}
double VB4(double x, double xmax){
    return sin(2*M_PI*x/xmax);
}


void relaksacjaWielosiatkowa(double delta, int nx, int ny, double TOL){
    double xmax = delta*nx;
    double ymax = delta*ny;
    double V[nx+1][ny+1];
    int t=1;
    double sn;
    double s_prev = 0.0;
  
    for(int i =0;i<nx+1;i++){
        for(int j=0;j<ny+1;j++){
            V[i][j] = 0;
        }
    }
    for(int i =0;i<=nx;i++){
        V[i][ny] = VB2(i*delta,xmax);
        V[i][0] = VB4(i*delta,xmax);
    }
    
    for(int i =0;i<=ny;i++){
        V[0][i] = VB1(i*delta,ymax);
        V[nx][i] = VB3(i*delta,ymax);
    }

    for(int k =16;k>=1;k/=2){
        std::ofstream mapaPotencjalu("k"+std::to_string(k)+".dat");
        std::ofstream wartoscCalki("wartosc"+std::to_string(k)+".dat");

    do{
        for(int i =k;i<nx;i+=k){
            for(int j=k;j<ny;j+=k){
                V[i][j] = 0.25*(V[i+k][j] + V[i-k][j] + V[i][j+k] + V[i][j-k]);
            }
        }
        s_prev = sn;
        sn=0.0;
    
        for(int i = 0; i < nx; i+=k) {
            for(int j = 0; j < ny; j+=k) {
                sn += (std::pow(k*delta,2)/2)*(std::pow((V[i+k][j]-V[i][j])/(2*k*delta) + (V[i+k][j+k]-V[i][j+k])/(2*k*delta),2)+ std::pow((V[i][j+k]-V[i][j])/(2*k*delta) + (V[i+k][j+k]-V[i+k][j])/(2*k*delta),2));
            }
        }
        wartoscCalki<<t<<"\t"<<sn<<"\n";
        t++;
    }while(std::fabs((sn-s_prev)/s_prev)>=TOL);
    wartoscCalki.close();

    for(int i =0;i<nx;i+=k){
        for(int j =0;j<ny;j+=k){
            mapaPotencjalu<<i*delta<<"\t"<<j*delta<<"\t"<<V[i][j]<<"\n";
        }
    }
    mapaPotencjalu.close();
    
    if(k!=1){
        for(int i =0;i<nx;i+=k){
            for(int j =0;j<ny;j+=k){
                V[i+k/2][j+k/2] = 0.25* (V[i][j] + V[i+k][j] + V[i][j+k] + V[i+k][j+k]);
                V[i+k][j+k/2] = 0.5*(V[i+k][j] + V[i+k][j+k]);
                V[i+k/2][j+k] = 0.5*(V[i][j+k] + V[i+k][j+k]);
                V[i+k/2][j] = 0.5*(V[i][j] + V[i+k][j]);
                V[i][j+k/2] = 0.5*(V[i][j] + V[i][j+k]);
            }
        }
    }
     for(int i =0;i<=nx;i++){
        V[i][ny] = VB2(i*delta,xmax);
        V[i][0] = VB4(i*delta,xmax);
    }
    
    for(int i =0;i<=ny;i++){
        V[0][i] = VB1(i*delta,ymax);
        V[nx][i] = VB3(i*delta,ymax);
    }
    }

}


int main(){

 
relaksacjaWielosiatkowa(0.2,128,128,10E-9);






}