#include <iostream>
#include<cmath>
using namespace std;
long long int maxi=1000000007;
int main() {
	int a[10000000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long int sum=(a[0]*((int)pow(2.0, n)-1))%maxi;
	long long int prev=((int)pow(2.0, n)-1);
	sum=(sum+(a[n-1]*((int)pow(2.0, n)-1))%maxi)%maxi;
	for(int i=1;i<=n-2;i++)
	{
		sum=(sum+(a[i]*(prev+(int)pow(2.0,n-i-1)-(int)pow(2.0,i-1)))%maxi)%maxi;
		prev+=(int)pow(2.0,n-i-1)-(int)pow(2.0,i-1);
	}
	cout<<sum;
	return 0;
}
