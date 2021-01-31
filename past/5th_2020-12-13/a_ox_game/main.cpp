/* -------------------

以下のルールで○✕ゲームが行われています。

まず、縦 1マス、横 5マスのマス目を作る。
全てのマスに o または x を書き込む。
o が横に連続して 3つ以上並んでいるなら、 o の勝ちである。
そうでなくて、 x が横に連続して 3つ以上並んでいるなら、 x の勝ちである。
このどちらでもない場合、引き分けである。

書き込みが終わった後のマス目の状態が与えられます。左から i
番目のマスに書かれた記号は Si です。
○✕ゲームの結果を判定してください。

--------------------*/

#include<iostream>
#include<string>

using namespace std;

enum ret_judge{WIN, LOSE, DRAW, ERROR};

int judge(string);

int main(){
    char str[5];
    cin >> str;

    switch(judge(str)){
        case WIN:
            cout << "o" << endl;
            break;
        
        case LOSE:
            cout << "x" << endl;
            break;
        
        case DRAW:
            cout << "draw" << endl;
            break;        
        default:
            cout << "Error!" << endl;
            break;
    }    

    return 0;
}

int judge(string str){
    int count = 0;

    for(int i=0; i<(int)str.size(); i++){
        if(count != 0 && str[i] != str[i-1]) count = 0;

        if(str[i] == 'o'){
            count++;
        } else if(str[i] == 'x') {
            count--;
        } else {
            return ERROR;
        }

        if(count>2){
            return WIN;
        } else if(count<-2){
            return LOSE;
        }
    }
    return DRAW;
}