#include <iostream>
#include <cstring>
using namespace std;
struct Coor
{
	int x;
	int y;
}a[13];

int beeper;
bool vis [10 + 3] [1024 + 5]; // is_visited
int val [10 + 3] [1024 + 5]; // cost

int dp(int pos,int mask)
{
	if(mask==(1<<beeper)-1)
	{
		vis[pos][mask]=true;
		return val[pos][mask]=abs(a[pos].x-a[0].x)+abs(a[pos].y-a[0].y);
	}
	if(vis[pos][mask])
		return val[pos][mask];

	int ans=100000;
	for(int i=0;i<beeper;i++)
	{
		if((mask & (1<<i))==0)
		{
			int cost=dp(i,mask |  (1<<i))+abs(a[pos].x-a[i].x)+abs(a[pos].y-a[i].y);
			if(ans>cost) ans=cost;
		}
	}
	vis[pos][mask]=true;
	return val[pos][mask]=ans;

}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int row,col;
		scanf("%d%d",&row,&col);
		scanf("%d%d",&a[0].x,&a[0].y);
		scanf("%d",&beeper);
		beeper++;
		for(int i=1;i<beeper;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
		}

		memset(vis,false,sizeof(vis));
		printf("The shortest path has length %d\n",dp(0,1));
	}
	return 0;
}
