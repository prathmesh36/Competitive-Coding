#include <iostream>
#include<string>
using namespace std;
int n,q;
string digit[]={"0","1","2","3","4","5","6","7","8","9"};
string dict[100];
string query;
void backtrack(int v,string s)
{
	if(v==query.size())
	{
		cout<<s<<"\n";
		return;
	}
	switch(query[v])
	{
		case '#':
		for(int i=0;i<n;i++)
		  backtrack(v+1,s+dict[i]);
		break;
		case '0':
		for(int i=0;i<10;i++)
			backtrack(v+1,s+digit[i]);
		break;
	}
}
int main() {
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			cin>>dict[i];
		}

		cin>>q;
		printf("--\n");
		for(int i=0;i<q;i++)
		{
			cin>>query;
			backtrack(0,"");
		}
	}
	return 0;
}
