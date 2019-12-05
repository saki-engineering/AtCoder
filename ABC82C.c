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
    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    qsort(A,N,sizeof(int),asc);

    int ans=0;
    int tmp=A[0];
    int cnt=0;
    for(int i=0;i<N;i++){
        if(A[i]==tmp) cnt++;
        else{
            if(cnt<tmp) ans+=cnt;
            else ans+=(cnt-tmp);

            tmp=A[i];
            cnt=1;
        }
    }
    if(cnt<tmp) ans+=cnt;
    else ans+=(cnt-tmp);
    printf("%d\n",ans);

    return 0;
}