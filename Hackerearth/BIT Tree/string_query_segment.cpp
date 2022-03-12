/*
				C++
				encoding: UTF-8
				Modified: <04/Oct/2019 03:48:21 PM>

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
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 2e5 + 5;
int arr[N], tree[4 * N][26];
string s;
int n;

#define left 2 * node
#define right left + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][arr[start]] = 1;
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	fr (i, 0, 26) {
		tree[node][i] = tree[left][i] + tree[right][i];
	}
}

void update (int idx, int val, int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][val] = 0;
		s[start - 1] = '#';
		return;
	}
	int mid = (start + end) >> 1;
	if (tree[left][val] >= idx) {
		update (idx, val, left, start, mid);
	} else {
		update (idx - tree[left][val], val, right, mid + 1, end);
	}
	fr (i, 0, 26) {
		tree[node][i] = tree[left][i] + tree[right][i];
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> s;
	n = len (s);
	fr (i, 1, n + 1) arr[i] = s[i - 1] - 'a';
	build ();
	int tc;
	cin >> tc;
	while (tc--) {
		int k;
		char x;
		cin >> k >> x;
		update (k, x - 'a');
	}
	for (auto i : s) {
		if (i != '#') cout << i;
	}
	cout << "\n";
	return 0;
}
