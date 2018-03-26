#include <iostream>
#include<cstring>
using namespace std;
int n,q,d,m;
long long int nums[205],memo[205][205][15];;

int divi(int sum, int i, int cm)
{
	if(cm==m)
	{
		if(sum==0)
		return 1;
		else
		return 0;
	}

	if(i==n)
		return 0;
	if(memo[i][sum][cm] != -1)
		return memo[i][sum][cm];
	return memo[i][sum][cm]=divi(sum%d,i+1,cm)+divi((sum+nums[i])%d,i+1,cm+1);
}

int main() {
	int j=1;
	cin>>n>>q;
	while(n!=0 && q!=0)
	{
		for(int i=0;i<n;i++)
			cin>>nums[i];
		cout<<"SET "<<j<<":\n";
		for(int i=0;i<q;i++){
			cin>>d;
			cin>>m;
			memset(memo, -1, sizeof(memo));
			cout<<"QUERY "<<i+1<<": "<<divi(0,0,0)<<"\n";
		}
	cin>>n>>q;
	j++;
	}
	return 0;
}
