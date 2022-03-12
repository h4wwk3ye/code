/*
                C++
                encoding:UTF-8
                Modified: <20/Feb/2019 10:20:49 AM>

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

int n, m;
const int N = 1e5 + 5;
vector<int> graph[N];
int visited[N];
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  visited[1] = 1;
  priority_queue<int, vector<int>, greater<>> Q;
  Q.push(1);

  while (!Q.empty()) {
    int node = Q.top();
    Q.pop();
    ans.pb(node);
    for (int neighbour : graph[node]) {
      if (!visited[neighbour]) {
        Q.push(neighbour);
        visited[neighbour] = 1;
      }
    }
  }

  for (int node : ans)
    cout << node << " ";
  cout << "\n";
  return 0;
}
