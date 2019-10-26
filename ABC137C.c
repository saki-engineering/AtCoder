#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//char型のポインタ(=配列と意味は同じ)をString型と定義([0]から数える)
typedef char* String;

//与えられた文字列を比較し、結果によって決められたint型変数を返す関数
//p<qなら-1,p>qなら+1,p==qなら0
int string_compare(const void* a,const void* b){
    String p = *(String*) a;
    String q = *(String*) b;
    int i=0;
    while(i<10){
        if(p[i]<q[i]) return -1;
        else if(p[i]>q[i]) return 1;
        else{i++;}
    }
    return 0;
}

//文字列中の文字を辞書順にソートする
void string_lexical_order(String s){
    //挿入法でのソートを行う
    int i,j;
    for(i=0;i<10;i++){
        char c=s[i]; //これからこの文字(s[i])の挿入場所を探す
        for(j=i-1;j>=0&&s[j]>c;j--){ //探す範囲はs[i-1]~s[0]
            s[j+1]=s[j]; //ここじゃないなと思ったら、後ろにずらしていく
        }
        if(j!=i-1){
            s[j+1]=c; //挿入場所に入れる
        }
    }
    return;
}

int main(void){
    int N;
    scanf("%d",&N);

    //S[0]~S[N-1]に文字列(ソートずみ)を格納する
    String* S;
    NEW(S,N);
    for(int i=0;i<N;i++){
        NEW(S[i],11);
        scanf("%s",S[i]);
        string_lexical_order(S[i]);
    }

    qsort(S,N,sizeof(S[0]),string_compare);

    long ans=0;
    long count=1;
    for(int i=1;i<N;i++){
        //ポインタSに+iする=S[i]
        //ポインタにして渡さなきゃいけないことに注意
        if(string_compare(S+(i-1),S+i)==0){
            count++;
        }
        else{
            ans+=count*(count-1)/2;
            count=1;
        }
    }
    ans+=count*(count-1)/2;

    printf("%ld\n",ans);

    return 0;
}


//ansがlongだったら、ansに絡んだ演算は全てlongでやったほうがいい
//countをintにしたらWAが出た