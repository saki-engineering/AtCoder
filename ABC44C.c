#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ
 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
 
int main(void){
    int N,A;
    scanf("%d%d",&N,&A);
 
    int* x;
    NEW(x,N);
    for(int i=0;i<N;i++){
        scanf("%d",&x[i]);
    }
 
    //DP[i][j][k]...x[0]~x[i]までで、j枚使って計kになる場合の数
    long DP[N][N+1][2501];
    for(int i=0;i<N;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=2500;k++) DP[i][j][k]=0;
        }
    }
    //初期値
    DP[0][0][0]=1;
    DP[0][1][x[0]]=1;
 
    //DPを埋める
    for(int i=1;i<N;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<=50*i;k++){
                DP[i][j][k]+=DP[i-1][j][k];
                if(j+1<=N && k+x[i]<=2500)DP[i][j+1][k+x[i]]+=DP[i-1][j][k];
            }
        }
    }
 
    long ans=0;
    for(int i=1;i<=N;i++){
        ans+=DP[N-1][i][A*i];
    }
    printf("%ld\n",ans);
 
    return 0;
}