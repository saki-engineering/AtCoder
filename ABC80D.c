#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    int s;
    int t;
    int c;
}data;

int main(void){
    int N,C;
    scanf("%d%d",&N,&C);

    data* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&A[i].s,&A[i].t,&A[i].c);
        A[i].s=A[i].s*2-1;
        A[i].t*=2;
        A[i].c--;
    }

    int t_max=0;
    for(int i=0;i<N;i++) t_max=MAX(t_max,A[i].t);

    int M[C][t_max];
    for(int i=0;i<C;i++){
        for(int j=0;j<=t_max;j++) M[i][j]=0;
    }
    for(int i=0;i<N;i++){
        for(int j=A[i].s;j<=A[i].t;j++) M[A[i].c][j]=1;
    }

    int ans=0;
    for(int i=0;i<=t_max;i++){
        int tmp=0;
        for(int j=0;j<C;j++) tmp+=M[j][i];
        ans=MAX(ans,tmp);
    }
    printf("%d\n",ans);

    return 0;
}