#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define WHITE 0
#define GRAY 1
#define BLACK 2

//節点uからでる枝の構造体の定義
typedef struct slobj_{
    struct slobj_ *next;
    int v; //uから枝が伸びている節点v
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

//vにnを持つslobj型のリスト要素のメモリ確保+作成する関数
slobj slobj_new(int n){
    slobj p;
    NEW(p,1);
    p->v=n;
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

//節点i(0~n-1)から節点j(0~n-1)に枝を追加する関数
void add_edge(graph G, int i, int j){
    //枝データを追加
    slobj p=slobj_new(j);
    slist_append_tail(G->E[i],p);

    return;
}

//根(節点i)からの長さをdfs
void dfs(graph G, int i, long* d, int* color){
    color[i]=GRAY;
	slobj p=G->E[i]->head;
	while(p!=NULL){
		if(color[p->v]==WHITE){ //未探索なら
			d[p->v]+=d[i];
			dfs(G,p->v,d,color);
		}
		p=p->next;
	}
    color[i]=BLACK;
	return;
}

int main(void){
    int N,Q;
    scanf("%d%d",&N,&Q);

    graph G = graph_new(N);

    //無向グラフに枝を追加
    for(int i=0;i<N-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(G,a-1,b-1);
        add_edge(G,b-1,a-1);
    }

    //頂点に付いているカウンターの値
    long d[N];
    for(int i=0;i<N;i++) d[i]=0;

    //カウンターの値を標準入力から入れる
    for(int i=0;i<Q;i++){
        int p;
        long x;
        scanf("%d%ld",&p,&x);
        d[p-1]+=x;
    }

    //頂点を訪れたかどうかを格納する配列
    int color[N];
    for(int i=0;i<N;i++) color[i]=0;

    dfs(G,0,d,color);

    for(int i=0;i<N;i++){
        printf("%ld ",d[i]);
    }
    printf("\n");

    return 0;
}

//400てん
//リストをたどる時、q=q->nextし忘れるの私多いよね〜〜気をつけてね〜〜
//足し算をいつすればいいのかよく考えよう
//そうすると典型的なdfsの問題になる
//何も問題に書いてある順番にやらなくてもええんやで