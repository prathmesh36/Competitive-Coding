#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int m, n;
int p[110], f[110];
int dp[110][15000];

int recurse(int i, int w) {
    if(w > m && m < 1800)
        return -1000;
    if(w > m + 200)
        return -1000;
    if(i == n) {
        if(w > m && w <= 2000)
            return -1000;
        return 0;
    }
    if(dp[i][w] != -1)
        return dp[i][w];

    return dp[i][w] = max(recurse(i + 1, w),
        f[i] + recurse(i + 1, w + p[i]));
}

int main() {
    while(scanf("%d %d", &m, &n) == 2) {
        for(int i = 0; i < n; i++)
            scanf("%d %d", &p[i], &f[i]);
        memset(dp, -1, sizeof dp);

        printf("%d\n", recurse(0, 0));
    }
}

/* without refund part
#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,p[105],f[105],memo[105][10000];

int dots(int money,int c)
{
	if(c==n || money==0)
	{

		return 0;
	}
	if(memo[c][money]!=-1)return memo[c][money];

	if(p[c]>money) return memo[c][money]=dots(money,c+1);
	return memo[c][money]=max(dots(money,c+1),f[c]+dots(money-p[c],c+1));
}

int main() {
	while(scanf("%d%d",&m,&n)==2)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&p[i],&f[i]);
		}
		memset(memo, -1, sizeof memo);
		cout<<dots(m,0)<<"\n";
	}
	return 0;
}
*/
