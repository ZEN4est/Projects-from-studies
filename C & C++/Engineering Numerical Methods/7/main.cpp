#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

int i1_idx = 50;
int j1_idx = 55;
int IT_MAX = 20000;
double delta = 0.01;
double p = 1.0;
double mi = 1.0;
const int Nx = 200;
const int Ny = 90;

void wbPsi(double (&psi)[Nx+1][Ny+1], double x[Nx+1], double y[Ny+1], double qwe, double qwy ){
    for (int j = j1_idx; j <= Ny; j++) psi[0][j] = (qwe/(2.0*mi))*((pow(y[j],3)/3.0)-(pow(y[j], 2)/2.0)*(y[j1_idx]+y[Ny])+y[j]*y[j1_idx]*y[Ny]);
    for (int j = 0; j <= Ny; j++) psi[Nx][j] = (qwy/(2.0*mi))*((pow(y[j], 3)/3.0)-(pow(y[j],2)/2.0)*y[Ny])+(qwe*pow(y[j1_idx],2)*(-y[j1_idx]+3.0*y[Ny]))/(12.0*mi);
    for (int i = 1; i <= Nx-1; i++) psi[i][Ny] = psi[0][Ny];
    for (int i = i1_idx; i <= Nx-1; i++) psi[i][0] = psi[0][j1_idx];
    for (int j = 1; j <= j1_idx; j++) psi[i1_idx][j] = psi[0][j1_idx];
    for (int i = 1; i <= i1_idx; i++) psi[i][j1_idx] = psi[0][j1_idx];
}

void wbDzeta(double (&dzeta)[Nx+1][Ny+1], double psi[Nx+1][Ny+1], double x[Nx+1], double y[Ny+1], double qwe, double qwy) {
    for (int j = j1_idx; j <= Ny; j++) dzeta[0][j] = (qwe/(2.0*mi))*(2.0 * y[j]  - y[j1_idx] - y[Ny]);
    for (int j = 0; j <= Ny; j++) dzeta[Nx][j] = (qwy/(2.0*mi)) * (2.0*y[j] - y[Ny]);
    for (int i = 1; i <= Nx-1; i++) dzeta[i][Ny] = (2.0/pow(delta, 2))*(psi[i][Ny-1] - psi[i][Ny]);
    for (int i = i1_idx + 1; i <= Nx-1; i++) dzeta[i][0] = (2.0/pow(delta, 2))*(psi[i][1] - psi[i][0]);
    for (int j = 1; j <= j1_idx-1; j++) dzeta[i1_idx][j] = (2.0/pow(delta, 2))*(psi[i1_idx + 1][j] - psi[i1_idx][j]);
    for (int i = 1; i <= i1_idx; i++) dzeta[i][j1_idx] = (2.0/pow(delta, 2))*(psi[i][j1_idx + 1] - psi[i][j1_idx]);
    dzeta[i1_idx][j1_idx] = (1.0/2.0)*(dzeta[i1_idx - 1][j1_idx] + dzeta[i1_idx][j1_idx - 1]);
}

void rel(double qwe, double x[Nx+1], double y[Ny+1], FILE *file1, FILE *file2) {
    double psi[Nx+1][Ny+1] = {0};
    double dzeta[Nx+1][Ny+1] = {0};
    double omega;
    double gamma;
    double qwy = qwe*((pow(y[Ny],3)-pow(y[j1_idx], 3)-3.0*y[j1_idx]*pow(y[Ny], 2) + 3.0*pow(y[j1_idx],2)*y[Ny])/(pow(y[Ny],3)));

    wbPsi(psi,x,y, qwe, qwy);
    
    for (int it = 1; it < IT_MAX; it++) {
        omega = (it < 2000) ? 0.0 : 1.0;


        for (int i = 1; i <= Nx-1; i++) {
            for (int j = 1; j <= Ny-1; j++) {
                if (j > j1_idx || i > i1_idx) {
                    psi[i][j] = 0.25*(psi[i+1][j]+psi[i-1][j]+psi[i][j+1]+psi[i][j-1]-pow(delta, 2) * dzeta[i][j]);
                    dzeta[i][j] = 0.25*(dzeta[i+1][j]+dzeta[i-1][j]+dzeta[i][j+1]+dzeta[i][j-1])-omega*(p/(16.0*mi))*((psi[i][j+1]-psi[i][j-1])*(dzeta[i+1][j]-dzeta[i-1][j])-(psi[i+1][j]-psi[i-1][j])*(dzeta[i][j+1]-dzeta[i][j-1]));
                }
            }
        }
        wbDzeta(dzeta,psi,x,y,qwe, qwy);
        gamma=0.0;
        for (int i = 1; i<= Nx-1; i++) gamma += (psi[i+1][j1_idx + 2] + psi[i-1][j1_idx+2] + psi[i][j1_idx+3] + psi[i][j1_idx+1] - 4.0*psi[i][j1_idx+2] - pow(delta,2)*dzeta[i][j1_idx+2]);
    } 
}

int main() {

    double x[Nx+1];
    double y[Ny+1];
    double q1 = -1000.0;
    double q2 = -4000.0;
    double q3 = 4000.0;
    for (int i = 0; i <= Nx; i++) x[i]=  delta * i;
    for (int j = 0; j <= Ny; j++) y[j] = delta * j;
	FILE *psim1000 = fopen("psim1000.dat", "w");
    FILE *dzetam1000 = fopen("dzetam1000.dat", "w");
    FILE *psim4000 = fopen("psim4000.dat", "w");
    FILE *dzetam4000 = fopen("dzetam4000.dat", "w");
    FILE *psi4000 = fopen("psi4000.dat", "w");
    FILE *dzeta4000 = fopen("dzeta4000.dat", "w");


    rel(q1, x, y, psim1000, dzetam1000);
    rel(q2, x, y, psim4000, dzetam4000);
    rel(q3, x, y, psi4000, dzeta4000);

    return 0;
}