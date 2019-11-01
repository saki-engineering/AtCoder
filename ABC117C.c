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

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    //X[0]~X[M-1]に格納→昇順ソート
    int* X;
    NEW(X,M);
    for(int i=0;i<M;i++){
        scanf("%d",&X[i]);
    }
    qsort(X,M,sizeof(int),asc);


    long ans=0;
    if(N<M){
        //X座標の差を配列Yに格納→昇順ソート
        int* Y;
        NEW(Y,M-1);
        for(int i=0;i<M-1;i++){
            Y[i]=X[i+1]-X[i];
        }
        qsort(Y,M-1,sizeof(int),asc);

        int j=0;
        while(M>N){
            ans+=Y[j];
            j++;
            M--;
        }
    }
    printf("%ld\n",ans);

    return 0;
}

//変なWAがでる(ローカルとコードテストで値が違うとか)場合は、ansの初期化を忘れてないかチェックすること