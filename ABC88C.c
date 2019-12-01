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
    int c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) scanf("%d",&c[i][j]);
    }

    int a[3]={0,c[1][0]-c[0][0],c[2][0]-c[0][0]};
    int b[3]={c[0][0],c[0][1],c[0][2]};

    if(c[1][1]!=a[1]+b[1]){
        printf("No\n");
        return 0;
    }
    if(c[1][2]!=a[1]+b[2]){
        printf("No\n");
        return 0;
    }
    if(c[2][1]!=a[2]+b[1]){
        printf("No\n");
        return 0;
    }
    if(c[2][2]!=a[2]+b[2]){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");

    return 0;
}


//a,bの組みはたくさんあるから、a1=0と決め打ってしまえるかどうかが決めて