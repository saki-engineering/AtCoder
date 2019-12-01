#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct obj_{
    int key;
    struct obj_ *next;
}*obj;

//slobj型の変数のポインタをslist型と定義→いずれリストの先頭・最後尾要素を指す
typedef struct{
    obj head;
    obj tail;
}*queue;

//keyにxをもつキュー要素を作る関数
obj obj_new(int x){
    obj p;
    NEW(p,1);
    p->key=x;
    p->next=NULL;
    return p;
}

//slist型の空リスト1つを作る関数
queue queue_new(void){
    queue Q;
    NEW(Q,1);
    Q->head=NULL;
    Q->tail=NULL;
    return Q;
}

//enqueue(リスト最後尾に挿入)
void enqueue(queue Q,obj p){
    if(Q->head==NULL){
        Q->head=p;
        Q->tail=p;
    }
    else{
        Q->tail->next=p;
        Q->tail=p;
    }
    
    return;
}

obj dequeue(queue Q){
    obj p=Q->head;
    if(p==Q->tail){
        Q->tail=NULL;
        Q->head=NULL;
    }
    else{
        Q->head=p->next;
    }
    return p;
}

int main(void){
    int H,W;
    scanf("%d%d",&H,&W);

    int M[H][W];
    int white=0;
    for(int i=0;i<H;i++){
        char c[W+1];
        scanf("%s",c);
        for(int j=0;j<W;j++){
            if(c[j]=='.'){
                M[i][j]=0;
                white++;
            }
            else M[i][j]=-1; 
        }
    }

    queue Q=queue_new();
    enqueue(Q,obj_new(0));
    while(1){
        obj p=dequeue(Q);
        if(p==NULL) break;

        //これからM[x][y]の話をする(対応はx*W+y)
        int x=(p->key)/W;
        int y=(p->key)%W;
        if(x!=0 && M[x-1][y]==0){
            enqueue(Q,obj_new((x-1)*W+y));
            M[x-1][y]=M[x][y]+1;
        }
        if(x!=H-1 && M[x+1][y]==0){
            enqueue(Q,obj_new((x+1)*W+y));
            M[x+1][y]=M[x][y]+1;
        }
        if(y!=0 && M[x][y-1]==0){
            enqueue(Q,obj_new(x*W+y-1));
            M[x][y-1]=M[x][y]+1;
        }
        if(y!=W-1 && M[x][y+1]==0){
            enqueue(Q,obj_new(x*W+y+1));
            M[x][y+1]=M[x][y]+1;
        }
    }

    int ans;
    if(M[H-1][W-1]==0) ans=-1;
    else ans=white-(M[H-1][W-1]+1);
    printf("%d\n",ans);

    return 0;
}

//重みなし最短路(BFS)くらいなら、わざわざgraph構造体持ち出さなくても、int二重配列のままいけちゃう
//実際にどのルートを通るかは問題ではない、重要なのはいくつ通るかなので、BFSで最短路の長さだけ求める→問題の簡略化の思想