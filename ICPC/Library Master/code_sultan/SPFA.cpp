vi dist(V, INF); dist[s] = 0;
queue<int> q; q.push(s);
vi in_queue(V, 0); in_queue[s] = 1;
while (!q.empty()) {
    int u = q.front(); q.pop(); in_queue[u] = 0;
    for (auto &v : AdjList[u])
        if (dist[u] + v.second < dist[v.first]) {
            dist[v.first] = dist[u] + v.second;
            if (!in_queue[v.first]) {
                q.push(v.first);
                in_queue[v.first] = 1;
            }
        }
}
