/*
                C++
                encoding:UTF-8
                Modified: <04/Feb/2019 08:26:11 PM>

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

vector<vector<ll>> graph(10005);
ll visited[10005] = {0};
ll color[10005];
ll cnt = 0;

void explore(ll node) {
  visited[node] = 1;
  for (auto neighbour : graph[node]) {
    if (visited[neighbour] == 0 && color[neighbour] == color[node])
      explore(neighbour);
  }
}

void dfs(ll n) {
  for (ll i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      cnt += 1;
      explore(i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll n;
  cin >> n;
  ll a;
  for (ll i = 2; i < n + 1; i++) {
    cin >> a;
    graph[a].push_back(i);
  }
  for (ll i = 1; i <= n; i++) {
    cin >> color[i];
  }
  dfs(n);
  cout << cnt;
  return 0;
}
