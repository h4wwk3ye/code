/*
				C++
				encoding:UTF-8
				Modified: <07/Jun/2019 07:48:45 PM>

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
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

// clang-format on

int n;
const int N = 2e5 + 5;
ve< int > a (N), b (2 * N);

int f () {
	int ans = 0;
	fr (i, 1, n + 1) {
		if (b[i]) {
			ans = max (ans, i - b[i] + 1);
		}
	}
	return ans + n;
}

int s () {
	set< int > s;
	fr (i, 1, n + 1) if (a[i]) s.insert (a[i]);
	int i = 1, ans = 0;
	while (!s.empty () and ans < n) {
		b[i + n] = *s.begin ();
		s.erase (s.begin ());
		if (b[i]) s.insert (b[i]);
		i++;
		ans++;
	}
	fr (j, 1, n + 1) {
		if (b[i + j - 1] != j) return 2e9;
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 1, n + 1) cin >> a[i];
	fr (i, 1, n + 1) cin >> b[i];
	pr1 (min (f (), s ()));
	return 0;
}
