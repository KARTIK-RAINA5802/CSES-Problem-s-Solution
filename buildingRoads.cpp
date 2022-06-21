#include <bits/stdc++.h>
using namespace std;

int n, m, connectedComponents = 0;
vector<vector<int>> grid;
vector<bool> vis;
vector<int> lead;

void dfs(int u)
{
    vis[u] = true;

    for (int v : grid[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

void findConnectedComponents()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            connectedComponents++;
            lead.push_back(i);
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    grid.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    findConnectedComponents();

    int roads = connectedComponents - 1;
    cout << roads << endl;

    if (connectedComponents > 1)
    {
        int u = lead[0];
        int v;

        for(int i=1; i<connectedComponents; i++) {
            v = lead[i];
            cout << u << " " << v << endl;
            u = v;
        }
    }

    return 0;
}