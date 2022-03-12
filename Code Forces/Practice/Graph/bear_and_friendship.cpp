/*
                C++
                encoding:UTF-8
                Modified: <14/Feb/2019 11:17:47 AM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define reset(a, b) memset(a, b, sizeof(a));
#define pb push_back

const int N = 150005;
vector<int> graph[N];
int visited[N];
int vertices, edges;
int flag = 1;

void explore(int node) {
  visited[node] = 1;
  vertices++;
  edges += graph[node].size();
  for (int neighbour : graph[node]) {
    if (!visited[neighbour]) {
      explore(neighbour);
    }
  }
}

void dfs(int n) {
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      vertices = 0, edges = 0;
      explore(i);
      if (edges != (ll)vertices * (vertices - 1)) {
        flag = 0;
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  int u, v;

  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs(n);
  cout << (flag ? "YES" : "NO") << "\n";
  return 0;
}
