#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define N 2019

int main(void){
    int L,R;
    scanf("%d %d",&L, &R);

    int ans;
    if((R-L)>=N){
        ans=0;
    }
    else{
        int l,r;
        l=L%N;
        r=R%N;
        if(r<l){
            ans=0;
        }
        else{
            ans=N;
            for(int i=l;i<r;i++){
                for(int j=i+1;j<=r;j++){
                    int tmp=i*j%N;
                    if(tmp<ans) ans=tmp;
                }
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}


//300点
//i*j mod の最低が、l*(l+1)とは限らない！！→forループでしらみつぶし