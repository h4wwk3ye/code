#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define pr 62ll
ll a[55][55];
ll b[55][55] = {0};
int n, m;
bool check (int i, int j) {
	bool b = false;
	if (i - 1 >= 0 && j + 1 < m)
		if (a[i][j] && a[i - 1][j + 1] && a[i - 1][j] && a[i][j + 1]) b = true;
	if (i + 1 < n && j + 1 < m)
		if (a[i][j] && a[i + 1][j + 1] && a[i + 1][j] && a[i][j + 1]) b = true;
	if (i - 1 >= 0 && j - 1 >= 0)
		if (a[i][j] && a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1]) b = true;
	if (i + 1 < n && j - 1 >= 0)
		if (a[i][j] && a[i + 1][j - 1] && a[i + 1][j] && a[i][j - 1]) b = true;
	return b;
}
pair< int, int > check1 (int i, int j) {
	bool b = false;
	if (i - 1 >= 0 && j + 1 < m)
		if (a[i][j] && a[i - 1][j + 1] && a[i - 1][j] && a[i][j + 1])
			return make_pair (i - 1 + 1, j + 1);
	if (i + 1 < n && j + 1 < m)
		if (a[i][j] && a[i + 1][j + 1] && a[i + 1][j] && a[i][j + 1])
			return make_pair (i + 1, j + 1);
	if (i - 1 >= 0 && j - 1 >= 0)
		if (a[i][j] && a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1])
			return make_pair (i - 1 + 1, j - 1 + 1);
	if (i + 1 < n && j - 1 >= 0)
		if (a[i][j] && a[i + 1][j - 1] && a[i + 1][j] && a[i][j - 1])
			return make_pair (i + 1, j - 1 + 1);
	return make_pair (-1, -1);
}
int main () {
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j], b[i][j] = 0;
	bool c = true;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j]) c = check (i, j);
			if (c == false) break;
		}
		if (c == false) break;
	}
	if (c == false)
		cout << "-1" << endl;
	else {
		map< pair< int, int >, int > v;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (a[i][j]) v[check1 (i, j)] = 1;

		map< pair< int, int >, int >::iterator it;
		ll s = 0;
		for (it = v.begin (); it != v.end (); it++)
			if (it->second) s++;
		cout << s << endl;
		for (it = v.begin (); it != v.end (); it++)
			if (it->second) cout << it->first.first << " " << it->first.second << endl;
	}
	return 0;
}
