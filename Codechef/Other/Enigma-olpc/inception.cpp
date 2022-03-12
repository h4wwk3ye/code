/*
				C++
				encoding: UTF-8
				Modified: <12/Oct/2019 09:56:38 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

// https://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/

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

// A C++ program to check if a string is 'n' times
// repetition of one of its substrings

void computeLPSArray (string str, int M, int lps[]) {
	int len = 0; // lenght of the previous longest prefix suffix
	int i;

	lps[0] = 0; // lps[0] is always 0
	i = 1;

	// the loop calculates lps[i] for i = 1 to M-1
	while (i < M) {
		if (str[i] == str[len]) {
			len++;
			lps[i] = len;
			i++;
		} else // (pat[i] != pat[len])
		{
			if (len != 0) {
				// This is tricky. Consider the example AAACAAAA
				// and i = 7.
				len = lps[len - 1];

				// Also, note that we do not increment i here
			} else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Returns true if str is repetition of one of its substrings
// else return false.
int isRepeat (string str) {
	// Find length of string and create an array to
	// store lps values used in KMP
	int n = str.size ();
	int lps[n];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray (str, n, lps);

	// Find length of longest suffix which is also
	// prefix of str.
	int len = lps[n - 1];

	// If there exist a suffix which is also prefix AND
	// Length of the remaining substring divides total
	// length, then str[0..n-len-1] is the substring that
	// repeats n/(n-len) times (Readers can print substring
	// and value of n/(n-len) for more clarity.

	fr (i, 0, n) {
		cout << lps[i] << " ";
	}
	cout << endl;

	int ans = lps[n - 1];
	dfr (i, n - 1, -1) {
		if (lps[i] == 1 and ans == 1) {
			return i;
		}
		if (lps[i] == ans) {
			ans--;
		} else
			return n;
	}
	return n;
	// return (len > 0 && n % (n - len) == 0) ? true : false;
}


signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);

	string s;
	cin >> s;
	int i = (isRepeat (s));
	int j = i;
	while (i < s.size ()) {
		cout << i << " ";
		i += j;
	}
	cout << s.size () << "\n";
	return 0;
}
