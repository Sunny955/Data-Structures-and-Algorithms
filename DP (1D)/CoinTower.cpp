/*
Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?
Input Format :

Contains three value N,X,Y as mentioned in the problem statement

Output Format :

A string containing the name of the winner like “Whis” or “Beerus” (without quotes)

Constraints:

1<=N<=10^6
2<=X<=Y<=50

Sample Input :

 4 2 3

Sample Output :

 Whis

 */


#include<iostream>
#include<string>
#include <vector>
using namespace std;

/* Iterative Solution 

string findWinner(int n, int x, int y)
{
	// Write your code here .
    string out;
    int *dp=new int[n+1]();
    
    dp[0]=100;
    dp[1]=1;
    dp[x]=1;
    dp[y]=1;
    
    for(int i=2;i<=n;i++)
    {
        int ans1=-1,ans2=-1,ans3=-1,ans;
        if(dp[i]==0)
        {
            if(i-1>0)
            {
                ans1=dp[i-1]^1;
            }
            if(i-x>0)
            {
                ans2=dp[i-x]^1;
            }
            if(i-y>0)
            {
                ans3=dp[i-y]^1;
            }
        }
        
    	ans=max(ans1,max(ans2,ans3));
        dp[i]=ans;
        
    }
    
    if(dp[n]!=0)
    {
        out="Beerus";
    }
    else
    {
       out="Whis";    
    }
    return out;
}
*/

int BeerusWin(vector<int> &dp,int n,int x,int y){
    if(n==1 || n==x || n==y)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    
    int ans;
    //You'll have take care when n>x or <x, likewise for y
    if(n>x && n>y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y) || !BeerusWin(dp,n-y,x,y);
    else if(n>x && n<y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y);
    else if(n<x && n>y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-y,x,y);
    else
        ans=!BeerusWin(dp,n-1,x,y);
    
    dp[n]=ans;
    return dp[n];
}


string solve(int n, int x, int y)
{
	// Write your code here .
    vector<int> dp(n+1,-1);
    
    int ans=BeerusWin(dp,n,x,y);
    
    if(ans)
        return "Beerus";
    else
        return "Whis";
}


int n,x,y;
int main()
{
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
}
