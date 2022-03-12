/*
				C++
				encoding: UTF-8
				Modified: <03/Oct/2019 02:08:21 PM>

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

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 (v.size())
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
const int N = 1e5 + 5;
int n, q;
string arr[N];

struct Trie {
	Trie* child[26];
	int cnt, l;
	int mn, mx;
	Trie () {
		fr (i, 0, 26) this->child[i] = nullptr;
		cnt = 0;
		l = 0;
		mn = -1;
		mx = -1;
	}
};

int cmp_mn (string& x, string& y) {
	int n = len (x);
	int m = len (y);
	fr (i, 0, min (n, m)) {
		if (x[i] < y[i])
			return 1;
		else if (y[i] < x[i])
			return 0;
	}
	if (n > m) return 0;
	return 1;
}

int cmp_mx (string& x, string& y) {
	int n = len (x);
	int m = len (y);
	fr (i, 0, min (n, m)) {
		if (x[i] < y[i])
			return 0;
		else if (y[i] < x[i])
			return 1;
	}
	if (n > m) return 1;
	return 0;
}

void insert (Trie* root, string& s, int idx) {
	Trie* node = root;
	int x = len (s);
	for (auto i : s) {
		if (node->child[i - 'a'] == nullptr) {
			node->child[i - 'a'] = new Trie ();
		}
		node = node->child[i - 'a'];
		if (node->mn == -1) {
			node->mn = idx;
		} else {
			int c = cmp_mn (s, arr[node->mn]);
			if (c == 1) node->mn = idx;
		}
		if (node->mx == -1) {
			node->mx = idx;
		} else {
			int c = cmp_mx (s, arr[node->mx]);
			if (c == 1) node->mx = idx;
		}
		x--;
		node->cnt += x;
		// node->l++;
	}
}

void query (Trie* root, string& s) {
	Trie* node = root;
	for (auto i : s) {
		if (node->child[i - 'a'] == nullptr) {
			pr (-1);
			return;
		}
		node = node->child[i - 'a'];
	}
	pr (node->cnt, arr[node->mn], arr[node->mx]);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	Trie* root = new Trie ();

	fr (i, 1, n + 1) {
		cin >> arr[i];
		insert (root, arr[i], i);
	}
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		query (root, s);
	}

	return 0;
}
