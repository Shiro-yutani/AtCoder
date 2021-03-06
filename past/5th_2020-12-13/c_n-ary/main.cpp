/*  問題文
    16 進法では、一般的に 0123456789ABCDEF の 16 個の数字を使って 1 つの桁を表しますが、 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ の 36 個の数字を使う 36 進法を考えます。
    36 進法では、0 の次は 1 、 9 の次は A 、Z の次は 10 になります。 
    整数 N が 10 進表記で与えられるので、 36 進表記に変換してください。

    制約
    ・N は整数
    ・0 <= N <= 36^3

    入力
    入力は以下の形式で標準入力から与えられる。

    出力
    N を 36 進表記で出力せよ。
*/

#include<iostream>
#include<string>
#include<cmath>

//for Debug
//define _Debug

//入力範囲の設定
#define NUM_MAX pow(36.0, 3.0)
#define NUM_MIN 0

//36進数で出力
#define ARY 36

using namespace std;

//関数プロトタイプ宣言
string dec2nary(int value, int ary);
char extract_char_from_string(string s, int i);

int main(){
    unsigned short num;
    bool num_input_success_flg = false;

    // 入力
    while(!num_input_success_flg){
        cin >> num;
        if(num >= NUM_MIN && num <= NUM_MAX) num_input_success_flg = true; //入力チェック
#ifdef _Debug
        num_input_success_flg == true ? cout << "Input success." <<endl : cout << "Input error." << endl;
#endif
    }

    cout << dec2nary(num, ARY);

    return 0;
}

/*  関数名          dec2nary()
    説明            整数 value を受け取り、ary 進数に変換して string 型で返す
    使用ライブラリ  
    備考            最大36進数まで対応
*/
string dec2nary(int value, int ary){
    string symbol("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string ret;
    int num_of_current_place;

    do{
        num_of_current_place = value%ary;
        value /= ary;
        ret = (extract_char_from_string(symbol, num_of_current_place)) + ret;
#ifdef _Debug
        cout << "numofcurrentplace:" << num_of_current_place << ", value:" << value << ", ret:" << ret << endl;
#endif
    } while(value != 0);

    return ret;
}

/*  関数名          extract_char_from_string()
    説明            string s の左から i 番目の文字を取り出す
    使用ライブラリ  なし
*/
char extract_char_from_string(string s, int i){
    char c = s[i];
    return c;
}