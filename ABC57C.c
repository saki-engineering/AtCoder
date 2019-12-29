#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

int main(void){
    long N;
    scanf("%ld",&N);

    int ans=11;
    for(long i=1;i*i<=N;i++){
        if(N%i==0){
            int tmp = log10(N/i)+1;
            ans=MIN(ans,tmp);
        }
    }
    printf("%d\n",ans);

    return 0;
}