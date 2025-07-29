//Problem - https://www.naukri.com/code360/problems/painter's-partition-problem_1089557

//This Problem is very much similar to Book allocation problem 


bool isPossible(vector<int> &boards,int size,  int k, int mid){
    int painterCount = 1;

    int time = 0;
    for(int i =0; i<size; i++){
        if(time + boards[i] <= mid){
            time += boards[i];
        }
        else{
            painterCount++;
            if (painterCount > k || boards[i] > mid) {
                return false;
            }
            time = boards[i];

        }
    }
    return true;
}




int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();

    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += boards[i];
    }
    int e = sum;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return ans;
}
