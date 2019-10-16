#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    long K;
    scanf("%d %ld",&N, &K);

    //A[0]~A[N-1]に格納する
    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    //答えの個数
    long ans=0;

    //尺取り法で数え上げる(O(N^2)がO(N)になる)
    int left=0;
    int right=0;
    long sum=0;
    for(left=0;left<N;left++){
        //もしもsumがKより小さい(条件を満たしてない)なら、rightを条件を満たすまで上げる
        while(sum<K){
            if(right==N) break;
            else{
                sum+=A[right];
                right++;
            }
        }
        //もし終端まで試しても条件を満たさないなら、今後leftをあげても満たされることはないので、break
        if(sum<K) break;
        //区間[left,right-1]からが条件を満たしている→個数は(N-1)-(right-1)+1
        ans+=N-right+1;
        sum-=A[left];
    }
    

    printf("%ld\n",ans);

    return 0;
}