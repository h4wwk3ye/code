/*
                C++
                encoding:UTF-8
                Modified: <24/Feb/2019 01:10:50 PM>

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

int a[105], b[105], visited[105], n;

void dfs(int i) {
  visited[i] = 1;
  for (int k = 1; k <= n; k++) {
    if (!visited[k]) {
      if (a[i] > a[k] && a[i] < b[k])
        dfs(k);
      else if (b[i] > a[k] && b[i] < b[k])
        dfs(k);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  int t, x, y;
  while (tc--) {
    cin >> t >> x >> y;
    if (t == 1) {
      n++;
      a[n] = x;
      b[n] = y;
    } else {
      reset(visited, 0);
      dfs(x);

      if (visited[y] == 1)
        cout << "YES \n";
      else
        cout << "NO \n";
    }
  }
  return 0;
}
