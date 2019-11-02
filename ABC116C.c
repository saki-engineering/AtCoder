#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N;
    scanf("%d",&N);

    //h[0]~h[N-1]に格納する
    int* h;
    NEW(h,N);
    for(int i=0;i<N;i++){
        scanf("%d",&h[i]);
    }

    int ans=0;

    int i=0;
    while(i<N){
        while(h[i]!=0){
            //h[i]から始まるブロックの中での最小値minを求める
            int j=i;
            int min=h[i];
            while(j<N-1 && h[j+1]!=0){
                min=MIN(min,h[j+1]);
                j++;
            }

            //このとき、minはh[i]~h[j]までの最小値
            //minが0でないなら、h[i]~h[j]までmin回水やり
            if(min!=0){
                ans+=min;
                for(int k=i;k<=j;k++) h[k]-=min;
            }
        }
        i++;
    }

    printf("%d\n",ans);

    return 0;
}

//左から順番にh[i]から始まるブロックを潰す(つまり開始位置固定)という考え方をする
//h[i]が0になって水やりできなくなったら、i++する