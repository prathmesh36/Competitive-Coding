#include <iostream>
#include<bitset>
using namespace std;
bitset<30> rw,ld,rd;
int n,ans=0;;
char board[15][15];
void backtrack(int c)
{
	if(c==n)
	{
		ans++;
		return;
	}else
	{
		for(int r=0;r<n;r++)
		{
			if(board[r][c]!='*' && !rw[r] && !rd[r+c] && !ld[r-c+n-1])
			{
				rw[r]=rd[r+c]=ld[r-c+n-1]=true;
				backtrack(c+1);
				rw[r]=ld[r-c+n-1]=rd[r+c]=false;
			}
		}
	}

}

int main() {
	cin>>n;
	int count=1,i,j;
	if(n!=0)
	{
		while(n!=0)
		{
			ans=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cin>>board[i][j];
				}
			}
			backtrack(0);
			cout<<"Case "<<count<<": "<<ans<<"\n";
			count++;
			cin>>n;
		}
	}
	return 0;
}
