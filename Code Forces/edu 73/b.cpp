/*
				C++
				encoding: UTF-8
				Modified: <20/Sep/2019 09:59:23 AM>

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
ve< ve< int > > arr;
int n;

bool chk (int i, int j) {
	return (i >= 1 and i <= n and j >= 1 and j <= n);
}

ve< pii > neighbours (int i, int j) {
	ve< pii > ne = {{i - 1, j - 2},
					{i - 1, j + 2},
					{i + 1, j + 2},
					{i + 1, j - 2},
					{i + 2, j + 1},
					{i + 2, j - 1},
					{i - 2, j + 1},
					{i - 2, j - 1}};
	return ne;
}

void solve (int i, int j, int f) {
	if (arr[i][j] != -1) return;
	arr[i][j] = f;
	for (auto p : neighbours (i, j)) {
		if (chk (p.ff, p.ss)) {
			solve (p.ff, p.ss, 1 ^ f);
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	arr.resize (n + 1, ve< int > (n + 1, -1));

	fr (i, 1, n + 1) {
		fr (j, 1, n + 1) {
			if (arr[i][j] == -1) {
				solve (i, j, 0);
			}
		}
	}
	fr (i, 1, n + 1) {
		fr (j, 1, n + 1) {
			if (arr[i][j] == 1) {
				cout << "W";
			} else {
				cout << "B";
			}
		}
		cout << endl;
	}
	return 0;
}
