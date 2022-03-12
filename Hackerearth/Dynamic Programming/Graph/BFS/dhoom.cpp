/*
                C++
                encoding:UTF-8
                Modified: <18/Feb/2019 02:27:11 PM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000

int main() {

  // ifstream cin("input.txt");
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll root, ans;
  cin >> root >> ans;

  ll n;
  cin >> n;
  ll keys[n];
  for (size_t i = 0; i < n; i++) {
    cin >> keys[i];
  }
  queue<ll> que;
  que.push(root);
  ll depth[100005];
  memset(depth, -1, sizeof(depth));
  depth[root] = 0;
  while (!que.empty()) {
    ll popped = que.front();
    if (ans == popped) {
      cout << depth[popped] << "\n";
      return 0;
    }
    que.pop();
    for (size_t i = 0; i < n; i++) {
      ll prod = (keys[i] * popped) % mod;
      if (depth[prod] == -1) {
        que.push(prod);
        depth[prod] = 1 + depth[popped];
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}
