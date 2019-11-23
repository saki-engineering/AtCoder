#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

//Nが素数だと1,素数じゃないと0になる関数
int is_prime(int N){
    int ans=1;

    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            ans=0;
            break;
        }
    }
    return ans;
}

int main(void){
    int N;
    scanf("%d",&N);

    int cnt=0;
    int p=2;
    while(cnt<N){
        if(is_prime(p)){
            if(p%5==1){
                printf("%d\n",p);
                cnt++;
            }
        }
        p++;
    }
    printf("\n");

    return 0;
}