#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    long a;
    long b;
}sword;

//b→aの降順
int desc(const void* a, const void* b){
    sword p=*(sword*)a;
    sword q=*(sword*)b;
    if(q.b-p.b>0) return 1;
    else if(q.b-p.b<0) return -1;
    else{
        if(q.a-p.a>0) return 1;
        else if(q.a-p.a<0) return -1;
        else return 0;
    }
}

int main(void){
    int N;
    long H;
    scanf("%d%ld",&N,&H);

    //A[0]~A[N-1]に格納する
    sword* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld%ld",&A[i].a,&A[i].b);
    }
    qsort(A,N,sizeof(sword),desc);

    //その刀を投げるより、別の刀を振るう方がダメージでかい奴はそもそも使わない→除外
    int M=0; //除外されない刀の数
    long a_max=A[0].a;
    for(int i=0;i<N;i++) a_max=MAX(a_max,A[i].a);
    for(int i=0;i<N;i++){
        if(A[i].b>=a_max) M++;
    }

    //全ての刀を投げつけた時の合計ダメージ
    long b_sum=0;
    for(int i=0;i<M;i++) b_sum+=A[i].b;

    long ans=9999999999;
    long tmp=0;
    long damage=0;
    //刀を振らなくても大丈夫なとき
    if(H<=b_sum){
        for(int j=0;j<M;j++){
            if(damage>=H) break;
            tmp++;
            damage+=A[j].b;
        }
    }
    //最後に残した刀を使うパターン
    else{
        damage=b_sum;
        tmp=M;
        if(H-damage>0){
            tmp+=(H-damage)/a_max;
            if((H-damage)%a_max) tmp++;
        }
    }
    ans=MIN(ans,tmp);
    
    printf("%ld\n",ans);
    return 0;
}

//最後に振るうために残しておく刀は、a_maxの刀と決め打ちしても良いので、そこまで断定してしまう！
//(直す前は、残す刀をforループで探してたけど、TLE)