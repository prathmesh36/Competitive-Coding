#include <iostream>
using namespace std;
int coins[]={1,5,10,25,50};
int mincoin(int m, int v)
{
	int table[v+1][m],x,y;
	for(int i=0;i<m;i++)
	table[0][i]=1;
	for(int i=1;i<=v;i++)
	{
		for(int j=0;j<m;j++)
		{
			x=(i-coins[j]>=0)?table[i-coins[j]][j]:0;
			y=(j>0)?table[i][j-1]:0;
			table[i][j]=x+y;
		}
	}
	return table[v][m-1];
}

int main() {
	int v;
	while(scanf("%d",&v)==1)
	printf("%d\n",mincoin(5,v));
	return 0;
}
