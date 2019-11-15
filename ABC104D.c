#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MOD 1000000007

//S[0]から始まる文字列の長さを求める関数
int string_len(char* str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

int main(void){
    char S[100001];
    scanf("%s",S);

    //数列Sの長さ
    int N=string_len(S);

    //dp[i][j]...i-1文字目までは処理が終わっていて、ABCのうち前からj文字までどこを選ぶか決定している
    long dp[N+1][4];
    dp[N][3]=1;
    dp[N][2]=0;
    dp[N][1]=0;
    dp[N][0]=0;
    for(int i=N-1;i>=0;i--){
        //dp[3]について
        if(S[i]=='?') dp[i][3]=(3*dp[i+1][3])%MOD;
        else dp[i][3]=dp[i+1][3];

        //dp[2]について
        if(S[i]=='?') dp[i][2]=(3*dp[i+1][2]+dp[i+1][3])%MOD;
        else if(S[i]=='C') dp[i][2]=(dp[i+1][2]+dp[i+1][3])%MOD;
        else dp[i][2]=dp[i+1][2];

        //dp[1]について
        if(S[i]=='?') dp[i][1]=(3*dp[i+1][1]+dp[i+1][2])%MOD;
        else if(S[i]=='B') dp[i][1]=(dp[i+1][1]+dp[i+1][2])%MOD;
        else dp[i][1]=dp[i+1][1];

        //dp[0]について
        if(S[i]=='?') dp[i][0]=(3*dp[i+1][0]+dp[i+1][1])%MOD;
        else if(S[i]=='A') dp[i][0]=(dp[i+1][0]+dp[i+1][1])%MOD;
        else dp[i][0]=dp[i+1][0];
    }

    printf("%ld\n",dp[0][0]);

    return 0;
}

//ABCをどこから持ってくるかではなく、何文字もう決まっているかというところにレベルを落とす
//dpを降順でやることもある