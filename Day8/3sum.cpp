//problem - https://www.naukri.com/code360/problems/3sum_893028


#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	
	vector<vector<int>> ans;
	set<vector<int>> s;

	for(int i =0 ; i<arr.size();i++){
		for(int j= i+1; j< arr.size();j++){
			for(int k =j+1; k<arr.size();k++){

				if(arr[i] +arr[j] +arr[k]  == K ){

					vector <int> temp;
					temp.push_back(arr[i]);
					temp.push_back(arr[j]);
					temp.push_back(arr[k]);
					sort(temp.begin(), temp.end());
					s.insert(temp);
				}
			}
		}
	}
	for(auto x :s){
		ans.push_back(x);
	}

	return ans;
}