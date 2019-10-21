#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;


int main(void){
    int N;
    scanf("%d",&N);

    //文字列の長さがわかっているんだったら、malloc→scanf%sでやったほうがエラーが起きない
    //自作のstring_inputでやったら謎のREが出てしまった
    String S;
    NEW(S,N+1);
    scanf("%s", S);

    int ans=1;
    for(int i=1;i<N;i++){
        if(S[i]!=S[i-1]){
            ans++;
        }
    }
    printf("%d\n",ans);

    return 0;
}