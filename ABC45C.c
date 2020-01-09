#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef char* String;

String string_input(void){
    int i,len;
    char buf[30];
    String str;
    scanf("%s",buf);//buf=入力した文字列が入るchar型の配列
    
    len=strlen(buf);//len=文字列の長さを表すint型変数
    NEW(str,len+1);//strはただのポインタだから、ここでNEWを使ってメモリを確保しなくちゃいけない
    for(i=0;i<len;i++){
        str[i]=buf[i];
    }
    str[len]=0;
    
    return str;
}

int main(void){
    String S=string_input();
    int N=strlen(S);

    int* A;
    NEW(A,N);
    for(int i=0;i<N;i++) A[i]=S[i]-'0';

    long ans=0;
    for(int i=0;i<(1<<(N-1));i++){
        long tmp=0;
        long t=A[0];
        for(int j=0;j<N-1;j++){
            if(i&(1<<j)) t=t*10+A[j+1];
            else{
                tmp+=t;
                t=A[j+1];
            }
        }
        tmp+=t;
        ans+=tmp;
    }
    printf("%ld\n",ans);

    return 0;
}