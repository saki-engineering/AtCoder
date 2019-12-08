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
    int H,W;
    scanf("%d%d",&H,&W);

    int c[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) scanf("%d",&c[i][j]);
    }

    int A[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) scanf("%d",&A[i][j]);
    }

    //C[i][n]...n回の操作でi→1にするときの魔力
    int C[10][1001];
    for(int i=0;i<10;i++) C[i][1]=c[i][1];
    //DPで埋める
    for(int j=2;j<=1000;j++){
        for(int i=0;i<10;i++){
            C[i][j]=99999999;
            for(int k=0;k<10;k++) C[i][j]=MIN(C[i][j],C[k][j-1]+c[i][k]);
        }
    }

    int magic[10];
    for(int i=0;i<10;i++){
        magic[i]=C[i][1];
        for(int j=2;j<=1000;j++) magic[i]=MIN(magic[i],C[i][j]);
    }

    int ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(A[i][j]!=-1) ans+=magic[A[i][j]];
        }
    }
    printf("%d\n",ans);

    return 0;
}