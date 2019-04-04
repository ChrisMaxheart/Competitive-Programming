#define LSOne(S) ((S)&(-S))
#define INF 1E9
#define pb push_back
typedef vector<int> vi;

int N;
vector<vi> AM;
vector<vi> memo;

// start and stop always at node 0
// init using INF, as below
int tsp() {
    int full = (1 << N) - 1;
    for (int i = 0; i <= full; i++) {
        vi emp;
        for (int j = 0; j < N; j++) {
            emp.pb(INF);
        }
        memo.pb(emp);
    }
    memo[full-1][0] = 0;
    for (int mask = full - 1; mask >= 0; mask-= 2) {
        int rmask = mask ^ full;
        while(int temp = LSOne(rmask)) {
            rmask -= temp;
            int idxfrom = __builtin_ctz(temp);
            int dummymask = mask;
            if (memo[mask][idxfrom] == INF) {
                continue;
            }
            while(int temp2 = LSOne(dummymask)) {
                dummymask -= temp2;
                int idxto = __builtin_ctz(temp2);
                int newmask = mask ^ temp2;
                // cout << idxfrom << " " << idxto << endl;
                // if(idxfrom < N && idxto < N) {
                // cout << " =============== " << endl;
                // cout << memo[newkey] << endl;
                // cout << memo[mp(mask, idxfrom)] + AM[idxfrom][idxto] << endl;
                // cout << "dp yang dipanggil = " << memo[mp(mask, idxfrom)] << endl;
                // cout << "mask tujuan = " << newmask << endl;
                memo[newmask][idxto] = min(memo[newmask][idxto], memo[mask][idxfrom] + AM[idxfrom][idxto]);
                // cout << idxfrom << " to " << idxto << " in condition " << mask << " curr score " << memo[newkey] << endl;
                // } else {
                //     cout << idxfrom << " " << idxto << endl;
                // }
            }
        }
    }

    int mini = INF;
    for (int i = 1; i < N; i++) {
        mini = min(mini, memo[0][i] + AM[i][0]);
    }
    return mini;
}