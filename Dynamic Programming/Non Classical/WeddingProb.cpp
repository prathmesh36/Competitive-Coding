#include <iostream>
#include<cstring>
using namespace std;
int prize[25][25],memo[215][25],m,c;
int shop(int money, int g)
{
	if(money<0)
		return -1000000;
	if(g==c)
		return m-money;
	if(memo[money][g]!=-1)
		return memo[money][g];
	int ans=-1;
	for(int i=1;i<=prize[g][0];i++)
		ans= max(ans,shop(money-prize[g][i],g+1));
	return memo[money][g]=ans;
}

int main() {
	int tc,sol;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&m,&c);
		for(int i=0;i<c;i++)
		{
			scanf("%d",&prize[i][0]);
			for(int j =1;j<=prize[i][0];j++)
			{
				scanf("%d",&prize[i][j]);
			}
		}
		memset(memo,-1,sizeof memo);
		sol=shop(m,0);
		if(sol==-1)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%d\n",sol);
		}

	}
	return 0;
}
