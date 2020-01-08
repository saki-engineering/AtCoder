#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N;
    scanf("%d",&N);

    long* T;
    long* A;
    NEW(T,N);
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld%ld",&T[i],&A[i]);
    }

    long t=T[0];
    long a=A[0];
    for(int i=1;i<N;i++){
        long c1=t/T[i];
        if(t%T[i]!=0) c1++;
        long c2=a/A[i];
        if(a%A[i]!=0) c2++;

        t=T[i]*MAX(c1,c2);
        a=A[i]*MAX(c1,c2);
    }
    printf("%ld\n",t+a);

    return 0;
}