#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    int priority;
    double value;
}data;

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    int N,C;
    scanf("%d%d",&N,&C);

    int D[C+1][C+1];
    for(int i=1;i<=C;i++){
        for(int j=1;j<=C;j++) scanf("%d",&D[i][j]);
    }

    int map[N+1][N+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) scanf("%d",&map[i][j]);
    }

    //(i+j)%3の値ごとにそれぞれ、何色のますがいくつあるのか格納
    int R[3][C+1];
    for(int i=0;i<3;i++){
        for(int j=1;j<=C;j++) R[i][j]=0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) R[(i+j)%3][map[i][j]]++;
    }

    //何色で塗ればいいか全探索
    int ans=1000000000;
    for(int a=1;a<=C;a++){
        for(int b=1;b<=C;b++){
            if(a==b) continue;
            for(int c=1;c<=C;c++){
                if(a==c || b==c) continue;
                int tmp=0;
                for(int l=1;l<=C;l++){
                    tmp+=R[0][l]*D[l][a];
                    tmp+=R[1][l]*D[l][b];
                    tmp+=R[2][l]*D[l][c];
                }
                ans=MIN(ans,tmp);
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}

//continueのつもりでbreak書いてませんか？？？当然WAになる
//Rのように、データをためておこうという発想ができるかどうかが肝、一個ずつマスを塗り替えるんじゃなくて、同じ色のものをまとめて何色に塗り替えるかが大事なんだから