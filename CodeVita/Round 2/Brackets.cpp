#include <iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

int main() {
	int tc;
	cin>>tc;
    cin.ignore (numeric_limits<streamsize>::max(), '\n'); 		
	while(tc--)
	{
		string s;
		int flag=0,brflag=0;
		vector<char> brac;
		getline(cin,s);
		for(unsigned int i=0;i<s.length();i++)
		{
			if((s[i]=='(' || s[i]=='<' || s[i]=='{' || s[i]=='[' || s[i]=='/') && flag==0)
			{
				brac.push_back(s[i]);
			}
			else if((s[i]==')') && flag==0)
			{
				if(brac.size()>0)
				{
					if(brac[brac.size()-1]=='(')
					{
					brac.pop_back();
					}
					else
					{
						brflag=1;
						break;
					}
				}
				else
				{
					brflag=1;
					break;
				}
			}
			else if(s[i]=='>' && flag==0)
			{
				if(brac.size()>0)
				{				
					if(brac[brac.size()-1]=='<')
					{
					brac.pop_back();
					}
					else
					{
						brflag=1;
						break;
					}	
				}else
				{
					brflag=1;
					break;
				}
			}
			else if(s[i]=='}' && flag==0)
			{
				if(brac.size()>0)
				{
					if(brac[brac.size()-1]=='{')
					{
					brac.pop_back();
					}
					else
					{
						brflag=1;
						break;
					}	
				}
				else
				{
					brflag=1;
					break;
				}
			}
			else if(s[i]==']' && flag==0)
			{
				if(brac.size()>0)
				{				
					if(brac[brac.size()-1]=='[')
					{
					brac.pop_back();
					}
					else
					{
						brflag=1;
						break;
					}
				}
				else
				{
					brflag=1;
					break;
				}
			}
			else if(s[i]=='\\' && flag==0)
			{
				if(brac.size()>0)
				{				
					if(brac[brac.size()-1]=='/')
					{
					brac.pop_back();
					}
					else
					{
						brflag=1;
						break;
					}	
				}
				else
				{
					brflag=1;
					break;
				}
			}
			else if(s[i]=='@' && flag==0)
			{
				if(s[i+1]=='*')
				{
					flag=1;
					i=i+1;
				}
			}
			else if(s[i]=='*' && flag==1)
			{
				if(s[i+1]=='@')
				{
					flag=0;
					i=i+1;
				}
			}
		}
		if(brac.size()==0 && brflag!=1)
		{
			cout<<"True\n";
		}
		else
		{
			cout<<"False\n";
		}
	}
	return 0;
}