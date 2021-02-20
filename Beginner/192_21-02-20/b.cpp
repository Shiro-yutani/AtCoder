#include<iostream>
#include<cmath>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int main(){
    string S;
    string cap  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ncap = "abcdefghijklmnopqrstuvwxyz";
    bool judge = true;

    cin >> S;
    //cout << S.length();

    for(int i=0; i<S.length(); i++){
        if(i%2==1){
            for(int j=0;j<cap.length();j++){
                if( S[i] == cap[j] ) judge = false;
                //cout <<__LINE__ << ", i=" << S[i] << ", j=" << cap[j] << ", " << judge << endl;
            }
        } else {
            for(int j=0;j<ncap.length();j++){
                if( S[i] == ncap[j] ) judge = false;
                //cout <<__LINE__ << ", i=" << S[i] << ", j=" << ncap[j] << ", " << judge << endl;
            }
        }
        judge = !judge;
        if(judge == false) break;
    }

    if(judge==false){
        cout << "No";
    } else {
        cout << "Yes";
    }

    return 0;
}