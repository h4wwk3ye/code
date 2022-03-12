/*
				C++
				encoding:UTF-8
				Modified: <24/May/2019 10:00:27 PM>

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
int x1, y1, x2, y2;
set< tuple< int, int, int > > s;
int ans;

bool check (int x, int y) {
	return (x <= x2 and y <= y2);
}

void solve (int x, int y, int c) {
	if (!check (x, y)) return;
	pr3 (x, y, c);
	if (x == x2 and y == y2) return;
	if (s.find (make_tuple (x, y, c)) != s.end ()) return;
	ans++;
	s.insert (make_tuple (x, y, c));
	solve (x + 1, y, c + 1);
	solve (x, y + 1, c + 1);
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	fr (t, 1, tc + 1) {
		cout << "Case " << t << ": ";
		cin >> x1 >> y1 >> x2 >> y2;
		if (x2 < x1 or y2 < y1) {
			pr1 (-1);
			continue;
		}
		s.clear ();
		ans = 0;
		solve (x1, y1, 0);
		pr1 (ans);
	}
	return 0;
}
