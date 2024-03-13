#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "mgmres.h"
#include "mgmres.c"

double p1(double x,double y, double xmax,double ymax, double sigma){
    return exp((-1*pow(x-0.25*xmax,2))/(sigma*sigma)-(pow(y-0.5*ymax,2))/(sigma*sigma));
}
double p2(double x,double y, double xmax,double ymax, double sigma){
    return (-1)*exp((-1*pow(x-0.75*xmax,2))/(sigma*sigma)-(pow(y-0.5*ymax,2))/(sigma*sigma));
}

int j(int nx, int l){
    return l/(nx+1);
}

int i(int nx, int l){
    return l-j(nx,l)*(nx+1);
}

double epsilon(int l,int nx,double e1,double e2){
    return (i(nx,l)<=nx/2 ? e1: e2);
}
void poissonMatrix(double delta, int n, double eps, double v1, double v2,bool bool1){
    int nx = n;
    int ny=n;
    double E1 = eps;
    double E2 = eps;
    double V1 = v1;
    double V3 = v1;
    double V2 = v2;
    double V4 = v2;
    int N = (nx+1)*(ny+1);
    double xmax = delta*nx;
    double ymax = delta*ny;
    double sigma = xmax/10;
    double *a = malloc(sizeof *a * 5 * N);
	double b[N], V[N];
	int ja[5 * N], ia[N + 1];
	for (int i = 0; i < 5 * N; i++)
	{
		a[i] = 0;
		ja[i] = 0;
		if (i < N + 1)
		{
			ia[i] = -1;
		}
		if (i < N)
		{
			b[i] = 0;
			V[i] = 0;
		}
	}
    int k=-1;
    int brzeg;
    int vb;

    for (int l=0;l<N;l++){
        brzeg =0;
        vb = 0;
        if(i(nx,l)==0){
            brzeg =1;
            vb=V1;
        }
        if(j(nx,l)==ny){
            brzeg =1;
            vb=V2;
        }
        if(i(nx,l)==nx){
            brzeg=1;
            vb=V3;
        }
        if(j(nx,l)==0){
            brzeg=1;
            vb=V4;
        }
    if (bool1) {
    b[l] = -1*(p1(delta*i(nx, l), delta*j(nx, l), xmax, ymax, sigma) + p2(delta*i(nx, l), delta*j(nx, l), xmax, ymax, sigma));
    } else {
        if (brzeg==1) {
            b[l] = vb;
        } else {
            b[l] = 0;
        }
    }
        ia[l]=-1;
        if(l-nx-1>=0 && brzeg==0){
            k++;
            if(ia[l]<0) ia[l]=k;
            a[k]=(epsilon(l,nx,E1,E2)/(pow(delta,2)));
            ja[k] = l-nx-1;
        }
        if(l-1>=0 && brzeg==0){
            k++;
            if(ia[l]<0) ia[l]=k;
            a[k] = (epsilon(l,nx,E1,E2)/(pow(delta,2)));
            ja[k] =l-1;
        }
        k++;
        if(ia[l]<0) ia[l]=k;
        if(brzeg==0){
            a[k] = -1*(2*epsilon(l,nx,E1,E2)+ epsilon(l+1,nx,E1,E2) + epsilon(l+nx+1,nx,E1,E2))/pow(delta,2);
        }else{
            a[k]=1;
        }
        ja[k]=l;

        if(l<N && brzeg==0){
            k++;
            a[k]=epsilon(l+1,nx,E1,E2)/pow(delta,2);
            ja[k] = l+1;
        }
        if(l<N-nx-1 && brzeg==0){
            k++;
            a[k] = epsilon(l+nx+1,nx,E1,E2)/pow(delta,2);
            ja[k] = l+nx+1;
        }
    }
    int nz_num;
    nz_num=k+1;
    ia[N]=nz_num;
    pmgmres_ilu_cr(N, nz_num, ia, ja, a, V, b, 500, 500, 1e-8, 1e-8);
    FILE *fp_a = fopen("macierzA.dat" , "w");
    for(int l=0;l<5*N;l++){
        fprintf(fp_a,"%d\t%d\t%d\t%lf\n",l,i(nx,l),j(nx,l),a[l]);
    }
    FILE *fp_b = fopen("b.dat","w");
    for(int l=0;l<N;l++){
        fprintf(fp_b,"%d\t%d\t%d\t%lf\n",l,i(nx,l),j(nx,l),b[l]);
    }
    fclose(fp_a);
    fclose(fp_b);
    free(a);
}


