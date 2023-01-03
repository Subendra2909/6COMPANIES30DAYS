class Solution {
public:
    /*int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        int n = nums.size();
        int x = -1;
        int y = -1;
        if(copy == nums) return 0;
        for(int i=0;i<n;i++){
            if(nums[i] != copy[i] and x == -1){
                x = i;
            }
            else if(nums[i] != copy[i] and x != -1) y = i;
        }
        return y-x+1;
    }*/

    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = -1, r = -1;
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                l = i;
                break;
            }    
        }
        for(int i = n - 1; i >= 1; i--) {
            if(arr[i] < arr[i - 1]) {
                r = i;
                break;
            }
        }

        if(l == -1) return 0; // array already sorted

        int mini = arr[l], maxi = arr[l];
        for(int i = l; i <=r; i++) {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        l = upper_bound(arr.begin(), arr.begin() + l, mini) - arr.begin();
        r = lower_bound(arr.begin() + r + 1, arr.end(), maxi) - arr.begin();
        return r - l;
    }

};