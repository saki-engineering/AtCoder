#include<stdio.h>
#include<stdlib.h>

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
    int N;
    scanf("%d",&N);
    char S[N+1];
    scanf("%s",S);

    //0~i-1までで、Wを向いている人の数(W[0]=0)
    int W[N];
    W[0]=0;
    for(int i=1;i<N;i++){
        if(S[i-1]=='W') W[i]=W[i-1]+1;
        else W[i]=W[i-1];
    }
    
    //i+1~Nまでで、Eを向いている人の数(E[N-1]=0)
    int E[N];
    E[N-1]=0;
    for(int i=N-2;i>=0;i--){
        if(S[i+1]=='E') E[i]=E[i+1]+1;
        else E[i]=E[i+1];
    }
    
    int ans=N;
    for(int i=0;i<N;i++){
        ans=MIN(ans,W[i]+E[i]);
    }
    printf("%d\n",ans);
    
    return 0;
}

//45行目が、for(int i=N-2;N>=0;i--)でTLEになった