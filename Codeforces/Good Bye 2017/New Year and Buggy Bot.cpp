#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

bool checkdeath(int posisi, int jebakan[], int baris, int kolom, int pointer)
{
    if (binary_search(jebakan, jebakan+pointer, posisi))
        return true;
    else if (posisi < 0)
        return true;
    else if (posisi%100 >= kolom)
        return true;
    else if (posisi/100 >= baris)
        return true;
    else
        return false;
}

int gerak(int posisi, int move1, int move2, int move3, int move4, char command)
{
    int final;
    final = 0;
    command = int(command) - 48;
    if (command == move1)
        final = posisi + 100;
    else if (command == move2)
        final = posisi - 100;
    else if (command == move3)
        final = posisi + 1;
    else if (command == move4)
        final = posisi - 1;
    return final;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int jebakan[2505];
    string move;
    char x;
    int baris, kolom, posisi, awal, akhir, counter, pointer;
    bool correct;

    pointer = 0;
    cin >> baris >> kolom;
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
        {
            cin >> x;
            if (int (x) == 35)
            {
                jebakan[pointer] = 100*i + j;
                pointer++;
            }
            else if (int(x) == 83)
                awal = 100*i + j;
            else if (int(x) == 69)
                akhir = 100*i +j;
        }
    posisi = awal;
    cin >> move;
    counter = 0;
    for (int i = 0; i < 4; i++)
        for(int j = 0; j < 4 ; j++)
        {
            if (i == j)
                continue;
            else
                for (int k = 0; k < 4; k ++)
                {
                    if ((k == i ) || (k == j))
                        continue;
                    else
                        for (int l = 0; l<4; l++)
                        {
                            if (((l == i) || (l == j)) || (l == k))
                                continue;
                            else
                            {
                                posisi = awal;
                                correct = true;
                                for (int m = 0; m < move.length(); m++)
                                {
                                    posisi = gerak(posisi, i, j, k, l, move[m]);
                                    if (checkdeath(posisi, jebakan, baris, kolom, pointer))
                                    {   
                                        correct = false;
                                        break;
                                    }
                                    else if (posisi == akhir)
                                        break;
                                }
                                if (correct)
                                    if (posisi == akhir)
                                        counter++;
                            }
                        }
                }
        }
        cout << counter << endl;

    return 0;
}