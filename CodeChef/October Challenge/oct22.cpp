#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> nums;
		vector<int> mex;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			nums.push_back(temp);
		}
		//for(auto elem:nums)
		//cout<<elem<<" ";
		sort(nums.begin(),nums.end());
		int curnum=0,i=0;
		while(curnum<n)
		{
			//cout<<nums[curnum]<<" ";
			if(nums[curnum]==i)
			{
				curnum++;
			}
			else
			{
				mex.push_back(i);
			}
			i++;
			if(mex.size()==k+1)
			break;
		}
		if(mex.size()<k+1)
		{
			cout<<nums[n-1]+(k+1-mex.size())<<endl;
		}
		else
		{
			cout<<mex[k]<<endl;
		}
	}
	return 0;
}
