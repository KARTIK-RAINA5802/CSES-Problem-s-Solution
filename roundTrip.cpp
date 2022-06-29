#include <bits/stdc++.h>
using namespace std;

int n, m;
int sv, ev;

vector<vector<int>> grid;
vector<int> vis;
vector<int> parent;

bool dfs(int u, int parentNode)
{
    vis[u] = true;
    parent[u] = parentNode;

    for (auto v : grid[u])
    {
        if (v == parentNode)
            continue;

        if (vis[v])
        {
            sv = v;
            ev = u;
            return true;
        }

        if (!vis[v])
        {
            if (dfs(v, u)) {
                return true;
            }
        }
    }

    return false;
}

bool visitAllNodes()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    grid.resize(n + 1);
    vis.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    bool cycleFound = visitAllNodes();

    if (!cycleFound)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    int cv = ev;
    vector<int> ans;

    ans.push_back(ev);
    while (cv != sv)
    {
        ans.push_back(parent[cv]);
        cv = parent[cv];
    }
    ans.push_back(ev);

    cout << ans.size() << endl;

    for (auto cities : ans)
    {
        cout << cities << " ";
    }

    return 0;
}