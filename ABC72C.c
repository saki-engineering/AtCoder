#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

int main(void){
    int N;
    scanf("%d",&N);

    int* A;
    NEW(A,1e5+2);
    for(int i=0;i<1e5+2;i++) A[i]=0;

    for(int i=0;i<N;i++){
        int a;
        scanf("%d",&a);
        A[a]++;
    }

    int ans=0;
    for(int i=1;i<=1e5;i++){
        ans=MAX(ans,A[i-1]+A[i]+A[i+1]);
    }
    printf("%d\n",ans);

    return 0;
}