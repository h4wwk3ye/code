/*
                C++
                encoding:UTF-8
                Modified: <08/Feb/2019 02:45:07 PM>

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

ll n, m;
ll matrix[201][201] = {0};
ll distance_1[201][201] = {0};
ll distance_2[201][201] = {0};
ll visited_1[201][201] = {0};
ll visited_2[201][201] = {0};

bool check(ll i, ll j) { return (i >= 1 and i <= n and j >= 1 and j <= m); }

void bfs_1(ll x, ll y) {
  visited_1[x][y] = 1;
  queue<ll> que;
  que.push((x, y));
  ll neighbours[4][2] = {
      {i, j - 1},
      {i - 1, j},
      {i + 1, j},
      {i, j + 1},
  };
  ll s, r;
  for (auto p : neighbours) {
    s = p[0];
    r = p[1];
    if (check(s, r) && !visited_1[s][r] && matrix[s][r] == 0) {
      distance_1[s]
    }
  }
}

int main() {
  // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  ll x, y;
  cin >> x >> y;
  matrix[x][y] = 1 ll u, v;
  cin >> u >> v;
  matrix[u][v] = 2 bfs_1(x, y);
  return 0;
}
