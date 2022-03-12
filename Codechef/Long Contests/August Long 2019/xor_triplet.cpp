/*
				C++
				encoding: UTF-8
				Modified: <16/Aug/2019 06:17:45 PM>

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
#define         mod                    1000000007
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

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

int n;
const int N = 1e5 + 5;
int arr[N];

struct Trie {
	Trie* children[2];
	int idx;
	int l;
	Trie () {
		this->children[0] = this->children[1] = nullptr;
		this->idx = 0;
		this->l = 0;
	}
};

void insert (Trie* node, int num, int i) {
	for (int bits = 30; bits >= 0; bits--) {
		int curr_bit = (num >> bits) & 1;
		if (node->children[curr_bit] == nullptr) {
			node->children[curr_bit] = new Trie ();
		}
		node = node->children[curr_bit];
		if (bits == 0) node->idx += i, node->l++;
	}
}

int query (Trie* node, int num, int i) {
	for (int bits = 30; bits >= 0; bits--) {
		int curr_bit = (num >> bits) & 1;
		if (node->children[curr_bit] == nullptr) {
			return 0;
		}
		node = node->children[curr_bit];
	}
	int sz = node->l;
	int ans = (sz * i) - node->idx;
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int curr = 0, ans = 0;
		Trie* root = new Trie ();
		fr (i, 1, n + 1) {
			int x;
			cin >> x;
			insert (root, curr, i);
			curr ^= x;
			ans += query (root, curr, i);
		}
		pr (ans);
	}
	return 0;
}
