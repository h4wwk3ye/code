/*
                C++
                encoding:UTF-8
                Modified: <28/Feb/2019 08:36:05 PM>

                ✪ H4WK3yE乡
                Mohd. Farhan Tahir
                Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define sum(v) accumulate(v.begin(), v.end(), 0);
#define ve vector
#define reset(a, b) memset(a, b, sizeof(a));
#define pb push_back

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  int arr[n + 1];
  int prefix[n + 1] = {0};

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    prefix[i] = (prefix[i - 1] + arr[i]);
  }
  int x;

  for (int i = 0; i < q; i++) {
    cin >> x;
    int low = 1, high = n;
    while (low < high) {
      int mid = (low + high) / 2;
      if (prefix[mid] >= x)
        high = mid;
      else
        low = mid + 1;
    }
    cout << low << "\n";
  }

  return 0;
}
