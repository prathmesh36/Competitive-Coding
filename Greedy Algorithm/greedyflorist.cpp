#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.rbegin(),v.rend());
	int mc=1;
	long int ans=0;
	for(int i=0;i<n;i=i+k)
	{
		for(int j=0;j<k;j++)
		{
			if(i+j<n)
			ans+=v[i+j]*mc;
		}
		mc++;
	}
	cout<<ans;
	return 0;
}
