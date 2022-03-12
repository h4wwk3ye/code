/*
                C++
                encoding:UTF-8
                Modified: <20/Feb/2019 07:53:56 PM>

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

vector<int> factors[1005];
void prime_factors(int n, int index) {
  int i = 2;
  while (i * i <= n) {
    if (n % i)
      i++;
    else {
      n /= i;
      factors[index].pb(i);
    }
  }
  if (n > 1)
    factors[index].pb(n);
}

int main() {
  //  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int no[n];
  for (int i = 0; i < n; i++) {
    int le;
    cin >> le;
    int x;
    no[i] = 1;
    for (int j = 0; j < le; j++) {
      cin >> x;
      // cout << no[i] << " ";
      no[i] *= x;
    }
  }
  for (int i = 0; i < n; i++) {
    prime_factors(no[i], i);
  }
  unordered_map<int, vector<int>> counter;
  for (int i = 0; i < n; i++) {
    for (int j : factors[i])
      counter
  }

  return 0;
}
