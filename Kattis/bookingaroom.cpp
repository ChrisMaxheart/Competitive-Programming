#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
  return a > b;
}

class Hotel
{
private:
  vector<bool> room;
public:
  Hotel()
  {

  }
  Hotel(int r)
  {
    room.assign(r, false);
  }
  void book(int x)
  {
    room[x-1] = true;
  }
  bool isfullybooked(int r)
  {
    bool booked = true;
    for (int i = 0; i <r; i++)
      if (!room[i])
      {
        return false;
      }
    return true;
  }

  int anyempty(int r)
  {
    if (isfullybooked(r))
      return -1;
    else
    {
      for (int i = 0; i<r; i++)
        if (!room[i])
          return (i+1);
    }
  }
};

int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);



  int r, n, x;
  cin >> r >> n;
  Hotel csh(r);
  for(int j = 0; j < n; j++)
  {
    cin >> x;
    csh.book(x);
  }
  x = csh.anyempty(r);
  if (x == -1)
    cout << "too late" << endl;
  else
    cout << x << endl;

  return 0;
}