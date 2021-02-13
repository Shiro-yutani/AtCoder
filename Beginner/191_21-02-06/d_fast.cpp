#include<iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll sqrt_ll(ll a);

int main(){

    //long double x,y,r;
    double x, y, r;
    ll x_min, y_min, x_max, y_max, x_ll, y_ll, r_ll, cx, y_tp, y_bt;
    ll res=0;
    bool y_tp_judge=false, y_bt_judge=false;

    cin >> x >> y >> r;

    x_ll = (ll)(x * 10000);
    y_ll = (ll)(y * 10000);
    r_ll = (ll)(r * 10000);

    //cout << __LINE__ << ": x_ll=" << x_ll << ", y_ll=" << y_ll <<  ", r_ll=" << r_ll << endl;

    x_min = x_ll - r_ll;
    y_min = y_ll - r_ll;
    x_max = x_ll + r_ll;
    y_max = y_ll + r_ll;

    //cout << __LINE__ << ": x_min=" << x_min << ", y_min=" << y_min <<  ", x_max=" << x_max <<  ", y_max=" << y_max << endl;

    x_min = (x_ll - r_ll)/10000 *10000;
    y_min = (y_ll - r_ll)/10000 *10000;
    x_max = (x_ll + r_ll)/10000 *10000;
    y_max = (y_ll + r_ll)/10000 *10000;

    //cout << __LINE__ << ": x_min=" << x_min << ", y_min=" << y_min <<  ", x_max=" << x_max <<  ", y_max=" << y_max << endl;
    ///*
    for(cx = x_min; cx <= x_max; cx += 10000){
        y_tp = r_ll*r_ll - (cx-x_ll)*(cx-x_ll);
        cout << __LINE__ << ": y_tp2=" << y_tp << ", x=" << cx << endl;
        y_tp = sqrt_ll(y_tp);
        //cout << __LINE__ << ": y_tp2=" << y_tp << endl;
        y_bt = (y_ll - y_tp) - (y_ll - y_tp)%10000;
        y_tp = (y_ll + y_tp) - (y_ll + y_tp)%10000;

        y_tp_judge=false;
        y_bt_judge=false;

        if((cx-x_ll)*(cx-x_ll)+(y_tp-y_ll)*(y_tp-y_ll)<=r_ll*r_ll){
            while((cx-x_ll)*(cx-x_ll)+(y_tp-y_ll)*(y_tp-y_ll)<=r_ll*r_ll){
                y_tp+=10000;
            }
            y_tp-=10000;
            y_tp_judge = true;
        } else {
            while((cx-x_ll)*(cx-x_ll)+(y_tp-y_ll)*(y_tp-y_ll)>r_ll*r_ll){
                if(y_tp<y_ll){
                    y_tp_judge = false;
                    break;
                } else {
                    y_tp_judge = true;
                    y_tp-=10000;
                }
            }
        }

        if((cx-x_ll)*(cx-x_ll)+(y_bt-y_ll)*(y_bt-y_ll)<=r_ll*r_ll){
            while((cx-x_ll)*(cx-x_ll)+(y_bt-y_ll)*(y_bt-y_ll)<=r_ll*r_ll){
                y_bt-=10000;
            }
            y_bt+=10000;
            y_bt_judge = true;
        } else {
            while((cx-x_ll)*(cx-x_ll)+(y_bt-y_ll)*(y_bt-y_ll)>r_ll*r_ll){
                if(y_bt>y_ll){
                    y_bt_judge = false;
                    break;
                } else {
                    y_bt_judge = true;
                    y_bt+=10000;
                }
            }
        }
        //cout << __LINE__ << ": x=" << cx/10000 << ", y_bt= " << y_bt << ", y_tp=" << y_tp <<endl;

        if(y_tp_judge==true && y_bt_judge==true) res += (y_tp - y_bt)/10000 + 1;
    }

    cout << res << endl;
    //*/
    return 0;
}

ll sqrt_ll(ll a){
    if(a<0) a*=(-1);
    ll x=a/2;
    ll last=0;
    ll diff = x-last;

    int i;
    cout << __LINE__ << ": x=" << x << ", last=" << last << ", diff=" << diff << endl;

    while(diff){// && i<100000){
        last = x;
        x = (x+a/x)/2;
        diff = x-last;//>0 ? x-last : last-x;
        //cout << __LINE__ << ": i=" << i<< ", x=" << x << ", last=" << last << endl;
        i++;
    }
    //cout << __LINE__ << ", i=" << i << endl;
    return x;
}