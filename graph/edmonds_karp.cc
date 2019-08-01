/*
 * Edmonds-Karp algorithm
 */

const int MAX_V = 111;
const int INF = 1 << 30;

int graph[MAX_V][MAX_V], mf, f, s, t;
vector<int> parent;

void augment(int v, int min_edge) {
    if (v == s)
        f = min_edge;
    else if (parent[v] != -1) {
        augment(parent[v], min(min_edge, graph[parent[v]][v]));
        graph[parent[v]][v] -= f;
        graph[v][p[v]] += f;
    }
}

int maxflow() {
    mf = 0;
    while (true) {
        f = 0;
        vector<int> dist(MAX_V, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        parent.assign(MAX_V, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break;
            for (int v = 0; v < MAX_V; ++v)
                if (graph[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), parent[v] = u;
        }
        augment(t, INF);
        if (f == 0) break;
        mf += f;
    }
    return mf;
}
