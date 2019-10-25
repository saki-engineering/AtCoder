#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

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

    //文字列の長さ
    int N=string_len(S);

    //0101...にマッチしている添字の数
    int b=0;
    for(int i=0;i<N;i++){
        if(i%2==0){
            if(S[i]=='0') b++;
        }
        else{
            if(S[i]=='1') b++;
        }
    }

    //1010...にマッチしている添字の数
    int w=0;
    for(int i=0;i<N;i++){
        if(i%2==0){
            if(S[i]=='1') w++;
        }
        else{
            if(S[i]=='0') w++;
        }
    }

    int ans;
    if(b>=w) ans=N-b;
    else ans=N-w;

    printf("%d\n",ans);

    return 0;
}

//特に困ったことなし