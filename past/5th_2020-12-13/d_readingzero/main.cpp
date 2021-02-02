/*  問題文
    N 個の文字列 Si が与えられます。Si は数字のみからなる文字列です。
    これらの文字列を 10 進法の数とみなして、値の小さい順にソートして出力してください。
    ただし、値が等しい数は、先頭につく 0 の個数が多い方を前にしてください。

    制約
    1≤N≤105
    Si の長さの和は 105 以下
    Si は数字のみからなる

    入力
    入力は以下の形式で標準入力から与えられる。
    N
    S1
    ⋮
    SN

    出力
    与えられた文字列を指定された順序にソートし、改行区切りで出力せよ。
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

//関数プロトタイプ宣言


//クラス定義
class StringNumber{
    private:
        int m_value; //整数に変換したときの値
        int m_NumOfZero; //先頭につくゼロの個数
        string m_str;
    public:
        StringNumber(string str) : m_str(str){}
        int getValue();        
        int getNumOfZero();

};

int main(void){
    int N; //文字列の個数
    vector<StringNumber> strList; //文字列のリスト
    string strTmp;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> strTmp;
        strList.push_back(StringNumber(strTmp));
    }

    return 0;
}

int StringNumber::getValue(){
    return atoi(m_str.c_str());
}