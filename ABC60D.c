#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

//降順
int desc(const void* a, const void* b){
    long p=*(long*)a;
    long q=*(long*)b;
    if((q-p)>0) return 1;
    else if((q-p)<0) return -1;
    else return 0;
}

int main(void){
    int N;
    long W;
    scanf("%d%ld",&N,&W);

    long A[4][N];
    int M[4]={0,0,0,0};
    long w1;
    scanf("%ld%ld",&w1,&A[0][0]);
    M[0]++;
    for(int i=1;i<N;i++){
        long w2;
        long a;
        scanf("%ld%ld",&w2,&a);
        A[w2-w1][M[w2-w1]]=a;
        M[w2-w1]++;
    }
    for(int i=0;i<4;i++) qsort(A[i],M[i],sizeof(long),desc);

    //累積和にする
    for(int i=0;i<4;i++){
        for(int j=1;j<=M[i];j++) A[i][j]+=A[i][j-1];
    }

    long ans=0;
    for(int a=0;a<=M[0];a++){
        for(int b=0;b<=M[1];b++){
            for(int c=0;c<=M[2];c++){
                for(int d=0;d<=M[3];d++){
                    long w_sum=a*w1+b*(w1+1)+c*(w1+2)+d*(w1+3);
                    if(w_sum<=W){
                        long price=0;
                        if(a!=0) price+=A[0][a-1];
                        if(b!=0) price+=A[1][b-1];
                        if(c!=0) price+=A[2][c-1];
                        if(d!=0) price+=A[3][d-1];
                        ans=MAX(ans,price);
                    }
                }
            }
        }
    }
    printf("%ld\n",ans);

    return 0;
}

//DPは無理
//それぞれの重さのものをいくつ入れるかが全探索できるからそれでやる