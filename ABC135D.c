#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define N 1000000007;

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;

//S[0]から始まる文字列の長さを求める関数
int string_len(String str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

//文字列を標準入力から読み込み、それをString型のメモリを確保し直してくれる関数
//S[0]~S[n-1]までが入力で、S[n]は0になる
//文字列長さの上限は1000まで
String string_input(void){
    int i,len;
    char buf[100001];
    String str;
    scanf("%s",buf);//buf=入力した文字列が入るchar型の配列
    
    len=string_len(buf);//len=文字列の長さを表すint型変数
    NEW(str,len+1);//strはただのポインタだから、ここでNEWを使ってメモリを確保しなくちゃいけない
    for(i=0;i<len;i++){
        str[i]=buf[i];
    }
    str[len]=0;
    
    return str;
}

//char→int
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(void){
    //0桁目~n-1桁目まで
    String S=string_input();
    int n=string_len(S);

    //10^iの、13で割ったあまり
    int r[6]={1,10,9,12,3,4};

    //下からi桁目は、S[n-1-i]
    //DP[i][j]に、下からi桁目までで13で割ってjになるものがいくつあるのかを格納
    //iは0~n-1まで、jは0~12まで
    int DP[n][13];
    for(int i=0;i<n;i++){
        for(int j=0;j<13;j++) DP[i][j]=0;
    }

    //DP[0]を埋める
    if(S[n-1]!='?'){
        DP[0][ctoi(S[n-1])]=1;
    }
    else{
        for(int i=0;i<10;i++) DP[0][i]=1;
    }

    //DP[1]以降を埋める
    for(int i=1;i<n;i++){
        //その桁を考慮することによってどれだけあまりが増えるか
        int add;
        char c=S[n-1-i];
        int ci;
        if(c!='?'){
            ci=ctoi(c);
            add=(ci*r[i%6])%13;
            for(int j=0;j<13;j++) DP[i][(j+add)%13]=(DP[i][(j+add)%13]+DP[i-1][j])%N;
        }
        else{
            for(int k=0;k<10;k++){
                ci=k;
                add=(ci*r[i%6])%13;
                for(int j=0;j<13;j++) DP[i][(j+add)%13]=(DP[i][(j+add)%13]+DP[i-1][j])%N;
            }
        }
    }
    
    printf("%d\n",DP[n-1][5]);

    return 0;
}

//0始まりの習慣をつけたほうがいい(heap除く)