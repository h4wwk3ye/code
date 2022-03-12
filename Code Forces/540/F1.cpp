/*
                C++
                encoding:UTF-8
                Modified: <19/Feb/2019 11:56:03 PM>

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

const int N = 3e5 + 5;
int n, blue, red;
vector<int> graph[N];
int c[N], r[N], b[N], ans;

void dfs(int node, int parent) {
  if (c[node] == 1)
    r[node]++;
  if (c[node] == 2)
    b[node]++;

  for (int neighbour : graph[node]) {
    if (neighbour != parent) {
      dfs(neighbour, node);
      b[node] += b[neighbour];
      r[node] += r[neighbour];
    }
  }

  if (parent != -1) {
    if (b[node] == blue and r[node] == 0)
      ans++;
    if (r[node] == red and b[node] == 0)
      ans++;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (c[i] == 1)
      red++;
    else if (c[i] == 2)
      blue++;
  }
  int u, v;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  dfs(1, -1);
  cout << ans << "\n";
  return 0;
}
