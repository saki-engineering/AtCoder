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
    //A[0]~A[N-1]に格納する
    int* A;
    NEW(A,3);
    for(int i=0;i<3;i++){
        scanf("%d",&A[i]);
    }
    qsort(A,3,sizeof(int),asc);

    int ans=(A[2]-A[1])+(A[1]-A[0])/2+((A[1]-A[0])%2)*2;
    printf("%d\n",ans);

    return 0;
}

//困った事なし