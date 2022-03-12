/*
                C++
                encoding:UTF-8
                Modified: <20/Feb/2019 05:43:54 PM>

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

ll powermod(ll _a, ll _b, ll _m) {
  ll _r = 1;
  while (_b) {
    if (_b % 2 == 1)
      _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}

void multiply(ll F[][2], ll M[][2]) {
  ll x = (((F[0][0] % mod * M[0][0] % mod) % mod) +
          ((F[0][1] % mod * M[1][0] % mod) % mod)) %
         mod;
  ll y = (((F[0][0] % mod * M[0][1] % mod) % mod) +
          ((F[0][1] % mod * M[1][1] % mod) % mod)) %
         mod;
  ll z = (((F[1][0] % mod * M[0][0] % mod) % mod) +
          ((F[1][1] % mod * M[1][0] % mod) % mod)) %
         mod;
  ll w = (((F[1][0] % mod * M[0][1] % mod) % mod) +
          ((F[1][1] % mod * M[1][1] % mod) % mod)) %
         mod;
  F[0][0] = x, F[0][1] = y, F[1][0] = z, F[1][1] = w;
}

void power(ll matrix[2][2], ll n) {
  if (n == 0 || n == 1)
    return;
  ll res[2][2] = {{1, 1}, {1, 0}};
  power(matrix, n / 2);
  multiply(matrix, matrix);
  if (n & 1)
    multiply(matrix, res);
}

ll fib(ll n) {
  ll matrix[2][2] = {{1, 1}, {1, 0}};
  power(matrix, n - 1);
  return matrix[0][0];
}

int main() {
  // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  ll n;
  while (tc--) {
    cin >> n;
    ll v = powermod(2, n, mod);
    ll u = (v - fib(n + 1) % mod + mod) % mod;
    cout << u << " " << v << "\n";
    ll ans = (((u % mod) * powermod(v, mod - 2, mod)) % mod);
    cout << ans << "\n";
  }
  return 0;
}
