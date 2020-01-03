#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int sx,sy,tx,ty;
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);

    for(int i=sy;i<ty;i++) printf("U");
    for(int i=sx;i<tx;i++) printf("R");
    for(int i=ty;i>sy;i--) printf("D");
    for(int i=tx;i>sx;i--) printf("L");

    printf("L");
    for(int i=sy;i<ty+1;i++) printf("U");
    for(int i=sx;i<tx+1;i++) printf("R");
    printf("DR");
    for(int i=ty;i>sy-1;i--) printf("D");
    for(int i=tx;i>sx-1;i--) printf("L");
    printf("U\n");

    return 0;
}