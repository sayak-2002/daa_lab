#include <bits/stdc++.h>
using namespace std;

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

bool compare(pair<int, int>& a, pair<int, int>& b){
	return a.second<b.second;
}

int main(){
    init_code();

    int n;
    cin>>n;

    vector<int> start;
    vector<int> finish;

    for(int i=0; i<n; i++){
    	int x;
    	cin>>x;
    	start.push_back(x);
    }

    for(int i=0; i<n; i++){
    	int x;
    	cin>>x;
    	finish.push_back(x);
    }

    vector<pair<int, int>> vp;

    for(int i=0; i<n; i++){
    	vp.push_back({start[i], finish[i]});
    }

    sort(vp.begin(), vp.end(), compare);

    vector<pair<int, int>> tasks;


    
    int end = vp[0].second;
    tasks.push_back(vp[0]);


    for(int i=1; i<n; i++){
    	if(vp[i].first > end){
    		end = vp[i].second;
    		tasks.push_back(vp[i]);
    	}
    }

    for(int i=0; i<tasks.size(); i++){
    	cout<<tasks[i].first<<" "<<tasks[i].second<<endl;
    }
    


return 0;
}