// https://www.geeksforgeeks.org/primality-test-set-4-solovay-strassen/
#pragma GCC optimize("-O3")
/*
                C++
                encoding: UTF-8
                Last Modified: 30/Oct/19 08:27:48 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N=1e5+5;
int arr[N];
int n;

// C++ program to implement Solovay-Strassen 
// Primality Test 


// modulo function to perform binary exponentiation 
long long modulo(long long base, long long exponent, 
									long long mod) 
{ 
	long long x = 1; 
	long long y = base; 
	while (exponent > 0) 
	{ 
		if (exponent % 2 == 1) 
			x = (x * y) % mod; 

		y = (y * y) % mod; 
		exponent = exponent / 2; 
	} 

	return x % mod; 
} 

// To calculate Jacobian symbol of a given number 
int calculateJacobian(long long a, long long n) 
{ 
	if (!a) 
		return 0;// (0/n) = 0 

	int ans = 1; 
	if (a < 0) 
	{ 
		a = -a; // (a/n) = (-a/n)*(-1/n) 
		if (n % 4 == 3) 
			ans = -ans; // (-1/n) = -1 if n = 3 (mod 4) 
	} 

	if (a == 1) 
		return ans;// (1/n) = 1 

	while (a) 
	{ 
		if (a < 0) 
		{ 
			a = -a;// (a/n) = (-a/n)*(-1/n) 
			if (n % 4 == 3) 
				ans = -ans;// (-1/n) = -1 if n = 3 (mod 4) 
		} 

		while (a % 2 == 0) 
		{ 
			a = a / 2; 
			if (n % 8 == 3 || n % 8 == 5) 
				ans = -ans; 

		} 

		swap(a, n); 

		if (a % 4 == 3 && n % 4 == 3) 
			ans = -ans; 
		a = a % n; 

		if (a > n / 2) 
			a = a - n; 

	} 

	if (n == 1) 
		return ans; 

	return 0; 
} 

// To perform the Solovay-Strassen Primality Test 
bool solovoyStrassen(long long p, int iterations) 
{ 
	if (p < 2) 
		return false; 
	if (p != 2 && p % 2 == 0) 
		return false; 

	for (int i = 0; i < iterations; i++) 
	{ 
		// Generate a random number a 
		long long a = rand() % (p - 1) + 1; 
		long long jacobian = (p + calculateJacobian(a, p)) % p; 
		long long mod = modulo(a, (p - 1) / 2, p); 

		if (!jacobian || mod != jacobian) 
			return false; 
	} 
	return true; 
} 

// Driver Code 
signed main() 
{ 
	cin>>n;
    fr(i, 0, n) cin>>arr[i];
    int f = 0, s = 0;
    int c1 = 0, c2 = 0;
    fr(i, 0, n/2){
        if (solovoyStrassen(arr[i], 30)){
            //pr(arr[i], "first");
            c1++;
            if (!f){
                f = arr[i];
            }
        }
    }
    fr(i, n/2, n){
        if (solovoyStrassen(arr[i], 30)){
            //pr(arr[i], "second");
            c2++;
            s = arr[i];
        }
    }
    //pr(c1, c2, f, s);
    if (c1==c2 and f > s){
        pr("PERFECT");
    }else{
        pr("IMPERFECT");
    }
	return 0; 
} 
