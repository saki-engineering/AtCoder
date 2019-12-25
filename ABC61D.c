#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007
#define INF 1e18 

typedef struct{
    int a;
    int b;
    long c;
}edge;

//a→bの順での昇順
int asc(const void* a, const void* b){
    edge p=*(edge*)a;
    edge q=*(edge*)b;
    if((p.a-q.a)>0) return 1;
    else if((p.a-q.a)<0) return -1;
    else{
        if((p.b-q.b)>0) return 1;
        else if((p.b-q.b)<0) return -1;
        else return 0;
    };
}

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    edge* E;
    NEW(E,M);
    for(int i=0;i<M;i++){
        scanf("%d%d%ld",&E[i].a,&E[i].b,&E[i].c);
        E[i].a--;
        E[i].b--;
        E[i].c=-E[i].c;
    }
    qsort(E,M,sizeof(edge),asc);

    long* d;
    NEW(d,N);
    for(int i=0;i<N;i++) d[i]=INF;
    d[0]=0;

    for(int i=1;i<N;i++){
        for(int j=0;j<M;j++){
            if(d[E[j].a]==INF) continue;

            if(d[E[j].a]+E[j].c<d[E[j].b]){
                d[E[j].b]=d[E[j].a]+E[j].c;
            }
        }
    }

    long ans=d[N-1];

    int* negative;
    NEW(negative,N);
    for(int i=0;i<N;i++) negative[i]=0;

    for(int i=1;i<N;i++){
        for(int j=0;j<M;j++){
            if(d[E[j].a]==INF) continue;

            if(d[E[j].a]+E[j].c<d[E[j].b]){
                d[E[j].b]=d[E[j].a]+E[j].c;
                negative[E[j].b]=1;
            }

            if(negative[E[j].a]) negative[E[j].b]=1;
        }
    }

    if(negative[N-1]) printf("inf\n");
    else printf("%ld\n",-ans);

    return 0;
}