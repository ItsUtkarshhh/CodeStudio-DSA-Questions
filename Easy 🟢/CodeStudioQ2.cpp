// Question Link : https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true
int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = (start+end)/2; // More optimized way to use here is, mid = (start + ((end-start)/2)), but okay keep this thing in mind during interviews and coding compettions and online coding! to pass all the test cases!
    while(start<=end) {
        if(key==arr[mid]) {
            return mid;
        }

        if(key>arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = (start+end)/2;
    }
    return -1;
}

int pivotElement(vector<int>& arr, int n) {
    int s = 0; int e = n-1;
    int mid = s +(e-s)/2;
    while(s<e) {
        if(arr[mid]>=arr[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s +(e-s)/2;
    }
    return s;
}
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = pivotElement(arr, n);
    int e = n-1;
    if(k>=arr[pivot] && k<=arr[e]) {
        return binarySearch(arr,pivot,n-1,k);
    }
    else {
        return binarySearch(arr, 0, pivot-1, k);
    }
}
