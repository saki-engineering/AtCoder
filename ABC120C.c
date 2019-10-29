#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int string_len(char* str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

int main(void){
    //S[0]~S[N-1]に格納する
    char S[100001];
    scanf("%s",S);

    int N=string_len(S);

    int R=0;
    int B=0;
    for(int i=0;i<N;i++){
        if(S[i]=='0') R++;
        else B++;
    }

    printf("%d\n",MIN(R,B)*2);

    return 0;
}