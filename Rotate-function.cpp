class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int f1 = 0;
        int max_sum;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            f1 += nums[i]*i;
        }
        max_sum = f1;

        for(int i=n-1;i>=0;i--){
            f1 = f1 + sum - (nums[i]*n);
            max_sum = max(max_sum, f1); 
        }
        return max_sum;
    }
};