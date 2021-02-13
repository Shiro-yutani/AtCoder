#include<iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main(){

    long double x,y,r;
    int x_min, y_min, x_max, y_max, i, j;
    ll res=0;
    bool c_up, c_down;

    cin >> x >> y >> r;

    cout << __LINE__ << ": x = " << x << ", y = " << y <<  ", r = " << r << endl;

    x_min = (int)(x - r);
    y_min = (int)(y - r);
    x_max = (int)(x + r);
    y_max = (int)(y + r);

    cout << __LINE__ << ": x_min=" << x_min << ", y_min=" << y_min <<  ", x_max=" << x_max <<  ", y_max=" << y_max << endl;

    /*for(i=x_min; i<=x_max; i+=10000){
        c_up=true;
        c_down=true;
        for(j=y_min; j<=y_max; j+=10000){
                while(c_up){
                    if((i-x_ll)*(i-x_ll) + (j-y_ll)*(j-y_ll) <= r_ll * r_ll) count++;
            }
    //    cout << __LINE__ << " current i= " << i << ", " << " current j= " << j <<", "  << " current count= " << count <<". " << endl;
    }
    cout << count;*/

    return 0;
}