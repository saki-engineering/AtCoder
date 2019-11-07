#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int n; //ブロック中の文字数
    int c; //ブロックの文字
    int begin; //ブロック開始場所の添字
    int end; //ブロック終了場所の添字
}block;

void array_blocked_3(int* S, int N, block* A){
    int a=0;
    int count=1;

    A[a].begin=0;

    for(int i=1;i<N;i++){
        if(S[i-1]==S[i]){
            count++;
        }
        else{
            A[a].n=count;
            A[a].c=S[i-1];
            A[a].end=i-1;
            a++;
            A[a].begin=i;
            count=1;
        }
    }
    A[a].n=count;
    A[a].c=S[N-1];
    A[a].end=N-1;
    return;
}

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//ブロック降順
int block_asc(const void* a, const void* b){
    block p=*(block*)a;
    block q=*(block*)b;
    return q.n-p.n;
}

int main(void){
    int N;
    scanf("%d",&N);

    //奇数番目、偶数番目の要素数
    int n=N/2;

    //奇数番目、偶数番目の数列を分けて格納→昇順ソート
    int* odd;
    int* even;
    NEW(odd,n);
    NEW(even,n);
    for(int i=0;i<n;i++){
        scanf("%d",&odd[i]);
        scanf("%d",&even[i]);
    }

    qsort(odd,n,sizeof(int),asc);
    qsort(even,n,sizeof(int),asc);

    block* b_odd;
    block* b_even;
    NEW(b_odd,n);
    NEW(b_even,n);
    for(int i=0;i<n;i++){
        b_odd[i].n=-1;
        b_even[i].n=-1;
    }
    array_blocked_3(odd,n,b_odd);
    array_blocked_3(even,n,b_even);

    int odd_block_num=0;
    int even_block_num=0;
    for(int i=0;i<n;i++){
        if(b_odd[i].n==-1) break;
        else odd_block_num++;
    }
    for(int i=0;i<n;i++){
        if(b_even[i].n==-1) break;
        else even_block_num++;
    }
    qsort(b_odd,odd_block_num,sizeof(block),block_asc);
    qsort(b_even,even_block_num,sizeof(block),block_asc);

    int ans;
    if(b_odd[0].c!=b_even[0].c) ans=N-(b_odd[0].n+b_even[0].n);
    else{
        if(b_odd[1].n==-1 && b_even[1].n==-1) ans=n;
        else if(b_odd[1].n==-1 && b_even[1].n!=-1) ans=MIN(N-(b_even[0].n),N-(b_odd[0].n+b_even[1].n));
        else if(b_odd[1].n!=-1 && b_even[1].n==-1) ans=MIN(N-(b_odd[0].n),N-(b_odd[1].n+b_even[0].n));
        else ans=MIN(N-(b_odd[1].n+b_even[0].n),N-(b_odd[0].n+b_even[1].n));
    }
    printf("%d\n",ans);

    return 0;
}