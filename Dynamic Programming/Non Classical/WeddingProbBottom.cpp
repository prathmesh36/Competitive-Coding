#include <iostream>
#include<cstring>
using namespace std;
int prize[25][25],m,c;
bool reachable[25][201];
int main() {
	int tc,sol;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&m,&c);
		for(int i=0;i<c;i++)
		{
			scanf("%d",&prize[i][0]);
			//cout<<prize[i][0];
			for(int j=1;j<=prize[i][0];j++)
			{
				scanf("%d",&prize[i][j]);
			}
		}
		memset(reachable,false,sizeof reachable);
		for(int g=1;g<=prize[0][0];g++)
		{
			if(m-prize[0][g]>=0)
			{
				reachable[0][m-prize[0][g]]=true;
			}
		}

		for(int G=1;G<c;G++)
		{
			for(int money=0;money<m;money++)
			{
				if(reachable[G-1][money])
					for(int g=1;g<=prize[G][0];g++)
					{
						if(money-prize[G][g]>=0)
							reachable[G][money-prize[G][g]]=true;
					}
			}
		}
		int money=0;
		for(money=0;money<=m && !reachable[c-1][money];money++);
		if(money==m+1)
			printf("no solution\n");
		else
			printf("%d\n",m-money);
	}
	return 0;
}
