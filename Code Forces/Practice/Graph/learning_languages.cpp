/*
				C++
				encoding:UTF-8
				Modified: <24/Mar/2019 03:07:37 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (int i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 105;
ve< int > lang[N];

int prnt[N], rnk[N];

void init () {
	fr (i, 0, N) {
		rnk[i] = 0;
		prnt[i] = i;
	}
}

int fnd (int x) {
	if (prnt[x] != x) {
		prnt[x] = fnd (prnt[x]);
	}
	return prnt[x];
}

void unon (int x, int y) {
	int x_id = fnd (x);
	int y_id = fnd (y);
	if (x_id == y_id) return;

	if (rnk[x_id] > rnk[y_id]) {
		prnt[y_id] = x_id;
	} else {
		prnt[x_id] = y_id;
		if (rnk[x_id] == rnk[y_id]) rnk[y_id]++;
	}
}

int main () {
	init ();
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, m;
	cin >> n >> m;

	fr (i, 1, n + 1) {
		int l;
		cin >> l;
		lang[i].resize (l);
		fr (j, 0, l) cin >> lang[i][j];
	}

	fr (i, 1, n + 1) {
		if (len (lang[i]) == 0) continue;
		int x = lang[i][0];
		fr (j, 1, len (lang[i])) {
			unon (x, lang[i][j]);
		}
	}

	umap< int, int > mp;
	int ans = -1;
	int none = 0;
	fr (i, 1, n + 1) {
		if (len (lang[i]) == 0) {
			none++;
			continue;
		}
		int x = fnd (lang[i][0]);
		if (mp.find (x) == mp.end ()) {
			ans++;
			mp[x] = 1;
		}
	}
	if (ans == -1) ans = 0;
	pr1 (ans + none);

	return 0;
}
