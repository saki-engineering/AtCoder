#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

int main(void){
    long x;
    scanf("%ld",&x);

    long ans=(x/11)*2;
    if(x%11==0) ans+=0;
    else if(x%11<=6) ans+=1;
    else ans+=2;

    printf("%ld\n",ans);

    return 0;
}