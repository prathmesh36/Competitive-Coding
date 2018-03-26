#include <iostream>
using namespace std;
int a[2001],lis[2001],lds[2001];
int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		lis[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{
			lis[i]=1;
			for(int j=i;j<n;j++)
			{
				if(a[i]<a[j])
				{
					lis[i]=max(lis[j]+1,lis[i]);
				}
			}
		}

		lds[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{
			lds[i]=1;
			for(int j=i;j<n;j++)
			{
				if(a[i]>a[j])
				{
					lds[i]=max(lds[j]+1,lds[i]);
				}
			}
		}

		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans=max(lis[i]+lds[i]-1,ans);
		}

		cout<<ans<<"\n";
	}
	return 0;
}
