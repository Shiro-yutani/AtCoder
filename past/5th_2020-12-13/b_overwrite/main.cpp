/* 問題文

    英小文字からなる長さ N の文字列 S が与えられます。
    また、文字列 T があり、 T ははじめ空文字列です。

    あなたは以下の操作を i=1,2,…,N に対して、 i=1 から順に行います。
    S の左から i 番目の文字を c とする。
    T から c と同じ文字を全て削除した後、 T の末尾に c を追加する。

    操作が終わった後の T を求めてください。

*/

/* 制約
    1≤N≤100
    S は英小文字からなる長さ N の文字列
*/

/* 入力
    入力は以下の形式で標準入力から与えられる。

    N
    S
*/

#include<iostream>
#include<string>
#include <algorithm>
//#include<regex>

#define _Debug

using namespace std;

//関数プロトタイプ宣言
string delete_specific_char(string, char);
char extract_char_from_string(string, int);

//メイン関数
int main(){
    string str, t_str;
    int n, i;
    char ext;
    bool str_length_input_success = false;

    //文字列の長さを取得
    cin >> n;

    //文字列を取得
    while(!str_length_input_success){ //文字列の長さがnでなければ再取得する
        cin >> str;
        if(str.size()==n) str_length_input_success = true; //文字列の長さがnであればフラグ解除
    }

    for(i=0; i<n; i++){
        ext = extract_char_from_string(str, i);
        t_str = delete_specific_char(t_str, ext);
        t_str.push_back(ext);
    }    

    cout << t_str;

    return 0;
}

/*  関数名          delete_specific_cah()
    説明            string s から 文字 c を削除し返す
    使用ライブラリ  algorithm
*/
string delete_specific_char(string s, char c){
    s.erase(remove(s.begin(), s.end(), c), s.end());
    return s;
}

/*  関数名          extract_char_from_string()
    説明            string s の左から i 番目の文字を取り出す
    使用ライブラリ  なし
*/
char extract_char_from_string(string s, int i){
    char c = s[i];
    return c;
}