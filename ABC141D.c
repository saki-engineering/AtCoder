#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ


#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)

//priorityに対してプライオリティキューを構築
typedef struct{
    double priority;
    double value;
}heapdata; //heapの構造体の中の要素を定義

//ヒープ二分木のポインタをheap型と定義
typedef struct{
    int max_size; //ヒープ二分木(配列A)の中に格納できる最大要素数
    int heap_size; //ヒープ二分木(配列A)の中に現在入っている要素の数
    heapdata* A; //要素を格納するための配列(ポインタ)
}* heap;

//ヒープH内の配列のA[i]とA[j]の値を入れ替える関数
void heap_swap(heap H,int i,int j){
    heapdata tmp;
    
    tmp=H->A[i];
    H->A[i]=H->A[j];
    H->A[j]=tmp;
    
    return;
}

//ヒープの削除
void free_heap(heap H){
    free(H);
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
        if(A[l].priority>A[i].priority){
            largest=l;
        }
        else{
            largest=i;
        }
    }
    else{
        if(A[r].priority>A[l].priority){
            largest=r;
        }
        else{
            largest=l;
        }
        if(A[i].priority>A[largest].priority){
            largest=i;
        }
    }
    
    if(largest!=i){
        heap_swap(H,i,largest);
        heapify(H,largest);
    }
    
    return;
}

//BUILD_HEAP O(n)

//要素n個の配列A、max_sizeをもつヒープ木Hのメモリを確保し出力する関数
heap heap_build(int n, heapdata* A, int max_size){
    int i;
    heap H;
    NEW(H,1);
    
    H->max_size=max_size;
    H->heap_size=n;
    H->A=A;
    
    for(i=n/2;i>=1;i--){
        heapify(H,i);
    }
    
    return H;
}

//EXTRACT_MAX O(logn)

//ヒープ木の中の最大要素を削除し、その最大要素を除いたヒープ木を再構成する関数
heapdata extract_max(heap H){
    int n=H->heap_size;
    
    heap_swap(H,1,n);
    H->heap_size=n-1;
    heapify(H,1);
    
    return H->A[n];
}

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
        while(PARENT(i)>=1&&H->A[i].priority>H->A[PARENT(i)].priority){
            heap_swap(H,i,PARENT(i));
            i=PARENT(i);
        }
        return;
    }
}


int main(void){
    int N, M;
    scanf("%d %d",&N, &M);

    heapdata* A;
    NEW(A,N+1); //A[1]~A[N]と思われ
    for(int i=1;i<=N;i++){
        scanf("%lf",&A[i].priority);
    }

    heap H = heap_build(N,A,N);
    while(M!=0){
        heapdata h = extract_max(H);
        h.priority=(h.priority)/2;
        heap_insert(H,h);
        M--;
    }

    long ans=0;
    for(int i=1;i<=N;i++){
        int tmp=A[i].priority;
        ans+=tmp;
    }
    printf("%ld\n",ans);

    return 0;
}


//400点
//プライオリティーキューってheap木のことね！！！