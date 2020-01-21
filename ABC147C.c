#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    int N;
    scanf("%d",&N);

    //Map[i][j]...iの人がjの人に対してなんて言及しているか(1→正直,0→不親切,-1→言及なし)
    int Map[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) Map[i][j]=-1;
    }

    //Mapを埋める
    for(int i=0;i<N;i++){
        int A;
        scanf("%d",&A);
        int x,y;
        for(int j=0;j<A;j++){
            scanf("%d%d",&x,&y);
            Map[i][x-1]=y;
        }
    }

    int ans=0;
    for(int i=0;i<(1<<N);i++){
        int flg=1;
        for(int j=0;j<N;j++){
            if(!flg) break;

            int person; //jが正直ものなら1,真偽不明なら0
            if(i&(1<<j)) person=1;
            else person=0;

            for(int k=0;k<N;k++){
                if((i&(1<<k))==0) continue;
                
                if(Map[k][j]!=person){
                    if(Map[k][j]!=-1){
                        flg=0;
                        break;
                    }
                }
            }
        }
        if(flg) ans=MAX(ans,__builtin_popcount(i));
    }
    printf("%d\n",ans);

    return 0;
}