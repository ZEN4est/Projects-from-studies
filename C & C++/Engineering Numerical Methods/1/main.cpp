#include <iostream>
#include <cmath>
#include <vector>

void RK2(FILE *fp, FILE *fpblad,double deltaT, double y0,double tStart, double tStop,double lambda){
    double T = tStart;
    double k1 = lambda*y0;
    double k2 = lambda*(y0+deltaT*k1);

    fprintf(fp,"%lf\t%lf\n",T,y0);
    fprintf(fpblad,"%lf\t%lf\n",T,0.0);
    double yn1 = y0+ (deltaT/2)*(k1+k2);
    double yn1True =exp(lambda*T);
    T+=deltaT;
    fprintf(fp,"%lf\t%lf\n",T,yn1);
    fprintf(fpblad,"%lf\t%lf\n",T,yn1-exp(lambda*T));
    T+=deltaT;
    do{
        k1 = yn1*lambda;
        k2 = lambda*(yn1+deltaT*k1);
        yn1 = yn1+ (deltaT/2)*(k1+k2);
        yn1True = exp(lambda*T);
        fprintf(fp,"%lf\t%lf\n",T,yn1);
        fprintf(fpblad,"%lf\t%lf\n",T,yn1-yn1True);
        T+=deltaT;
    }while(T<=tStop);
}

void RK4(FILE *fp, FILE *fpblad,double deltaT, double y0,double tStart, double tStop,double lambda){
    double T = tStart;
    double k1 = lambda*y0;
    double k2 = lambda*(y0+deltaT/2*k1);
    double k3 = lambda*(y0+deltaT/2*k2);
    double k4 = lambda*(y0+deltaT*k3);

    fprintf(fp,"%lf\t%lf\n",T,y0);
    fprintf(fpblad,"%lf\t%.12lf\n",T,0.0);
    double yn1 = y0+ (deltaT/6)*(k1+2*k2+2*k3+k4);
    double yn1True =exp(lambda*T);
    T+=deltaT;
    fprintf(fp,"%lf\t%lf\n",T,yn1);
    fprintf(fpblad,"%lf\t%.12lf\n",T,yn1-exp(lambda*T));
    T+=deltaT;

    do{
        k1 = yn1*lambda;
        k2 = lambda*(yn1+deltaT/2*k1);
        k3 = lambda*(yn1+deltaT/2*k2);
        k4 = lambda*(yn1+deltaT*k3);
        yn1 = yn1+ (deltaT/6)*(k1+2*k2+2*k3+k4);
        yn1True = exp(lambda*T);
        fprintf(fp,"%lf\t%lf\n",T,yn1);
        fprintf(fpblad,"%lf\t%.12lf\n",T,yn1-yn1True);
        T+=deltaT;
    }while(T<=tStop); 
}

void euler(FILE *fp,FILE *fpblad,double deltaT, double y0,double tStart, double tStop,double lambda){
    double yn1;
    double yn1True;
    double T = tStart;

    fprintf(fp,"%lf\t%lf\n",T,0.0);
    fprintf(fpblad,"%lf\t%lf\n",T,0.0);
    yn1 = y0+ deltaT*lambda*y0;
    T+=deltaT;
    fprintf(fp,"%lf\t%lf\n",T,yn1);
    fprintf(fpblad,"%lf\t%lf\n",T,yn1-exp(lambda*T));
    T+=deltaT;

    do{
        yn1 = yn1+ deltaT*lambda*yn1;
        yn1True = exp(lambda*T);
        fprintf(fp,"%lf\t%lf\n",T,yn1);
        fprintf(fpblad,"%lf\t%lf\n",T,yn1-yn1True);
        T+=deltaT;
    }while(T<=tStop);
}
double V(double t,double w0){
    return 10*sin(w0*t);
}
void RRZ(FILE *fpI,FILE *fpQ,double deltaT, double R,double L, double C,double tStart,double wv){
    
    double w0 = (1/sqrt(L*C))*wv;
    double T0 = (2*M_PI)/(1/sqrt(L*C));
    double TStop = 4*T0;
    double T = tStart;
    
    double In1=0;
    
    double Qn1=0;
    double k1Q = In1;
    double k1I = V(T,w0)/L - Qn1/(L*C) - R/L * In1;
    double k2Q = In1+deltaT/2 * k1I;
    double k2I = V(T+deltaT/2,w0)/L - (Qn1 + deltaT/2 *k1Q)/(L*C) - R/L*(In1 + deltaT/2 *k1I);
    double k3Q = In1 + deltaT/2 *k2I;
    double k3I = V(T+deltaT/2,w0)/L - (Qn1 + deltaT/2*k2Q)/(L*C) - R/L*(In1 + deltaT/2*k2I);
    double k4Q = In1 + deltaT*k3I;
    double k4I = V(T+deltaT,w0)/L - (Qn1 + deltaT*k3Q)/(L*C) - R/L*(In1 + deltaT*k3I);
    Qn1 = Qn1 + (deltaT/6)*(k1Q+2*k2Q+2*k3Q+k4Q);
    In1 = In1 + (deltaT/6)*(k1I+2*k2I+2*k3I+k4I);

        fprintf(fpI,"%lf\t%lf\n",T,In1);
        fprintf(fpQ,"%lf\t%lf\n",T,Qn1);

    T+=deltaT;
do{
    double k1Q = In1;
    double k1I = V(T,w0)/L - Qn1/(L*C) - R/L * In1;
    double k2Q = In1+deltaT/2 * k1I;
    double k2I = V(T+deltaT/2,w0)/L - (Qn1 + deltaT/2 *k1Q)/(L*C) - R/L*(In1 + deltaT/2 *k1I);
    double k3Q = In1 + deltaT/2 *k2I;
    double k3I = V(T+deltaT/2,w0)/L - (Qn1 + deltaT/2*k2Q)/(L*C) - R/L*(In1 + deltaT/2*k2I);
    double k4Q = In1 + deltaT*k3I;
    double k4I = V(T+deltaT,w0)/L - (Qn1 + deltaT*k3Q)/(L*C) - R/L*(In1 + deltaT*k3I);
    Qn1 = Qn1 + (deltaT/6)*(k1Q+2*k2Q+2*k3Q+k4Q);
    In1 = In1 + (deltaT/6)*(k1I+2*k2I+2*k3I+k4I);
        fprintf(fpI,"%lf\t%lf\n",T,In1);
        fprintf(fpQ,"%lf\t%lf\n",T,Qn1);
        T+=deltaT;
    }while(T<=TStop);

}

