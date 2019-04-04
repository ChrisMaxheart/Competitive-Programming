#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string bahasabaru[27] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};

    string soal;
    char dummy;
    std::locale loc;
    getline(cin, soal);
    for (int i = 0; i < soal.length(); i++)
    {
        dummy = soal[i];
        dummy = tolower(dummy, loc);
        if ((int(dummy)>= 97) && (int(dummy) <=122))
            cout << bahasabaru[int(dummy)%97];
        else
            cout << dummy;
    }
    cout << endl;

    return 0;
}