//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Mar/20 11:34:07 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

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
int n, k;
int ans = 0;

ve<int> not_paired;

struct Trie {
	Trie* child[26];
	int cnt;
	int depth = 0;
	Trie () {
		fr (i, 0, 26) this->child[i] = nullptr;
		cnt = 0;
		depth = 0;
	}

};

void insert (Trie* root, string& s) {
		Trie* node = node;
		for (auto& i: s) {
			if (!node->child[i-'A']) {
				node->child[i-'A'] = new Trie();
				node->child[i-'A']->depth = 1 + node->depth;
			}
			node = node->child[i-'A'];
			node->cnt++;
			if (node->cnt==k) {
				ans+=node->depth;
				
			}
		}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	fr (i, 1, tc + 1) {
		cout << "Case #" << i << ": ";
		not_paired.clear();
		cin >> n >> k;
		ve< string > arr (n);
		fr (i, 0, n) {
			cin >> arr[i];
		}

		Trie* root = new Trie ();

		fr (i, 0, n) {
			insert(root, arr[i]);
		}
	}
	return 0;
}