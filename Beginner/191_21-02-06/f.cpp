#include<iostream>

using namespace std;

int main(){
    short v,t,d, s;

    cin >> v >> t >> s >> d;

    (d >= v*t && d <= v*s) ? cout << "yes" : cout << "no"; 
    return 0;
}