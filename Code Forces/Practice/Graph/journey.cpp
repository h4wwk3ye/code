/*
                C++
                encoding:UTF-8
                Modified: <14/Feb/2019 10:48:08 AM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define reset(a, b) memset(a, b, sizeof(a));
#define pb push_back

const int N = 1e5 + 5;
std::vector<std::vector<ll>> graph(N);
ll n;
ll visited[N];
ld dp[N];

void dfs(ll node) {
  visited[node] = 1;
  ld s = 0;
  ll cnt = 0;
  for (auto neighbour : graph[node]) {
    if (!visited[neighbour]) {
      dfs(neighbour);
      s += dp[neighbour];
      cnt++;
    }
  }
  if (cnt)
    dp[node] = (s + cnt) * 1.0 / cnt;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  ll u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs(1);
  cout << fixed << setprecision(7) << dp[1];
  return 0;
}
