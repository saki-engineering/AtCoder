#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    long point;
    int num;
    long comp_point;
}question;

int main(void){
    int D;
    long G;
    scanf("%d%ld",&D,&G);

    //Q[0]~Q[D-1]に格納する
    question* Q;
    NEW(Q,D);
    for(int i=0;i<D;i++){
        Q[i].point=(i+1)*100;
        scanf("%d%ld",&Q[i].num,&Q[i].comp_point);
    }

    int ans=1000000000;
    //tのiビット目が1→全部とく、0→全部はとかない
    for(int t=0;t<(1<<D);t++){
        int tmp=0;
        int pnt=0;
        //全部とくものを処理
        for(int i=0;i<D;i++){
            if(t&(1<<i)){
                tmp+=Q[i].num;
                pnt+=Q[i].point*Q[i].num+Q[i].comp_point;
            }
        }
        if(pnt>=G){
            ans=MIN(ans,tmp);
            continue;
        }

        //全部はとかないものを処理
        for(int i=D-1;i>=0;i--){
            if(!(t&(1<<i))){
                int q_num=(G-pnt)/Q[i].point;
                if((G-pnt)%Q[i].point!=0) q_num++;

                //その問題を全部解いてもG点にできないものはアウト
                if(q_num>=Q[i].num) continue;
                //OKな場合は処理
                else{
                    tmp+=q_num;
                    ans=MIN(ans,tmp);
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}

//全部はとかないものは1種類のみと決め打ってしまえるかどうかが、勝負の分かれ目