#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,count;
    long x;
    long tmp;
    vector<long> a;
    vector<long>::iterator itr;

    cin >> n >> x;

    for(int i=0; i<n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }

    count = n;

    for(itr=a.begin(); itr!=a.end(); itr++){
        if(*itr!=x){
            cout << *itr << " "; 
        }
    }
    return 0;
}
