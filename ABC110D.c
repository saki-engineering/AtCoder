#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MOD 1000000007

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//割り算
long divi(long U,long D){
    if(U==D) return 1;

    if(U%D==0) return (U/D)%MOD;
    else return divi(U+MOD,D);
}

//nCmを求める
long combination(int n, int m){
    long U=1;
    long D=1;

    for(int i=n;i>(n-m);i--) U=(U*i)%MOD;
    for(int i=1;i<=m;i++) D=(D*i)%MOD;

    long ans=divi(U,D);
    return ans;
}


int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    int prime_factor[100000];
    for(int i=0;i<100000;i++) prime_factor[i]=0;

    //素因数分解
    int p_factor_num=0;
    for(int i=2;i*i<=M;i++){
        if(M%i==0){
            while(M%i==0){
                prime_factor[p_factor_num]++;
                M=M/i;
            }
            p_factor_num++;
        }
    }
    if(M>1){
        prime_factor[p_factor_num]++;
        p_factor_num++;
    }

    long long ans=1;
    for(int i=0;i<p_factor_num;i++){
        ans*=combination(prime_factor[i]+N-1,prime_factor[i]);
        ans%=MOD;
    }
    printf("%lld\n",ans);

    return 0;
}