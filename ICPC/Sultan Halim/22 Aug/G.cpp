#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

int get_max_star(int renk) {
    if (renk > 20) {
        return 2;
    } else
    if (renk > 15) {
        return 3;
    } else
    if (renk > 10) {
        return 4;
    } else
    if (renk > 0) {
        return 5;
    } else {
        return 0;
    }
}

int renk = 25;
int star = 0;
int cons = 0;

int main() {
    string sentence;
    cin >> sentence;
    int len = sentence.length();
    for (int i = 0; i < len; i++) {
        //cout << "START: " << renk << " " << star << " " << cons << "\n";
        if (renk == 0) {
            continue;
        }
        if (sentence[i] == 'W') {
            cons++;
            star++;
            if (cons >= 3 && renk > 5) {
                star++;
            }
            if (star > get_max_star(renk)) {
                star -= get_max_star(renk);
                renk--;
            }
            if (renk == 0) {
                star = 0;
            }
        } else
        if (sentence[i] == 'L') {
            cons = 0;
            if (renk > 20) {
                continue;
            }
            if (renk == 20 && star == 0) {
                continue;
            }
            star--;
            if (star < 0) {
                renk++;
                star += get_max_star(renk);
            }
        }
        //cout << "END: " << renk << " " << star << "\n";
    }

    if (renk == 0) {
        cout << "Legend" << "\n";
    } else {
        cout << renk << "\n";
    }

    return 0;
}
