#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int x;
    int y;
    long h;
}data;

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    data* A;
    NEW(A,N);
    data sample;
    for(int i=0;i<N;i++){
        scanf("%d%d%ld",&A[i].x,&A[i].y,&A[i].h);
        if(A[i].h!=0) sample=A[i];
    }

    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            long H = sample.h+abs(sample.x-i)+abs(sample.y-j);
            int co=1; //ピラミッドの中心として矛盾がないなら1,あるなら0
            for(int k=0;k<N;k++){
                if(A[k].h!=MAX(0,H-abs(A[k].x-i)-abs(A[k].y-j))){
                    co=0;
                    break;
                }
            }
            if(co){
                printf("%d %d %ld\n",i,j,H);
                return 0;
            }
        }
    }
}

//Nのオーダー的に、中心位置を全探索できる！！
//「h!=0というデータが1つあれば、中心位置の高さを求められる」が思いつけばできたかも・・・