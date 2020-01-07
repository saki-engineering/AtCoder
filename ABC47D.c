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
    long T;
    scanf("%d%ld",&N,&T);

    //A[0]~A[N-1]に格納する
    long* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld",&A[i]);
    }

    long* min;
    NEW(min,N);
    min[0]=A[0];
    for(int i=1;i<N;i++){
        if(A[i]<min[i-1]) min[i]=A[i];
        else min[i]=min[i-1];
    }

    long B=A[0]-min[0];
    for(int i=1;i<N;i++) B=MAX(B,A[i]-min[i]);

    int ans=0;
    for(int i=0;i<N;i++){
        if(A[i]-min[i]==B) ans++;
    }
    printf("%d\n",ans);

    return 0;
}