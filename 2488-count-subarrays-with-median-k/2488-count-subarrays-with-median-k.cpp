class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        map<int, int> c;
        c[0] = 1;
        bool flag = false;
        int sum = 0;
        int n=nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < k)
                sum--;
            else if (nums[i] > k)
                sum++;
            if (nums[i] == k)
                flag = true;

            if (flag)
                ans += c[sum] + c[sum - 1];
            else
                c[sum]++;
        }
        return ans;
    }
};