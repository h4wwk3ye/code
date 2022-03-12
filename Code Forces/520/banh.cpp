#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ll n,q;
    cin>>n>>q;
    string arra;
    cin>>arra;
    char arr[n];
    strcpy(arr,arra.c_str());
    ll total[n];
    //cout<<arr[3]
    if (arr[0]=='1')
    {
        total[0]=1;
    }
    else
    {
        total[0]=0;
    }
    for (ll i=1;i<n;i++)
    {
        if (arr[i]=='1')
        {
            total[i]=total[i-1]+1;
        }
        else
        {
            total[i]=total[i-1];
        }
    }
    ll l,r;
    for (ll i=0;i<q;i++)
    {
        cin>>l>>r;
        l--;
        r--;
        ll ones=0;
        if(l==0)
        {
            ones=total[r];
        }
        else
        {
            ones=total[r]-total[l-1];
        }
        ll sum_1=0;
        if (ones>0)
        {
            sum_1=(pow(2,ones)-1);
        }
        ll zeroes=r-l+1-ones;
        ll sum_0=0;
        if (zeroes>0)
        {
            sum_0=((sum_1)*(pow(2,zeroes)-1));
        }
        ll ans=(sum_0+sum_1)%(mod);
        cout<<ans<<"\n";
    }
    return 0;
}
