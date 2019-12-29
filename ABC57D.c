#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 

//昇順
int desc(const void* a, const void* b){
    long p=*(long*)a;
    long q=*(long*)b;
    if(q-p>0) return 1;
    else if(q-p<0) return -1;
    else return 0;
}

long comb(long p,long q){
	if(q==0 || p==q)return 1;
	if(q>p/2)q=p-q;
	long ans=1;
	for(long i=1;i<=q;i++){
		ans*=p-i+1;
		ans/=i;
	}
	return ans;
}

int main(void){
    int N,A,B;
    scanf("%d%d%d",&N,&A,&B);

    long* v;
    NEW(v,N);
    for(int i=0;i<N;i++){
        scanf("%ld",&v[i]);
    }
    qsort(v,N,sizeof(long),desc);

    //平均値を求める
    double avg=0;
    for(int i=0;i<A;i++){
        avg+=v[i];
    }
    avg/=A;

    //l...v[A-1]より大きい値の数、m...v[A-1]と同じ値の数
    int l=0;
    int m=0;
    for(int i=0;i<N;i++){
        if(v[i]>v[A-1]) l++;
        else if(v[i]==v[A-1]) m++;
        else break;
    }

    long ans=0;
    long tmp;
    if(l==0){
        for(int i=A;i<=MIN(B,m);i++){
            //mCiを足せば良い
            tmp=comb(m,i);
            ans+=tmp;
        }
    }
    else{
        //mC(m-l)がans
        ans=comb(m,A-l);
    }

    printf("%.6f\n",avg);
    printf("%ld\n",ans);

    return 0;
}