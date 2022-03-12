/*
                C++
                encoding:UTF-8
                Modified: <08/Feb/2019 03:57:21 PM>

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

ll gcd(ll a, ll b);

// To compute x raised to power y under modulo m
ll power(ll x, ll y, ll m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m) {
  ll g = gcd(a, m);
  // If a and m are relatively prime, then modulo inverse
  // is a^(m-2) mode m
  return power(a, m - 2, m);
}

// To compute x^y under modulo m
ll power(ll x, ll y, ll m) {
  if (y == 0)
    return 1;
  ll p = power(x, y / 2, m) % m;
  p = (p * p) % m;

  return (y % 2 == 0) ? p : (x * p) % m;
}

// Function to return gcd of a and b
ll gcd(ll a, ll b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
// Driver program to test above function
const int N = 1e5 + 5;
ll arr[N];

void precompute() {
  arr[1] = 1;
  for (ll i = 2; i <= N - 2; i++)
    arr[i] = ((i % mod) * modInverse(arr[i - 1], mod)) % mod;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  precompute();
  ll t;
  cin >> t;
  ll n;
  while (t--) {
    cin >> n;
    cout << arr[n] << "\n";
  }
  return 0;
}
