#include <bits/stdc++.h>

using namespace std;

bool test;
int p, i;
long long l, r, d, x;
int main() {
  cin >> p;
  for (i = 0; i < p; ++i) {
    test = 1;
    cin >> l >> r >> d;
    x = d;
    if (d < l)
      cout << x << endl;
    else if (d > r)
      cout << x << endl;
    else {

      x += d * (r / d);
      cout << x << endl;
    }
  }
  return 0;
}
