#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>>& adj, int src) {
    vector<int> vis(n+1, 0);
    queue<int> q;
    vis[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

void dfsUtil(int u, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) if (!vis[v]) dfsUtil(v, adj, vis);
}
void dfs(int n, vector<vector<int>>& adj, int src) {
    vector<int> vis(n+1, 0);
    dfsUtil(src, adj, vis);
    cout << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;               // nodes, edges
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);     // remove if directed
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end()); // predictable order

    int src; cin >> src;
    cout << "BFS: "; bfs(n, adj, src);
    cout << "DFS: "; dfs(n, adj, src);
}