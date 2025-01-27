#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define chunk 100
#define samples 10

void print_array(float *d);

int main(){

    printf("Hello parallel computing world \n");
    float a[N], b[N], c[N];

    int i;

    for (i = 0; i<N; i++){
        a[i] = i*5;
        b[i] = (i+7) * 2.5;
    }

    int pieces = chunk;

    #pragma omp parallel for \
    shared(a,b,c,pieces) private(i) \
    schedule(static, pieces)

    for(i = 0; i<N; i++)
        c[i] = a[i] + b[i];
    
    printf("showing first %d samples for array a: \n", samples);
    print_array(a);
    printf("showing first %d samples for array b: \n", samples);
    print_array(b);
    printf("showing first %d samples for array c: \n", samples);
    print_array(c);
}

void print_array(float *d){

    for(int x=0; x<samples; x++)
        printf("%.2f", d[x]);
    printf("\n");


}