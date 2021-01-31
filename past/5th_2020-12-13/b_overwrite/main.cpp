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
#include<list>

#define _Debug
#define NUM_OF_INPUT 1

using namespace std;

string getStr();
string erase_and_log(list<string>::iterator, int);

int main(){
    list<string> strList;
    list<string>::iterator itr; //イテレータ
    int i, length;


    for(i=0; i<NUM_OF_INPUT; i++){
        strList.push_back(getStr());
    }

#ifdef _Debug
    cout << "strList = {";
    for(itr = strList.begin(); itr != strList.end(); itr++){
        cout << *itr << ", ";
    }
    cout << "}" << endl;
#endif

    length = (*(strList.begin())).size();

#ifdef _Debug
    cout << "N=" << length <<endl;
#endif

    strList.push_back( erase_and_log(strList.begin(), length) );

    return 0;
}

string getStr(){
    string str;
    cin >> str;
    return str;
}

string erase_and_log(list<string>::iterator itr, int l){
    string *ret;
    int ret_l;
    
    for(int i=0; i<l; i++){
        ret_l = (*ret).size();
        for(int j=0; j<ret_l;){
            if(*itr == *(ret+j)){
                (*ret).erase((*ret).begin() + j);
                ret_l--;
                (*ret).push_back(*itr);
            } else {
                j++;
            }
        }
    }

    return *ret;
}