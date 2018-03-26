#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int coins[10010];
pair<int,int> mincoins(int m, int v)
{
	int table[v+1];
	table[0]=0;
	for(int i=1;i<=v;i++)
		table[i]=100000000;
	int dif=10000;
	pair<int,int> books;
	for(int i=1;i<=v;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(coins[j]<=i)
			{
				int subres=table[i-coins[j]];
				if(i==v && subres==1)
				{
					int flag=0;
					table[i]=subres+1;
					if((i-coins[j])-coins[j]==0)
					{
						if(coins[j]!=coins[j+1]) flag=1;
					}
					if(dif>abs((i-coins[j])-coins[j]) && flag==0)
					{
						dif=abs((i-coins[j])-coins[j]);
						books=make_pair(coins[j],abs(i-coins[j]));
					}
				}
				else if(i!=v)
				{
					if(subres!=100000000 && subres+1<table[i])
					{
						table[i]=subres+1;
					}
				}
			}
		}
	}

	return books;
}

int main() {
	int nc;
	while(scanf("%d",&nc)==1)
	{
    	memset(coins, -1, sizeof coins);
		int v;
		for(int i=0;i<nc;i++)
		{
			cin>>coins[i];
		}
		sort(coins,coins+nc);
		cin>>v;
		pair<int,int> booko=mincoins(nc,v);
		if(booko.first<booko.second)
		cout<<"Peter should buy books whose prices are "<<booko.first<<" and "<<booko.second<<".\n\n";
		else
		cout<<"Peter should buy books whose prices are "<<booko.second<<" and "<<booko.first<<".\n\n";
	}
	return 0;
}
