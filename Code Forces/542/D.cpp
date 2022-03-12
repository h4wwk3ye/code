/*
                C++
                encoding:UTF-8
                Modified: <24/Feb/2019 11:01:03 PM>

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
const int N = 105;
vector<int> graph[N];

int solve(int i, int ans, unordered_map<int, int> mp, int cnt) {
  // cout << i << " " << ans << " \n";
  if (cnt == 0)
    return ans;
  ans++;
  if (mp.find(i) != mp.end()) {
    cnt--;
    mp.erase(i);
  }
  if (graph[i].size() == 0) {
    if (i == n)
      solve(1, ans, mp, cnt);
    else
      solve(i + 1, ans, mp, cnt);
  } else {
    int p = 1e9;
    for (int x : graph[i])
      if (mp.find(x) == mp.end()) {
        mp[x] = 1;
        int node;
        if (i == n)
          node = 1;
        else
          node = i + 1;
        p = min(p, solve(node, ans, mp, cnt));
      }
  }
}

int main() {
  // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].pb(v);
  }
  for (int i = 1; i <= n; i++) {
    int cnt = m;
    unordered_map<int, int> mp;
    int u = solve(i, 0, mp, cnt);
    cout << u << "\n";
  }
  return 0;
}
