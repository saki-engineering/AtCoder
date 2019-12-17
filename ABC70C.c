#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

//最大公約数
long long gcd(long long a, long long b){
    //a>bになるように入れ替え
    if(a<b){
        long tmp=a;
        a=b;
        b=tmp;
    }

    //ユークリッドの互除法
    if(a%b==0) return b;
    return gcd(b,a%b);
}

//最小公倍数
long long lcm(long long a,long long b){
    return a*(b/gcd(a,b));
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    long long* T;
    NEW(T,N);
    for(int i=0;i<N;i++){
        scanf("%lld",&T[i]);
    }

    long long ans=1;
    for(int i=0;i<N;i++){
        ans=lcm(ans,T[i]);
    }
    printf("%lld\n",ans);

    return 0;
}