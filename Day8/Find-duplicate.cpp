//problem - https://www.naukri.com/code360/problems/duplicate-in-array_893397?leftPanelTabValue=PROBLEM


int findDuplicate(vector<int> &arr) 
{
    int ans =0;

//XOR all array elements
    for(int i=0; i<arr.size(); i++){
        ans = ans^arr[i];
    }

//XPR [1,n-1]
    for(int i=0; i<arr.size(); i++){
        ans = ans^i;

    }
    return ans;
	
}
