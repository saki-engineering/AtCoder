#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007

int digit(long N){
    int ans=1;
    while(N/10!=0){
        ans++;
        N/=10;
    }
    return ans;
}

int main(void){
    long A,B,X;
    scanf("%ld%ld%ld",&A,&B,&X);

    long ans=0;
    if(A*1e9+B*10<=X) ans=1e9;

    //1~9桁の数を二分探索
    long min=0;
    long max=1e9;
    long mid;
    while(max-min>1){
        mid = (min+max)/2;
        if(A*mid+B*digit(mid)>X) max=mid;
        else min=mid;
    }

    ans=MAX(ans,min);
    printf("%ld\n",ans);

    return 0;
}