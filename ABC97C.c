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
    char buf[5001];
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

int string_compare(const void* a, const void* b){
    String p=*(String*)a;
    String q=*(String*)b;

    return strcmp(p,q);
}


int main(void){
    String S=string_input();
    int K;
    scanf("%d",&K);

    int N=strlen(S);

    String* A;
    NEW(A,N*K);

    //K文字以下の部分文字列を全て列挙
    int a=0;
    for(int k=1;k<=K;k++){
        for(int i=0;i<N+1-k;i++){
            String tmp;
            NEW(tmp,k+1);
            for(int j=0;j<k;j++){
                tmp[j]=S[i+j];
            }
            A[a]=tmp;
            a++;
        }
    }
    qsort(A,a,sizeof(String),string_compare);

    //配列Aの中で重複をなくす
    String* B;
    NEW(B,N*K);
    B[0]=A[0];
    int b=1;
    for(int i=1;i<a;i++){
        if(strcmp(A[i],B[b-1])){
            B[b]=A[i];
            b++;
        }
    }

    printf("%s\n",B[K-1]);

    return 0;
}

//答えの文字列の長さはたかだかK文字と気付けるかどうか
//string.hをうまく使えると綺麗に書ける
//l71 文字列が同じかどうかはA[i]!=B[b-1]ではなくてstrcmpの値を見ないと比べられない