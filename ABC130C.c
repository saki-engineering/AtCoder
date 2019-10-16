#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    double W, H, x, y;
    scanf("%lf %lf %lf %lf",&W, &H, &x, &y);

    double S=W*H/2;

    int ans;
    if(x==W/2&&y==H/2) ans=1;
    else ans=0;

    printf("%lf %d\n",S,ans);

    return 0;
}

//300点
//特に困ったことはない