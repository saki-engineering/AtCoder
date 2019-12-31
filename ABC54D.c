#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define INF 9999999

typedef struct{
    int a;
    int b;
    int c;
}data;

int main(void){
    int N,MA,MB;
    scanf("%d%d%d",&N,&MA,&MB);

    //A[0]~A[N-1]に格納する
    data* A;
    NEW(A,N+1);
    for(int i=1;i<=N;i++){
        scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].c);
    }

    //DP[a][b][c]...a番目までの薬で、Aがbg、Bがcgとなる最小価格
    int DP[N+1][401][401];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++) DP[i][j][k]=INF;
        }
    }

    //初期値
    DP[0][0][0]=0;

    //DPの更新
    for(int i=1;i<=N;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                if(DP[i-1][j][k]!=INF) DP[i][j][k]=DP[i-1][j][k];

                if(j-A[i].a>=0 && k-A[i].b>=0){
                    if(DP[i-1][j-A[i].a][k-A[i].b]!=INF) DP[i][j][k]=MIN(DP[i][j][k],DP[i-1][j-A[i].a][k-A[i].b]+A[i].c);
                }
            }
        }
    }

    int ans=INF;
    for(int j=1;j<=400;j++){
        for(int k=1;k<=400;k++){
            if(j*MB == k*MA) ans=MIN(ans,DP[N][j][k]);
        }
    }

    if(ans==INF) printf("-1\n");
    else printf("%d\n",ans);

    return 0;
}