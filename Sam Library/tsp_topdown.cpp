#define LSOne(S) ((S)&(-S))
typedef vector<int> vi;
typedef pair<int, int> pii;

int N;
int strt;
vector<vi> AM;
unordered_map<pii, int, custom_hash> memo;

// the first call the mask need to be one for strt, and 0 for all others
// initial mask should be all one
int tsp(int c, int mask) {
    if (mask == 0) {
        return AM[c][strt];
    }
    pii marker = mp(c, mask);
    if (memo.find(marker) == memo.end()) {
        int mini = INF;
        int newmask = mask;
        int temp = LSOne(newmask);
        while(temp) {
            int idx = log2(temp);
            mini = min(mini, tsp(idx, mask - temp) + AM[c][idx]);
            newmask -= temp;
            temp = LSOne(newmask);
        }
        memo[marker] = mini;
    }
    return memo[marker];
}