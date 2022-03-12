/*
                C++
                encoding:UTF-8
                Modified: <31/Dec/2018 10:40:54 PM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ll n, m;
  cin >> n >> m;
  std::vector<ll> graph[n + 1];
  ll a, b;
  for (size_t i = 0; i < m; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  ll q;
  cin >> q;
  for (size_t i = 0; i < q; i++) {
    cin >> a >> b;
    int flag = 0;
    for (size_t j = 0; j < graph[a].size(); j++) {
      if (graph[i][j] == b) {
        std::cout << "YES" << '\n';
        flag = 1;
        break;
      }
      if (flag == 0)
        std::cout << "NO" << '\n';
    }
  }
  return 0;
}
