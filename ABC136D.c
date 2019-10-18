#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;

//S[0]から始まる文字列の長さを求める関数
int string_len(String str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

//文字列を標準入力から読み込み、それをString型のメモリを確保し直してくれる関数
//S[0]~S[n-1]までが入力で、S[n]は0になる
//文字列長さの上限は10000まで
String string_input(void){
    int i,len;
    char buf[100001];
    String str;
    scanf("%s",buf);//buf=入力した文字列が入るchar型の配列
    
    len=string_len(buf);//len=文字列の長さを表すint型変数
    NEW(str,len+1);//strはただのポインタだから、ここでNEWを使ってメモリを確保しなくちゃいけない
    for(i=0;i<len;i++){
        str[i]=buf[i];
    }
    str[len]=0;
    
    return str;
}

//整数と、リストの次要素を指すポインタをまとめた構造体slobjを定義
typedef struct slobj_{
    char key; //そのブロックの要素が何か
    int sum; //ブロックの中に何個文字があるか
    struct slobj_ *next;
    struct slobj_ *prev;
}*slobj;

//slobj型の変数のポインタをslist型と定義→いずれリストの先頭・最後尾要素を指す
typedef struct{
    slobj head;
    slobj tail;
}*slist;

//keyにc, sumにnを持つリスト要素を作る関数
slobj slobj_new(char c, int n){
    slobj p;
    NEW(p,1);
    p->key=c;
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

slist array_blocked(String S, int N){
    slist L=slist_new();

    char c=S[0]; //ブロックの文字
    int charn=0; //ブロックの中にある文字の数

    for(int i=0;i<N;i++){
        if(S[i]==c){
            charn+=1;
        }
        else{
            slobj p=slobj_new(c, charn);
            slist_insert_tail(L,p);
            c=S[i];
            charn=1;
        }

        if(i==N-1){ //もし最後だったら、それをリストに足す
            slobj p=slobj_new(c, charn);
            slist_insert_tail(L,p);
        }
    }

    return L;
}

int main(void){
    String S=string_input();
    int N=string_len(S);

    slist L=array_blocked(S,N);

    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){A[i]=0;}
    
    slobj r=L->head;
    slobj l=L->head->next;
    int d=-1;
    while(r!=NULL){
        d+=(r->sum);
        A[d]=((r->sum)-(r->sum/2))+(l->sum/2);
        A[d+1]=(r->sum/2)+((l->sum)-(l->sum/2));
        d+=(l->sum);
        r=r->next->next;
        if(r!=NULL){l=l->next->next;}
    }
    

    for(int i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    return 0;
}

//400点
//10^100回とかいう、絶対に実行するのが不可能な値だったら、数学的に終わった後の答えを出してやる方向で
//REが出るなら、string_inputの文字列長さ上限を疑え！！