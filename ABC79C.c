#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

int main(void){
    int A[4];
    char S[5];
    scanf("%s",S);
    for(int i=0;i<4;i++){
        A[i]=S[i]-'0';
    }

    for(int i=0;i<8;i++){
        int ans=A[0];
        for(int j=0;j<3;j++){
            if(i&(1<<j)) ans+=A[j+1];
            else ans-=A[j+1];
        }
        if(ans==7){
            for(int j=0;j<3;j++){
                printf("%d",A[j]);
                if(i&(1<<j)) printf("+");
                else printf("-");
            }
            printf("%d=7\n",A[3]);
            return 0;
        }
    }

    return 0;
}