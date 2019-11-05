#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define N 1000000007

int main(void){
    int H,W,K;
    scanf("%d%d%d",&H,&W,&K);

    //ans[H][W]は、縦の長さがH,終点がWのあみだくじの本数
    long ans[H+1][W+1];
    //初期値のans[0]を格納
    ans[0][1]=1;
    for(int i=2;i<=W;i++) ans[0][i]=0;

    //DP表を更新する
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            ans[i][j]=0;
            //ans[i][j]がどう変わるのかを考える
            for(int k=0;k<(1<<(W-1));k++){
                //amida...あみだくじとして成立するなら0,しないなら1
                int amida=0;
                for(int l=0;l<(W-2);l++){
                    if(k&(1<<l) && k&(1<<(l+1))) amida=1;
                }

                //あみだくじとして成立しないならスキップ
                if(amida) continue;

                //左にずれて来るのを受け入れる
                if(j<W && (k>>(j-1))&1) ans[i][j]=(ans[i][j]+ans[i-1][j+1])%N;
                //右にずれて来るのを受け入れる
                else if(j>1 && (k>>(j-2))&1) ans[i][j]=(ans[i][j]+ans[i-1][j-1])%N;
                //そのまま
                else ans[i][j]=(ans[i][j]+ans[i-1][j])%N;
            }
        }
    }
    
    printf("%ld\n",ans[H][K]);

    return 0;
}

//左or右に移動,移動しないあみだくじの棒の配置の仕方は、全探索する！(間に合うオーダーだから)