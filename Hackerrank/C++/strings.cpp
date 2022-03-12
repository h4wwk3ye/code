/*
                C++
                encoding:UTF-8
                Modified: <31/Dec/2018 09:51:26 AM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  std::string a, b;
  std::cin >> a >> b;
  ll x = a.length();
  ll y = b.length();
  std::cout << x << " " << y << '\n';
  std::string c = a + b;
  std::cout << c << '\n';
  char tmp = a[0];
  a[0] = b[0];
  b[0] = tmp;
  std::cout << a << " " << b << '\n';
  return 0;
}
