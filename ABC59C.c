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

    long* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%ld",&A[i]);
    }

    long sum;

    //偶数番目を正にする
    long ans1=0;
    if(A[0]<=0){
        ans1+=labs(1-A[0]);
        sum=1;
    }
    else sum=A[0];
    for(int i=1;i<N;i++){
        //もし符号が同じなら
        if(sum*(sum+A[i])>=0){
            if(i%2==0){
                ans1+=labs(sum+A[i]-1);
                sum=1;
            }
            else{
                ans1+=labs(sum+A[i]-(-1));
                sum=-1;
            }
        }
        else sum+=A[i];
    }

    //奇数番目を正にする
    long ans2=0;
    if(A[0]>=0){
        ans2+=labs(-1-A[0]);
        sum=-1;
    }
    else sum=A[0];
    for(int i=1;i<N;i++){
        //もし符号が同じなら
        if(sum*(sum+A[i])>=0){
            if(i%2==1){
                ans2+=labs(sum+A[i]-1);
                sum=1;
            }
            else{
                ans2+=labs(sum+A[i]-(-1));
                sum=-1;
            }
        }
        else sum+=A[i];
    }

    long ans=MIN(ans1,ans2);
    printf("%ld\n",ans);

    return 0;
}

//偶数番目と奇数番目、どちらを正にするかで2通りある→調べて小さい方。
//↑この2通りに絞る考え方が出てくるか？