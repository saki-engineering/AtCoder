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
    int H,W;
    scanf("%d%d",&H,&W);

    //map[i][j]には、H=i,W=jのコイン枚数を格納
    int map[H+1][W+1];
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++) scanf("%d",&map[i][j]);
    }

    int N=0;
    int ans[H*W+1][4];

    //奇数枚のコインになる場所を最終列に固める
    for(int i=1;i<=H;i++){
        for(int j=1;j<W;j++){
            if(map[i][j]%2==1){
                N++;

                map[i][j]--;
                map[i][j+1]++;

                ans[N][0]=i;
                ans[N][1]=j;
                ans[N][2]=i;
                ans[N][3]=j+1;
            }
        }
    }

    //最終列に関しても同じことをする
    for(int i=1;i<H;i++){
        if(map[i][W]%2==1){
            N++;

            map[i][W]--;
            map[i+1][W]++;

            ans[N][0]=i;
            ans[N][1]=W;
            ans[N][2]=i+1;
            ans[N][3]=W;
        }
    }

    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    }

    return 0;
}

//特に困ったことなし