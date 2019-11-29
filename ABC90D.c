#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    int priority;
    double value;
}data;

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);

    long ans=0;
    //bはK+1以上であることが確定している
    for(int b=K+1;b<=N;b++){
        int q=N/b;
        int r=N%b;
        ans+=(q*(b-K)+MAX(r-K+1,0));
    }
    if(K==0) ans-=N;
    printf("%ld\n",ans);

    return 0;
}