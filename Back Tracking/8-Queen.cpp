#include <iostream>
#include <cstring>
using namespace std;
int row[8],a,b,lc=0;
 
bool place(int r,int c)
{
	for(int prev=0;prev<c;prev++)
	{
		if(row[prev]==r || abs(row[prev]-r)==abs(prev-c))
		{
			return false;
		}
	}
	return true;
}
 
void backtrack(int c)
{
	int i,r;
	if(c==8 && row[b]==a)
	{
		for(i=0;i<8;i++)
		{
			cout<<row[i]+1<<" ";
		}
		cout<<"\n";
	}
	else
	{
		for(r=0;r<8;r++)
		{
			if(place(r,c))
			{	
				row[c]=r;
				backtrack(c+1);
			}	
		}
	}
}
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cin>>b;
		a--;
		b--;
		memset(row,0,sizeof row);
		backtrack(0);
	}
 
	return 0;
}