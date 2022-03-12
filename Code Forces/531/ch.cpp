#include <bits/stdc++.h>
using namespace std;
/* Written by Nishant Mittal aka nishantwrp */
#define modnum 1000000007
#define mp make_pair
#define pb push_back
#define sl(a) (int)a.length()
#define sz(a) (int)a.size()
#define lcase(a) (char)tolower(a)
#define ucase(a) (char)toupper(a)
#define precise(a) fixed << setprecision(a) <<
#define F first
#define S second
#define pii pair<int, int>
#define time                                                                   \
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define lldmark                                                                \
  cout << "Long Long Int ..................................... Long Long "     \
          "Int\n";
int k;
int nextcolor(int a) {
  if (a == k) {
    return 1;
  } else {
    return a + 1;
  }
}
int main() {
  int n;
  cin >> n >> k;
  vector<int> data;
  set<int> check;
  map<int, int> solve;
  map<int, int> cnt;
  int maxa = 0;
  int i = 0;
  while (i < n) {
    int tmp;
    cin >> tmp;
    data.pb(tmp);
    check.insert(tmp);
    cnt[tmp]++;
    if (cnt[tmp] > maxa) {
      maxa = cnt[tmp];
    }
    i++;
  }
  /*set <int>:: iterator abc = check.begin();
  int vis=0;
  while(vis < sz(check) && vis < k) {
      solve[*abc] = vis;
      abc++;
      vis++;
  }*/
  set<int> testcolour[5001];
  if (sz(data) >= k && maxa <= k) {
    cout << "YES" << endl;
    int ana = 0;
    while (ana < k) {
      solve[data[ana]] = ana + 1;
      testcolour[data[ana]].insert(ana + 1);
      cout << ana + 1 << " ";
      ana++;
    }
    int j = ana;
    while (j < sz(data)) {
      solve[data[j]] = nextcolor(solve[data[j]]);
      while (testcolour[data[j]].count(solve[data[j]]) != 0) {
        solve[data[j]] = nextcolor(solve[data[j]]);
      }
      cout << solve[data[j]] << " ";
      j++;
    }
  } else {
    cout << "NO";
  }
  return 0;
}
