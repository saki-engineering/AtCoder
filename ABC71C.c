#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ
 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)
 
#define MOD 1000000007 
 
//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
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
    qsort(A,N,sizeof(int),desc);
 
    long H=0;
    long W=0;
    for(int i=1;i<N;i++){
        if(A[i]==A[i-1]){
            if(H==0) H=A[i];
            else{
                W=A[i];
                break;
            }
            i++;
        }
    }
 
    long ans=H*W;
    printf("%ld\n",ans);
 
    return 0;
}