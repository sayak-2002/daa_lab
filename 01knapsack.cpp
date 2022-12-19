#include <bits/stdc++.h>
using namespace std;

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

int knapsack(int w, int n, int wt[], int val[], 
	vector<vector<int>> &dp){
	if(n==0 || w==0){
		return 0;
	}

	if(dp[n][w] != -1){
		return dp[w][n];
	}

	if(w>=wt[n-1]){
		int take = knapsack(w-wt[n-1], n-1, wt, val, dp)
		+ val[n-1];
		int nottake = knapsack(w, n-1, wt, val, dp);

		dp[n][w] = max(take, nottake);
		return dp[n][w];
	}else{
		return dp[n][w] = knapsack(w, n-1, wt, val, dp);
	}
}

int main(){
    init_code();

    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};

    int w = 50;
    int n = sizeof(wt)/sizeof(wt[0]);
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));

    int ans =  knapsack(w, n, wt, val, dp);
    cout<<ans;


return 0;
}