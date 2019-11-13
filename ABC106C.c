#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    char S[101];
    long K;
    scanf("%s %ld",S,&K);

    int one_num=0;
    for(int i=0;i<=100;i++){
        if(S[i]=='1') one_num++;
        else break;
    }

    char ans;
    if(one_num>=K) ans='1';
    else ans=S[one_num];

    printf("%c\n",ans);

    return 0;
}

//特に困ったことなし