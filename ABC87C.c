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

    int M[2][N];
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++) scanf("%d",&M[i][j]);
    }
    
    //累積和をとる
    for(int i=1;i<N;i++) M[0][i]+=M[0][i-1];
    for(int i=N-2;i>=0;i--) M[1][i]+=M[1][i+1];
    
    int ans=0;
    for(int i=0;i<N;i++) ans=MAX(ans, M[0][i]+M[1][i]);
    printf("%d\n",ans);
    
    return 0;
}