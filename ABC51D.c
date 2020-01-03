#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define INF 999999999

typedef long* vector;

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    int* A;
    int* B;
    long* C;
    NEW(A,M);
    NEW(B,M);
    NEW(C,M);

    vector* dist;
    NEW(dist,N);
    for(int i=0;i<N;i++){
        NEW(dist[i],N);
        for(int j=0;j<N;j++) dist[i][j]=INF;
        dist[i][i]=0;
    }


    for(int i=0;i<M;i++){
        scanf("%d%d%ld",&A[i],&B[i],&C[i]);
        A[i]--;
        B[i]--;
        dist[A[i]][B[i]]=C[i];
        dist[B[i]][A[i]]=C[i];
    }

    //ワーシャルフロイド法
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) dist[i][j]=MIN(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }

    int ans=0;
    for(int i=0;i<M;i++){
        if(dist[A[i]][B[i]]!=C[i]) ans++;
    }
    printf("%d\n",ans);

    return 0;
}