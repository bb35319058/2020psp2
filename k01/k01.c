#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double square_ave);
double N;

int main(void)
{
    double val;
    double ave = 0,var = 0,square_ave = 0;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    N = 0;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

         N = N+1;
         var = var_online(val, ave, square_ave);
         ave = ave_online(val, ave);
         square_ave = ave_online(pow(val, 2), square_ave);

    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("ave_%1f\n", ave);
    printf("var=%1f\n", var)

    return 0;


}

double ave_online(double val, double ave)
{
    double average;

    average = ((N-1)/N * ave) + (1/N * val);

    return average;
}

double var_online(double val, double ave, double square_ave)
{
    double variable;
    
    variable = {((N-1)/N * square_ave) + (1/N * pow(val,2))} - pow({((N-1)/N * ave) + (1/N * val)},2) 

    return variable;
}