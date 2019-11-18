#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int a;
    int b;
}data;

//bの昇順→aの昇順でdataをソート
int asc(const void* a, const void* b){
    data p=*(data*)a;
    data q=*(data*)b;
    if(p.b!=q.b) return p.b-q.b;
    else return p.a-q.a;
}

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    //A[0]~A[M-1]に格納する
    data* A;
    NEW(A,M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&A[i].a,&A[i].b);
        A[i].a--;
        A[i].b--;
    }
    qsort(A,M,sizeof(data),asc);

    int ans=1;
    int bridge=A[0].b-1;
    for(int i=1;i<M;i++){
        if(A[i].a>bridge){
            bridge=A[i].b-1;
            ans++;
        }
    }
    printf("%d\n",ans);

    return 0;
}

//bの昇順に橋を落とせばいいことに気付けるか？
//(最初私がやったのは、a昇順→b昇順、でもこれだと入力例2の時に破綻する)