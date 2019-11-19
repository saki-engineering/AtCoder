#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(type, x, y) do { type tmp = x; x = y; y = tmp; } while (0)

#define MOD 1000000007 
 
//a*x + MOD*y = 1の整数解を求める。その中で最小の正数xがaの逆元となる。
//解き方は、ユークリッドの互除法
//参考：http://arc360.info/algo/privatekey.html
long modinv(long a, long m) {
  long b = m, u = 1, v = 0;
  while (b) {
    long t = a / b;
    a -= t * b; SWAP(long,a, b);
    u -= t * v; SWAP(long,u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

//nCmを求める
long combination(int n, int m){
    long ans=1;

    for(int i=n;i>(n-m);i--) ans=(ans*i)%MOD;
    for(int i=2;i<=m;i++) ans=(ans*modinv(i,MOD))%MOD;

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