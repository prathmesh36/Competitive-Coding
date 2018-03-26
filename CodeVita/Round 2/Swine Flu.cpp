#include <iostream>
#include <stdio.h>
using namespace std;
int people[15][15],infect[15][15];
bool anti[15][15];
int infr,infc,n;

void backtrack(int label,int curr,int curc)
{
	int i,j,k=0;
	int setp[9][2];
	for(i=curr-1;i<=curr+1;i++)
	{
		for(j=curc-1;j<=curc+1;j++)
		{
			if(infect[i][j]<infect[curr][curc]-1  && (i<n && j<n && i>=0 && j>=0) && infect[i][j]!=0)
			{
				if(i==curr && j==curc)
				{

				}
				else
				{
				infect[i][j]=label;
				setp[k][0]=i;
				setp[k][1]=j;
				k++;
				}
			}
		}
	}

	for(i=0;i<k;i++)
	{
		backtrack(label-1,setp[i][0],setp[i][1]);
	}
}

void abacktrack(int label,int curr,int curc)
{
	int i,j,k=0;
	int setp[9][2];
	for(i=curr-1;i<=curr+1;i++)
	{
		for(j=curc-1;j<=curc+1;j++)
		{
			if(infect[i][j]!=1 && (i<n && j<n && i>=0 && j>=0) && infect[i][j]!=0 && anti[i][j]==false)
			{
				if(i==curr && j==curc)
				{

				}
				else
				{
				if(label==1)
					infect[i][j]=label;
				else
					infect[i][j]--;
				setp[k][0]=i;
				setp[k][1]=j;
				k++;
				anti[i][j]=true;
				}
			}
		}
	}

	for(i=0;i<k;i++)
	{
		abacktrack(0,setp[i][0],setp[i][1]);
	}
}

int main() {
	int i,j,anir,anic;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&people[i][j]);
			infect[i][j]=people[i][j];
			anti[i][j]=false;
		}
	}
	scanf("%d",&infr);
	scanf("%d",&infc);
	scanf("%d",&anir);
	scanf("%d",&anic);
	infr--;
	infc--;
	anir--;
	anic--;
	infect[infr][infc]=5;
	backtrack(5,infr,infc);

	infect[anir][anic]=1;
	abacktrack(1,anir,anic);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<infect[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
