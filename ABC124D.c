#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int n; //ブロック中の文字数
    char c; //ブロックの文字
    int begin;
    int end;
}block;

void array_blocked(char* S, int N, block* A){
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

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);

    char S[N+1];
    scanf("%s",S);

    block* B;
    NEW(B,N+1);
    array_blocked(S,N,B);

    //ブロックの数
    int blo=0;
    while(B[blo].n!=0){
        //printf("char %c num %d begin %d end %d\n",B[blo].c, B[blo].n, B[blo].begin, B[blo].end);
        blo++;
    }

    int A[blo];
    for(int i=0;i<blo;i++){
        A[i]=0;

        //B[end]まで足す
        int end;
        if(B[i].c=='0'){
            end=i+2*(K-1)+1;
            end=MIN(end,blo-1);
        }
        else{
            end=i+2*K;
            end=MIN(end,blo-1);
        }

        A[i]=B[end].end-B[i].begin+1;
    }

    int ans=0;
    for(int i=0;i<blo;i++){
        if(A[i]>=ans) ans=A[i];
    }
    printf("%d\n",ans);

    return 0;
}