int main(){
    FILE *zad1a = fopen("zad1a.dat","w");
    FILE *zad1b = fopen("zad1b.dat","w");
    FILE *zad1c = fopen("zad1c.dat","w");
    FILE *zad1aBlad = fopen("zad1aBlad.dat","w");
    FILE *zad1bBlad = fopen("zad1bBlad.dat","w");
    FILE *zad1cBlad = fopen("zad1cBlad.dat","w");
    euler(zad1a,zad1aBlad,0.01,1,0,5,-1);
    euler(zad1b,zad1bBlad,0.1,1,0,5,-1);
    euler(zad1c,zad1cBlad,1,1,0,5,-1);
    FILE *zad2a = fopen("zad2a.dat","w");
    FILE *zad2b = fopen("zad2b.dat","w");
    FILE *zad2c = fopen("zad2c.dat","w");
    FILE *zad2aBlad = fopen("zad2aBlad.dat","w");
    FILE *zad2bBlad = fopen("zad2bBlad.dat","w");
    FILE *zad2cBlad = fopen("zad2cBlad.dat","w");
    RK2(zad2a,zad2aBlad,0.01,1,0,5,-1);
    RK2(zad2b,zad2bBlad,0.1,1,0,5,-1);
    RK2(zad2c,zad2cBlad,1,1,0,5,-1);
    FILE *zad3a = fopen("zad3a.dat","w");
    FILE *zad3b = fopen("zad3b.dat","w");
    FILE *zad3c = fopen("zad3c.dat","w");
    FILE *zad3aBlad = fopen("zad3aBlad.dat","w");
    FILE *zad3bBlad = fopen("zad3bBlad.dat","w");
    FILE *zad3cBlad = fopen("zad3cBlad.dat","w");
    RK4(zad3a,zad3aBlad,0.01,1,0,5,-1);
    RK4(zad3b,zad3bBlad,0.1,1,0,5,-1);
    RK4(zad3c,zad3cBlad,1,1,0,5,-1);

    FILE *zad4aI = fopen("zad4aI.dat","w");
    FILE *zad4bI = fopen("zad4bI.dat","w");
    FILE *zad4cI = fopen("zad4cI.dat","w");
    FILE *zad4dI = fopen("zad4dI.dat","w");
    FILE *zad4aQ = fopen("zad4aQ.dat","w");
    FILE *zad4bQ = fopen("zad4bQ.dat","w");
    FILE *zad4cQ = fopen("zad4cQ.dat","w");
    FILE *zad4dQ = fopen("zad4dQ.dat","w");
    
    RRZ(zad4aI,zad4aQ,0.0001,100,0.1,0.001,0,0.5);
    RRZ(zad4bI,zad4bQ,0.0001,100,0.1,0.001,0,0.8);
    RRZ(zad4cI,zad4cQ,0.0001,100,0.1,0.001,0,1);
    RRZ(zad4dI,zad4dQ,0.0001,100,0.1,0.001,0,1.2);

   


}