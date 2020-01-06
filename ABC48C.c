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
    long x;
    scanf("%d%ld",&N,&x);

    long* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld",&A[i]);
    }

    long ans=0;
    for(int i=1;i<N;i++){
        int diff=A[i]+A[i-1]-x;
        if(diff>0){
            if(A[i]>=diff)A[i]-=diff;
            else{
                A[i-1]-=(diff-A[i]);
                A[i]=0;
            }
            ans+=diff;
        }
    }
    printf("%ld\n",ans);

    return 0;
}