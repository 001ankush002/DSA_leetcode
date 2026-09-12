class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end());

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        vector<vector<long long>> score(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];
                score[i][k] = score[i + 1][k];

                long long takeScore = a[i][2] + score[nxt[i]][k - 1];

                vector<int> take = dp[nxt[i]][k - 1];
                take.push_back((int)a[i][3]);
                sort(take.begin(), take.end());

                if (takeScore > score[i][k] ||
                    (takeScore == score[i][k] && take < dp[i][k])) {
                    score[i][k] = takeScore;
                    dp[i][k] = take;
                }
            }
        }

        return dp[0][4];
    }
};
