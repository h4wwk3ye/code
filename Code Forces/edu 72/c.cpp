/*
				C++
				encoding: UTF-8
				Modified: <05/Sep/2019 10:16:42 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

const int N = 2e5 + 5;
string s;
string tree[4 * N];
int n;
int ans;

#define left 2 * node + 1
#define right left + 1


void build (int node = 1, int start = 0, int end = n - 1) {
	if (start == end) {
		tree[node] = s[start];

		if (s[start] == '1') {
			ans++;
			// pr (start, end, s[start - 1], s[start - 1] == '1', "here");
		}
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node] = tree[left];
	tree[node] += (tree[right]);
	ll val = bitset< 64 > (tree[node]).to_ullong ();
	if (val == (end - start + 1)) {
		ans++;
	}
}
string query (int l, int r, int node = 1, int start = 0, int end = n - 1) {
	if (start > end or end < l or start > r) return "";
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	string a = query (l, r, left, start, mid);
	a += query (l, r, right, mid + 1, end);
	return a;
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		ans = 0;
		cin >> s;
		n = len (s);
		fr (i, 0, 4 * n + 2) tree[i] = "";
		build ();
		fr (i, 0, n / 2) {
			fr (j, n / 2, n) {
				string x = query (i, j);
				ll val = bitset< 64 > (x).to_ullong ();
				if (val == (j - i + 1)) {
					pr (j, i, x);
					ans++;
				}
			}
		}
		pr (ans);
	}
	return 0;
}
