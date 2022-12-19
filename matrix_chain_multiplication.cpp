#include <bits/stdc++.h>
using namespace std;

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int dp[100][100];
int solve(int arr[], int i, int j){
	if(i == j) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	dp[i][j] = INT_MAX;

	for(int k=i; k<j; k++){
		dp[i][j] = min(dp[i][j], solve(arr, i, k)+solve(arr, k+1, j)+
			arr[i-1]*arr[j]*arr[k]);
	}
	return dp[i][j];
}

int main(){
    init_code();

    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
    int ans = solve(arr, 1, n-1);

    cout<<ans<<endl;
    


return 0;
}