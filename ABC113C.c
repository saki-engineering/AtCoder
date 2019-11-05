#include<stdio.h>
#include<stdlib.h>
 
#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ
 
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
 
typedef struct{
    int name;
    int prefecture;
    int year;
    int id;
}city;
 
//cityをprefecture昇順→yearの昇順に並び替え
int city_asc(const void* a, const void* b){
    city p=*(city*)a;
    city q=*(city*)b;
 
    if(p.prefecture-q.prefecture>0) return 1;
    else if(p.prefecture-q.prefecture<0) return -1;
    else{
        if(p.year-q.year>0) return 1;
        else if(p.year-q.year<0) return -1;
    }
    return 0;
}
 
int name_asc(const void* a, const void* b){
    city p=*(city*)a;
    city q=*(city*)b;
 
    return p.name-q.name;
}
 
int main(void){
    int N,M;
    scanf("%d%d",&N,&M);
 
    //C[0]~C[M-1]に格納→昇順ソート
    city* C;
    NEW(C,M);
    for(int i=0;i<M;i++){
        C[i].name=i;
        scanf("%d",&C[i].prefecture);
        scanf("%d",&C[i].year);
        C[i].id=0;
    }
    qsort(C,M,sizeof(city),city_asc);
 
    //認識番号をそれぞれidに格納
    C[0].id=1;
    for(int i=1;i<M;i++){
        if(C[i].prefecture==C[i-1].prefecture) C[i].id=C[i-1].id+1;
        else C[i].id=1;
    }
 
    //入力順に並び替え
    qsort(C,M,sizeof(city),name_asc);
 
    for(int i=0;i<M;i++){
        //%06d...6桁になるまで0で埋めて出力！
        printf("%06d%06d\n",C[i].prefecture,C[i].id);
    }
 
    return 0;
}