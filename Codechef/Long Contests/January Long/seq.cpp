/*
                C++
                encoding:UTF-8
                Modified: <12/Jan/2019 10:07:57 PM>

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

std::vector<ll> primes;
std::vector<ll> ans(50006);

void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p])
      primes.push_back(p);
}
void precompute() {
  map<ll, map<ll, ll>> check;
  ans[0] = 6;
  ans[1] = 10;
  check[0][1] = 1;
  check[0][2] = 1;
  check[1][0] = 1;
  check[2][0] = 1;
  ll prev = 2;
  for (size_t i = 2; i < 50005; i++) {
    ll key = -1;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  SieveOfEratosthenes(1000001);
  precompute();
  return 0;
}
