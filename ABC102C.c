#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]にA_i-iの値を格納する
    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        A[i]-=(i+1);
    }
    qsort(A,N,sizeof(int),asc);

    long ans=0;
    int b;
    if(N%2==0){
        b=(A[N/2]+A[N/2-1])/2;
        for(int i=0;i<N;i++) ans+=abs(A[i]-b);

        b++;
        long tmp=0;
        for(int i=0;i<N;i++) tmp+=abs(A[i]-b);

        ans=MIN(ans,tmp);
    }
    else{
        b=A[N/2];
        for(int i=0;i<N;i++) ans+=abs(A[i]-b);
    }

    printf("%ld\n",ans);

    return 0;
}

//特に困ったことなし