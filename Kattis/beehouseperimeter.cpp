#include <bits/stdc++.h>

using namespace std;

// to minimize
    // defines
        const double PI = acos(-1);
        #define INF 1E9
        #define INFflow 1E8
        #define endl '\n'
        #define Tloop int T; cin >> T; for(int count_ = 1; count_ < T+1; count_++)
        #define Nloop int N; cin >> N; for(int count__ = 0; count__ < N; count__++)
        #define printcaseg cout << "Case #" << count_ << ": "
        #define printcaseu cout << "Case " << count_ << ": "
        #define MOD 1000000007
        #define LSOne(S) ((S)&(-S))
        #define SZ(S) S.size()
        #define ALL(S) S.begin(), S.end()
        #define pb push_back
        #define fi first
        #define se second
        #define eb emplace_back
        #define mp make_pair

    // A lot of typedefs
        typedef long long ll;
        typedef unsigned long long ull;
        typedef stack<int> si;
        typedef stack<long long> sll;
        typedef stack<string> ss;
        typedef stack<double> sd;
        typedef queue<int> qi;
        typedef queue<long long> qll;
        typedef queue<string> qs;
        typedef queue<double> qd;
        typedef deque<int> di;
        typedef deque<long long> dll;
        typedef deque<string> ds;
        typedef deque<double> dd;
        typedef priority_queue<int> pqi;
        typedef priority_queue<long long> pqll;
        typedef priority_queue<string> pqs;
        typedef priority_queue<double> pqd;
        typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pqdijk;
        typedef set<int> seti;
        typedef set<long long> setll;
        typedef set<string> sets;
        typedef set<double> setd;
        typedef unordered_set<int> useti;
        typedef unordered_set<long long> usetll;
        typedef unordered_set<string> usets;
        typedef unordered_set<double> usetd;
        typedef map<int, string> mapis;
        typedef map<string, int> mapsi;
        typedef map<long long, string> maplls;
        typedef map<string, long long> mapsll;
        typedef map<int, int> mapii;
        typedef map<string, string> mapss;
        typedef map<long long, long long> mapllll;
        typedef map<long long, double> maplld;
        typedef map<double, long long> mapdll;
        typedef map<string, double> mapsd;
        typedef map<double, string> mapds;
        typedef map<int, double> mapid;
        typedef map<double, int> mapdi;
        typedef unordered_map<int, string> umapis;
        typedef unordered_map<string, int> umapsi;
        typedef unordered_map<long long, string> umaplls;
        typedef unordered_map<string, long long> umapsll;
        typedef unordered_map<int, int> umapii;
        typedef unordered_map<string, string> umapss;
        typedef unordered_map<long long, long long> umapllll;
        typedef unordered_map<long long, double> umaplld;
        typedef unordered_map<double, long long> umapdll;
        typedef unordered_map<string, double> umapsd;
        typedef unordered_map<double, string> umapds;
        typedef unordered_map<int, double> umapid;
        typedef unordered_map<double, int> umapdi;
        typedef vector<int> vi;
        typedef vector<long long> vll;
        typedef vector<string> vs;
        typedef vector<double> vd;
        typedef vector<vector<pair<int,int>>> vwAL;
        typedef vector<vector<int>> vAL;
        typedef pair<int, int> pii;
        typedef pair<int, string> pis;
        typedef pair<string, int> psi;
        typedef pair<long long, long long> pllll;
        typedef pair<long long, string> plls;
        typedef pair<double, string> pds;
        typedef pair<double, double> pdd;
        typedef pair<double, int> pdi;
        typedef pair<double, long long> pdll;

    // struct
        struct mystruct {
            int counter;
        };

    //custom hashing
        struct custom_hash {
            inline std::size_t operator()(const std::pair<int,int> & v) const {
                    return v.first*31+v.second*7;
            }
        };

    // pq/set custom comparator
        class mycomp {
            public:
            bool operator() (mystruct a, mystruct b) {
                return a.counter > b.counter;
            }
        };

    // sort custom comparator
        bool customcompare(mystruct a, mystruct b) {
            return a.counter > b.counter;
        }

        // string split
        vector<string> strsplit(string toSplit, char tok) {
            vector<string> ans;
            string token;
            istringstream iss(toSplit);
            while(getline(iss, token, tok)) {
                ans.pb(token);
            }
            return ans;
        }

