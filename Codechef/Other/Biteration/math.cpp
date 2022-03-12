/*
				C++
				encoding:UTF-8
				Modified: <17/Mar/2019 10:36:34 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>
using namespace std;

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           for (size_t i = s ; i < n ; i++) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (size_t i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (size_t i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}



const int N = 1e7;
int lp[N+1];
vector<int> pr;

void sieve(){
    for (int i=2; i<=N; ++i) {
    	if (lp[i] == 0) {
    		lp[i] = i;
    		pr.push_back (i);
    	}
    	for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j){
    		lp[i * pr[j]] = pr[j];
        }
    }
}


const int MAXN=1e6+5;

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve_o()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

set<ll> getFactorization(int x, set<ll> ret)
{
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
        if (len(ret)>2)
            break;
    }
    return ret;
}


int main() {
    //ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();


    sieve();
    sieve_o();
    int tc; cin >> tc;
    while(tc--){
        ll n;
        cin>>n;
        while (1){
            if (n<=1){
                pr1(-1);
                break;
            }
            set<ll> s;
            fr(i,0,len(pr)){
                if (n%pr[i]==0){
                    s.insert(pr[i]);
                    n/=pr[i];
                    break;
                }
            }
            getFactorization(n, s);
            if (len(s)==2){
                pr1(n);
                break;
            }
            n--;
        }
    }


    end = chrono::high_resolution_clock::now();
    ll elapsed_time = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << "\nElapsed Time: " << elapsed_time << "ms\n";

    return 0;
}
