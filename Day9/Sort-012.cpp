//Problem - https://www.naukri.com/code360/problems/sort-0-1-2_631055


void sort012(int *arr, int n) {
    int i = 0, j = 0, k = n - 1;

    while (j <= k) {
        if (arr[j] == 0) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[j] == 2) {
            swap(arr[j], arr[k]);
            k--;
            // Don't increment j here
        }
        else { // arr[j] == 1
            j++;
        }
    }
}
