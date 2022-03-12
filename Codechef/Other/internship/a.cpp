#include <bits/stdc++.h>
using namespace std;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		sort (s.begin (), s.end ());
		cout << ((s == "CMP") ? "YES\n" : "NO\n");
	}
	return 0;
}