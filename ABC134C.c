#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    scanf("%d",&N);

    //A[0]~A[N-1]に格納する
    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    int first;
    int second;
    int fi; //一番大きい数がA[fi]に入る

    //first,second,fiの初期値
    if(A[0]>A[1]){first=A[0];second=A[1];fi=0;}
    else{first=A[1];second=A[0];fi=1;}
    //更新
    for(int i=2;i<N;i++){
        if(A[i]>first){
            second=first;
            first=A[i];
            fi=i;
        }
        else if(first>=A[i]&&A[i]>second){
            second=A[i];
        }
    }

    for(int i=0;i<N;i++){
        if(i==fi) printf("%d\n",second);
        else printf("%d\n",first);
    }

    return 0;
}

//300
//特に困らなかった