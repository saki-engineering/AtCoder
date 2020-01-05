#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int n;
    double value;
}data;

//昇順
int asc(const void* a, const void* b){
    data p=*(data*)a;
    data q=*(data*)b;

    if(p.value-q.value>0) return 1;
    else if(p.value-q.value<0) return -1;
    else return p.n-q.n;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    data* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        A[i].n=i;
        scanf("%lf",&A[i].value);
    }

    double avg=0;
    for(int i=0;i<N;i++) avg+=A[i].value;
    avg/=N;

    for(int i=0;i<N;i++) A[i].value=fabs(A[i].value-avg);
    qsort(A,N,sizeof(data),asc);

    printf("%d\n",A[0].n);

    return 0;
}