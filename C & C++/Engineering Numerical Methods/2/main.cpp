#include <iostream>
#include <cmath>

void newton(FILE *u, FILE *z,double beta, double N, double gamma, double tmax, double deltaT, double u0,double maxMicro, double TOL){
double un1=1;
double unnew=1;
double un=1;
double alfa = beta*N - gamma;
double t = 0;
    fprintf(u,"%lf\t%lf\n",t,unnew);
    fprintf(z,"%lf\t%lf\n",t,N-un1);

for(t=deltaT;t<tmax;t+=deltaT){
    un1 = un;
    for(int mi =0;mi<maxMicro;mi++){
        unnew = un1 - (un1 -un - (deltaT/2)*(alfa*un - beta* pow(un,2) + (alfa*un1 - beta*pow(un1,2))))/(1 - (deltaT/2)*(alfa - 2*beta*un1));
         if (abs(un1-unnew) < TOL){
             break;
         }
        un1 = unnew;
    }
    un = unnew;
    fprintf(u,"%lf\t%lf\n",t,unnew);
    fprintf(z,"%lf\t%lf\n",t,N-unnew);
}
}


void picard(FILE *u, FILE *z,double beta, double N, double gamma, double tmax, double deltaT, double u0,double maxMicro, double TOL){
double un1=1;
double unnew=1;
double un=1;
double alfa = beta*N - gamma;
double t = 0;
    fprintf(u,"%lf\t%lf\n",t,unnew);
    fprintf(z,"%lf\t%lf\n",t,N-un1);

for(t=deltaT;t<tmax;t+=deltaT){
    un1 = un;
    for(int mi =0;mi<maxMicro;mi++){
        unnew = un+ (deltaT/2)*(alfa*un - beta*pow(un,2) + (alfa*un1 - beta * (pow(un1,2))));
         if (abs(un1-unnew) < TOL){
             break;
         }
        un1 = unnew;
    }
    un = unnew;
    fprintf(u,"%lf\t%lf\n",t,unnew);
    fprintf(z,"%lf\t%lf\n",t,N-unnew);
}
}

double a[2][2] = {{0.25,0.25-(sqrt(3)/6)},{0.25+(sqrt(3)/6),0.25}};
double b[2] = {0.5,0.5};
double c[2] = {0.5 - (sqrt(3)/6),0.5 + (sqrt(3)/6)};

double f(double beta,double u,double N, double gamma){
    return (beta*N -gamma)*u - beta*pow(u,2);
}

double F1(double deltaT,double alfa, double beta,double un, double U1,double U2){
    return U1 - un - deltaT*(a[0][0]*(alfa*U1-beta*pow(U1,2))+a[0][1]*(alfa*U2 - beta*pow(U2,2)));
}

double F2(double deltaT,double alfa, double beta,double un, double U1,double U2){
    return U2 - un - deltaT*(a[1][0]*(alfa*U1-beta*pow(U1,2))+a[1][1]*(alfa*U2 - beta*pow(U2,2)));
}

void RK2(FILE *u, FILE *z,double beta, double N, double gamma, double tmax, double deltaT, double u0,double maxMicro, double TOL){

double alfa =  beta*N - gamma;
double U1new=1;
double U2new=1;
double U1=1;
double U2=1;
double un =u0;
double m[2][2]= {{0,0},{0,0}};

fprintf(u,"%lf\t%lf\n",0.0,un );
fprintf(z,"%lf\t%lf\n",0.0,N -un );

for(double t=deltaT;t<tmax;t+=deltaT){
    U1 = un;
    U2 = un;
    for(int mi =0;mi<maxMicro;mi++){
        m[0][0] = 1-deltaT*a[0][0]*(alfa - 2*beta*U1);
        m[0][1] = -deltaT*a[0][1]*(alfa - 2*beta*U2);
        m[1][0] = -deltaT*a[1][0]*(alfa-2*beta*U1);
        m[1][1] = 1- deltaT*a[1][1]*(alfa - 2*beta*U2);

        U1new = U1 + (F2(deltaT,alfa,beta,un,U1,U2)*m[0][1] - F1(deltaT,alfa,beta,un,U1,U2)*m[1][1])/(m[0][0]*m[1][1] - m[0][1]*m[2][1]);
        U2new = U2 + (F1(deltaT,alfa,beta,un,U1,U2)*m[1][0] - F2(deltaT,alfa,beta,un,U1,U2)*m[0][0])/(m[0][0]*m[1][1] - m[0][1]*m[2][1]);

        if(abs(U1new - U1) < TOL && abs(U2new - U2) < TOL){break;}
        
        U1 = U1new;
        U2 = U2new;
    }
    un = un + deltaT*(b[0]*f(beta,U1,N,gamma) + b[1]*f(beta,U2,N,gamma));
    fprintf(u,"%lf\t%lf\n",t,un);
    fprintf(z,"%lf\t%lf\n",t,N -un);

}



}


int main (){

FILE *zad1picardu = fopen("zad1picardu.dat","w");
FILE *zad1picardz = fopen("zad1picardz.dat","w");
picard(zad1picardu,zad1picardz,0.001,500,0.1,100,0.1,1,20,10E-7);

FILE *zad1newtonu = fopen("zad1newtonu.dat","w");
FILE *zad1newtonz = fopen("zad1newtonz.dat","w");
newton(zad1newtonu,zad1newtonz,0.001,500,0.1,100,0.1,1,20,10E-7);

FILE *zad2u = fopen("zad2u.dat","w");
FILE *zad2z = fopen("zad2z.dat","w");
RK2(zad2u,zad2z, 0.001,500,0.1,100,0.1,1,20,10E-7);

}