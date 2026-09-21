class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);
        for (int x : nums) {
            vector<long long> next_dp(k, 0);
            int rem = x % k;
            next_dp[rem]++;
            for (int i = 0; i < k; ++i) {
                if (dp[i]) next_dp[(i * rem) % k] += dp[i];
            }
            for (int i = 0; i < k; ++i) ans[i] += next_dp[i];
            dp = std::move(next_dp);
        }
        return ans;
    }
};