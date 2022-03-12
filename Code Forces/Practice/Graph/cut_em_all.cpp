/*
                C++
                encoding:UTF-8
                Modified: <21/Feb/2019 02:45:09 PM>

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
vector<int> graph[N];
int n;
int ans = 0;
int sz[N];

void dfs(int node, int parent) {
  sz[node] = 1;
  for (int neighbour : graph[node]) {
    if (neighbour != parent) {
      dfs(neighbour, node);
      sz[node] += sz[neighbour];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  if (n % 2 == 1) {
    cout << -1;
    return 0;
  }
  dfs(1, -1);
  for (int i = 2; i <= n; i++) {
    if (sz[i] % 2 == 0)
      ans++;
  }
  cout << ans;
  return 0;
}
