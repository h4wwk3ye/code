/*
				C++
				encoding: UTF-8
				Modified: <14/Sep/2019 08:55:16 PM>

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
int arr[N];
int tree[4 * N], tree1[4 * N];

void build (int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) >> 1;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);

	tree[node] = min (tree[2 * node], tree[2 * node + 1]);
}

int query (int node, int start, int end, int l, int r) {
	if (start > r or end < l) return 2e9 - 5;
	if (start >= l and end <= r) return tree[node];

	int mid = (start + end) >> 1;

	return min (query (2 * node, start, mid, l, r), query (2 * node + 1, mid + 1, end, l, r));
}

void build1 (int node, int start, int end) {
	if (start == end) {
		tree1[node] = arr[start];
		return;
	}

	int mid = (start + end) >> 1;
	build1 (2 * node, start, mid);
	build1 (2 * node + 1, mid + 1, end);

	tree1[node] = max (tree1[2 * node], tree1[2 * node + 1]);
}

int query1 (int node, int start, int end, int l, int r) {
	if (start > r or end < l) return -1;
	if (start >= l and end <= r) return tree1[node];

	int mid = (start + end) >> 1;

	return max (query1 (2 * node, start, mid, l, r), query1 (2 * node + 1, mid + 1, end, l, r));
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		fr (i, 0, 4 * n + 2) {
			tree[i] = 0;
			tree1[i] = 0;
		}
		string s;
		cin >> s;
		int mini = 1e9;
		fr (i, 1, n + 1) {
			int x = s[i - 1] - '0';
			arr[i] = x;
			mini = min (arr[i], mini);
		}
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		build (1, 1, n);
		build1 (1, 1, n);
		int idx = n;

		ve< int > chk (n + 1);
		int mx = -1;
		int fl = 0;
		int mn = -1;
		fr (i, 1, n) {
			if (fl) {
				chk[i] = 2;
				continue;
			}
			if (arr[i] < mx) {
				chk[i] = 1;
				mn = max (mn, arr[i]);
				continue;
			}
			mx = max (mx, arr[i]);
			int x = query (1, 1, n, i + 1, n);
			int y = query1 (1, 1, n, i + 1, n);


			if (x == arr[i] and y == arr[i]) {
				chk[i] = 2;
				fl = 1;
				continue;
			}
			if (x >= arr[i] and y > arr[i] and arr[i] == mx and arr[i] != mini) {
				chk[i] = 2;
				continue;
			}

			if (x < arr[i]) {
				chk[i] = 2;
			} else {
				chk[i] = 1;
				mn = max (mn, arr[i]);
			}
		}
		if (arr[n] >= mx) {
			chk[n] = 2;
		} else {
			chk[n] = 1;
		}
		ve< int > one, two, o, t;
		fr (i, 1, n + 1) {
			if (chk[i] == 1) {
				one.pb (arr[i]);
				o.pb (arr[i]);
			} else {
				two.pb (arr[i]);
				t.pb (arr[i]);
			}
		}
		// fr (i, 1, n + 1) cout << chk[i] << " ";
		// cout << endl;
		sort (all (one));
		sort (all (two));
		int f = 0;

		fr (i, 0, len (one)) {
			if (one[i] != o[i]) {
				f = 1;
			}
		}
		fr (i, 0, len (two)) {
			if (two[i] != t[i]) {
				f = 1;
			}
		}
		if (len (one) != 0 and len (two) != 0)
			if (one.back () > two[0]) f = 1;
		if (f) {
			pr ("-");
		} else {
			fr (i, 1, n + 1) cout << chk[i];
			cout << endl;
		}

		/*fr (i, 1, n + 1) cout << chk[i] << " ";
		cout << endl;*/
	}
	return 0;
}
