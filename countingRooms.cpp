#include <bits/stdc++.h>
#define ll    long long int
#define ld    long double
#define mod   1000000007
#define f     first
#define s     second
#define inf   1e18
using namespace std;

int n,m;

vector<vector<bool>> vis;
vector<vector<char>> grid;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isSafe(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == true || grid[i][j] == '#') {
        return false;
    }
 
    return true;
}

void dfs(int cur_i, int cur_j) {
    vis[cur_i][cur_j] = true;

    for(int i=0; i<4; i++) {
        int new_i = cur_i + dx[i];
        int new_j = cur_j + dy[i];

        if(isSafe(new_i, new_j)){
            dfs(new_i, new_j);
        } 
    }
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin >> n >> m;
   vis.resize(n, vector<bool> (m, false));
   grid.resize(n, vector<char> (m));

   int count = 0;

   for(int i=0; i<n; i++) {
       for(int j=0; j<m; j++) {
           cin >> grid[i][j];
       }
   }

   for(int i=0; i<n; i++) {
       for(int j=0; j<m; j++) {
           if(grid[i][j] == '.' && vis[i][j] == false) {
               count++;
               dfs(i,j);
           }
       }
   }

   cout << count << endl;
   
   return 0;
}