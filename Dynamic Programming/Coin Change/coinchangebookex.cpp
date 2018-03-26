#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int coins[]={1,3,4,5};
int mincoins(int m, int v)
{
	int table[v+1];
	table[0]=0;
	for(int i=1;i<=v;i++)
		table[i]=INT_MAX;

	for(int i=1;i<=v;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(coins[j]<=i)
			{
				int subres=table[i-coins[j]];
				if(subres!=INT_MAX && subres+1<table[i])
				{
					table[i]=subres+1;
				}
			}
		}
	}
	return table[v];
}

int main() {

	int m=sizeof(coins)/sizeof(coins[0]);
	int v=7;
	printf("%d",mincoins(m,v));
	return 0;
}
