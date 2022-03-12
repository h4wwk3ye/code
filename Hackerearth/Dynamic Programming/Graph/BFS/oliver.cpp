/*
                C++
                encoding:UTF-8
                Modified: <01/Jan/2019 09:08:13 PM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define sortv(v) sort(v.begin(), v.end())
#define len(v) v.length()
#define reset(a, b) memset(a, b, sizeof(a));

ll mx;
ll matrix[n][m];
ll visited[n][m], counter = 0;

void bfs(i, j) {
  ll count = 1;
  visited[i][j] = 1;
  queue <
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll tc;
  cin >> tc;
  for (size_t i = 0; i < tc; i++) {
    ll n, m;
    cin >> n >> m;
    mx = 0;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        cin >> matrix[i][j];
      }
    }
    counter = 0;
    reset(visited, 0) for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if (matrix[i][j] == 1 && visited[i][j] == 0) {
          bfs(i, j);
          counter += 1;
        }
      }
    }
  }

  return 0;
}
