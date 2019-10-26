#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;

//S[0]から始まる文字列の長さを求める関数
int string_len(String str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

//文字列を標準入力から読み込み、それをString型のメモリを確保し直してくれる関数
//S[0]~S[n-1]までが入力で、S[n]は0になる
//文字列長さの上限は1000まで

String string_input(void){
    int i,len;
    char buf[1000];
    String str;
    scanf("%s",buf);//buf=入力した文字列が入るchar型の配列
    
    len=string_len(buf);//len=文字列の長さを表すint型変数
    NEW(str,len+1);//strはただのポインタだから、ここでNEWを使ってメモリを確保しなくちゃいけない
    for(i=0;i<len;i++){
        str[i]=buf[i];
    }
    str[len]=0;
    
    return str;
}

int main(void){
    String S=string_input(); //入力文字列

    int N=string_len(S);

    int count; //Yesなら1,Noなら0にする
    for(int i=0;i<N;i++){
        if(i%2==0){
            if(S[i]=='L'){
                count=0;
                break;
            }
            else{
                count=1;
            }
        }
        else{
            if(S[i]=='R'){
                count=0;
                break;
            }
            else{
                count=1;
            }
        }
    }

    if(count==1){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}

//文字列をS[0]から始めるときは、問題文と偶奇がずれるので気をつける