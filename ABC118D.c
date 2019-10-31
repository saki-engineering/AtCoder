#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define INFTY 99999999

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

//num[i]..数字のiはマッチを何本使うか
int num[10]={0,2,5,5,4,5,6,3,7,6};

int main(void){
    int N,M;
    scanf("%d%d",&N,&M);

    //A[0]~A[N-1]に格納する→降順ソート
    int* A;
    NEW(A,M);
    for(int i=0;i<M;i++){
        scanf("%d",&A[i]);
    }
    qsort(A,M,sizeof(int),desc);

    //digit[i]...マッチi本で最大何桁の数が作れるかを格納
    int digit[N+1];
    digit[0]=0;
    for(int i=1;i<=N;i++) digit[i]=-INFTY;

    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            if((i-num[A[j]])>=0) digit[i]=MAX(digit[i], digit[i-num[A[j]]]+1);
        }
    }

    int match=N;
    while(match>0){
        for(int j=0;j<M;j++){
            //ここのmatch-num[A[j]]>=0がないとWAになっちゃう
            if(digit[match]==digit[match-num[A[j]]]+1 && match-num[A[j]]>=0){
                match-=num[A[j]];
                printf("%d",A[j]);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}

//最後、マッチがぴったり0本になるようにしなきゃいけないとか、隠れた条件がないかを考えること
//小さいNでテストできる→DP