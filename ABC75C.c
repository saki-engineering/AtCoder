#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct slobj_{
    struct slobj_ *next;
    int v; //uから枝が伸びている節点v
    long d; //枝(u,v)の重み
}* slobj;

//slobj型のリストの定義
typedef struct{
    slobj head;
    slobj tail;
}* slist;

//グラフの構造体の定義
typedef struct{
    int n; //節点数
    slist* E; //枝リストの配列E[0]~E[n-1],未ソート単方向
}* graph;

//vにn,dにxを持つslobj型のリスト要素のメモリ確保+作成する関数
slobj slobj_new(int n,long x){
    slobj p;
    NEW(p,1);
    p->v=n;
    p->d=x;
    p->next=NULL;
    return p;
}

//slist型のメモリを1個確保し、空リスト1つを作る関数
slist slist_new(void){
    slist L;
    NEW(L,1);
    L->head=NULL;
    L->tail=NULL;
    return L;
}

//各slistを空リストにした,節点nのgraph型のメモリを確保する関数(Eは0カウント)
graph graph_new(int n){
    graph G;
    NEW(G,1);
    
    G->n=n;
    
    NEW(G->E,G->n);
    int i;
    for(i=0;i<G->n;i++){
        G->E[i]=slist_new();
    }
    
    return G;
}

//リストLの末尾に要素rを追加する関数
void slist_append_tail(slist L,slobj r){
    if(L->head==NULL){
        L->head=r;
        L->tail=r;
    }
    else{
        L->tail->next=r;
        L->tail=r;
    }
    
    return;
}

//節点i(0~n-1)から節点j(0~n-1)に、重さxの枝を追加する関数
void add_edge(graph G, int i, int j, int x){
    //枝データを追加
    slobj p=slobj_new(j,x);
    slist_append_tail(G->E[i],p);

    return;
}

void delete_edge(graph G, int i, int j){
    slobj p=G->E[i]->head;
    slobj q=NULL;
    while(p!=NULL){
        if(p->v==j) break;
        q=p;
        p=p->next;
    }
    //削除するpがhead
    if(q==NULL){
        G->E[i]->head=p->next;
    }
    else{
        q->next=p->next;
    }
    //削除するpがtail
    if(p->next==NULL){
        G->E[i]->tail=q;
    }
    return;
}

//根(節点i)からの長さをdfs
void dfs(graph G, int i, int* d){
	slobj p=G->E[i]->head;
	while(p!=NULL){
		if(d[p->v]==-1){ //未探索なら
			d[p->v]=d[i]+p->d;
			dfs(G,p->v,d);
		}
		p=p->next;
	}
	return;
}

typedef struct{
    int a;
    int b;
}edge;

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    graph G=graph_new(N);
    edge* A;
    NEW(A,M);

    for(int i=0;i<M;i++){
        scanf("%d%d",&A[i].a,&A[i].b);
        A[i].a--;
        A[i].b--;
        add_edge(G,A[i].a,A[i].b,1);
        add_edge(G,A[i].b,A[i].a,1);
    }

    int ans=0;
    for(int i=0;i<M;i++){
        delete_edge(G,A[i].a,A[i].b);
        delete_edge(G,A[i].b,A[i].a);

        int d[N];
        for(int j=0;j<N;j++) d[j]=-1;

        d[0]=0;
        dfs(G,0,d);

        for(int j=0;j<N;j++){
            if(d[j]==-1){
                ans++;
                break;
            }
        }

        add_edge(G,A[i].a,A[i].b,1);
        add_edge(G,A[i].b,A[i].a,1);
    }
    printf("%d\n",ans);

    return 0;
}