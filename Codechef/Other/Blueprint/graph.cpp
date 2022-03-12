/*
                C++
                encoding:UTF-8
                Modified: <07/Feb/2019 10:23:29 AM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define sort(v) sort(v.begin(), v.end())
#define reset(a, b) memset(a, b, sizeof(a));

const int N = 1e4 + 5;
vector<vector<ll>> graph(N);
vector<vector<ll>> reverse_graph(N);
ll visited[N] = {0};
ll n, m, k;
vector<ll> stk;
ll scc;

void explore(ll node) {
  visited[node] = 1;
  for (auto neighbour : reverse_graph[node]) {
    if (!visited[neighbour])
      explore(neighbour);
  }
  stk.push_back(node);
}

void dfs() {
  reset(visited, 0);
  for (ll i = 1; i <= n; i++) {
    if (!visited[i])
      explore(i);
  }
}

void explore_o(ll node) {
  visited[node] = 1;
  for (auto neighbour : graph[node]) {
    if (!visited[neighbour])
      explore_o(neighbour);
  }
}

ll dfs_o() {
  reverse(stk.begin(), stk.end());
  scc = 0;
  reset(visited, 0);
  for (auto node : stk) {
    if (!visited[node]) {
      scc++;
      explore_o(node);
    }
  }
  return scc;
}

ll npr(ll n, ll r) {
  ll ans = 1;
  for (ll i = 0; i < r; i++) {
    ans *= n;
    n -= 1;
    ans %= mod;
  }
  return ans;
}

int main() {
  // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll tc;
  cin >> tc;
  while (tc--) {
    cin >> k >> n >> m;
    for (ll i = 1; i <= n; i++) {
      graph[i].clear();
      reverse_graph[i].clear();
    }
    ll u, v;
    for (ll i = 0; i < m; i++) {
      cin >> u >> v;
      graph[u].push_back(v);
      reverse_graph[v].push_back(u);
    }
    dfs();
    ll ans = dfs_o();
    if (ans > k) {
      cout << -1 << "\n";
      continue;
    }
    ll p = npr(k, ans);
    cout << p << "\n";
  }
  return 0;
}
