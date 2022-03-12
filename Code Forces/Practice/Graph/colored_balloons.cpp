/*
                C++
                encoding:UTF-8
                Modified: <20/Feb/2019 11:21:20 AM>

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
int n;
vector<int> graph[N];
int color[N];

void dfs(int node, int parent) {
  int curr = 1;
  for (int neighbour : graph[node]) {
    if (neighbour != parent) {
      while (curr == color[node] || curr == color[parent])
        curr++;
      color[neighbour] = curr;
      curr++;
      dfs(neighbour, node);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  int mx = -1;
  for (int i = 1; i <= n; i++) {
    int x = graph[i].size();
    mx = max(mx, x);
  }
  for (int i = 1; i <= n; i++) {
    color[i] = 1;
  }
  dfs(1, 1);
  cout << mx + 1 << "\n";
  for (int i = 1; i <= n; i++) {
    cout << color[i] << " ";
  }
  cout << "\n";
  return 0;
}
