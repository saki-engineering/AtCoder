#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N,A,B,C;
    scanf("%d%d%d%d",&N,&A,&B,&C);

    //l[0]~l[N-1]に格納
    int* l;
    NEW(l,N);
    for(int i=0;i<N;i++){
        scanf("%d",&l[i]);
    }

    int ans=1000000000;

    for(int i=0;i<(1<<(2*N));i++){
        //allicationを2bitずつブロックで区切って、その値でl[j]の竹をAorBorCに使うor使わないを判断
        int allocation=i;
        //a,b,cの材料になる竹の総長
        int aing=0;
        int bing=0;
        int cing=0;

        int mp=0;

        //allocationのビットで竹を割り振り
        for(int j=0;j<N;j++){
            int c=allocation&3;

            if(c==1){
                if(aing!=0) mp+=10; 
                aing+=l[j];
            }
            else if(c==2){
                if(bing!=0) mp+=10;
                bing+=l[j];
            }
            else if(c==3){
                if(cing!=0) mp+=10;
                cing+=l[j];
            }

            allocation=(allocation-c)>>2;
        }

        if(aing==0 || bing==0 || cing==0) continue;

        mp+=abs(A-aing)+abs(B-bing)+abs(C-cing);

        if(ans>mp) ans=mp;
    }

    printf("%d\n",ans);

    return 0;
}

//Nが少ない→全探索できる
//魔法を軸に考えるのではなく、A,B,Cの材料を何にするかを考える

//stdlibには絶対値abs関数がある