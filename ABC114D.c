#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N;
    scanf("%d",&N);

    int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

    int prime_factor[25]={};
    for(int i=2;i<=N;i++){
        int n=i;
        for(int j=0;j<25;j++){
            while(n%prime[j]==0){
                prime_factor[j]++;
                n=n/prime[j];
            }
        }
    }

    int ans=0;

    //p^74を探す
    for(int i=0;i<25;i++){
        if(prime_factor[i]>=74) ans++;
    }

    //p^14+q^4 or p^2+q^24を探す
    for(int i=0;i<24;i++){
        for(int j=i+1;j<25;j++){
            if(prime_factor[i]>=14 && prime_factor[j]>= 4) ans++;
            if(prime_factor[i]>= 4 && prime_factor[j]>=14) ans++;
            if(prime_factor[i]>= 2 && prime_factor[j]>=24) ans++;
            if(prime_factor[i]>=24 && prime_factor[j]>= 2) ans++;
        }
    }

    //p^2+q^4+r^4 を探す
    for(int i=0;i<23;i++){
        for(int j=i+1;j<24;j++){
            for(int k=j+1;k<25;k++){
                if(prime_factor[i]>=2 && prime_factor[j]>=4 && prime_factor[k]>=4) ans++;
                if(prime_factor[i]>=4 && prime_factor[j]>=2 && prime_factor[k]>=4) ans++;
                if(prime_factor[i]>=4 && prime_factor[j]>=4 && prime_factor[k]>=2) ans++;
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}

//75=3*5*5
//n=p^2+q^4+r^4 or p^14+q^4 or p^2+q^24 or p^74を探せばいい

//N!の素因数は、1~Nまで順番に素因数分解すればいい(しらみつぶししても間に合うようなNのオーダーだから)