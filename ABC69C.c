#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    int* A;
    NEW(A,N);
    int a=0;
    int b=0;
    int c=0;
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(A[i]%2==1){
            A[i]=1;
            a++;
        }
        else{
            if(A[i]%4==0){
                A[i]=4;
                c++;
            }
            else{
                A[i]=2;
                b++;
            }
        }
    }

    int flg=1;
    if(a>c+1) flg=0;
    else if(a==c+1){
        if(a+c!=N) flg=0;
    }

    if(flg) printf("Yes\n");
    else printf("No\n");

    return 0;
}