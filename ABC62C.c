#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

//昇順
int asc(const void* a, const void* b){
    if((*(long*)a-*(long*)b)>0) return 1;
    else if((*(long*)a-*(long*)b)<0) return -1;
    return 0;
}

int main(void){
    long H,W;
    scanf("%ld%ld",&H,&W);

    long ans=H*W;
    if(H%3==0) ans=0;
    else if(W%3==0) ans=0;
    else{
        long S[3];
        //例2の切り方
        for(int i=1;i<=W-1;i++){
            S[0]=H*i;
            S[1]=(W-i)*(H/2);
            S[2]=(W-i)*(H-H/2);
            qsort(S,3,sizeof(long),asc);
            ans=MIN(ans,S[2]-S[0]);
        }
        //例3の切り方
        for(int i=1;i<=H-1;i++){
            S[0]=W*i;
            S[1]=(H-i)*(W/2);
            S[2]=(H-i)*(W-W/2);
            qsort(S,3,sizeof(long),asc);
            ans=MIN(ans,S[2]-S[0]);
        }
        //縦斬り
        ans=MIN(ans,H);
        //横切り
        ans=MIN(ans,W);
    }
    printf("%ld\n",ans);

    return 0;
}