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
#include<algorithm>

#define _debug

using namespace std;

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
        string getString();

};

//関数プロトタイプ宣言
vector<StringNumber> StringNumberSort(vector<StringNumber>);

int main(void){
    int N; //文字列の個数
    vector<StringNumber> strList; //文字列のリスト
    string strTmp;
    vector<StringNumber>::iterator itr;

    cin >> N;
#ifdef _debug
    cout << "[" << __func__ << ":" << __LINE__ << "] " << "Input N finished. N=" << N << endl;
#endif //_debug

    for(int i=0; i<N; i++){
        cin >> strTmp;
        strList.push_back(StringNumber(strTmp));
    }
#ifdef _debug
    for(itr=strList.begin(); itr!=strList.end(); itr++){
        cout << "[" << __func__ << ":" << __LINE__ << "] itr->getZumOfZero() = " << itr->getNumOfZero() << ", itr->getValue() = " << itr->getValue() << endl;
    }
    cout << endl;
#endif //_debug

    strList = StringNumberSort(strList);

    for(itr=strList.begin(); itr!=strList.end(); itr++){
        cout << itr->getString() << endl;
    }

    return 0;
}

int StringNumber::getValue(){
    return atoi(m_str.c_str());
}

int StringNumber::getNumOfZero(){
    int i;
    for(i=0; m_str[i] == '0'; i++){
    }
    return i;
}

string StringNumber::getString(){
    return m_str;
}

vector<StringNumber> StringNumberSort(vector<StringNumber> StrNum){
    vector<StringNumber>::iterator itr, itr_for_comp, itr_tmp;
    bool sort_finished_flg = false;

    while(!sort_finished_flg){
        sort_finished_flg = true; //フラグ解除

        itr=StrNum.begin();
        itr_for_comp =itr;

        while(itr_for_comp!=StrNum.end()-1){
#ifdef _debug
            cout << "[" << __func__ << ":" << __LINE__ << "] cycle start." << endl;
#endif
            itr_for_comp++;
#ifdef _debug
            cout << "[" << __func__ << ":" << __LINE__ << "] itr->getValue:" << itr->getValue() << ", itr_for_comp->getValue:" << itr_for_comp->getValue() << endl;
#endif
            if((itr->getValue() > itr_for_comp->getValue()) || // itr+1 のほうが値が小さい場合
                (itr->getValue() == itr_for_comp->getValue() && itr->getNumOfZero() < itr_for_comp->getNumOfZero()) ){ // itrとitr+1 は同じ値、かつitr+1のほうがゼロが多い場合
#ifdef _debug
                cout << "Swapping start." <<endl;
#endif
                iter_swap(itr, itr_for_comp);
                sort_finished_flg = false; //入れ替え実施したのでフラグをもとに戻す
#ifdef _debug
                cout << "Swapping finished." <<endl;
#endif
            }
#ifdef _debug
            cout << "[" << __func__ << ":" << __LINE__ << "] itr->getValue:" << itr->getValue() << endl;
#endif
            itr++;
#ifdef _debug
            cout << "[" << __func__ << ":" << __LINE__ << "] 1 cycle finished." << endl;
#endif
        }
    }
#ifdef _debug
    cout << "Sorting finished";
#endif

    return StrNum;
}