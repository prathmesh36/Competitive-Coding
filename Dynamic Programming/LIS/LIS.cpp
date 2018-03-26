#include <iostream>
#include<stack>
#include<algorithm>
#define MAX 100000
using namespace std;
int L[MAX], L_id[MAX],P[MAX],a[MAX];
void reconstruct(int end)
{
	int x=end;
	stack<int> s;
	for(;P[x]>=0;x=P[x])s.push(a[x]);
	printf("%d\n",a[x]);
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
}
int main() {
	int i=0;
	while(cin>>a[i])
	{
		i++;
	}

	int lis=0, lis_end=0;

	for(int j=0;j<i;j++)
	{
		int pos=lower_bound(L,L+lis,a[j])-L;
		L[pos]=a[j];
		L_id[pos]=j;
		P[j]=pos?L_id[pos-1]:-1;
		if(pos+1>lis)
		{
			lis=pos+1;
			lis_end=j;
		}
	}
	cout<<lis<<endl<<"-"<<endl;

	reconstruct(lis_end);
	return 0;
}
