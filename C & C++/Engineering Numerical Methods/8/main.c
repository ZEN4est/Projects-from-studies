#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_blas.h>


const int nx = 40;
const int ny = 40;
const int N = (nx + 1) * (ny + 1);
const double kb = 0.1;
const double kd = 0.6;
const int IT_MAX = 2000;
const int Ta = 40;
const int Tb = 0;
const int Tc = 30;
const int Td = 0;
const double delta = 1.0;
const double deltaT = 1.0;


int indx(int i, int j){
    return (i + j*(ny+1));
}


void fillMatrix(gsl_matrix *a,gsl_matrix *b,gsl_vector *c, gsl_vector *T){
    for (int i = 1; i <= nx-1; i++) {
        for (int j = 1; j <= ny-1; j++) {
            gsl_matrix_set(a, indx(i,j), indx(i,j) - nx - 1, deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(a, indx(i,j), indx(i,j) - 1, deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(a, indx(i,j), indx(i,j) + 1, deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(a, indx(i,j), indx(i,j) + nx + 1, deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(a, indx(i,j), indx(i,j), -((2.0*deltaT)/pow(delta,2)) - 1.0);
            gsl_matrix_set(b, indx(i,j), indx(i,j)-nx-1, -deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(b, indx(i,j), indx(i,j)-1,    -deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(b, indx(i,j), indx(i,j)+1,    -deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(b, indx(i,j), indx(i,j)+nx+1, -deltaT / (2.0*pow(delta, 2)));
            gsl_matrix_set(b, indx(i,j), indx(i,j),      (2.0*deltaT)/(pow(delta,2)) - 1.0);
        }
    }

    for (int j = 0; j <= ny; j++) {
        gsl_matrix_set(a, indx(0, j), indx(0,j), 1.0);
        gsl_matrix_set(a, indx(nx, j), indx(nx,j), 1.0);
        gsl_matrix_set(b, indx(0, j), indx(0,j), 1.0);
        gsl_matrix_set(b, indx(nx, j), indx(nx,j), 1.0);
        gsl_vector_set(c, indx(0, j), 0.0);
        gsl_vector_set(c, indx(nx, j), 0.0);
        gsl_vector_set(T, indx(0, j), Ta);
        gsl_vector_set(T, indx(nx, j), Tc);
    }


    for(int i = 1; i <= nx - 1; i++) {
        gsl_matrix_set(a, indx(i, ny), indx(i, ny) - nx - 1, -1.0/(kb * delta));
        gsl_matrix_set(a, indx(i, ny), indx(i, ny), 1.0 + 1.0/(kb * delta));
        gsl_vector_set(c, indx(i, ny), Tb);
        gsl_matrix_set(a, indx(i, 0), indx(i, 0), 1.0 + 1.0/(kd * delta));
        gsl_matrix_set(a, indx(i, 0), indx(i, 0) + nx + 1, -1.0/(kd * delta));
        gsl_vector_set(c, indx(i, 0), Td);
    }

    for (int j = 0; j < N; j++) {
        for(int i = 1; i <= nx-1; i++) {
        gsl_matrix_set(b, indx(i, ny), j, 0.0);
        gsl_matrix_set(b, indx(i, 0), j, 0.0);
        }
    }

    for(int i = 1; i <= nx-1; i++){
        for(int j = 0; j <= ny; j++)
        gsl_vector_set(T, indx(i, j), 0.0);
    }

}

void CN(FILE *f1_100, FILE *f2_100, FILE *f1_200, FILE *f2_200, FILE *f1_500, FILE *f2_500, FILE *f1_1000, FILE *f2_1000, FILE *f1_2000, FILE *f2_2000){
    gsl_matrix *a = gsl_matrix_calloc(N,N);
    gsl_matrix *b = gsl_matrix_calloc(N,N);
    gsl_vector *c = gsl_vector_calloc(N);
    gsl_vector *d = gsl_vector_calloc(N);
    gsl_vector *T = gsl_vector_calloc(N);
    fillMatrix(a,b,c,T);
    gsl_permutation *p = gsl_permutation_calloc(N);
    int s=0;
    gsl_linalg_LU_decomp(a,p,&s);
    double f2=0;
    for(int it =1; it <= IT_MAX; it++){
        gsl_blas_dgemv(CblasNoTrans, 1, b, T, 0, d);
        gsl_blas_daxpy(1,c,d);
        gsl_linalg_LU_solve(a,p,d,T);
        if(it ==100 || it == 200 || it == 500 || it == 1000 || it == 2000){
            for (int i = 1; i <= nx - 1; i++){
                for (int j = 1; j <= ny - 1; j++){
                    switch (it)
                    {
                    case 100:
                        fprintf(f1_100,"%d\t%d\t%g\n",i,j, gsl_vector_get(T, indx(i,j)));

                        f2 = ((gsl_vector_get(T, indx(i,j) + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)-1))/pow(delta, 2)) 
                        + ((gsl_vector_get(T, indx(i,j) + nx + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)- nx -1) )/pow(delta, 2));

                        fprintf(f2_100,"%d\t%d\t%g\n",i,j, f2);
                        break;
                    case 200:
                        fprintf(f1_200,"%d\t%d\t%g\n",i,j, gsl_vector_get(T, indx(i,j)));

                        f2 = ((gsl_vector_get(T, indx(i,j) + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)-1))/pow(delta, 2)) 
                        + ((gsl_vector_get(T, indx(i,j) + nx + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)- nx -1) )/pow(delta, 2));
    
                        fprintf(f2_200,"%d\t%d\t%g\n",i,j, f2);
                        break;
                    case 500:
                        fprintf(f1_500,"%d\t%d\t%g\n",i,j, gsl_vector_get(T, indx(i,j)));

                        f2 = ((gsl_vector_get(T, indx(i,j) + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)-1))/pow(delta, 2)) 
                        + ((gsl_vector_get(T, indx(i,j) + nx + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)- nx -1) )/pow(delta, 2));

                        fprintf(f2_500,"%d\t%d\t%g\n",i,j, f2);
                        break;
                    case 1000:
                        fprintf(f1_1000,"%d\t%d\t%g\n",i,j, gsl_vector_get(T, indx(i,j)));

                        f2 = ((gsl_vector_get(T, indx(i,j) + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)-1))/pow(delta, 2)) 
                        + ((gsl_vector_get(T, indx(i,j) + nx + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)- nx -1) )/pow(delta, 2));

                        fprintf(f2_1000,"%d\t%d\t%g\n",i,j, f2);
                        break;
                    case 2000:
                        fprintf(f1_2000,"%d\t%d\t%g\n",i,j, gsl_vector_get(T, indx(i,j)));
                        
                        f2 = ((gsl_vector_get(T, indx(i,j) + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)-1))/pow(delta, 2)) 
                        + ((gsl_vector_get(T, indx(i,j) + nx + 1) 
                        - 2.0*gsl_vector_get(T, indx(i,j)) 
                        + gsl_vector_get(T, indx(i,j)- nx -1) )/pow(delta, 2));

                        fprintf(f2_2000,"%d\t%d\t%g\n",i,j, f2);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    gsl_matrix_free(a);
    gsl_matrix_free(b);
    gsl_vector_free(c);
    gsl_vector_free(d);
    gsl_vector_free(T);
    gsl_permutation_free(p);
}


int main (){

FILE *f1_100 = fopen("T1_100.dat","w");
FILE *f2_100 = fopen("T2_100.dat","w");
FILE *f1_200 = fopen("T1_200.dat","w");
FILE *f2_200 = fopen("T2_200.dat","w");
FILE *f1_500 = fopen("T1_500.dat","w");
FILE *f2_500 = fopen("T2_500.dat","w");
FILE *f1_1000 = fopen("T1_1000.dat","w");
FILE *f2_1000 = fopen("T2_1000.dat","w");
FILE *f1_2000 = fopen("T1_2000.dat","w");
FILE *f2_2000 = fopen("T2_2000.dat","w");

CN(f1_100,f2_100,f1_200,f2_200,f1_500,f2_500,f1_1000,f2_1000,f1_2000,f2_2000);

fclose(f1_100);
fclose(f2_100);
fclose(f1_200);
fclose(f2_200);
fclose(f1_500);
fclose(f2_500);
fclose(f1_1000);
fclose(f2_1000);
fclose(f1_2000);
fclose(f2_2000);

}