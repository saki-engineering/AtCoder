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
    int N,Y;
    scanf("%d%d",&N,&Y);

    int x_max=Y/10000;
    int y_max=Y/5000;

    for(int x=0;x<=x_max;x++){
        for(int y=0;y<=y_max;y++){
            int z=N-x-y;
            if(z<0) continue;
            int sum = x*10000+y*5000+z*1000;

            if(sum==Y){
                printf("%d %d %d\n",x,y,z);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}

//特に困ったことなし