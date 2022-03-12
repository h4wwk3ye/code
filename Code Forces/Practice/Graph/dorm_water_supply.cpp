/*
                C++
                encoding:UTF-8
                Modified: <24/Feb/2019 08:28:48 PM>

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

const int N = 1e3 + 5;
int n, m;
vector<pair<int, int>> graph[N], reverse_graph[N];
int tap, diameter = 1e9;
int visited[N];
vector<int> ans;
int cnt;

void explore(int node) {
  visited[node] = 1;
  for (auto x : graph[node]) {
    int neighbour = x.first;
    int dia = x.second;
    if (!visited[neighbour]) {
      diameter = min(diameter, dia);
      if (int(graph[neighbour].size()) == 0) {
        tap = neighbour;
        return;
      } else
        explore(neighbour);
    }
  }
}

void dfs() {
  for (int i = 1; i <= n; i++) {
    if (!visited[i] and int(reverse_graph[i].size()) == 0) {
      explore(i);
      // cout << tap << " " << diameter << " \n";
      if (diameter != 1e9) {
        cnt++;
        ans.pb(i);
        ans.pb(tap);
        ans.pb(diameter);
        // cout << i << " " << tap << " " << diameter << "\n";
        diameter = 1e9;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int u, v, d;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> d;
    graph[u].pb(make_pair(v, d));
    reverse_graph[v].pb(make_pair(u, d));
  }

  dfs();
  if (cnt == 0) {
    cout << 0 << "\n";
    return 0;
  }

  cout << cnt << "\n";
  for (int i = 0; i < ans.size(); i += 3) {
    cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << "\n";
  }
  return 0;
}
