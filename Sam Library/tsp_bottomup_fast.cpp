/*
held-karp TSP algorithm
O(N^2 2^N)
*/

// N = total number of nodes
// max is the question limit
// start and stop are from node 0
#define MAX 20
#define INF 1E9
int N;
int dist[MAX][MAX];
int dp[1 << MAX][MAX];

int tsp(){
    for (int i = 0; i < (1 << MAX); i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = INF;
        }
    }
    dp[(1<<0)][0] = 0;
    int i, j;
    for (int mask = 1; mask < (1 << N); mask++) {
        for (i = 0; i < N; ++i) {
            if (dp[mask][i] == INF || (mask & (1 << i)) == 0) {
                continue;
            }
            for (j = 0; j < N; ++j) {
                if ((mask & (1 << j)) != 0)
                    continue;
                int new_mask = mask | (1 << j);
                int cost = dp[mask][i] + dist[i][j];
                dp[new_mask][j] = min(dp[new_mask][j], cost);
            }
        }
    }
    int final_mask = (1 << N) - 1;
    int ans = INF;
    for (i = 1; i < N; ++i)
        ans = min(ans, dp[final_mask][i] + dist[i][0] );
    return ans;
}