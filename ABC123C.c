#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    long N,A,B,C,D,E;
    long T[5];
    scanf("%ld%ld%ld%ld%ld%ld",&N,&T[0],&T[1],&T[2],&T[3],&T[4]);

    //TminにT[5]の中の最小値を格納
    long Tmin=T[0];
    for(int i=0;i<5;i++){
        if(Tmin>T[i]){
            Tmin=T[i];
        }
    }

    //時間
    long t=N/Tmin+MIN(N%Tmin,1)+4;
    printf("%ld\n",t);

    return 0;
}

//特に困ったことなし