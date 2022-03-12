/*
                C++
                encoding:UTF-8
                Modified: <21/Feb/2019 12:59:06 AM>

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

int n, m, k;
vector<int> capitals;
const int N = 1e4 + 5;
vector<int> graph[N];
int sz, visited[N];
vector<int> component;

void dfs(int node) {
  visited[node] = 1;
  sz++;
  for (int neighbour : graph[node]) {
    if (!visited[neighbour])
      dfs(neighbour);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  capitals.resize(k);
  for (int i = 0; i < k; i++)
    cin >> capitals[i];

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  for (int node : capitals) {
    sz = 0;
    dfs(node);
    component.pb(sz);
  }
  sort(component.begin(), component.end());
  int used = 0;
  ll ans = 0, nodes;

  for (auto i : component)
    used += i; // total nodes that are capitals or conencted to capitals
  component[component.size() - 1] += n - used;
  // subtracting those nodes from the largest component
  for (auto i : component) {
    nodes = 1ll * i * (i - 1) / 2;
    ans += nodes;
  }

  cout << ans - m << "\n";

  return 0;
}
