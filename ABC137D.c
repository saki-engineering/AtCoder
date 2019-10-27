#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)

typedef struct{
    long price;
    int date;
}heapdata;

//ヒープ木型の定義
typedef struct{
    int max_size;   //ヒープ二分木(配列A)の中に格納できる最大要素数
    int heap_size;  //ヒープ二分木(配列A)の中に現在入っている要素の数
    heapdata* A;    //要素を格納するための配列(ポインタ)
}* heap;

//ヒープH内の配列のA[i]とA[j]の値を入れ替える関数
void heap_swap(heap H,int i,int j){
    heapdata tmp;
    
    tmp=H->A[i];
    H->A[i]=H->A[j];
    H->A[j]=tmp;
    
    return;
}

//HEAPIFY O(nlogn)
//A[i]を根とする部分木がヒープになるように整序する関数
void heapify(heap H, int i){
    int l,r,largest,size;
    heapdata* A;
    
    l=LEFT(i); //iの左の子の添字
    r=RIGHT(i); //iの右の子の添字
    size=H->heap_size; //今のヒープHのサイズ
    A=H->A; //ヒープ二分木に格納されている要素の配列
    
    //以下largestを決めるコード
    if(l>size&&r>size){
        largest=i;
    }
    else if(l<=size&&r>size){
        if(A[l].price>A[i].price){
            largest=l;
        }
        else{
            largest=i;
        }
    }
    else{
        if(A[r].price>A[l].price){
            largest=r;
        }
        else{
            largest=l;
        }
        if(A[i].price>A[largest].price){
            largest=i;
        }
    }
    
    //largestが決まったら要素を入れ替えする
    if(largest!=i){
        heap_swap(H,i,largest);
        heapify(H,largest);
    }
    
    return;
}

//EXTRACT_MAX O(logn)
//ヒープ木の中の最大要素を削除し出力、その最大要素を除いたヒープ木を再構成する関数
heapdata extract_max(heap H){
    int n=H->heap_size;
    if(n>0){
        heap_swap(H,1,n);
        H->heap_size=n-1;
        heapify(H,1);
        
        return H->A[n];
    }
    else{
        heapdata x;
        x.price=-1;
        return x;
    }
}

//INSERT O(logn)
//data xをヒープHに挿入する関数
void heap_insert(heap H,heapdata x){
    int n=H->heap_size;
    
    if(n==H->max_size){
        printf("ERROR　cannot insert anymore\n");
        return;
    }
    else{
        H->A[n+1]=x;
        H->heap_size=n+1;
        
        int i=n+1;
        while(PARENT(i)>=1&&H->A[i].price>H->A[PARENT(i)].price){
            heap_swap(H,i,PARENT(i));
            i=PARENT(i);
        }
        return;
    }
}

//dateの昇順
int comp(const void* a, const void* b){
    heapdata p = *(heapdata *)a;
    heapdata q = *(heapdata *)b;
    if(p.date < q.date) return -1;
    else if(p.date > q.date) return 1;
    else return 0;
}

int main(void){
    int N,M;
    scanf("%d %d",&N, &M);

    //S[1]~S[N]に格納する
    heapdata* S;
    NEW(S,N);
    for(int i=0;i<N;i++){
        scanf("%d %ld",&S[i].date, &S[i].price);
    }
    //dateの昇順にソート
    qsort(S,N,sizeof(S[0]),comp);

    //空のヒープ木の作成
    heap T;
    NEW(T,1);
    T->max_size=N;
    T->heap_size=0;
    NEW(T->A,N+1);

    long ans=0;
    int day=1;
    int i=0;
    while(day<=M){
        //報酬がday日後にもらえる仕事をheapに入れる
        while(i<N){
            if(S[i].date==day){
                heap_insert(T,S[i]);
                i++;
            }
            else break;
        }

        //heap内にある仕事(=報酬がもらえる)の中で一番高額なものを受ける
        heapdata x=extract_max(T);
        if(x.price>0){
            ans+=x.price;
        }

        day++;
    }
    

    //今日が0日目、M日目までに得られる報酬の最大値が欲しい

    printf("%ld\n",ans);


    return 0;
}

//ヒープが空の時にextract_maxされたときにどうするのか考えること
//それを考えないとREになる