#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(char argc, char* argv[argc])
{
    FILE *in1 = fopen("input.txt", "r");
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int cnt = -2;
    int t = 0;
    double *a;
    double p;
    int n;
    double max1 = 0;
    double max2 = 0;
    int m;
    double r= 0;
    double tmp;
    if(!in || !in1){
        printf("1");
        fclose(in);
        fclose(in1);
        fclose(out);
        return -1;
    }
    if(in1 == NULL || in == NULL){
        fclose(in);
        fclose(in1);
        fclose(out);
        printf("2");
        return -1;
    }
    while(fscanf(in1, "%lf", &p) == 1){
        cnt += 1;
    }
    fclose(in1);
    fscanf(in, "%d %d", &n, &m);
    if(n <= 0 || m <= 0){
        printf("4");
        fclose(in);
        fclose(out);
        return -1;
    }
    if(cnt != n*m){
        //printf("%d %d %d ", n, m, cnt);
        fclose(in);
        fclose(out);
        printf("3");
        return -1;
    }
    fprintf(out, "%d %d\n", n, m);
    a = malloc(sizeof(double)*n *m);
    for (int i = 0; i < n*m; i++){
        fscanf(in, "%lf", &a[i]);
    }
    while (t < m){
        for (int j = 0; j < m -1; j++){
            for (int i = 0; i < n; i++){
                max1 = a[j];
                max2 = a[j+1];
                if(a[i*m+j] >= max1){
                    max1 = a[i*m+j];
                }
                if(a[i*m+j+1] >= max2){
                    max2 = a[i*m+j+1];
                }
            }
            if(max1 > max2){
                for(int k = 0; k < n; k++){
                    tmp = a[k*m+j];
                    a[k*m+j] = a[k*m+j+1];
                    a[k*m+j+1] = tmp; 
                }
            } 
            max1 = 0;
            max2 = 0;
        }
        t++;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <m; j++){
            fprintf(out, "%lf ", a[i*m+j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j <m; j++){
            r += a[i*m+j] * a[j];
        }
        fprintf(out, "%lf ", r);
        r = 0;
    }
    free(a);
    fclose(in);
    fclose(out);
    return 0;
}