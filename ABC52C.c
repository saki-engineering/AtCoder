#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MOD 1000000007 

int main(void){
    int N;
    scanf("%d",&N);

    int* prime_factor;
    NEW(prime_factor,N+1);
    for(int i=1;i<=N;i++) prime_factor[i]=0;

    //素因数をかぞえあげる
    for(int i=1;i<=N;i++){
        int tmp=i;
        int q=2;
        while(tmp!=1){
            if(tmp%q==0){
                prime_factor[q]++;
                tmp/=q;
            }
            else q++;
        }
    }

    long ans=1;
    for(int i=1;i<=N;i++){
        ans=(ans*(prime_factor[i]+1))%MOD;
    }
    printf("%ld\n",ans);

    return 0;
}