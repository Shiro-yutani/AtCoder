#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
using ll = long long;

int g1(string N);
int g2(string N);

int main(){
    string N;
    int K;
    cin >> N >> K;

    //cout << g1(N) << endl;
    //cout << g2(N) << endl;

    for(int i=0; i<K; i++){
        if(N=="0") break;
//        cout << i << "回目:" << N << ", g1(N)=" << g1(N) << ", g2(N)=" << g2(N);
        N = to_string(g1(N)-g2(N));
//        cout << ", res=" << N << endl;
    }

    if(K==0){
        cout << atoi(N.c_str());
    } else {
        cout << N;
    }

    return 0;
}

int g1(string N){
    bool jdg;
    do{
        for(int i=1; i<N.length(); i++){
            jdg = false;
            if(N[i-1]<N[i]){
                char tmp = N[i];// cout << "[" << N[i] << "," << N[i+1] << "]" << endl;
                N[i] = N[i-1];
                N[i-1] = tmp;
                jdg = true;
                i = 0;
            }
//            cout << __LINE__ << ", i=" << i << ", N=" << N << endl;
        }
    } while(jdg);

    return atoi(N.c_str());
}

int g2(string N){
    bool jdg;
    do{
        for(int i=1; i<N.length(); i++){
            jdg = false;
            if(N[i-1]>N[i]){
                char tmp = N[i]; //cout << "[" << N[i] << "," << N[i+1] << "]" << endl;
                N[i] = N[i-1];
                N[i-1] = tmp;
                jdg = true;
                i = 0;
            }
//            cout << __LINE__ << ", i= " << i << ", N=" << N << endl;
        }
    } while(jdg);

    return atoi(N.c_str());
}