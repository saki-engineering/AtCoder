#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef char* String;

String string_input(void){
    int i,len;
    char buf[101];
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
    int N;
    scanf("%d",&N);

    String* s;
    NEW(s,N);
    int* t;
    NEW(t,N);
    for(int i=0;i<N;i++){
        s[i]=string_input();
        scanf("%d",&t[i]);
    }

    String X=string_input();

    int index;
    for(int i=0;i<N;i++){
        if(strcmp(s[i],X)==0){
            index=i;
            break;
        }
    }

    long ans=0;
    for(int i=index+1;i<N;i++) ans+=t[i];
    printf("%ld\n",ans);

    return 0;
}