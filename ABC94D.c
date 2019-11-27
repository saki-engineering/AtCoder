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

//配列sの中で、keyより初めて小さくなる添字を出力
int binary_search_left(int* array,int min, int max, int key){
    if(min<max){
        int mid=min+(max-min)/2;

        if(key<array[mid]) return binary_search_left(array,min,mid,key);
        else if(key>array[mid]) return binary_search_left(array,mid+1,max,key);
    }
    if(key>array[min]) return min;
    return min-1;
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

    int tmp=abs(A[0]-A[N-1]/2);
    int index=0;
    for(int i=0;i<N-1;i++){
        if(tmp>=abs(A[i]-A[N-1]/2)){
            tmp=abs(A[i]-A[N-1]/2);
            index=i;
        }
    }
    printf("%d %d\n",A[N-1],A[index]);

    return 0;
}