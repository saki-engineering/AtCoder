#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int comp(const void* a, const void* b){
    if (*(long*)a > *(long*)b) return -1;
	if (*(long*)a < *(long*)b) return 1;
	return 0;
}

int main(void){
    int X,Y,Z,K;
    scanf("%d%d%d%d",&X,&Y,&Z,&K);

    //A[0]~A[X-1]に格納する→降順ソート
    long A[1000];
    for(int i=0;i<X;i++){
        scanf("%ld",&A[i]);
    }
    qsort(A,X,sizeof(long),comp);
    //B[0]~B[Y-1]に格納する→降順ソート
    long B[1000];
    for(int i=0;i<Y;i++){
        scanf("%ld",&B[i]);
    }
    qsort(B,Y,sizeof(long),comp);
    //C[0]~C[Z-1]に格納する→降順ソート
    long C[1000];
    for(int i=0;i<Z;i++){
        scanf("%ld",&C[i]);
    }
    qsort(C,Z,sizeof(long),comp);

    long AB[1000000];
    int ab=0;
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            AB[ab]=A[i]+B[j];
            ab++;
        }
    }
    qsort(AB,ab,sizeof(long),comp);

    long ans[3000000];
    int count=0;
    for(int i=0;i<Z;i++){
        for(int j=0;j<K && j<ab;j++){
            ans[count]=C[i]+AB[j];
            count++;
        }
    }
    qsort(ans,count,sizeof(long),comp);

    for(int i=0;i<K;i++){
        printf("%ld\n",ans[i]);
    }

    return 0;
}

//確実に上位K位に入らないものを取り除くという考え方
//comp関数に引数longを使う時には、return *(long*)b-*(long*)a;とするとreturn がオーバーフローする可能性があるので注意！！