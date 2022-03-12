/*
				C++
				encoding:UTF-8
				Modified: <27/May/2019 11:32:36 PM>

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

int n;
const int N = 3e5 + 5;
pii t[N];
int parent[N];
map< pii, int > mp;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 1, n + 1) cin >> t[i].ff;
	fr (i, 1, n + 1) cin >> t[i].ss;
	fr (i, 1, n + 1) {
		mp[{t[i].ff, t[i].ss}] = i;
	}
	sort (t + 1, t + n + 1);
	map< int, int > s;
	s[t[1].ss] = 1;
	fr (i, 2, n + 1) {
		auto it = s.lower_bound (t[i].ss);
		parent[mp[{t[i].ff, t[i].ss}]] = mp[{t[it->ss].ff, t[it->ss].ss}];
		s[t[i].ss] = i;
	}
	fr (i, 1, n + 1) cout << parent[i] << " ";
	return 0;
}