void poisson(char file[],double delta, int n, double eps1,double eps2, double v1, double v2,bool bool1){
    int nx = n;
    int ny=n;
    double E1 = eps1;
    double E2 = eps2;
    double V1 = v1;
    double V3 = v1;
    double V2 = v2;
    double V4 = v2;
    int N = (nx+1)*(ny+1);
    double xmax = delta*nx;
    double ymax = delta*ny;
    double sigma = xmax/10;
    double *a = malloc(sizeof *a * 5 * N);
	double b[N], V[N];
	int ja[5 * N], ia[N + 1];
	for (int i = 0; i < 5 * N; i++)
	{
		a[i] = 0;
		ja[i] = 0;
		if (i < N + 1)
		{
			ia[i] = -1;
		}
		if (i < N)
		{
			b[i] = 0;
			V[i] = 0;
		}
	}
    int k=-1;
    int brzeg;
    int vb;

    for (int l=0;l<N;l++){
        brzeg =0;
        vb = 0;
        if(i(nx,l)==0){
            brzeg =1;
            vb=V1;
        }
        if(j(nx,l)==ny){
            brzeg =1;
            vb=V2;
        }
        if(i(nx,l)==nx){
            brzeg=1;
            vb=V3;
        }
        if(j(nx,l)==0){
            brzeg=1;
            vb=V4;
        }
        if (brzeg==1) {
            b[l] = vb;
        }else if(bool1){
            b[l] = -1*(p1(delta*i(nx, l), delta*j(nx, l), xmax, ymax, sigma) + p2(delta*i(nx, l), delta*j(nx, l), xmax, ymax, sigma));
        }else{
            b[l] = 0;
        }
    
        ia[l]=-1;
        if(l-nx-1>=0 && brzeg==0){
            k++;
            if(ia[l]<0) ia[l]=k;
            a[k]=(epsilon(l,nx,E1,E2)/(pow(delta,2)));
            ja[k] = l-nx-1;
        }
        if(l-1>=0 && brzeg==0){
            k++;
            if(ia[l]<0) ia[l]=k;
            a[k] = (epsilon(l,nx,E1,E2)/(pow(delta,2)));
            ja[k] =l-1;
        }
        k++;
        if(ia[l]<0) ia[l]=k;
        if(brzeg==0){
            a[k] = -1*(2*epsilon(l,nx,E1,E2)+ epsilon(l+1,nx,E1,E2) + epsilon(l+nx+1,nx,E1,E2))/pow(delta,2);
        }else{
            a[k]=1;
        }
        ja[k]=l;

        if(l<N && brzeg==0){
            k++;
            a[k]=epsilon(l+1,nx,E1,E2)/pow(delta,2);
            ja[k] = l+1;
        }
        if(l<N-nx-1 && brzeg==0){
            k++;
            
            a[k] = epsilon(l+nx+1,nx,E1,E2)/pow(delta,2);
            ja[k] = l+nx+1;
        }
    }
    int nz_num;
    nz_num=k+1;
    ia[N]=nz_num;
    pmgmres_ilu_cr(N, nz_num, ia, ja, a, V, b, 500, 500, 1e-8, 1e-8);
    FILE *fp = fopen(file , "w");
    for(int l=0;l<N;l++){
        fprintf(fp,"%lf\t%lf\t%lf\n",delta*i(nx,l),delta*j(nx,l),V[l]);
    }
    fclose(fp);
    free(a);
}

int main(){


poissonMatrix(0.1,4,1,10,-10,false);
poisson("5a.dat",0.1,50,1,1,10,-10,false);
poisson("5b.dat",0.1,100,1,1,10,-10,false);
poisson("5c.dat",0.1,200,1,1,10,-10,false);
poisson("6a.dat",0.1,100,1,1,0,0,true);
poisson("6b.dat",0.1,100,1,2,0,0,true);
poisson("6c.dat",0.1,100,1,10,0,0,true);






}