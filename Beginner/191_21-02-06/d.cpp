#include<iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main(){

    long double x,y,r;
    ll x_min, y_min, x_max, y_max, x_ll, y_ll, r_ll, i, j;
    ll res=0;
    bool c_up, c_down;

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

    for(i=x_min; i<=x_max; i+=10000){
        c_up=true;
        c_down=true;
        for(j=y_min; j<=y_max; j+=10000){
                while(c_up){
                    if((i-x_ll)*(i-x_ll) + (j-y_ll)*(j-y_ll) <= r_ll * r_ll) count++;
            }
    //    cout << __LINE__ << " current i= " << i << ", " << " current j= " << j <<", "  << " current count= " << count <<". " << endl;
    }
    cout << count;

    return 0;
}