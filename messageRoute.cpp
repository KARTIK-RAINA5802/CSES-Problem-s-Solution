#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> grid;
vector<bool> vis;
vector<int> parent;

void bfs() {
    vis[1] = true;
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(auto u: grid[v]) {
            if(!vis[u]) {
                vis[u] = true;
                parent[u] = v;
                q.push(u);
            }
        }
    }

}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin >> n >> m;

   grid.resize(n+1);
   vis.resize(n+1);
   parent.resize(n+1);

   for(int i=0; i<=n; i++) {
      parent[i] = -1;
   }
   
   for(int i=0; i<m; i++) {
       int u,v;
       cin >> u >> v;

       grid[u].push_back(v);
       grid[v].push_back(u);
   }

   bfs();

   if(parent[n] == -1) {
       cout << "IMPOSSIBLE" << endl;
       return 0;
   }

   stack<int> s;
   int current = n;

   while(current != -1) {
       s.push(current);
       current = parent[current];
   }

   cout << s.size() << endl;

   while (!s.empty())
   {
       cout << s.top() << " ";
       s.pop();
   }
   

   return 0;
}