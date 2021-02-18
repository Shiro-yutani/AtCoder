#include<iostream>
#include<vector>

using namespace std;

int main(){
    int h,w,count, peak=0;
    string s[10];

    cin >> h >> w;
    for(int i=0; i<h; i++){
        cin >> s[i];
    }

    for(int i=1; i<h; i++){
        for(int j=1; j<w; j++){
            count=0;
            if(s[i-1][j-1] == '#'){ count++;}
            if(s[i-1][j] == '#'){ count++;}
            if(s[i][j-1] == '#'){ count++;}
            if(s[i][j] == '#'){ count++;}
            if(count%2) peak++;
//            cout <<__LINE__<< s[i-1][j-1] << s[i-1][j] << s[i][j-1] << s[i][j] << ", count=" << count << ", peak=" << peak << endl;
        }
    }
    cout << peak;

    return 0;
}