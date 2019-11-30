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

    long name[5]={0};
    char c[6]="MARCH";

    for(int i=0;i<N;i++){
        char S[11];
        scanf("%s",S);
        for(int j=0;j<5;j++){
            if(S[0]==c[j]) name[j]++;
        }
    }

    long ans=0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){
            for(int k=j+1;k<5;k++) ans+=name[i]*name[j]*name[k];
        }
    }
    printf("%ld\n",ans);

    return 0;
}

//困ったことなし