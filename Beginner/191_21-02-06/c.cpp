#include<iostream>
#include<vector>

using namespace std;

int main(){
    int h,w,count, peak=0;
    string s[6];

    cin >> h >> w;
    for(int i=0; i<h; i++){
        cin >> s[i];
    }

    for(int i=1; i<h-1; i++){
        for(int j=1; j<w-1; j++){
            if(s[i][j]=='#'){
                count=0;
                if(s[i][j-1] == '.'){ count++;}
                if(s[i][j+1] == '.'){ count++;}
                if(s[i-1][j] == '.'){ count++;}
                if(s[i+1][j] == '.'){ count++;}
            }
            if(count>2) peak++;
        }
    }
    cout << peak;

    return 0;
}