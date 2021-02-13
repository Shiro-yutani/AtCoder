#include<iostream>
#include<cmath>

using ll = long long;
using namespace std;

int main(){
    double X,Y,R;
    ll x, y, r;
    ll x_min, x_max, y_st;
    ll cx, yt, yb;
    ll res=0;
    bool yt_jdg, yb_jdg;

    ll scale = 10000;
    cin >> X >> Y >> R;
//    cout << __LINE__ << ": X=" << X << ", Y=" << Y << ", R=" << R << endl;

    x = round(X*scale);
    y = round(Y*scale);
    r = round(R*scale);
//    cout << __LINE__ << ": x=" << x << ", y=" << y << ", r=" << r << endl;

    x_min = (x-r) - (x-r)%scale;
    x_max = (x+r) - (x+r)%scale;
    y_st  = y - y%scale;
//    cout << __LINE__ << ": x_min=" << x_min << "(" << x-r << "), x_max=" << x_max << "(" << x+r << "), y_st=" << y_st << "(" << y <<")" << endl;

    yt = y_st;
    yb = y_st;

    for(cx = x_min; cx <= x_max; cx+=scale){
        yt_jdg=false;
        yb_jdg=false;

        if((cx-x)*(cx-x) + (yt-y)*(yt-y) <= r*r){
            yt_jdg=true;
            while((cx-x)*(cx-x) + (yt-y)*(yt-y) <= r*r){
                yt+=scale;
                //cout << __LINE__ << ": yt=" << yt << endl;
            }
            yt-=scale;
        } else {
            while((cx-x)*(cx-x) + (yt-y)*(yt-y) > r*r){
                yt-=scale;
                if(yt<y){
                    yt_jdg = false;
                    break;
                }
                //cout << __LINE__ << ": yt=" << yt << endl;
            }
            if((cx-x)*(cx-x) + (yt-y)*(yt-y) <= r*r){
                yt_jdg = true;
            }
        }

        if((cx-x)*(cx-x) + (yb-y)*(yb-y) <= r*r){
            yb_jdg=true;
            while((cx-x)*(cx-x) + (yb-y)*(yb-y) <= r*r){
                yb-=scale;
                //cout << __LINE__ << ": yb=" << yb << endl;
            }
            yb+=scale;
        } else {
            while((cx-x)*(cx-x) + (yb-y)*(yb-y) > r*r){
                yb+=scale;
                if(yb>y){
                    yb_jdg = false;
                    break;
                }
                //cout << __LINE__ << ": yb=" << yb << endl;
            }
            if((cx-x)*(cx-x) + (yb-y)*(yb-y) <= r*r){
                yb_jdg = true;
            }
        }

        if(yb_jdg==true || yt_jdg==true){
    //        cout << __LINE__ << ": yt=" << yt << ", yb=" << yb << endl;
            res += (yt-yb)/scale+1;
        }

        char f='x';
    //    cout << __LINE__ << ": x=" << cx << ", yt=" << (yt_jdg==true ? yt : f) << ", yb=" << (yb_jdg==true ? yb : f) << ", res=" << res << endl;
    }

    cout << res;

    return 0;

}