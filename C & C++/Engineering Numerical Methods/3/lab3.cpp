#include <iostream>
#include <cmath>
#include <algorithm> 
#include <cstdlib> 

double alfa = 5.0;
double x0 = 0.01;
double v0 = 0.0;
double deltaT = 1.0;
double S = 0.75;
double p = 2.0;
double tmax = 40;


void control(FILE *xt,FILE *vt, FILE *dt, FILE *vx,std::pair<double,double> (*fun)(double,double,double), double TOL){
    double t = 0;
    double dT = deltaT;
    double xn = x0;
    double vn = v0;
    double xn1_2;
    double vn1_2;
    double xn2_2;
    double vn2_2;
    double xn2_1;
    double vn2_1;
    double Ex;
    double Ev;
    do{
        xn1_2 = fun(xn,vn,dT).first;
        vn1_2 = fun(xn,vn,dT).second;
        xn2_2= fun(xn1_2,vn1_2,dT).first;
        vn2_2= fun(xn1_2,vn1_2,dT).second;

        xn2_1 = fun(xn,vn,2*dT).first;
        vn2_1 = fun(xn,vn,2*dT).second;
   
        Ex = (xn2_2 - xn2_1)/(pow(2,p)-1);
        Ev = (vn2_2 - vn2_1)/(pow(2,p)-1);

        if(std::max<double>(fabs(Ex),fabs(Ev)) < TOL){
            t= t+2*dT;
            xn = xn2_2;
            vn = vn2_2;
            fprintf(xt, "%lf\t%lf\n",t,xn);
            fprintf(vt, "%lf\t%lf\n",t,vn);
            fprintf(dt, "%lf\t%lf\n",t,dT);
            fprintf(vx, "%lf\t%lf\n",xn,vn);
        }
        
        dT *= pow((S*TOL)/(std::max<double>(fabs(Ex),fabs(Ev))),1.0/(p+1.0));
  
    }while(t<tmax);

}


std::pair<double,double> RK2(double xn, double vn, double deltaT){

    double k1x,k1v,k2x,k2v,xn1,vn1;
    k1x = vn;
    k1v = alfa*(1-xn*xn)*vn - xn;
    k2x = vn + deltaT*k1v;
    k2v = alfa*(1-pow((xn+deltaT*k2x),2))*(vn+deltaT*k1v) - (xn + deltaT*k1x);
    xn1 = xn + (deltaT/2)*(k1x + k2x);
    vn1 = vn + (deltaT/2)*(k1v + k2v);
    return std::pair<double,double>(xn1,vn1);

}

std::pair <double,double> trapez(double xn, double vn, double deltaT){

    double xn1=xn;
    double vn1=vn;
    double F;
    double G;
    double a11,a12,a21,a22;
    double dx;
    double dv;
        do{
            F = xn1 - xn - (deltaT/2)*(vn1+vn);
            G = vn1 - vn - (deltaT/2)*((alfa*(1-xn*xn)*vn - xn)+ ((alfa*(1-xn*xn)*vn - xn)));
            a11 = 1;
            a12 = -1*deltaT/2;
            a21 = (-1*deltaT/2)*(-2*alfa*xn1*vn1-1);
            a22 = 1 - (deltaT/2)*(alfa*(1-xn1*xn1));

            dx = ((-1*F)*a22 - (-1*G)*a12)/(a11*a22 - a12*a21);
            dv = (a11*(-1*G)- a21*(-1*F))/(a11*a22 - a12*a21);

           
            xn1 += dx;
            vn1 += dv;
        } while (fabs(dx) >= 10E-11 && fabs(dv) <= 10E-11);

    return std::pair<double, double>(xn1,vn1);
    
}


int main (){
    
FILE *trapezvt = fopen("trapezvt.dat","w");
FILE *trapezxt = fopen("trapezxt.dat","w");
FILE *trapezdtt = fopen("trapezdtt.dat","w");
FILE *trapezvx = fopen("trapezvx.dat","w");

FILE *trapezvt2 = fopen("trapezvt2.dat","w");
FILE *trapezxt2 = fopen("trapezxt2.dat","w");
FILE *trapezdtt2 = fopen("trapezdtt2.dat","w");
FILE *trapezvx2 = fopen("trapezvx2.dat","w");

FILE *RK2vt = fopen("RK2vt.dat","w");
FILE *RK2xt = fopen("RK2xt.dat","w");
FILE *RK2dt = fopen("RK2dt.dat","w");
FILE *RK2vx = fopen("RK2vx.dat","w");

FILE *RK2vt2 = fopen("RK2vt2.dat","w");
FILE *RK2xt2 = fopen("RK2xt2.dat","w");
FILE *RK2dt2 = fopen("RK2dt2.dat","w");
FILE *RK2vx2 = fopen("RK2vx2.dat","w");

control(trapezvt,trapezxt,trapezdtt,trapezvx,trapez,10E-3);
control(trapezvt2,trapezxt2,trapezdtt2,trapezvx2,trapez,10E-6);

control(RK2xt,RK2vt,RK2dt,RK2vx, RK2,10E-3);
control(RK2xt2,RK2vt2,RK2dt2,RK2vx2, RK2,10E-6);


}