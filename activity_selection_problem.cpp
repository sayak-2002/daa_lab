#include <bits/stdc++.h>
using namespace std;

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

struct activity {
	int start, finish;
};

bool compare(activity a1, activity a2){
	return a1.finish < a2.finish; 
}

void activity_selection(activity arr[], int n){

	sort(arr, arr+n, compare);

	int i=0;

	cout<<arr[i].start<<" "<<arr[i].finish<<endl;


	for(int j=1; j<n; j++){
		if(arr[j].start >= arr[i].finish){
			cout<<arr[j].start<<" "<<arr[j].finish<<endl;
		}
	}
}

int main(){
    init_code();
    int n;
    cin>>n;
    activity arr[n];

    for(int i=0; i<n; i++){
    	cin>>arr[i].start>>arr[i].finish;
    }

    activity_selection(arr, n);
    


return 0;
}