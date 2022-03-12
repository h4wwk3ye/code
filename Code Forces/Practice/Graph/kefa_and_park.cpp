/*
                C++
                encoding:UTF-8
                Modified: <11/Feb/2019 06:22:07 PM>

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

const int N = 2e5 + 5;
vector<vector<ll>> graph(N);
ll cats[N];
ll visited[N] = {0};
ll m, ans = 0;

void dfs(ll node, ll cnt) {
  visited[node] = 1;
  if (cats[node])
    cnt++;
  else
    cnt = 0;
  // cout << node << " " << cnt << "\n";
  if (cnt > m)
    return;
  ll flag = 0;
  for (auto neighbour : graph[node]) {
    if (!visited[neighbour]) {
      flag = 1;
      dfs(neighbour, cnt);
    }
  }
  if (graph[node].size() == 1 && flag == 0) {
    ans++;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll n;
  cin >> n >> m;
  for (ll i = 1; i <= n; i++)
    cin >> cats[i];
  ll u, v;
  for (ll i = 1; i < n; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs(1, 0);
  cout << ans << "\n";
  return 0;
}
