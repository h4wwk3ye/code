/*
                C++
                encoding:UTF-8
                Modified: <22/Feb/2019 11:19:30 AM>

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

struct str {
  string x;
  str *point;
  str *en;
  int sz;
  str *prev;
};

/*bool palindrome(string s) {
  int n = s.size();
  int m = n / 2;
  int j = n - 1, i;
  for (i = 0; i < m; i++) {
    if (s[i] != s[j])
      return false;
    j--;
  }
  if (i == m)
    return true;
}*/

bool ispalindrome(str &st) {
  cout << "yes \n";
  int n = st.sz;
  int m = n / 2;
  auto curr = st.en;
  int j = curr->sz - 1, i;
  // auto other = st.point;
  for (int i = 0; i < m; i++) {
    if (j == 0) {
      j = (curr->prev)->sz - 1;
      curr = curr->prev;
    }
    if (st.x[i] != st.x[j])
      return false;
    j--;
    {
      if (i == st.x.size()) {
        st = st.point;
      }
    }
  }
  if (i == m)
    return true;
}

int main() {
  // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  str arr[n + 1];
  string s;
  int p = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    arr[i].x = s;
    arr[i].point = NULL;
    arr[i].prev = NULL;
    arr[i].en = &arr[i];
    arr[i].sz = s.size();
  }
  int t, a, b;
  for (int i = 0; i < q; i++) {

    cin >> t >> a >> b;
    if (t == 1) {
      a = (a ^ p);
      b = (b ^ p);
      arr[b].prev = arr[a].en;
      arr[a].en->point = &arr[b];
      arr[a].sz += arr[b].sz;

      if (ispalindrome(arr[a])) {
        p++;
      }
      // cout << "yes";
      if (ispalindrome(arr[b]))
        p--;
      // cout << "yes \n";

    } else if (t == 2) {
      string c;
      cin >> c;
      a = (a ^ p);
      int _p = p;
      if (ispalindrome(arr[a]))
        _p--;

      b = (b ^ p);
      arr[a].sz++;

      if (b == (arr[a].sz) + 1)
        (arr[a].en)->x.append(c);
      else {
        b--;
        auto curr = &arr[a];
        int cnt = curr->x.size();
        while (cnt < b) {
          curr = (curr->point);
          cnt += curr->x.size();
        }
        cnt -= curr->x.size();
        b -= cnt;
        (curr->x).insert(b, c);

        p = _p;
        if (ispalindrome(arr[a]))
          p++;
      }
    }
  }
  return 0;
}
