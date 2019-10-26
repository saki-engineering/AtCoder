#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MIN(a,b) ((a) < (b) ? (a) : (b))

//整数と、リストの次要素を指すポインタをまとめた構造体slobjを定義
typedef struct slobj_{
    char direction; //そのブロックの人が左向きLか右向きRか
    int sum; //ブロックの中に何個文字があるか
    struct slobj_ *next;
    struct slobj_ *prev;
}*slobj;

//slobj型の変数のポインタをslist型と定義→いずれリストの先頭要素を指す
typedef struct{
    slobj head;
    slobj tail;
}*slist;

//cirectionにc, sumにnを持つリスト要素を作る関数
slobj slobj_new(char c, int n){
    slobj p;
    NEW(p,1);
    p->direction=c;
    p->sum=n;
    p->next=NULL;
    p->prev=NULL;
    return p;
}

//slist型の空リスト1つを作る関数
slist slist_new(void){
    slist L;
    NEW(L,1);
    L->head=NULL;
    L->tail=NULL;
    return L;
}

//slobj要素のメモリを解放する
void free_slobj(slobj p){
    free(p);
    return;
}

//slobj型の要素pをリストLの最後に挿入する関数
void slist_insert_tail(slist L,slobj p){
    if(L->head==NULL){ //もし最初に挿入するなら
        //p->prev=NULL;
        //p->next=NULL;
        L->head=p;
        L->tail=p;
    }
    else{ //それ以外なら
        p->prev=L->tail;
        //p->next=NULL;
        L->tail->next=p;
        L->tail=p;
    }
    
    return;
}




int main(void){
    int N;
    scanf("%d",&N);

    int K;
    scanf("%d",&K);

    char S[N+1];
    scanf("%s",S); //S[0]~S[N-1]まで文字列、S[N]は0

    //ここから文字列ブロック化、関数にしても良い

    //文字列をブロックリストLに格納
    slist L=slist_new();
    int block_sum=0; //ブロック総数

    char c=S[0]; //ブロックの文字
    int charn=0; //ブロックの中にある文字の数

    for(int i=0;i<N;i++){
        if(S[i]==c){
            charn+=1;
        }
        else{
            block_sum+=1;
            slobj p=slobj_new(c, charn);
            slist_insert_tail(L,p);
            c=S[i];
            charn=1;
        }

        if(i==N-1){ //もし最後だったら、それをリストに足す
            block_sum+=1;
            slobj p=slobj_new(c, charn);
            slist_insert_tail(L,p);
        }
    }

    /* このprintを使えば、ブロックリストに何が入っているのか、ブロックが総数いくつあるのか確認可能
    slobj q=L->head;
    while(q!=NULL){
        printf("%c %d\n",q->direction, q->sum);
        q=q->next;
    }
    printf("%d\n",block_sum);
    */

    int unhappy;
    if((block_sum/2)>K){
        unhappy=block_sum-K*2;
    }
    else{
        unhappy=1;
    }

    int ans=N-unhappy;
    printf("%d\n",ans);

    return 0;
}

//400
//ブロックで考えること
//何も問題文に律儀に回転させる必要はない！！！LとRの変換だけでいい！！！
//文字列をブロック化することが一番大事！！！！
//手こずったねえ・・・