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
    int A,B,C,D,E,F;
    scanf("%d%d%d%d%d%d",&A,&B,&C,&D,&E,&F);

    int ans1=A*100;
    int ans2=0;
    double cmax=0;
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            //水の量
            int W=((A*i)+(B*j))*100;
            //もし水が0gならスキップ、重量オーバーならbreakで次のforループに
            if(W==0) continue;
            if(W>F) break;

            int limit_sugar=MIN((A*i+B*j)*E,F-W);
            for(int k=0;k<=(limit_sugar)/C;k++){
                //砂糖の量
                int S=C*k+D*((limit_sugar-C*k)/D);
                double c=100.0*S/(W+S);
                
                if(c>cmax){
                    cmax=c;
                    ans1=W+S;
                    ans2=S;
                }
            }
        }
    }
    printf("%d %d\n",ans1,ans2);

    return 0;
}