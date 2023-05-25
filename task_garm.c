#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-16
int main(char argc, char* argv[argc])
{
    FILE *in1 = fopen("input.txt", "r");
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    double *a;
    int cnt = -2;
    int n;
    int m;
    double p;
    double sum1 = 0;
    double sum2 = 0;
    double tmp;
    int t = 0;
    int flag1 = 0;
    int flag2 = 0;
    double u;
    double r = 0;
    double gar1 = 0;
    double gar2 = 0;
    if(!in || !in1){
        printf("1");
        fclose(in);
        fclose(in1);
        fclose(out);
        return -1;
    }
    if(in == NULL || in1 == NULL){
        printf("5");
        fclose(in1);
        fclose(in);
        fclose(out);
        return -1;
    }
    while (fscanf(in1, "%lf", &p) == 1){
        cnt += 1;
    }
    fclose(in1);
    fscanf(in, "%d %d", &n, &m);
    if(n <= 0 || m <= 0){
        printf("2");
        fclose(in);
        fclose(out);
        return -1;
    }
    if(cnt != n * m){ // дробная размерность матрицы
        //printf("%d %d %d", cnt, n ,m);
        fclose(in);
        fclose(out);
        printf("3");
        return -1;
    }
    fprintf(out, "%d %d\n", n, m);
    //printf("%d %d %d", cnt, n ,m);
    a = malloc(sizeof(double)*n*m); // напишите динамический массив
    for (int i = 0; i < n*m; i++){
            fscanf(in, "%lf", &u);
            a[i] = u;
            //printf("%lf ", a[i]);
            //printf("\n");
    }
    while(t < n){
        for (int i = 0; i < n-1; i++){
                for(int j=  0; j < m; j++){
                    if(fabs(a[i*n+j]) >= eps){
                        sum1 += 1 /(a[i*n+j]);
                    }
                    else{
                        sum1 = 0;
                        flag1 = 1;
                    }
                    if(fabs(a[(i+1)*n+j]) >= eps){
                        sum2 += 1 /(a[(i+1)*n+j]);
                    }
                    else{
                        sum2 = 0;
                        flag2 = 1;
                    }
                }
                if(flag1 == 0){
                    gar1 = m / sum1;
                }
                else{
                    gar1 = 0;
                }
                if(flag2 == 0){
                    gar2 = m / sum2;
                }
                else{
                    gar2 = 0;
                }
                if(gar2 > gar1){
                    for (int k = 0; k < m; k++){
                        tmp = a[i*m+k];
                        a[i*m+k] = a[(i+1)*m+k];
                        a[(i+1)*m+k] = tmp;
                    }
                }
                sum1 = 0;
                sum2 = 0;
                flag1 = 0;
                flag2 = 0;
        }
        t++;
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fprintf(out, "%lf ", a[i*m+j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           r += a[i*m+j] * a[(n-1)*m+j];
        }
        fprintf(out, "%lf ", r);
        r = 0;
    }
    free(a);
    fclose(in);
    fclose(out);
    return 0;
}