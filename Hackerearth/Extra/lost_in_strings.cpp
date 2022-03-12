/*
				C++
				encoding: UTF-8
				Modified: <14/Sep/2019 06:15:55 PM>

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

const int N = 3e5 + 5;
string s[N];

struct Trie {
	ve< int > val;
	Trie* children[26];
	Trie () {
		fr (i, 0, 26) this->children[i] = nullptr;
	}
};


void insert (Trie* root, string str, int idx) {
	Trie* node = root;
	for (auto i : str) {
		if (node->children[i - 'a'] == nullptr) node->children[i - 'a'] = new Trie ();
		node = node->children[i - 'a'];
		node->val.pb (idx);
	}
}

Trie* Node;

void query (Trie* root, string str) {
	Node = nullptr;
	Trie* node = root;
	for (auto i : str) {
		if (node->children[i - 'a'] == nullptr) {
			Node = nullptr;
			return;
		}
		node = node->children[i - 'a'];
		Node = node;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> s[1];

	Trie* root = new Trie ();
	insert (root, s[1], 1);

	int tc;
	cin >> tc;
	int idx = 1;
	while (tc--) {
		int t;
		cin >> t;

		if (t == 1) {
			idx++;
			int p, n;
			string c;
			cin >> p >> n >> c;
			string tmp = "";
			p--;
			int i = 0;
			while (p--) {
				tmp += s[n][i];
				i++;
			}
			tmp += c;
			insert (root, tmp, idx);
			s[idx] = tmp;
		} else if (t == 2) {
			idx++;
			int p, n;
			string tmp = "";
			cin >> p >> n;
			int i = 0;
			while (p--) {
				tmp += s[n][i];
				i++;
			}
			insert (root, tmp, idx);
			s[idx] = tmp;
		} else {
			int l, r;
			string c;
			cin >> l >> r >> c;
			query (root, c);
			if (Node == nullptr) {
				pr ("no");
			} else {
				auto x = lower_bound (all (Node->val), l);

				if (x == Node->val.end ()) {
					pr ("no");
					continue;
				}
				if (*x >= l and *x <= r) {
					pr ("yes");
				} else {
					pr ("no");
				}
			}
		}
	}
	return 0;
}
