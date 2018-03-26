#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > small;  //to store all the small rocks
vector<int> big; //to store big rocks
int N, end; // store no of rocks and last bank
int main(){
 int TC;
 scanf("%d",&TC);
 for(int T=1;T<=TC;++T){
  printf("Case %d: ",T); 
  big.clear();
  small.clear();
  scanf("%d %d",&N,&end);
  big.push_back(0); //store first bank
  small.push_back(vector<int>()); //store empty vector in 'small' representing first bank
  int itv = 0;
  for(int i=0;i<N;++i){
   char state;
   int M;
   scanf(" %c-%d", &state, &M); 
   if(state == 'B'){  //if rock is big rock then push empty vector in 'small' representing that rock and push big rock in 'big'
    small.push_back(vector<int>());
    big.push_back(M);
    ++itv; //increment itv
   } else {
    small[itv].push_back(M);  //if rock is small push it in 'small' at pos itv. so all the small rocks will be pushed in 'small' at position itv until a big rock is inputted. So it will be like the small rocks are between the big rock and the next big rock.
   }
  }
  big.push_back(end); //insert the last bank in the 'big'
  int mleap=-1; //max leap count
  for(int i=0;i<=itv;++i){  //for loop till itv which represents no of big rock including the first and last bank
   int sz = small[i].size();
   int temp = -1;
   for(int j=2;j<sz;++j)  //for from 2 till size of the inner vector representing the small rocks between 2 big rocks 
     temp = max(small[i][j]-small[i][j-2], temp); //temp will store the max leap from the series of small rock between two big rocks
   if(sz <= 1)   //if there are only one small rock or less small rock then just calculate the leap between two big rocks dont consider the inner small rocks
    temp = max(big[i+1] - big[i], temp);
   if(sz > 1){  // if there are more than one small rock than calculate the leap from start bank to next alternate rock and from last bank to previous alternate rock
    temp = max(small[i][1] - big[i], temp);
    temp = max(big[i+1] - small[i][sz-2], temp);
   }
   mleap = max(mleap, temp); //to calculate max from all the different series of small rock
  }
  printf("%d\n", mleap);
 }
 return 0;
}

/*
Hint:
https://abitofcs.blogspot.in/2014/07/a-bit-of-uva-uva-11157-dynamic-frog.html
Summary:
Given an integer 
N
N
and two sets of numbers (all different), 
S={s1,s2,…,sn}
S={s1,s2,…,sn}
(small rocks) and 
B={b1,b2,…,bm}
B={b1,b2,…,bm}
(big rocks), we construct 2 sequence from 0 to N and from N to 0 respectively, one ascending and the other descending,  such that each element on S can only be use once, while we can use elements from B twice (one on the ascending sequence, the other on the descending sequence). Amongst all such construction, find the minimum distance between two consecutive element in both sequences.
(Actually the summary seems more confusing haha)
Firstly, notice that we can break the problem into smaller sub-problems since big rocks can be used twice, so essentially we can treat them as two ends. Now the base sub-problem is made up of all small rocks. Here, we need to choose a way to go forward and backward such that each small rocks is only used once, and that the maximum leap we make will be minimum overall (minimax, or the lowest maximum possible, so to say).
Here my intuition was to choose alternate rocks to jump on. I was not convince that this will lead to optimal solution, so I want to prove it. Consider this case where N = 20:
S={1,5,9,11}
S={1,5,9,11}

If I choose 
{1,9}
{1,9}
for the jump forward, the jump backward will be using 
{5,11}
{5,11}
. Smallest distance for jump forward will be minimax of 
{|0−1|,|1−9|,|9−20|}
{|0−1|,|1−9|,|9−20|}
while second jump will be the minimax amongst 
{|0−5|,|5−11|,|11−20|}
{|0−5|,|5−11|,|11−20|}
. If we choose another configuration, that is for the first jump we choose 
{1,11}
{1,11}
instead, the minimax for first jump will increase while the second will decrease, and essentially the minimax for the whole jump will increase. We can do this analysis more formally and extend it to general N cases, but we get the idea.


if still not unserstood then manupalate the program by taking inputs.
*/