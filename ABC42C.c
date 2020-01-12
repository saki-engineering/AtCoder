#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N,K;
    scanf("%d%d",&N,&K);

    //使用可能なら1,無理なら0
    int c[10];
    for(int i=0;i<10;i++) c[i]=1;

    for(int i=0;i<K;i++){
        int D;
        scanf("%d",&D);
        c[D]=0;
    }

    int ans;
    int M=N;
    while(1){
        int tmp=M;
        int flg=1;
        while(tmp){
            int digit=tmp%10;
            if(!c[digit]){
                flg=0;
                break;
            }
            else{
                tmp=(tmp-digit)/10;
            }
        }
        if(flg){
            ans=M;
            break;
        }
        else M++;
    }
    printf("%d\n",ans);

    return 0;
}