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
    int N,K;
    scanf("%d%d",&N,&K);

    //h[0]~h[N-1]に格納する
    int* h;
    NEW(h,N);
    for(int i=0;i<N;i++){
        scanf("%d",&h[i]);
    }
    qsort(h,N,sizeof(int),asc);

    int ans=h[K-1]-h[0];
    for(int i=0;i<=(N-K);i++){
        ans=MIN(ans,h[K-1+i]-h[i]);
    }
    printf("%d\n",ans);

    return 0;
}

//特に困ったことなし