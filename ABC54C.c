#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

typedef int* vector;

int ans=0;

void make_perm(int n, int size, int* buffer, int* used, vector* Map){
    if (n == size){
        int tmp = 0;
        for(int i = 1; i < size; i++){
            tmp += Map[buffer[i-1]][buffer[i]];
        }
        if(tmp==size-1 && buffer[0] == 0){
            ans++;
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if (used[i]) continue;
            buffer[n] = i;
            used[i] = 1;
            make_perm(n + 1, size, buffer, used, Map);
            used[i] = 0;
        }
    }
}

int main(void){
    int N, M;
    scanf("%d%d",&N,&M);

    vector* Map;
    NEW(Map,N)
    for(int i=0;i<N;i++){
        NEW(Map[i],N)
        for(int j=0;j<N;j++) Map[i][j]=0;
    }

    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Map[a-1][b-1]=1;
        Map[b-1][a-1]=1;
    }

    int* buffer;
    int* used;
    NEW(buffer,N);
    NEW(used,N);
    for(int i=0;i<N;i++) used[i]=0;

    make_perm(0,N,buffer,used,Map);
    printf("%d\n",ans);

    return 0;
}