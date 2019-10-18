#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MIN(a, b) ((a) < (b) ? (a) : (b))

//ソートされたA[left~mid]とA[mid+1~right]をくっつける関数
void merge(int* A, int left, int mid, int right, int* B){
    int i,j,k;
    int tmp;

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
void merge_sort(int* A, int left, int right, int*B){
    int mid;

    if(left<right){
        mid=(left+right)/2;
        merge_sort(A,left,mid,B); //A[left]~A[mid]までを再帰的にソート
        merge_sort(A,mid+1,right,B); //A[mid+1]~A[right]までを再帰的にソート
        merge(A,left,mid,right,B); //分割した二つをくっつける
    }
}

int main(void){
    int N, K;
    scanf("%d %d",&N, &K);

    //V[0]~V[N-1]に格納する
    int* V;
    NEW(V,N);
    for(int i=0;i<N;i++){
        scanf("%d",&V[i]);
    }

    int ans=0;

    //A+Bをやる回数は最大でR=MIN(N,K)
    int R=MIN(N,K);
    for(int i=0;i<=R;i++){
        for(int j=0;j<=i;j++){
            //A,Bはそれぞれ操作を行う回数
            int A=j;
            int B=i-j;
            
            //Dは操作を行う回数
            int D=K-(A+B);

            //プレーヤーが持っている宝石の価値をここに格納
            int U[A+B];
            //mergeソート用の仮メモリ
            int Uk[A+B];

            //宝石をUに入れる
            int u=0;
            int b=0;
            int vmax=N-1;
            for(u=0;u<A;u++) U[u]=V[u]; //左の宝石を入れる
            //右の宝石を入れる
            while(b<B){
                U[u++]=V[vmax--];
                b++;
            }

            //Uをソート
            merge_sort(U,0,(A+B)-1,Uk);

            //プレイヤーが持っている宝石の総価値をここに入れる
            int count=0;

            //宝石を捨てる
            for(int l=0;l<D;l++){
                if(U[l]<0&&l<(A+B)){
                    count-=U[l];
                }
            }

            for(int l=0;l<i;l++){
                count+=U[l];
            }

            if(count>ans) ans=count;

        }
    }

    printf("%d\n",ans);

    return 0;
}

//N,Kが小さいので、全探索可能！！