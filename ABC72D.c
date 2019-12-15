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
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    int* p;
    NEW(p,N);
    for(int i=0;i<N;i++){
        scanf("%d",&p[i]);
    }

    int ans=0;
    for(int i=0;i<N;i++){
        if(p[i]-1==i){
            ans++;
            if(i==N-1) SWAP(int, p[i],p[i-1]);
            else SWAP(int, p[i],p[i+1]);
        }
    }
    printf("%d\n",ans);

    return 0;
}

//そうすれば最適にswapできるかという規則をコードを書くまえに見つけ出せるかどうか次第