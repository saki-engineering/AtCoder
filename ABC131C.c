#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//最大公約数
//最大公約数
long gcd(long a, long b){
    //a>bになるように入れ替え
    if(a<b){
        long tmp=a;
        a=b;
        b=tmp;
    }
    //ユークリッドの互除法
    if(a%b==0) return b;
    return gcd(b,a%b);
}

//最小公倍数
long lcm(long a, long b){
    long ab=a*b;
    return ab/gcd(a,b);
}

int main(void){
    long A,B,C,D;
    scanf("%ld %ld %ld %ld",&A, &B, &C, &D);

    long cmin=(A-1)/C;
    long cmax=B/C;
    long c=cmax-cmin;

    long dmin=(A-1)/D;
    long dmax=B/D;
    long d=dmax-dmin;

    long L=lcm(C,D);
    long cdmin=(A-1)/(L);
    long cdmax=B/(L);
    long cd=cdmax-cdmin;


    long ans=(B-A+1)-c-d+cd;
    printf("%ld\n",ans);

    return 0;
}

//300点
//REの時は、デバッグprintfの消し忘れ、0割、配列外参照を疑え！
//解き方はあっているのにWAの時は、longをintにしていて溢れていることを疑え