#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve(int n) {
	int a = (n % 2 == 0) ? 0 : 1;
	int m = (a - n) / 2;
	if (m != 0) solve(m);
	printf("%d", a);
}

int main(void){
    int N;
    scanf("%d",&N);

    solve(N);
    return 0;
}