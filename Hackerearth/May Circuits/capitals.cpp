/*
				C++
				encoding:UTF-8
				Modified: <27/May/2019 11:31:00 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, ll>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

ll n, k;
const ll N = 3e5 + 5;
pii arr[N];
umap< ll, ll > chk;
int org[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> k;
	ll total = 0;
	fr (i, 1, n + 1) {
		ll x;
		cin >> x;
		if (chk.find (x) == chk.end ()) {
			chk[x] = i;
		}
		arr[i] = {x, i};
		total += x;
		org[i] = x;
	}

	sort (arr + 1, arr + n + 1);


	/*fr (i, 1, n + 1) cout << arr[i].ff << " ";
	cout << endl;*/

	if (n == 1) {
		pr2 (1, k % 2);
		return 0;
	}
	if (n == 2) {
		if (arr[1].ff + k >= arr[2].ff) {
			k -= arr[2].ff - arr[1].ff;
			arr[2].ff = arr[1].ff;
			if (k % 2 == 0) {
				pr2 (1, 0);
			} else {
				pr2 (1, 1);
			}
		} else {
			arr[2].ff -= k;
			pr2 (1, arr[2].ff - arr[1].ff);
		}
		return 0;
	}

	ll ans = 0;
	ll tmp = k;
	ll ind = 0;
	ll posi = 0;
	fr (i, 1, n + 1) {
		ind = i;
		if (abs (arr[i].ff - org[1]) <= tmp) {
			tmp -= abs (arr[i].ff - org[1]);
		} else {
			if (arr[i].ff > org[1]) {
				ans += (arr[i].ff - tmp - org[1]);
				tmp = 0;
				break;
			} else {
				ans += (org[1] - arr[i].ff - tmp);
				tmp = 0;
				break;
			}
		}
	}
	fr (i, ind + 1, n + 1) {
		ans += abs (arr[i].ff - org[1]);
	}
	posi = 1;
	ans += tmp % 2;

	ll m2 = (1 + n) / 2;
	ll m1 = m2 - 1;
	ll m3 = m2 + 1;
	while (m1 > 1 and arr[m1].ff == arr[m2].ff)
		m1 -= 1;
	while (m3 < n and arr[m2].ff == arr[m3].ff)
		m3 += 1;
	ll m4 = 0;
	if (m1 > 1) {
		m4 = m1 - 1;
		while (m4 > 1 and arr[m4].ff == arr[m1].ff)
			m4--;
	}
	ll m5 = 0;
	if (m3 < n) {
		m5 = m3 + 1;
		while (m5 < n and arr[m5].ff == arr[m3].ff)
			m5++;
	}

	ll m6 = 0, m7 = 0;
	if (m4 > 1) {
		m6 = m4 - 1;
		while (m6 > 1 and arr[m6].ff == arr[m4].ff)
			m6--;
	}
	if (m5 < n) {
		m7 = m5 + 1;
		while (m7 < n and arr[m7].ff == arr[m5].ff)
			m7--;
	}

	ind = 0;
	tmp = k;
	ll curr = 0;
	fr (i, 1, n + 1) {
		ind = i;
		if (abs (arr[i].ff - arr[m2].ff) <= tmp) {
			tmp -= abs (arr[i].ff - arr[m2].ff);
		} else {
			if (arr[i].ff > arr[m2].ff) {
				curr += (arr[i].ff - tmp - arr[m2].ff);
				tmp = 0;
				break;
			} else {
				curr += (arr[m2].ff - arr[i].ff - tmp);
				tmp = 0;
				break;
			}
		}
	}
	fr (i, ind + 1, n + 1) {
		curr += abs (arr[i].ff - arr[m2].ff);
	}
	curr += tmp % 2;
	// pr1 (ans);
	if (curr < ans) {
		posi = chk[arr[m2].ff];
		ans = curr;
	}
	if (curr == ans) {
		if (chk[arr[m2].ff] < posi) {
			posi = chk[arr[m2].ff];
		}
	}

	tmp = k;
	ind = 0;
	curr = 0;
	fr (i, 1, n + 1) {
		ind = i;
		if (abs (arr[i].ff - arr[m1].ff) <= tmp) {
			tmp -= abs (arr[i].ff - arr[m1].ff);
		} else {
			if (arr[i] > arr[m1]) {
				curr += (arr[i].ff - tmp - arr[m1].ff);
				tmp = 0;
				break;
			} else {
				curr += (arr[m1].ff - arr[i].ff - tmp);
				tmp = 0;
				break;
			}
		}
	}
	fr (i, ind + 1, n + 1) {
		curr += abs (arr[i].ff - arr[m1].ff);
	}
	curr += tmp % 2;
	// pr1 (curr);
	if (curr < ans) {
		posi = chk[arr[m1].ff];
		ans = curr;
	}
	if (curr == ans) {
		if (chk[arr[m1].ff] < posi) {
			posi = chk[arr[m1].ff];
		}
	}

	tmp = k;
	ind = 0;
	curr = 0;
	fr (i, 1, n + 1) {
		ind = i;
		if (abs (arr[i].ff - arr[m3].ff) <= tmp) {
			tmp -= abs (arr[i].ff - arr[m3].ff);
		} else {
			if (arr[i].ff > arr[m3].ff) {
				curr += (arr[i].ff - tmp - arr[m3].ff);
				tmp = 0;
				break;
			} else {
				curr += (arr[m3].ff - arr[i].ff - tmp);
				tmp = 0;
				break;
			}
		}
	}
	fr (i, ind + 1, n + 1) {
		curr += abs (arr[i].ff - arr[m3].ff);
	}
	curr += tmp % 2;
	// pr1 (curr);
	if (curr < ans) {
		posi = chk[arr[m3].ff];
		ans = curr;
	}
	if (curr == ans) {
		if (chk[arr[m3].ff] < posi) {
			posi = chk[arr[m3].ff];
		}
	}


	if (m4 != 0) {
		tmp = k;
		ind = 0;
		curr = 0;
		fr (i, 1, n + 1) {
			ind = i;
			if (abs (arr[i].ff - arr[m4].ff) <= tmp) {
				tmp -= abs (arr[i].ff - arr[m4].ff);
			} else {
				if (arr[i].ff > arr[m4].ff) {
					curr += (arr[i].ff - tmp - arr[m4].ff);
					tmp = 0;
					break;
				} else {
					curr += (arr[m4].ff - arr[i].ff - tmp);
					tmp = 0;
					break;
				}
			}
		}
		fr (i, ind + 1, n + 1) {
			curr += abs (arr[i].ff - arr[m4].ff);
		}
		curr += tmp % 2;
		// pr1 (curr);
		if (curr < ans) {
			posi = chk[arr[m4].ff];
			ans = curr;
		}
		if (curr == ans) {
			if (chk[arr[m4].ff] < posi) {
				posi = chk[arr[m4].ff];
			}
		}
	}

	if (m5 != 0) {
		tmp = k;
		ind = 0;
		curr = 0;
		fr (i, 1, n + 1) {
			ind = i;
			if (abs (arr[i].ff - arr[m5].ff) <= tmp) {
				tmp -= abs (arr[i].ff - arr[m5].ff);
			} else {
				if (arr[i].ff > arr[m5].ff) {
					curr += (arr[i].ff - tmp - arr[m5].ff);
					tmp = 0;
					break;
				} else {
					curr += (arr[m5].ff - arr[i].ff - tmp);
					tmp = 0;
					break;
				}
			}
		}
		fr (i, ind + 1, n + 1) {
			curr += abs (arr[i].ff - arr[m5].ff);
		}
		curr += tmp % 2;
		// pr1 (curr);
		if (curr < ans) {
			posi = chk[arr[m5].ff];
			ans = curr;
		}
		if (curr == ans) {
			if (chk[arr[m5].ff] < posi) {
				posi = chk[arr[m5].ff];
			}
		}
	}

	if (m6 != 0) {
		tmp = k;
		ind = 0;
		curr = 0;
		fr (i, 1, n + 1) {
			ind = i;
			if (abs (arr[i].ff - arr[m6].ff) <= tmp) {
				tmp -= abs (arr[i].ff - arr[m6].ff);
			} else {
				if (arr[i].ff > arr[m6].ff) {
					curr += (arr[i].ff - tmp - arr[m6].ff);
					tmp = 0;
					break;
				} else {
					curr += (arr[m6].ff - arr[i].ff - tmp);
					tmp = 0;
					break;
				}
			}
		}
		fr (i, ind + 1, n + 1) {
			curr += abs (arr[i].ff - arr[m6].ff);
		}
		curr += tmp % 2;
		// pr1 (curr);
		if (curr < ans) {
			posi = chk[arr[m6].ff];
			ans = curr;
		}
		if (curr == ans) {
			if (chk[arr[m6].ff] < posi) {
				posi = chk[arr[m6].ff];
			}
		}
	}

	if (m7 != 0) {
		tmp = k;
		ind = 0;
		curr = 0;
		fr (i, 1, n + 1) {
			ind = i;
			if (abs (arr[i].ff - arr[m7].ff) <= tmp) {
				tmp -= abs (arr[i].ff - arr[m7].ff);
			} else {
				if (arr[i].ff > arr[m4].ff) {
					curr += (arr[i].ff - tmp - arr[m7].ff);
					tmp = 0;
					break;
				} else {
					curr += (arr[m7].ff - arr[i].ff - tmp);
					tmp = 0;
					break;
				}
			}
		}
		fr (i, ind + 1, n + 1) {
			curr += abs (arr[i].ff - arr[m7].ff);
		}
		curr += tmp % 2;
		// pr1 (curr);
		if (curr < ans) {
			posi = chk[arr[m7].ff];
			ans = curr;
		}
		if (curr == ans) {
			if (chk[arr[m7].ff] < posi) {
				posi = chk[arr[m7].ff];
			}
		}
	}

	pr2 (posi, ans);
	return 0;
}
