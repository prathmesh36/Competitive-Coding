#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int n,i,j,k,l;
	cin>>n;
	long long int a[n][n];
	for(i=0;i<n;i++)for(j=0;j<n;j++)
	{
		cin>>a[i][j];
		if(i>0) a[i][j]+=a[i-1][j];
		if(j>0) a[i][j]+=a[i][j-1];
		if(j>0 && i>0) a[i][j]-=a[i-1][j-1];
	}
	long long int maxsum=-99999999999999;
	for(i=0;i<n;i++)for(j=0;j<n;j++)
	for(k=i;k<n;k++)for(l=j;l<n;l++)
	{
		long long int submaxsum=a[k][l];
		if(i>0)submaxsum-=a[i-1][l];
		if(j>0)submaxsum-=a[k][j-1];
		if(i>0 && j>0)submaxsum+=a[i-1][j-1];
		maxsum=max(maxsum,submaxsum);
	}
	cout<<maxsum<<"\n";
	return 0;
}
