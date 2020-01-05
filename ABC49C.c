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
    char buf[100001];
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
    String S;
    S=string_input();

    //D[0]~D[3]に与えられた文字列を入れる
    String* D;
    NEW(D,4);
    NEW(D[0],6);
    D[0]="dream";
    NEW(D[1],8);
    D[1]="dreamer";
    NEW(D[2],6);
    D[2]="erase";
    NEW(D[3],7);
    D[3]="eraser";

    //DPMapを作る
    int N=strlen(S);
    int Map[N+1];
    for(int i=1;i<=N;i++) Map[i]=0;
    Map[0]=1;

    //Mapを埋める
    for(int i=1;i<=N;i++){
        for(int j=0;j<4;j++){
            if(i<strlen(D[j])) continue;

            int flg=1;
            for(int k=0;k<strlen(D[j]);k++){
                if(S[i-strlen(D[j])+k]!=D[j][k]){
                    flg=0;
                    break;
                }
            }

            if(flg) Map[i]=Map[i-strlen(D[j])];
        }
    }

    if(Map[N]) printf("YES\n");
    else printf("NO\n");

    return 0;
}