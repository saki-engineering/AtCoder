#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);

    //それぞれN以下の自然数の中で、もともとKの倍数と2倍して初めてKの倍数になるものの数
    long k1=0;
    long k2=0;
    for(int i=1;i<=N;i++){
        if(i%K==0) k1++;
        else if((i*2)%K==0) k2++;
    }


    long ans=(k1*k1*k1)+(k2*k2*k2);
    printf("%ld\n",ans);

    return 0;
}

//a+b,b+c,c+aがKの倍数→2*a,2*b,2*cがKの倍数