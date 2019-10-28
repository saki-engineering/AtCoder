#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    long price;
    int num;
}shop;

//昇順
int asc(const void* a, const void* b){
    shop p = *(shop*)a;
    shop q = *(shop*)b;

    if(p.price<q.price) return -1;
    else if(p.price>q.price) return 1;
    return 0;
}

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    //S[0]~S[N-1]にshopの情報を格納→priceの昇順ソート
    shop* S;
    NEW(S,N);
    for(int i=0;i<N;i++){
        scanf("%ld%d",&S[i].price, &S[i].num);
    }
    qsort(S,N,sizeof(shop),asc);

    //安い店から順番に回る
    long ans=0;
    int i=0;
    while(M>0){
        if(M>=S[i].num){
            ans+=S[i].price*S[i].num;
            M-=S[i].num;
        }
        else{
            ans+=S[i].price*M;
            M=0;
        }
        i++;
    }
    printf("%ld\n",ans);

    return 0;
}

//whileループでよくi++つけるの忘れるから気をつける！