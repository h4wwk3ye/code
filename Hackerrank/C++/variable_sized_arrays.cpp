/*
                C++
                encoding:UTF-8
                Modified: <31/Dec/2018 09:43:04 AM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
#define ll long long

int main() {
  ll n, q;
  std::cin >> n >> q;
  std::vector<std::vector<ll>> arr(n);
  for (size_t i = 0; i < n; i++) {
    ll k;
    std::cin >> k;
    arr[i].resize(k);
    for (size_t j = 0; j < k; j++) {
      std::cin >> arr[i][j];
    }
  }
  for (size_t i = 0; i < q; i++) {
    ll p, q;
    std::cin >> p >> q;
    std::cout << arr[p][q] << '\n';
  }
}
