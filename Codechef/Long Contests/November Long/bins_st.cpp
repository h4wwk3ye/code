#include<bits/stdc++.h>

#define ull unsigned long long int

using namespace std;
int main()
{

	int n,q;
	cin>>n>>q;
	string str;
	ull binary[n];
	for(int i=0;i<n;i++)
	{
	 cin>>str;
	 binary[i]=stoull(str, 0, 2);
	}
	for(int i=0;i<q;i++)
	{
		int l,r;
		string x;
		cin>>l>>r>>x;
		ull X=stoull(x, 0, 2);
		ull maximum=0,index=l-1;
		for(ull j=l-1;j<r;j++)
		{
			ull _xor=X^binary[j];
			if(maximum<_xor)
			{
			    maximum=_xor;
			    index=j;
            }
		}
		cout<<index+1<<endl;
	}
	return 0;
}
