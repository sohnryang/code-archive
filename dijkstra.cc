/*
 * Dijkstra's shortest path algorithm
 */

typedef pair<int, int> ipair;

int V, E;
vector<pair<int, int>> graph[20001];
vector<int> dist;
const int INF = 987654321;

void dijkstra(int s) {
    dist.assign(V + 1, INF);
    dist[s] = 0;
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (int j = 0; j < graph[u].size(); ++j) {
            auto v = graph[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
}
