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
    int C;
    int S;
    int F;
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

    //A[0]~A[N-2]に格納する
    data* A;
    NEW(A,N-1);
    for(int i=0;i<N-1;i++){
        scanf("%d%d%d",&A[i].C,&A[i].S,&A[i].F);
    }

    int ans[N];
    for(int i=0;i<N;i++){
        ans[i]=0;
        for(int j=i;j<N-1;j++){
            if(ans[i]<=A[j].S) ans[i]=A[j].S+A[j].C; //始発が出てないなら始発で移動
            else{
                if(ans[i]%A[j].F==0) ans[i]+=A[j].C;
                else ans[i]+=A[j].C+(A[j].F-ans[i]%A[j].F);
            }
        }
    }
    

    for(int i=0;i<N;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}