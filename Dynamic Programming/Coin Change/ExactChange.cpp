#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int coins[105];
int mincoins(int m, int v)
{
	int table[10010];
	table[0]=0;
	for(int i=1;i<=10010;i++)
		table[i]=INT_MAX;

	for(int i=0;i<m;i++)
	{
		for(int j=10000;j>=0;j--)
		{
			if(table[j]!=INT_MAX && coins[i]+j<=10000 && table[j+coins[i]]>table[j]+1)
				table[j+coins[i]]=table[j]+1;
		}
	}
	for(int i=v;i<=10000;i++)
	{
		if(table[i]!=INT_MAX)
		{
			cout<<i<<" ";
			return table[i];
		}
	}
}

int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
		int m;
		int v,max=0;
		cin>>v;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>coins[i];
		}
		printf("%d\n",mincoins(m,v));
	}
	return 0;
}
