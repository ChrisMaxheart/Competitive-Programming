#include<bits/stdc++.h>
using namespace std;


int main() {

    string x;

    cin >> x;

    int divi = x.length()/2;

    long long rot1 = 0;

    for (int i = 0; i < divi; i++) {
        rot1 += (x[i]-'A');
    }

    long long rot2 = 0;

    for (int i = divi; i < x.length(); i++) {
        rot2 += (x[i]-'A');
    }

    for (int i = 0; i < divi; i++) {
        x[i] = ((x[i]-'A' +rot1)%26)+'A';
    }

    for (int i = divi; i < x.length(); i++) {
        x[i] = ((x[i]-'A' +rot2)%26)+'A';
    }

    string newstring;

    for (int i = 0; i < divi; i++) {
        char dum = (x[i]-'A') + (x[divi+i] - 'A');
        dum = dum%26;
        dum = dum + 'A';
        newstring += dum;
    }

    cout << newstring << endl;

}