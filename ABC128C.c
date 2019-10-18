#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//この中では、全てカウント0スタート

//ランプ構造体の定義
typedef struct{
    int swi; //どこのスイッチに接続されているのかをビットマスクで格納
    int p; //pの値を格納する
}lamp;

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);

    lamp* L;
    NEW(L,M);
    //Lのswiを0に初期化
    for(int j=0;j<M;j++){
        L[j].swi=0;
    }

    //Lのswiを入力していく
    for(int j=0;j<M;j++){
        int k;
        scanf("%d", &k);
        for(int l=1;l<=k;l++){
            int s;
            scanf("%d", &s);
            L[j].swi+=(1<<(s-1));
        }
    }

    //Lのpを入力
    for(int j=0;j<M;j++){
        scanf("%d", &L[j].p);
    }

    int ans=0;

    //全探索を、0~(2^N-1)の整数xに対応させる
    int x;
    for(x=0;x<(1<<N);x++){
        //judgeが0なら全部点灯、1なら無理
        int judge=0;

        //それぞれのランプについて、点灯条件を満たしているかどうか確認
        for(int j=0;j<M;j++){
            if(__builtin_parity(x&L[j].swi)!=L[j].p){
                judge=1;
                break;
            }
        }
        if(judge==0) ans++;
    }

    printf("%d\n",ans);

    return 0;
}

//ランプと電球の関係を、二次元配列ではなくてビットで格納することで、ビット演算子を用いて処理をはるかに簡単にできる！！