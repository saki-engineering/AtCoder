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
    int A,B,C,X,Y;
    scanf("%d%d%d%d%d",&A,&B,&C,&X,&Y);

    long ans=0;
    if(A+B>2*C) ans+=2*C*MIN(X,Y);
    else ans+=(A+B)*MIN(X,Y);

    if(X>Y){
        if(A>2*C) ans+=2*C*(X-Y);
        else ans+=A*(X-Y);
    }
    else{
        if(B>2*C) ans+=2*C*(Y-X);
        else ans+=B*(Y-X);
    }
    printf("%ld\n",ans);

    return 0;
}