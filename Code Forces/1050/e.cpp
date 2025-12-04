/*
                C++
                encoding: UTF-8
                Last Modified: 2025/09/13 11:24:09
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include "../prettyprint.hpp"
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
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        map<int, int> total_count;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total_count[a[i]]++;
        }
        
        bool possible = true;
        map<int, int> max_allowed;
        
        for (auto& [val, count] : total_count) {
            if (count % k != 0) {
                possible = false;
                break;
            }
            max_allowed[val] = count / k;
        }
        
        if (!possible) {
            print(0);
            continue;
        }
        
        int awesome_count = 0;
        
        map<int, int> window;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            window[a[right]]++;
            
            while (window[a[right]] > max_allowed[a[right]]) {
                window[a[left]]--;
                left++;
            }
            
            awesome_count += right - left + 1;
        }
        
        print(awesome_count);
    }
    return 0;
}
