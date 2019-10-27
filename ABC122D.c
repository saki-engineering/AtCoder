#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MOD 1000000007

int main(void){
    int N;
    scanf("%d",&N);

    //前3文字だけで文字列を決定する
    //dp[i]は、長さi文字の文字列の数
    long dp[N+1][64];

    //初期値
    for(int i=0;i<64;i++) dp[3][i]=1;
    dp[3][6]  = 0; //AGC
    dp[3][9]  = 0; //ACG
    dp[3][18] = 0; //GAC

    //dpの中を埋める
    for(int i=4;i<=N;i++){
        for(int j=0;j<64;j++){
            dp[i][j]=0;

            if(j==6 || j==9 ||j==18) continue; //末尾がAGC,ACG,GACになるものはdp=0のまま

            //dp[i][j]にどんなdp[i-1][k]を足せばいいのか
            for(int k=0;k<64;k++){
                if( j%4==2 && k%16==1)          continue; //*AG(k%16=1)にCを足そうとする(j%4=2)のはだめ
                if( j%4==1 && k%16==2)          continue; //*AC(k%16=2)にGを足そうとする(j%4=1)のはだめ
                if (j%4==2 && k%16==4)          continue; //*GAにCを足そうとするのはだめ
				if (j%4==2 && k>>2==1)          continue; //AG*にCを足そうとするのはだめ
				if (j%4==2 && k>>4==0 && k%4==1)continue; // A*B + C

                //上記以外で、kの末尾2文字とjの頭2文字が一致しているなら、足す
                if((j>>2)==(k%16)) dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
            }
        }
    }


    long ans=0;
    for(int i=0;i<64;i++) ans=(ans+dp[N][i])%MOD;
    printf("%ld\n",ans);

    return 0;
}

/*
0 AAA  4 AGA  8 ACA  12 ATA
1 AAG  5 AGG  9 ACG  13 ATG
2 AAC  6 AGC 10 ACC  14 ATC
3 AAT  7 AGT 11 ACT  15 ATT
頭文字G +16
頭文字C +32
頭文字T +48
*/