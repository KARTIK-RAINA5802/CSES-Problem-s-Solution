#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair


int n, m;

bool vis[1000][1000];
char grid[1000][1000];
int prevStep[1000][1000];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string moves = "URDL";

int main() {
   cin >> n >> m;

   queue<ii> q;
   ii begin, end;
   
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         cin >> grid[i][j];
         if(grid[i][j] == 'A') {
            begin = mp(i, j);
         } else if(grid[i][j] == 'B') {
            end = mp(i, j);
         }
      }
   }

   q.push(begin);
   vis[begin.f][begin.s] = true;

   while(!q.empty()) {
      ii u = q.front();
      q.pop();

      for(int i=0; i<4; i++) {
         ii v = mp(u.f + dx[i], u.s + dy[i]);
         if(v.f < 0 || v.f >= n || v.s < 0 || v.s >=m) continue;
         if(grid[v.f][v.s] == '#') continue;
         if(vis[v.f][v.s]) continue;
         vis[v.f][v.s] = true;
         prevStep[v.f][v.s] = i;
         q.push(v);
      }
   }

   if(vis[end.f][end.s]) {
      cout << "YES" << endl;
      vector<int> steps;

      while (end != begin)
      {
         int p = prevStep[end.f][end.s];
         steps.push_back(p);
         end = make_pair(end.f - dx[p], end.s - dy[p]);
      }
      reverse(steps.begin(), steps.end());

      cout << steps.size() << endl;

      for(char i : steps) {
         cout << moves[i];
      }
      cout << endl;
   } else {
      cout << "NO" << endl;
   }

   return 0;
}
