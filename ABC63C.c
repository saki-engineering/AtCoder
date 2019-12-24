#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    int* S;
    NEW(S,N);
    for(int i=0;i<N;i++){
        scanf("%d",&S[i]);
    }
    qsort(S,N,sizeof(int),asc);

    int sum=0;
    for(int i=0;i<N;i++) sum+=S[i];

    int ans=0;
    if(sum%10!=0) ans=sum;
    else{
        for(int i=0;i<N;i++){
            if((sum-S[i])%10!=0){
                ans=sum-S[i];
                break;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}