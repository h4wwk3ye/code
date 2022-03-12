/*
				C++
				encoding: UTF-8
				Modified: <30/Jul/2019 11:47:32 AM>

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

#include <ext/pb_ds/assoc_container.hpp> // Common file
using namespace __gnu_pbds;
typedef cc_hash_table< int, int, hash< int > > ht;

int block_size;

bool cmp (const ve< int >& x, const ve< int >& y) {
	if (x[0] / block_size != y[0] / block_size) return x[0] < y[0];
	return x[1] < y[1];
}

struct Trie {
	Trie* children[2];
	Trie* parent;
	int val;
	Trie () {
		this->children[0] = this->children[1] = nullptr;
		this->val = 0;
	}
};

void insert (Trie* node, int& value) {
	dfr (bit, 30, -1) {
		int curr_bit = (value >> bit) & 1;
		if (node->children[curr_bit] == nullptr) node->children[curr_bit] = new Trie ();
		node->children[curr_bit]->parent = node;
		node = node->children[curr_bit];
		if (bit == 0) node->val = value;
	}
}

void del (Trie* node, int& value) {
	dfr (bit, 30, -1) {
		int curr_bit = (value >> bit) & 1;
		node = node->children[curr_bit];
	}
	fr (bit, 0, 31) {
		int curr_bit = (value >> bit) & 1;
		node = node->parent;
		if (node->children[1 ^ curr_bit] != nullptr) {
			Trie* tmp = node->children[curr_bit];
			node->children[curr_bit]->parent = nullptr;
			node->children[curr_bit] = nullptr;
			delete tmp;
			return;
		}
		Trie* tmp = node->children[curr_bit];
		delete tmp;
	}
}

int get_min (Trie* node, int& x) {
	dfr (bit, 30, -1) {
		int curr_bit = (x >> bit) & 1;
		if (node->children[curr_bit] != nullptr) {
			node = node->children[curr_bit];
		} else {
			curr_bit = 1 ^ curr_bit;
			node = node->children[curr_bit];
		}
		if (bit == 0) return node->val;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	// freopen ("inp.txt", "r", stdin);
	int n;
	cin >> n;
	int arr[n + 1], counter[n + 1], mo_left = 1, mo_right = 0;
	block_size = sqrt (n);
	int cnt = 0;

	unordered_map< int, int > mp;
	// ht mp;

	fr (i, 1, n + 1) {
		cin >> arr[i];
		if (mp.find (arr[i]) == mp.end ()) {
			cnt++;
			mp[arr[i]] = cnt;
		}
		counter[i] = 0;
	}

	int q;
	cin >> q;
	ve< int > queries[q];
	pii answer[q];
	fr (i, 0, q) {
		int l, r, x;
		cin >> l >> r >> x;
		queries[i] = {l, r, x, i};
	}
	sort (queries, queries + q, cmp);

	Trie* root = new Trie ();
	for (auto query : queries) {
		int &l = query[0], &r = query[1], &x = query[2], &idx = query[3];
		while (mo_right != r) {
			if (mo_right > r) {
				int& num = mp[arr[mo_right]];
				counter[num]--;
				if (counter[num] == 0) {
					del (root, arr[mo_right]);
				}
				mo_right--;
			} else {
				mo_right++;
				int& num = mp[arr[mo_right]];
				counter[num]++;
				if (counter[num] == 1) {
					insert (root, arr[mo_right]);
				}
			}
		}
		while (mo_left != l) {
			if (mo_left < l) {
				int& num = mp[arr[mo_left]];
				counter[num]--;
				if (counter[num] == 0) {
					del (root, arr[mo_left]);
				}
				mo_left++;
			} else {
				mo_left--;
				int& num = mp[arr[mo_left]];
				counter[num]++;
				if (counter[num] == 1) {
					insert (root, arr[mo_left]);
				}
			}
		}
		int ans = get_min (root, x);
		answer[idx] = {ans, counter[mp[ans]]};
	}

	fr (i, 0, q) pr (answer[i].ff, answer[i].ss);

	return 0;
}
