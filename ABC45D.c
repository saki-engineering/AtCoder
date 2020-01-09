#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct{
    int a;
    int b;
}data;

//昇順
int asc(const void* a, const void* b){
    data p=*(data*)a;
    data q=*(data*)b;
    if(p.a!=q.a) return p.a-q.a;
    else return p.b-q.b;
}

int main(void){
    long H,W;
    int N;
    scanf("%ld%ld%d",&H,&W,&N);

    data* A;
    NEW(A,9*N);
    int cnt=0;
    for(int i=0;i<N;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j=0;j<=2;j++){
            for(int k=0;k<=2;k++){
                if(1<=a-j && a-j<=H-2 && 1<=b-k && b-k<=W-2){
                    A[cnt].a=a-j;
                    A[cnt].b=b-k;
                    cnt++;
                }
            }
        }
    }
    //for(int i=0;i<cnt;i++) printf("%d %d\n",A[i].a,A[i].b);
    qsort(A,cnt,sizeof(data),asc);

    long ans[10];
    ans[0]=(H-2)*(W-2);
    for(int i=1;i<10;i++) ans[i]=0;

    int c=1;
    for(int i=1;i<cnt;i++){
        if(A[i-1].a==A[i].a && A[i-1].b==A[i].b) c++;
        else{
            ans[c]++;
            c=1;
        }
    }
    if(cnt) ans[c]++;

    long sum=0;
    for(int j=1;j<10;j++) sum+=ans[j];
    ans[0]-=sum;

    for(int i=0;i<10;i++) printf("%ld\n",ans[i]);

    return 0;
}