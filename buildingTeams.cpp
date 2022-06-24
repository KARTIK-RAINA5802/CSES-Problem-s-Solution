#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int>> grid;
vector<bool> vis;
vector<int> colour;

bool bipartiteDfs(int node) {
    vis[node] = true;
    if(colour[node] == -1) colour[node] = 1;

    for(auto it: grid[node]) {
        if(colour[it] == -1 && !vis[it]) {
            colour[it] = colour[node]^3;
            if(!bipartiteDfs(it)) {
                return false;
            }
        } else if(colour[it] == colour[node]) return false;
    }

    return true;
}

bool checkBipartite() {
    for(int i=1; i<=n; i++) {
        if(colour[i] == -1) {
            if(!bipartiteDfs(i)) {
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin >> n >> m;

   grid.resize(n+1);
   vis.resize(n+1, false);
   colour.resize(n+1, -1);

   for(int i=0; i<m; i++) {
      int u, v;
      cin >> u >> v;

      grid[u].push_back(v);
      grid[v].push_back(u);
   }

   bool check = checkBipartite();

   if(check == false) {
      cout << "IMPOSSIBLE" << endl;
   } else {
      for(int i=1; i<=n; i++) {
        cout << colour[i] << " "; 
      }
   }
    

   return 0;
}