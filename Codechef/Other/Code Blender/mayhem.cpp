/*
                C++
                encoding:UTF-8
                Modified: <02/Feb/2019 10:51:33 PM>

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

ll visited[1000][1000] = {0};
ll matrix[1000][1000];
ll mx = 1;
ll maxi = 1e9;
ll cnt = 1;
bool check(ll i, ll j, ll n, ll m) {
  if (i >= 0 && i < n && j >= 0 && j < m)
    return true;
  return false;
}

void dfs(ll i, ll j, ll n, ll m) {
  visited[i][j] = 1;
  ll neighbours[4][2] = {
      {i, j - 1},
      {i - 1, j},
      {i + 1, j},
      {i, j + 1},
  };
  ll x, y;
  for (auto p : neighbours) {
    x = p[0];
    y = p[1];
    if (check(x, y, n, m) == true && visited[x][y] == 0) {
      if (matrix[x][y] == matrix[i][j]) {
        cnt++;
        if (cnt > mx) {
          maxi = matrix[i][j];
          mx = cnt;
        } else if (cnt == mx && matrix[i][j] < maxi)
          maxi = matrix[i][j];
        dfs(x, y, n, m);
      }
    }
  }
  if (cnt == mx && matrix[i][j] < maxi) {
    maxi = matrix[i][j];
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll n, m;
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cnt = 1;
      dfs(i, j, n, m);
    }
  }
  cout << maxi << " " << mx << "\n";
  return 0;
}
