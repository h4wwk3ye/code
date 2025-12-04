/*
                C++
                encoding: UTF-8
                Last Modified: 10/May/24 09:40:05 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
    cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
    cout << t << ' ';
    print (u, args...);
}

int32_t main () {
    ios_base::sync_with_stdio (false), cin.tie (nullptr);
    int tc;
    cin >> tc;
    while (tc--){
        string s;
        cin >> s;
        string c = s;
        sort(c.begin(), c.end());
        if (c != s) {
            print("YES");
            print(c);
            continue;
        }
        reverse(c.begin(), c.end());
        if (c != s) {
            print("YES");
            print(c);
            continue;
        }
        print("NO");
    }
    return 0;
}