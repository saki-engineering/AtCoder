#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void){
    double a,b,x;
    scanf("%lf%lf%lf",&a,&b,&x);

    double V=a*a*b;

    double h;
    double htan;
    //水の量が容積の半分以上
    if(x>=(V/2)){
        h=2*b-2*x/(a*a);
        htan=h/a;
    }
    else{
        h=2*x/(a*b);
        htan=b/h;
    }

    double ans=atan(htan)*180/(atan(1.0) * 4.0);
    printf("%.7lf\n",ans);

    return 0;
}