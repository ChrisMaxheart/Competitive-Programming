/*
held-karp TSP algorithm
O(N^2 2^N)
*/

// N = total number of nodes
// max is the question limit of node
// start and stop is index 0
#define MAX 20
int N;
int dist[MAX][MAX];
int dp[1 << MAX][MAX];

int tsp(){
    // cout << "test" << endl;
    for (int i = 0; i < (1 << MAX); i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = INF;
        }
    }
    dp[((1<<N) - 2)][0] = 0;
    int i, j;
    for (int mask = ((1<<N) - 2); mask >= 0; mask-=2) {
        int rmask = mask ^ ((1 << N)-1);
        // cout << "========================" << endl;
        // cout << rmask << endl;
        // cout << mask << endl;
        while(int temp = LSOne(rmask)) {
            rmask -= temp;
            int idx = __builtin_ctz(temp);
            // cout << "------------------" << endl;
            // cout << dp[mask][idx] << endl;
            if (dp[mask][idx] == INF) {
                continue;
            }
            int dummask = mask;
            while(int temp2 = LSOne(dummask)) {
                dummask -= temp2;
                int idx2 = __builtin_ctz(temp2);
                int new_mask = mask ^ (1 << idx2);
                int cost = dp[mask][idx] + dist[idx][idx2];
                // cout << cost << " " << dp[new_mask][idx2] << endl;
                // cout << "newmask " << new_mask << endl;
                dp[new_mask][idx2] = min(dp[new_mask][idx2], cost);
            }
        }
    }
    int final_mask = 0;
    int ans = INF;
    for (i = 1; i < N; ++i)
        ans = min(ans, dp[final_mask][i] + dist[i][0] );
    return ans;
}