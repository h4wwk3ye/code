/*
                C++
                encoding:UTF-8
                Modified: <07/Jan/2019 10:49:52 AM>

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

std::vector<std::vector<ll>> graph(100000 + 5);
std::vector<ll> child(100000 + 5);
ll count = 0;
ll n, m;

void explore(ll i, bool visited[]) {
  visited[i] = true;
  for (auto node : graph[i]) {
    if (visited[node] == false) {
      visited[node] = true;
      explore(node, visited);
    }
  }
}

void dfs() {
  bool visited[n + 1] = {false};
  for (size_t i = 1; i < n + 1; i++) {
    if (visited[i] == false)
      explore(i, visited);
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  ll u, v;
  for (size_t i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs();
  return 0;
}
