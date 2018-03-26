#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	unsigned int i,j,n;
	int ax,ay,bx,by,dist=0,k;
	vector<vector <int> > poles;
	cin>>n;
	cin>>ax;
	cin>>ay;
	cin>>bx;
	cin>>by;
	for(i=0;i<n;i++)
	{
		vector<int> a;
		a.push_back(ax);
		a.push_back(ay);
		a.push_back(3);
		poles.push_back(a);
		for(j=0;j<n;j++)
		{
			int temp;
			cin>>temp;
			if(temp==1)
			{
				vector<int> pole;
				pole.push_back(i);
				pole.push_back(j);
				pole.push_back(1);
				poles.push_back(pole);
			}
			else if(temp==2)
			{
				vector<int> pole2;
				pole2.push_back(i);
				pole2.push_back(j);
				pole2.push_back(2);
				poles.push_back(pole2);
			}
		}
	}
	/*for(i=0;i<poles.size();i++)
	{
		for(j=0;j<poles[i].size();j++)
		{
			cout<<poles[i][j]<<" ";
		}
		cout<<"\n";
	}*/
		vector<pair<int,int> > finaldist;
		int left,right,mini=50,dir1,dir2;
		pair<int,int> curr1;
		pair<int,int> curr2;
		pair<int,int> prevcurr;
		prevcurr.first=bx;
		prevcurr.second=by;
		for(i=0;i<poles.size();i++)
		{
			if(poles[i][0]==bx && poles[i][1]<by)
			{
				if(abs(poles[i][1]-by)<mini)
				{
					mini=abs(poles[i][1]-by);
					curr1 = make_pair(poles[i][0],poles[i][1]);
					dir1=poles[i][2];
				}
			}
		}
		left=mini;
		mini=50;
		for(i=0;i<poles.size();i++)
		{
			if(poles[i][0]==bx && poles[i][1]>by)
			{
				if(abs(poles[i][1]-by)<mini)
				{
					mini=abs(poles[i][1]-by);
					curr2 = make_pair(poles[i][0],poles[i][1]);
					dir2=poles[i][2];

				}
			}
		}
		right=mini;
		int maxpole=0;
		if(right!=50 && left!=50)
		{
			dist=left;
			maxpole=2;
		}
		else
		{
			maxpole=1;
			if(left!=50)
			{
				dist=left;
			}
			else if(right!=50)
			{
				dist=right;
				curr1=curr2;
				dir1=dir2;
			}
		}
		//cout<<curr2.first<<" "<<curr2.second<<"\n";
		for(k=0;k<maxpole;k++)
		{
			if(k==1)
			{
				curr1=curr2;
				dist=right;
				prevcurr.first=bx;
				prevcurr.second=by;
				dir1=dir2;
			}
			int count=0;
			mini=0;
			while(mini!=50)
			{
				int rc;
				//cout<<count<<" ";
				if(count%2==0)
				{
					rc=curr1.second;
				}
				else
				{
					rc=curr1.first;
				}
				if(dir1==3)
				{
					finaldist.push_back(make_pair(dist,count));
					break;
				}
				if(count%2==0)
				{
					if((dir1==1 && curr1.second<prevcurr.second) || (dir1==2 && curr1.second>prevcurr.second))
					{
						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][1]==rc && poles[i][0]>curr1.first)
							{
								if(abs(poles[i][0]-curr1.first)<mini)
								{
									mini=abs(poles[i][0]-curr1.first);
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr =curr1;
						curr1 = make_pair(x,y);
					}
					else if((dir1==1 && curr1.second>prevcurr.second) || (dir1==2 && curr1.second<prevcurr.second))
					{
						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][1]==rc && poles[i][0]<curr1.first)
							{
								if(abs(poles[i][0]-curr1.first)<mini)
								{
									mini=abs(poles[i][0]-curr1.first);
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr = curr1;
						curr1 = make_pair(x,y);
					}
				}
				else
				{
					if((dir1==1 && curr1.first<prevcurr.first) || (dir1==2 && curr1.first>prevcurr.first))
					{
						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][0]==rc && poles[i][1]>curr1.second)
							{
								if(abs(poles[i][1]-curr1.second)<mini)
								{
									mini=abs(poles[i][1]-curr1.second);
									//cout<<"mini:"<<mini<<"\n";
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr= curr1;
						curr1 = make_pair(x,y);

					}
					else if((dir1==1 && curr1.first>prevcurr.first) || (dir1==2 && curr1.first<prevcurr.first))
					{
						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][0]==rc && poles[i][1]<curr1.second)
							{
								if(abs(poles[i][1]-curr1.second)<mini)
								{
									mini=abs(poles[i][1]-curr1.second);
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr=curr1;
						curr1 = make_pair(x,y);
					}
				}

				if(mini!=50)
				{
					dist=dist+mini;
				}
				if(dir1==3)
				{
					finaldist.push_back(make_pair(dist,count+1));
					break;
				}
				count++;
			}
		}
		prevcurr.first=bx;
		prevcurr.second=by;
		mini=50;
		for(i=0;i<poles.size();i++)
		{
			if(poles[i][1]==by && poles[i][0]<bx)
			{
				if(abs(poles[i][0]-bx)<mini)
				{
					mini=abs(poles[i][0]-bx);
					curr1 = make_pair(poles[i][0],poles[i][1]);
					dir1=poles[i][2];
				}
			}
		}
		left=mini;
		mini=50;
		for(i=0;i<poles.size();i++)
		{
			if(poles[i][1]==by && poles[i][0]>bx)
			{
				if(abs(poles[i][0]-bx)<mini)
				{
					mini=abs(poles[i][0]-bx);
					curr2 = make_pair(poles[i][0],poles[i][1]);
					dir2=poles[i][2];

				}
			}
		}
		right=mini;;
		maxpole=0;
		if(right!=50 && left!=50)
		{
			dist=left;
			maxpole=2;
		}
		else
		{
			maxpole=1;
			if(left!=50)
			{
				dist=left;
			}
			else if(right!=50)
			{
				dist=right;
				curr1=curr2;
				dir1=dir2;
			}
		}
		//cout<<prevcurr.first<<" "<<prevcurr.second<<"\n";
		for(k=0;k<maxpole;k++)
		{
			if(k==1)
			{
				curr1=curr2;
				dist=right;
				prevcurr.first=bx;
				prevcurr.second=by;
				dir1=dir2;
			}
			int count=0;
			mini=0;
			while(mini!=50)
			{
				int rc;
				//cout<<count<<" ";
				if(count%2==1)
				{
					rc=curr1.second;
				}
				else
				{
					rc=curr1.first;
				}
				if(dir1==3)
				{
					finaldist.push_back(make_pair(dist,count));
					break;
				}

				if(count%2==1)
				{
					if((dir1==1 && curr1.second<prevcurr.second) || (dir1==2 && curr1.second>prevcurr.second))
					{
						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][1]==rc && poles[i][0]>curr1.first)
							{
								if(abs(poles[i][0]-curr1.first)<mini)
								{
									mini=abs(poles[i][0]-curr1.first);
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr=curr1;
						curr1 = make_pair(x,y);
					}
					else if((dir1==1 && curr1.second>prevcurr.second) || (dir1==2 && curr1.second<prevcurr.second))
					{
						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][1]==rc && poles[i][0]<curr1.first)
							{
								if(abs(poles[i][0]-curr1.first)<mini)
								{
									mini=abs(poles[i][0]-curr1.first);
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr=curr1;
						curr1 = make_pair(x,y);
					}
				}
				else
				{
					if((dir1==1 && curr1.first<prevcurr.first) || (dir1==2 && curr1.first>prevcurr.first))
					{

						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][0]==rc && poles[i][1]>curr1.second)
							{
								if(abs(poles[i][1]-curr1.second)<mini)
								{
									mini=abs(poles[i][1]-curr1.second);
									//cout<<"mini:"<<mini<<"\n";
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr=curr1;
						curr1 = make_pair(x,y);

					}
					else if((dir1==1 && curr1.first>prevcurr.first) || (dir1==2 && curr1.first<prevcurr.first))
					{
						mini=50;
						int x=-1,y=-1;
						for(i=0;i<poles.size();i++)
						{
							if(poles[i][0]==rc && poles[i][1]<curr1.second)
							{
								if(abs(poles[i][1]-curr1.second)<mini)
								{
									mini=abs(poles[i][1]-curr1.second);
									x=poles[i][0];
									y=poles[i][1];
									dir1=poles[i][2];
								}
							}
						}
						prevcurr=curr1;
						curr1 = make_pair(x,y);
					}
				}

				if(mini!=50)
				{
					//cout<<k<<" "<<count<<" "<<curr1.first<<" "<<curr1.second<<" "<<mini<<"\n";
					dist=dist+mini;
				}
				if(dir1==3)
				{
					finaldist.push_back(make_pair(dist,count+1));
					break;
				}
				count++;
			}
		}
		if(finaldist.size()>0)
		{
		sort(finaldist.begin(),finaldist.end());
		cout<<finaldist[0].first<<" "<<finaldist[0].second<<"\n";
		}
		else
		{
			cout<<"-1";
		}
	return 0;
}
