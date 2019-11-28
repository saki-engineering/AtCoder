#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

typedef struct{
    int x;
    int y;
    int flg;
}data;

//x軸の昇順
int xasc(const void* a, const void* b){
    data p = *(data*)a;
    data q = *(data*)b;
    if(p.x!=q.x) return p.x-q.x;
    else return p.y-q.y;
}

//y軸の降順
int ydesc(const void* a, const void* b){
    data p = *(data*)a;
    data q = *(data*)b;
    if(p.y!=q.y) return q.y-p.y;
    else return q.x-p.x;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    data* red;
    NEW(red,N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&red[i].x,&red[i].y);
        red[i].flg=0;
    }
    qsort(red,N,sizeof(data),ydesc);

    data* blue;
    NEW(blue,N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&blue[i].x,&blue[i].y);
        blue[i].flg=0;
    }
    qsort(blue,N,sizeof(data),xasc);

    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(red[j].flg) continue;
            if(red[j].x<blue[i].x && red[j].y<blue[i].y){
                ans++;
                red[j].flg=1;
                break;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}