#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359
#define INF 1E9
#define Tloop int T; cin >> T; for(int i = 1; i < T+1; i++)
#define Nloop int N; cin >> N; for(int j = 0; j < N; j++)
#define printcase cout << "Case #" << i << ": "

// Disclaimer: all this typedef only used for competitive programming
//             will not use it in a proper other codes
typedef long long ll;
typedef unsigned long long ull;

struct myword {
  bool leftactive = false;
  bool rightactive = false;
};

struct myword2 {
  string name;
  bool leftactive = false;
  bool rightactive = false;
};

// pq bakal kebalik
class mycomp
{
  public:
  bool operator() (myword a, myword b) {
    return a.leftactive < b.leftactive; 
  }
};

bool customcompare(int a, int b) {
  return a > b;
}

unordered_map<string, myword> finalmap;
unordered_map<string, unordered_set<string>> rightword; // leftactive
unordered_map<string, unordered_set<string>> leftword; // rightactive

void dfsleft(string x);

void dfsright(string x) {
  if(finalmap[x].rightactive == false) {
    finalmap[x].rightactive = true;
    for (auto z : rightword[x]) {
      // cout << z << endl;
      dfsleft(z);
    }
  }
  // cout << x << endl;
  // for(auto z : rightword[x]) {
  //   if (finalmap[z].leftactive == false) {
  //     finalmap[z].leftactive = true;
  //     // cout << z << endl;
  //     // cout << "kanan" << z << endl;
  //     dfsleft(z);

  //   }
  // }
}

void dfsleft(string x) {
  // cout << x << endl;
  if(finalmap[x].leftactive == false) {
    // cout << x << endl;
    finalmap[x].leftactive = true;
    for (auto z : leftword[x]) {
      // cout << z << endl;
      dfsright(z);
    }
  }
  // for(auto z : leftword[x]) {
  //   if (finalmap[z].rightactive == false) {
  //     finalmap[z].rightactive = true;
  //     // cout << "kiri" << z<< endl;
  //     dfsright(z);
  //   }
  // } 
}



int main ()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_set<string> initactive;

  
  // map<string, set<string>> test;
  // test["test"].insert("test");
  vector<string> dummy;

  string x, y, z;

  getline(cin, x);

  vector<bool> adatitik;

  istringstream iss(x);
  while(iss >> z) {
    if (z[z.length()-1] == '.') {
      z = z.substr(0, z.length()-1);
      adatitik.push_back(true);
    } else if (z[z.length()-1] == ',') {
      z = z.substr(0, z.length()-1);
      adatitik.push_back(false);
    } else {
      adatitik.push_back(false);
    }
    dummy.push_back(z);
  }

  // adatitik+= adatitik;

  for (int i = 0; i < dummy.size()-1; i++) {
    // myword newword;
    // newword.name = dummy[i+1];
    if(adatitik[i]) {
      continue;
    }
    rightword[dummy[i]].insert(dummy[i+1]);
    // cout << dummy[i+1] << endl;
  }

  for (int i = 1; i < dummy.size(); i++) {
    // myword newword;
    // newword.name = dummy[i-1];
    // newword.active = false;
    if(adatitik[i-1]) {
      continue;
    }
    leftword[dummy[i]].insert(dummy[i-1]);
  }

  istringstream icc(x);

  // bool bfr = false;

  

  while(icc >> z) { 
    if (z[z.length()-1] == ',') {
      string dum = z.substr(0, z.length()-1);
      dfsright(dum);
      // for (auto lll : rightword[z])
      //   cout << lll << endl;
      // cout << z << endl;
    //   for (auto lll : rightword["spot"])
    // cout << lll << endl;
    }
  }

  istringstream ifin(x);

  bool b4 = true;

  while(ifin >> z) {
    string dum;
    if (z[z.length()-1] == ',' || z[z.length()-1] == '.' )
      dum = z.substr(0, z.length()-1);
    else
      dum = z;
    // if (!(finalmap[dum].leftactive))
    // cout << endl << dum << "test" << endl;
    if (b4) {
      if (z[z.length()-1] == '.') {
        b4 = true;
        cout << z << " ";
      } else {
        if(finalmap[dum].rightactive) {
          cout << dum <<", ";
          b4 = true;
        } else {
          cout << dum;
          b4 = false;
        }
      }
    } else {
      if(finalmap[dum].leftactive)
        cout << ", ";
      else
        cout << " ";
      if (z[z.length()-1] == '.') {
        b4 = true;
        cout << z << " ";
      } else {
        if(finalmap[dum].rightactive) {
          cout << dum <<", ";
          b4 = true;
        } else {
          cout << dum;
          b4 = false;
        }
      }
    }
  }

  return 0;
}