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
    int N;
    scanf("%d",&N);

    int range[8]={400,800,1200,1600,2000,2400,2800,3200};
    int color[9]={0,0,0,0,0,0,0,0,0};

    for(int i=0;i<N;i++){
        int a;
        scanf("%d",&a);
        for(int j=0;j<8;j++){
            if(a<range[j]){
                color[j]++;
                break;
            }
        }
        if(a>=3200) color[8]++;
    }

    int min=0;
    for(int i=0;i<8;i++){
        if(color[i]>0) min++;
    }
    int max=min+color[8];
    if(min==0) min=1;
    printf("%d %d\n",min, max);

    return 0;
}

//38行目を忘れないで