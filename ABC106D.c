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
    int N,M,Q;
    scanf("%d%d%d",&N,&M,&Q);

    //map[L][R]は、Lから始まりRで終わる電車の数
    int map[N+1][N+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) map[i][j]=0;
    }
    //標準入力からmapの情報を入れる
    for(int i=0;i<M;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        map[l][r]++;
    }

    int sum[N+1][N+1];
    //累積和をとる
    for(int i=1;i<=N;i++){
        sum[i][0]=0;
        sum[i][1]=map[i][1];
        for(int j=2;j<=N;j++){
            sum[i][j]=sum[i][j-1]+map[i][j];
        }
    }

    int p[Q];
    int q[Q];
    for(int i=0;i<Q;i++){
        scanf("%d%d",&p[i],&q[i]);
    }

    for(int k=0;k<Q;k++){
        int ans=0;
        for(int i=p[k];i<=q[k];i++){
            ans+=sum[i][q[k]]-sum[i][p[k]-1];
        }
        printf("%d\n",ans);
    }

    return 0;
}