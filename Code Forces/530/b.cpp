/*
                C++
                encoding:UTF-8
                Modified: <05/Jan/2019 10:48:50 PM>

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
#define len(v) v.length()
#define reset(a, b) memset(a, b, sizeof(a));

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

  /*ll n;
  cin >> n;*/
  ll n = pow(10, 9);
  if (n == 1) {
    cout << 2;
    return 0;
  }
  ll ans = 100000000;
  for (ll i = 1; i < n + 1; i++) {
    ll x = ceil(double(n) / i) + i;
    ans = min(ans, x);
  }
  cout << ans << "\n";
  return 0;
}
