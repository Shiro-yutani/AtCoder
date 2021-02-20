#include<iostream>
#include<cmath>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int ctoi(const char);

int main(){
    string X;
    ll M;
    ll conv = 0;
    short max=0, tmp, count=0;
    bool cnt_flg = true;

    cin >> X >> M;

    for(int i=0; i<X.length(); i++){
        tmp = ctoi(X[i]);
        if(tmp > max) max = tmp;
    }

    //cout << max;

    while(cnt_flg && max < 11){
        tmp = max;
        for(int i=0; i<X.length(); i++){
            cout << __LINE__ << ":" << conv << endl;
            conv += X[X.length()-i-1] * tmp;
            cout << __LINE__ << " : " << X[X.length()-i-1] << " : " << tmp << " : " << conv << endl;
            if(conv > M){
                cnt_flg = false;
                break;
            }
            tmp *= max;
        }
        if(cnt_flg == true) count++;
        max++;
    }

    cout << count;

    return 0;
}

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