#include<iostream>

using namespace std;

int main(){
    long s, d, i;
    long *p_x = new long[99];
    long *p_y = new long[99];
    int n;
    bool judge = false;

    cin >> n >> s >> d;
    for(i=0; i<n; i++){
        cin >> *(p_x+i) >> *(p_y+i);
    }

    i=0;

    while(judge==false && i<n){
        if(*(p_x+i)<s && *(p_y+i)>d) judge = true;
        i++;
    }

    judge == true ? cout << "Yes" : cout << "No";

    return 0;

}