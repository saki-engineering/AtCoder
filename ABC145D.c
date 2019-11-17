#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MOD 1000000007

void swap(long *xp, long *yp) {
  long temp = *xp; 
  *xp = *yp; 
  *yp = temp; 
} 
 
long modinv(long a) {
  long b = MOD, u = 1, v = 0;
  while (b) {
    long t = a / b;
    a -= t * b; swap(&a, &b);
    u -= t * v; swap(&u, &v);
  }
  u %= MOD;
  if (u < 0) u += MOD;
  return u;
}

//nCmを求める
long combination(int n, int m){
    long ans=1;

    for(int i=n;i>(n-m);i--) ans=(ans*i)%MOD;
    for(int i=2;i<=m;i++) ans=(ans*modinv(i))%MOD;

    return ans;
}

int main(void){
    int X,Y;
    scanf("%d%d",&X,&Y);

    long ans;
    if((X+Y)%3!=0) ans=0;
    else{
        int m=(2*Y-X)/3; //(i+1,j+2)の回数
        int n=(2*X-Y)/3; //(i+2,j+1)の回数

        if(m<0 || n<0) ans=0;
        else ans=combination(m+n,n);
    }

    printf("%ld\n",ans);

    return 0;
}