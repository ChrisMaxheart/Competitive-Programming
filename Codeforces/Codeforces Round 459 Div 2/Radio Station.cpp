#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

struct setrak
{
  string server;
  string ip;
};

setrak data[1010];

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;

  string nama, ipcari;

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> data[i].server >> data[i].ip;
    data[i].ip += ";";
    // cout << data[i].server << "and"  << data[i].ip << endl; 
  }
  

  for (int i = 0; i < M; i++)
  {
    cin >> nama >> ipcari;
    for (int j = 0; j < N; j++)
    {
      // cout << ipcari << "Saat" << data[j].ip << endl;
      // cout << data[j].ip << endl;
      if (data[j].ip == ipcari)
      {
        // cout << "yey nemu" << endl;
        cout << nama << " " << ipcari << " #" << data[j].server << endl;
        break;
      }
      // cout << ipcari << endl;
    }
      
  }

  return 0;
}