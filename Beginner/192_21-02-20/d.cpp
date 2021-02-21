#include<iostream>
#include<cmath>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int ctoi(const char);
inline long long pow_ll(long long x, long long n);
long long conv_array(string IN, long long array);

int main(){
    string X;
    ll M;
    ll conv = 0;
    short max=0, tmp, count=0;
    bool cnt_flg = true;

    cin >> X >> M;

    cout << conv_array(X, M);
/*
    for(int i=0; i<X.length(); i++){
        tmp = ctoi(X[i]);
        if(tmp > max) max = tmp;
    }
*/
    //cout << max;

    

    return 0;
}

/*  関数名          ctoi(const char c)
    説明            char で 0〜9 を受け取り、intに直して返す。それ以外の文字が来た場合は-1を返す。
    使用ライブラリ  なし
*/
int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

/*  関数名          conv_array(string IN, unsigned long long array)
    説明            stringで数字の文字列を受け取り、array進数と見なしたときの値を10進数(long long)で返す
    使用ライブラリ  string
    使用関数        pow_ll, ctoi
*/
long long conv_array(string IN, long long array){
    short max=0;
    cout << __func__ << ", " << __LINE__ << ": IN= " << IN << ", array=" << array << endl; // debug用

    /* エラーチェック */
    for(int i=0; i<IN.length(); i++){
        cout << __func__ << ", " << __LINE__ << ": IN[" << i << "]= " << IN[i] << endl; // debug用

        /*  入力文字列に0〜9以外の文字が含まれていた場合はエラーとして -1 を return する */
        if(isdigit(IN[i])==false) return -1;
        
        /*  入力文字列に指定の進数では使えない文字が含まれていた場合、エラーとして -1 を return する
            例えば IN = "124", array = 3 のとき、4 は 3 進数で扱えないためエラーとなる
         */
        max = ctoi(IN[i]);
        if(max>=array) return -1; 
    }
    /* エラーチェックここまで */

    long long ret=0;
    for(int i=0; i<IN.length(); i++){
        ret += (long long) ctoi(IN[IN.length()-1-i]) * pow_ll(array , i);
    }
    cout << __func__ << ", " << __LINE__ << ": return=" << ret << endl;
    return ret;
}

/*  関数名          pow_ll(long long x, unsigned long long n)
    説明            x^n を計算する。long long 対応
    使用ライブラリ  string
*/
inline long long pow_ll(long long x, long long n){
    long long ret = x;
    cout << __func__ << ", " << __LINE__ << ": x= " << x << ", n=" << n << endl; // debug用
    if(n==0) return 1;
    for(long long i=1; i<n; i++){
        ret *= x;
    }
    cout << __func__ << ", " << __LINE__ << ": return=" << ret << endl; // debug用
    return ret;
}