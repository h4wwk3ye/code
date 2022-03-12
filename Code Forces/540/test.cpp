#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll a[n + 1];
  ll sum = 0;
  ll so = 0;
  ll se = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll z = 1;
  ll count = 0;
  ll se1 = 0;
  ll so1 = 0;
  //  cout<<so<<" "<<se<<endl;
  for (ll i = 2; i <= n; i++) {
    if (i % 2 == 0)
      so += a[i];
    else
      se += a[i];
  }
  if (so == se)
    count++;
  // cout<<so<<" "<<se<<endl;
  ll temp1 = 0, temp2 = 0, temp = 0;
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) {
      temp1 += a[i - 1];
      so -= a[i];
    } else {
      temp2 += a[i - 1];
      se -= a[i];
    }

    if (temp1 + so == temp2 + se)
      count++;
  }
  cout << count << endl;

  return 0;
}
