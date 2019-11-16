#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    double x;
    double y;
}city;

//昇順
int asc(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

//降順
int desc(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    city* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%lf%lf",&A[i].x,&A[i].y);
    }

    //map[i][j]はi→jの距離
    double map[N][N];
    double sum=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j]=sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x)+(A[i].y-A[j].y)*(A[i].y-A[j].y));
            sum+=map[i][j];
        }
    }

    double ans=sum/N;
    printf("%.7lf\n",ans);

    return 0;
}