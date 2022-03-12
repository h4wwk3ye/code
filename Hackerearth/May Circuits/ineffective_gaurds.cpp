/*
				C++
				encoding:UTF-8
				Modified: <30/May/2019 11:21:49 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

int n, m;
const int N = 2e5 + 5;
pii guard[N], jewel[N];
int p[N], cnt[N];

bool cmp (pii& a, pii& b) {
	return (a.ff + a.ss < b.ff + b.ss);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m;
	multimap< int, int > mp;
	fr (i, 1, n + 1) cin >> guard[i].ff >> guard[i].ss;
	sort (guard + 1, guard + n + 1, cmp);
	fr (i, 1, n + 1) {
		int x, y;
		x = guard[i].ff;
		y = guard[i].ss;
		mp.emplace (x + y, i);
	}

	unordered_set< int > s;
	s.reserve (n + 1);
	s.max_load_factor (0.25);
	fr (i, 1, m + 1) {
		int x, y;
		cin >> x >> y;
		jewel[i].ff = x;
		jewel[i].ss = y;
		auto it = mp.upper_bound (x + y);
		it--;
		int ind = it->ss;
		int curr = 0;
		int j;
		for (; ind >= 1; ind--) {
			if (y - x <= guard[ind].ss - guard[ind].ff) {
				j = ind;
				curr++;
				if (curr == 2) break;
			}
		}
		if (curr == 1) s.insert (j);
	}

	pr1 (n - len (s));
	return 0;
}
