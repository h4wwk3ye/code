/*
                C++
                encoding:UTF-8
                Modified: <20/Feb/2019 12:01:57 PM>

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

int n, m;
const int N = 2e5 + 5;
vector<int> graph[N];
int visited[N];
int scc;
bool ans;

void explore(int node) {
  visited[node] = 1;
  if (int(graph[node].size()) != 2)
    ans = false;
  for (int neighbour : graph[node])
    if (!visited[neighbour])
      explore(neighbour);
}

void dfs() {
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      ans = true;
      explore(i);
      if (ans)
        scc++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs();
  cout << scc << "\n";
  return 0;
}
