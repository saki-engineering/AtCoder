#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//Lの要素を比較する関数(第一引数が小さい時は負を、同じの時は0、第二引数が小さい時は正を出力)→qsortの第４引数に指定
//昇順
//void*は、どんな型でもいい汎用ポインタ
int com_L(const void* a, const void* b){
    return *(int*)a-*(int*)b;
    //(int*)aのintポインタを、前に*をつけることでint型に直している
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    int* L;
    NEW(L,N);
    for(int i=0;i<N;i++){
        scanf("%d",&L[i]);
    }

    //stdlibにあるソート関数qsortを使用→昇順にソートされる
    qsort(L, N, sizeof(int), com_L);

    int ans=0;

    for(int i=0;i<=N-3;i++){
        for(int j=i+1;j<=N-2;j++){
            int a=L[i]; //三角形で一番小さい辺
            int b=L[j]; //二番目に小さい辺

            //一番長い辺の長さはhigh未満
            //一番長い辺がbと同じ長さでもいい！
            int high=a+b;

            int count=0;
            int k=j+1;
            while(k<N){
                if(L[k]<high) count++;
                k++;
            }
            ans+=count;
        }
    }
    printf("%d\n",ans);

    return 0;
}

//400点
//qsortだと、構造体配列のときにも簡単にソートが可能→汎用性

//WAの時は、37行目みたいに不必要な条件を入れてないか考えること