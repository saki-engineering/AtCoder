#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//actionの定義
typedef struct{
    int max_card; //B
    long value;   //C
}action;

//昇順(第一引数が小さければ負になる)
int comp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//昇順(第一引数が小さければ負になる)
int comp_act(const void* a, const void* b){
    return ((action*)a)->value-((action*)b)->value;
}

int main(void){
    int N, M;
    scanf("%d %d",&N, &M);

    //A[0]~A[N-1]に格納する(i番目のカードに書いてある整数)
    long* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld",&A[i]);
    }
    //Aを昇順ソート
    qsort(A,N,sizeof(long),comp);


    //B,Cを格納
    action* D;
    NEW(D,M);
    for(int j=0;j<M;j++){
        scanf("%d %ld",&D[j].max_card, &D[j].value);
    }
    //Cの値を元に昇順ソート
    qsort(D,M,sizeof(action),comp_act);

    //操作をN回やってカードの数字を書き換える
    int a=0;
    for(int j=M-1;j>=0;j--){
        for(int i=0;i<D[j].max_card && a<N;i++){
            if(A[a]<D[j].value){
                A[a]=D[j].value;
                a++;
            }
            else break;
        }
    }

    long ans=0;
    for(int i=0;i<N;i++) ans+=A[i];
    printf("%ld\n",ans);

    return 0;
}


//入力ごとに1回ずつ処理(共通部分をとる)するのではなく、一気に処理することも考える！
//これも、一気に処理することを考えると操作がN回でいい訳で