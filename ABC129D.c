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
    char buf[3000];
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
    int H,W;
    scanf("%d %d",&H, &W);

    //幅、高さ(i)ともに0からカウント開始
    //map[i-1][j-1]が、高さi幅jの場所の地図
    String map[H];
    for(int i=0;i<H;i++){
        map[i]=string_input();
    }

    //L[i][j]は、map[i-1][j-1]に置いたときに照らされる左側のマスの数
    int L[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(map[i][j]=='#') L[i][j]=0;
            else{
                if(j==0) L[i][j]=1;
                else L[i][j]=L[i][j-1]+1;
            }
        }
    }
    

    //R[i][j]は、map[i-1][j-1]に置いたときに照らされる右側のマスの数
    int R[H][W];
    for(int i=0;i<H;i++){
        for(int j=W-1;j>=0;j--){
            if(map[i][j]=='#') R[i][j]=0;
            else{
                if(j==W-1) R[i][j]=1;
                else R[i][j]=R[i][j+1]+1;
            }
        }
    }

    //U[i][j]は、map[i-1][j-1]に置いたときに照らされる上側のマスの数
    int U[H][W];
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(map[i][j]=='#') U[i][j]=0;
            else{
                if(i==0) U[i][j]=1;
                else U[i][j]=U[i-1][j]+1;
            }
        }
    }

    //D[i][j]は、map[i-1][j-1]に置いたときに照らされる下側のマスの数
    int D[H][W];
    for(int j=0;j<W;j++){
        for(int i=H-1;i>=0;i--){
            if(map[i][j]=='#') D[i][j]=0;
            else{
                if(i==H-1) D[i][j]=1;
                else D[i][j]=D[i+1][j]+1;
            }
        }
    }

    int ans=0;
    int count;
    for(int j=0;j<W;j++){
        for(int i=H-1;i>=0;i--){
            count=L[i][j]+R[i][j]+U[i][j]+D[i][j]-3;
            if(count>=ans) ans=count;
        }
    }
    printf("%d\n",ans);

    return 0;
}

//「左右」や「上下」を同時に数えようとすると大変だけど、「右だけ」や「上だけ」ならforループを回しながら簡単にできる

//なぜかREになるときは、string_inputのデフォルト長1000を超えた入力があって、オーバーフローしている可能性を考慮する！！