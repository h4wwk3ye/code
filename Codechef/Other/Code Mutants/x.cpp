/*
                C++
                encoding:UTF-8
                Modified: <28/Feb/2019 01:09:30 AM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define ve vector
#define reset(a, b) memset(a, b, sizeof(a));
#define pb push_back

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  string f, s;
  cin >> f;
  cin >> s;
  int a, b, c, d, cost = 0;
  int u = 0;
  cin >> a >> b >> c >> d;
  for (int i = 0; i < n; i++) {
    if (f[i] == s[i])
      continue;
    if ((f[i] == '1' or f[i] == '2') and (s[i] == '1' or s[i] == '2'))
      cost += min(d, a);
    else if ((f[i] == '3' or f[i] == '2') and (s[i] == '3' or s[i] == '2'))
      cost += min(d, b);
    else if ((f[i] == '1' or f[i] == '3') and (s[i] == '1' or s[i] == '3'))
      cost += min(d, c);
  }
  cout << cost << "\n";
  return 0;
}
