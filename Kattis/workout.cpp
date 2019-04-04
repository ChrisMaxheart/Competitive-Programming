#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {

    vi jut, jrt, put, prt, pst, ptct;
    
    long long time = 0;
    int dum = 10;
    while(dum--) {
        int x, y;
        cin >> x >> y;
        jut.push_back(x);
        jrt.push_back(y);
    }
    dum = 10;
    while(dum--) {
        int x, y, z;
        cin >> x >> y >> z;
        put.push_back(x);
        prt.push_back(y);
        pst.push_back(z);
        ptct.push_back(x+y);
    }
    
    dum = 3;
    while(dum--) {
        for (int i = 0;i < 10; i++) {
            long long timef, times;
            times = (time-pst[i])%ptct[i];
            //cout << "time" << time << endl;
            //cout << "pst" << pst[i] << endl;
            //cout << "ptct" << ptct[i] << endl;
            while(times < 0) {
                times += ptct[i];
            }
            
            if(times< put[i] && time >= pst[i]) {
                time += (put[i] - times);
            }
            
            times = (time-pst[i])%ptct[i];
            
            while(times < 0) {
                times += ptct[i];
            }
            
            time += jut[i];
            
            
            
            timef = (time-pst[i])%ptct[i];
            
            while(timef < 0) {
                timef += ptct[i];
            }
            
            if ((timef < times || jut[i] > ptct[i]) && time >= pst[i] ) {
                pst[i] += timef;
            }
            time += jrt[i];
            //cout << time << endl;
        }
    }
    
    time -= jrt[9];
    cout << time << endl;
    
    return 0;
}