/*
                C++
                encoding:UTF-8
                Modified: <20/Feb/2019 01:08:38 PM>

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
const int N = 4005;
int degree[N];
int edges[N][N];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    edges[u][v] = edges[v][u] = 1;
    degree[u]++;
    degree[v]++;
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (edges[i][j]) {
        for (int k = j + 1; k <= n; k++) {
          if (edges[i][k] && edges[j][k])
            ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
        }
      }
    }
  }
  if (ans == 1e9)
    cout << -1 << "\n";
  else
    cout << ans << "\n";

  return 0;
}