// vector<vi> AL;
vector<vi> grid;

useti rumah;
int R, K;

pii loc(int N) {
    int row, col;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == N) {
                row = i;
                col = j;
            }
        }
    }
    return mp(row, col);
}

// true kalo nambah
bool kiri(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;
    if (col == 0) {
        return true;
    }

    int bil = grid[row][col-1];
    return rumah.find(bil) == rumah.end();
}

bool kanan(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;
    if (col == grid[row].size()-1) {
        return true;
    }
    int bil = grid[row][col+1];
    return rumah.find(bil) == rumah.end();
}

bool ataskiri(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == 0) {
        return true;
    }

    if (row < R) {
        if (col == 0) {
            return true;
        }
        int bil = grid[row-1][col-1];
        return rumah.find(bil) == rumah.end();
    } else {
        int bil = grid[row-1][col];
        return rumah.find(bil) == rumah.end();
    }
}

bool ataskanan(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == 0) {
        return true;
    }

    if (row < R) {
        if (col == grid[row].size()-1) {
            return true;
        }
        int bil = grid[row-1][col];
        return rumah.find(bil) == rumah.end();
    } else {
        int bil = grid[row-1][col+1];
        return rumah.find(bil) == rumah.end();
    }
}

bool bawahkanan(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == R + R - 2) {
        return true;
    }

    if (row < R-1) {
        int bil = grid[row+1][col+1];
        return rumah.find(bil) == rumah.end();
        // return true;
    } else {
        if (col == grid[row].size()-1) {
            return true;
        }
        int bil = grid[row+1][col];
        return rumah.find(bil) == rumah.end();
    }
}

bool bawahkiri(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == R + R - 2) {
    // if (row == 0) {
        return true;
    }

    if (row < R-1) {
        int bil = grid[row+1][col];
        return rumah.find(bil) == rumah.end();
        // return true;
    } else {
        if (col == 0) {
            return true;
        }
        int bil = grid[row+1][col-1];
        return rumah.find(bil) == rumah.end();
    }
}

// true kalo nambah
int kirin(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;
    if (col == 0) {
        return -1;
    }

    int bil = grid[row][col-1];
    return rumah.find(bil) == rumah.end() ? bil : -1;
}

int kanann(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;
    if (col == grid[row].size()-1) {
        return -1;
    }
    int bil = grid[row][col+1];
    return rumah.find(bil) == rumah.end() ? bil : -1;
}

int ataskirin(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == 0) {
        return -1;
    }

    if (row < R) {
        if (col == 0) {
            return -1;
        }
        int bil = grid[row-1][col-1];
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
    } else {
        int bil = grid[row-1][col];
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
    }
}

int ataskanann(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == 0) {
        return -1;
    }

    if (row < R) {
        if (col == grid[row].size()-1) {
            return -1;
        }
        int bil = grid[row-1][col];
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
    } else {
        int bil = grid[row-1][col+1];
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
    }
}

int bawahkanann(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == R + R - 2) {
        return -1;
    }

    if (row < R-1) {
        int bil = grid[row+1][col+1];
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
        // return true;
    } else {
        if (col == grid[row].size()-1) {
            return -1;
        }
        int bil = grid[row+1][col];
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
    }
}

