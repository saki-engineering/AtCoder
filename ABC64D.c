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

int main(void){
    int N;
    scanf("%d",&N);

    String S;
    NEW(S,N+1);
    scanf("%s",S);

    int d=0;
    int x=0;
    int l=0;
    int r=0;
    for(int i=0;i<N;i++){
        if(S[i]=='(') l++;
        else r++;
        d=l-r;
        x=MIN(d,x);
    }

    for(int i=1;i<=(-x);i++) printf("(");
    printf("%s",S);
    for(int i=1;i<=(d-x);i++) printf(")");
    printf("\n");

    return 0;
}