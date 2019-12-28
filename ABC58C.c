#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef char* String;

String string_input(void){
    int i,len;
    char buf[100];
    String str;
    scanf("%s",buf);//buf=入力した文字列が入るchar型の配列
    
    len=strlen(buf);//len=文字列の長さを表すint型変数
    NEW(str,len+1);//strはただのポインタだから、ここでNEWを使ってメモリを確保しなくちゃいけない
    for(i=0;i<len;i++){
        str[i]=buf[i];
    }
    str[len]=0;
    
    return str;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    String* S;
    NEW(S,N);
    for(int i=0;i<N;i++){
        S[i]=string_input();
    }

    int* ans;
    NEW(ans,26);
    for(int i=0;i<26;i++) ans[i]=50;

    int* tmp;
    NEW(tmp,26);
    for(int i=0;i<N;i++){
        for(int j=0;j<26;j++) tmp[j]=0;

        for(int j=0;j<strlen(S[i]);j++){
            tmp[S[i][j]-'a']++;
        }

        for(int j=0;j<26;j++) ans[j]=MIN(ans[j],tmp[j]);
    }

    for(int i=0;i<26;i++){
        char c='a'+i;
        for(int j=1;j<=ans[i];j++) printf("%c",c);
    }
    printf("\n");

    return 0;
}