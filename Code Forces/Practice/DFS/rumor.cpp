/*
                C++
                encoding:UTF-8
                Modified: <03/Feb/2019 02:22:00 PM>

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

vector<vector<ll>> graph(100005);
ll visited[100005];
ll scc = 0;
ll component[100005] = {-1};

void explore(ll node) {
  visited[node] = 1;
  component[node] = scc;
  for (auto neighbour : graph[node]) {
    if (visited[neighbour] == 0)
      explore(neighbour);
  }
}

void dfs(ll n) {
  for (ll i = 1; i < n + 1; i++) {
    if (visited[i] == 0) {
      scc++;
      explore(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll n, m;
  cin >> n >> m;
  ll gold[n + 1];
  for (size_t i = 1; i < n + 1; i++) {
    cin >> gold[i];
  }
  ll u, v;
  for (ll i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(n);
  unordered_map<ll, vector<ll>> ans;
  ll x;
  for (ll i = 1; i < n + 1; i++) {
    x = component[i];
    ans[x].push_back(gold[i]);
  }
  u = 0;
  ll p;
  for (auto i : ans) {
    u += (*min_element(i.second.begin(), i.second.end()));
  }
  cout << u << "\n";
  return 0;
}
