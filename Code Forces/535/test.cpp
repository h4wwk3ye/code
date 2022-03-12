#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i, k, n) for (ll i = k; i < n; ++i)
#define all(c) (c).begin(), (c).end()
#define test()                                                                 \
  ll t;                                                                        \
  cin >> t;                                                                    \
  while (t--)
#define debug(x) cout << (#x) << " is " << (x) << endl
#define IOS                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0)
const ll MOD = 1e9 + 7;
const ll MAX = 1e6;

// POWER FUNCTION
ll power(ll a, ll b, ll m) {
  ll r = 1;
  while (b) {
    if (b % 2 == 1)
      r = (r * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return r;
}

// SOLVE
void solve() {
  int n;
  cin >> n;
  map<int, int> mvp;
  rep(i, 0, n) {
    int x;
    cin >> x;
    mvp[x]++;
  }
  auto it = mvp.end();
  it--;
  int x = it->ff;
  //     debug(x);
  for (auto tt : mvp) {
    if (x % tt.ff == 0) {
      int aa = tt.ff;
      mvp[aa]--;
    }
  }
  //     for(auto tt:mvp)cout<<tt.ff<<" "<<tt.ss<<endl;
  int y = 1;
  for (auto tt : mvp) {
    if (tt.ss > 0) {
      y = tt.ff;
    }
  }
  cout << x << " " << y;
}

// MAIN PROGRAM
int main() {
  IOS;
  //    test()
  solve();
  return 0;
}
