#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ


//ソートされたA[left~mid]とA[mid+1~right]をくっつける関数
void merge(double* A, int left, int mid, int right, double* B){
    int i,j,k;
    double tmp;

    //kは一時的な配列Bの現在の添字、iは前半A[left~mid]、jは後半A[mid+1~right]を指す添字
    k=left; i=left; j=mid+1;
    while(k<=right){
        if(j>right) tmp=A[i++]; //前半のみにデータがある
        else if(i>mid) tmp=A[j++]; //後半のみにデータがある
        else if(A[i]<=A[j]) tmp=A[i++]; //前半の方が小さい
        else tmp=A[j++]; //後半の方が小さい

        B[k++]=tmp;
    }
    for(i=left;i<=right;i++) A[i]=B[i]; //元の配列に戻す
}

//A[left]~A[right]までの配列を昇順にマージソートする関数
void merge_sort(double* A, int left, int right, double*B){
    int mid;

    if(left<right){
        mid=(left+right)/2;
        merge_sort(A,left,mid,B); //A[left]~A[mid]までを再帰的にソート
        merge_sort(A,mid+1,right,B); //A[mid+1]~A[right]までを再帰的にソート
        merge(A,left,mid,right,B); //分割した二つをくっつける
    }
}

int main(void){
    int N;
    scanf("%d",&N);

    //v[0]~v[N-1]に格納する
    double* v;
    NEW(v,N);
    for(int i=0;i<N;i++){
        scanf("%lf",&v[i]);
    }

    //マージソート用の仮配列
    double* u;
    NEW(u,N);
    //vをマージソート
    merge_sort(v,0,N-1,u);
    free(u);

    for(int i=0;i<=N-2;i++){
        v[i+1]=(v[i]+v[i+1])/2;
    }

    double ans=v[N-1];
    printf("%lf\n",ans);

    return 0;
}

//300点