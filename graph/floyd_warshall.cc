/*
 * Floyd-Warshall algorithm & path reconstruction
 */

const int MAX_V = 400, INF = 987654321;
int dist[MAX_V][MAX_V], next_edge[MAX_V][MAX_V], V;

void init() {
    memset(next_edge, -1, sizeof next_edge);
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = INF;
}

void floyd_warshall() {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][i];
                    next_edge[i][j] = next_edge[i][k];
                }
            }
        }
    }
}

vector<int> path(int u, int v) {
    vector<int> result;
    if (next_edge[u][v] == -1) return result;
    path.push_back(u);
    while (u != v) {
        u = next_edge[u][v];
        result.push_back(u);
    }
    return result;
}