int bawahkirin(int N) {
    pii locat = loc(N);
    int row = locat.fi;
    int col = locat.se;

    if (row == R + R - 2) {
    // if (row == 0) {
        return -1;
    }

    if (row < R-1) {
        int bil = grid[row+1][col];
        if (N == 1) {
            // cout << row << " " << col << endl;
            // cout << row+1 << endl;
            // cout << row+1 << " " << col << endl;
            // cout << bil << endl;
        }
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
        // return true;
    } else {
        if (col == 0) {
            return -1;
        }
        int bil = grid[row+1][col-1];
        return rumah.find(bil) == rumah.end() ? bil : -1;
        return bil;
    }
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> R >> K;


    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        rumah.insert(x);
    }

    int ctr = 1;

    for (int i = 0; i < R + R-1; i++) {
        int limitkanan;
        if (i < R) {
            limitkanan = R + i;
        } else {
            limitkanan = R + R - 1 - (i-R+1);
        }


        vi emp;
        for (int j = 0; j < limitkanan; j++) {
            emp.pb(ctr);
            ctr++;
        }
        grid.pb(emp);

        // for(int j = )
    }
    // for (auto x : grid) {
    //     for (auto y: x) {
    //         cout << y << " ";
    //     } cout << endl;
    // }

    // for (auto x : grid) {
    //     for (auto y: x) {
    //         cout << y << " punya kiri " << kirin(y);
    //         cout << endl;
    //         if (y == 1) {
    //             pii locc = loc(y);
    //             cout << locc.fi << " " << locc.se << endl;
    //         }
    //         cout << y << " punya kanan " << kanann(y);
    //         cout << endl;
    //         cout << y << " punya ataskiri " << ataskirin(y);
    //         cout << endl;
    //         cout << y << " punya ataskanan " << ataskanann(y);
    //         cout << endl;
    //         cout << y << " punya bawahkiri " << bawahkirin(y);
    //         cout << endl;
    //         cout << y << " punya bawahkanan " << bawahkanann(y);
    //         cout << endl;
    //     } cout << endl; 
    // }

    useti visited;
    qi bfs;
    visited.insert(-1);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            bool can = false;
            bool can2 = (rumah.find(grid[i][j]) == rumah.end());

            if (i == 0 || i == grid.size() - 1) {
                can = true;
            }

            if (j == 0 || j == grid[i].size() - 1) {
                can = true;
            }

            if (can && can2) {
                bfs.push(grid[i][j]);
            }
        }
    }

    while(bfs.size() > 0) {
        auto curr = bfs.front();
        bfs.pop();
        if (visited.find(curr) == visited.end()) {
            visited.insert(curr);
            int bil1 = kirin(curr);
            if (bil1 != -1) {
                bfs.push(bil1);
            }
            int bil2 = kanann(curr);
            if (bil2 != -1) {
                bfs.push(bil2);
            }
            int bil3 = ataskirin(curr);
            if (bil3 != -1) {
                bfs.push(bil3);
            }
            int bil4 = ataskanann(curr);
            if (bil4 != -1) {
                bfs.push(bil4);
            }
            int bil5 = bawahkirin(curr);
            if (bil5 != -1) {
                bfs.push(bil5);
            }
            int bil6 = bawahkanann(curr);
            if (bil6 != -1) {
                bfs.push(bil6);
            }

        }
    }

    for (auto x: visited) {
        // cout << x << endl;
    }

    int ttl = 0;

    for (auto elem: rumah) {
        if (kiri(elem) && visited.find(kirin(elem)) != visited.end()) {
            // cout << elem <<  " found " << kirin(elem) << " kiri" << endl; 
            ttl++;
        }

        if (kanan(elem) && visited.find(kanann(elem)) != visited.end()) {
            // cout << elem <<  " found " << kanann(elem) << " kanan" << endl; 
            ttl++;
        }

        if (ataskiri(elem) && visited.find(ataskirin(elem)) != visited.end()) {
            // cout << elem <<  " found " << ataskirin(elem) << " ataskiri" << endl; 
            ttl++;
        }

        if (ataskanan(elem) && visited.find(ataskanann(elem)) != visited.end()) {
            // cout << elem <<  " found " << ataskanann(elem) << " ataskanan" << endl; 
            ttl++;
        }

        if (bawahkiri(elem) && visited.find(bawahkirin(elem)) != visited.end()) {
            // cout << elem <<  " found " << bawahkirin(elem) << " bawahkiri" << endl; 
            ttl++;
        }

        if (bawahkanan(elem) && visited.find(bawahkanann(elem)) != visited.end()) {
            // cout << elem <<  " found " << bawahkanann(elem) << " bawahkanan" << endl; 
            ttl++;
        }
        // cout << elem << " " << ttl << endl;
    }

    cout << ttl << endl;


    return 0;
}