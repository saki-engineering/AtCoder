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
    int N;
    long M;
    scanf("%d%ld",&N,&M);

    //A[0]~A[N-1]に格納する
    long* A;
    NEW(A,N+1);
    for(int i=1;i<=N;i++){
        scanf("%ld",&A[i]);
    }

    //累積和(mod M)を入れる
    long* S;
    NEW(S,N+1);
    S[0]=0;
    for(int i=1;i<=N;i++){
        S[i]=(S[i-1]+A[i])%M;
    }
    qsort(S,N+1,sizeof(long),asc);

    long ans=0;
    long tmp=0;

    for(int i=1;i<=N;i++){
        if(S[i]==S[i-1]){
            tmp++;
        }
        else{
            ans+=tmp*(tmp+1)/2;
            tmp=0;
        }
    }
    ans+=tmp*(tmp+1)/2;
    printf("%ld\n",ans);

    return 0;
}

//ansがlongならtmpもlongにしたほうがいい、そうじゃないとオーバーフローして謎のWAがでる