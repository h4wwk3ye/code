/*
				C++
				encoding: UTF-8
				Modified: <06/Jul/2019 06:35:49 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

const int bits = 30;
const int N = 5e5 * bits;
int q, t[N][2], sz = 1;

void insert (int x) {
	int p = 0;
	dfr (i, bits - 1, -1) {
		if (t[p][x >> i & 1] == 0) {
			// If the ith bit of x is not set
			t[p][x >> i & 1] = sz;
			sz++;
		}
		p = t[p][x >> i & 1];
	}
}

int get (int x) {
	int ans = 0, p = 0;
	dfs (i, bits - 1, -1) {
		int curr_bit = x >> i & 1;
		if (t[p][curr_bit]) {
			p = t[p][curr_bit];
		} else {
			p = t[p][1 ^ curr_bit];
			ans
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	return 0;
}
