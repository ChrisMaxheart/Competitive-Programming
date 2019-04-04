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

    string final, code;
    int pointer;

    getline(cin, code);

    pointer = 0;

    final = "";

    while(pointer < code.length())
    {
        final += code[pointer];
        if ((code[pointer] == 97) || (code[pointer] == 101) || (code[pointer] == 105) || (code[pointer] == 111) || (code[pointer] == 117))
            pointer += 3;
        else
            pointer++;
    }

    cout << final << endl;

    return 0;
}