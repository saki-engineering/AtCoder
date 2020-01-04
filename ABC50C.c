#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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

    long ans=1;
    if(N%2==0){
        for(int i=0;i<(N/2);i++){
            if(A[2*i]==2*i+1 && A[2*i+1]==2*i+1) ans=(ans*2)%MOD;
            else{
                ans=0;
                break;
            }
        }
    }
    else{
        if(A[0]==0){
            for(int i=1;i<=(N/2);i++){
                if(A[2*i-1]==2*i && A[2*i]==2*i) ans=(ans*2)%MOD;
                else{
                    ans=0;
                    break;
                }
            }
        }
        else ans=0;
    }
    printf("%ld\n",ans);

    return 0;
}