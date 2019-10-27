#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    long N;
    scanf("%ld",&N);

    long ans=N-1;
    double D=sqrt(N);
    long d=D;
    
    int i=1;
    while(i<=D){
        long s;
        long tmp;
        if(N%i==0){
            s=N/i;
            tmp=i+s-2;
            if(ans>tmp) ans=tmp;
        }
        i++;
    }
    
    printf("%ld\n",ans);

    return 0;
}