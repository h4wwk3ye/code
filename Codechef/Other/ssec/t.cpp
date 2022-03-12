
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;


template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

vector< string > subs;

void printAllSubstrings (string s, int n) {
	/*
	 * Fix start index in outer loop.
	 * Reveal new character in inner loop till end of string.
	 * Print till-now-formed string.
	 */
	for (int i = 0; i < n; i++) {
		string tmp;
		int tempindex = 0;
		for (int j = i; j < n; j++) {
			tmp += s[j];
			subs.push_back (tmp);
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	printAllSubstrings (s, s.size ());
	sort (subs.begin (), subs.end ());
	string t;
	int l = 0;
	for (auto& i : subs) {
		t += i;
		if (l + i.size () >= k) {
			break;
		}
		l += i.size ();
	}
	cout << t[k - 1];
	return 0;
}
