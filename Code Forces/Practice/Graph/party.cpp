/*
                C++
                encoding:UTF-8
                Modified: <25/Feb/2019 11:47:19 PM>

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

const int N = 1e5 + 5;
int n, scc, visited[N], component[N], check[N], belong[N];
vector<int> graph[N];

void dfs(int node) {
  visited[node] = 1;
  component[scc]++;
  belong[node] = scc;
  for (int neighbour : graph[node]) {
    if (!visited[neighbour])
      dfs(neighbour);
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int k;
  cin >> k;
  int u, v;
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      scc++;
      dfs(i);
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> u >> v;
    if (belong[u] == belong[v]) {
      component[belong[u]] = 0;
    }
  }
  int mx = 0;
  for (int i = 1; i <= scc; i++) {
    mx = max(mx, component[i]);
  }
  cout << mx << "\n";

  return 0;
}
