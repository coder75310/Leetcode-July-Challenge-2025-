/* 1751. Maximum Number of Events That Can Be Attended II :

You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, 
you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, 
you cannot attend two events where one of them starts and the other ends on the same day.
Return the maximum sum of values that you can receive by attending events. */


class Solution {
public: ///////////
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        // Sort by end day
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        // Extract end days for binary search
        vector<int> endDays;
        for(auto &e : events)
            endDays.push_back(e[1]);
        
        // DP[i][j]: max value using first i events with at most j events attended
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        for(int i = 1; i <= n; ++i) {
            int start = events[i-1][0];
            int value = events[i-1][2];
            
            // Find the last event whose end day < start day
            int prev = upper_bound(endDays.begin(), endDays.end(), start-1) - endDays.begin();
            
            for(int j = 1; j <= k; ++j) {
                // Skip event i-1
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                // Take event i-1
                dp[i][j] = max(dp[i][j], dp[prev][j-1] + value);
            }
        }
        return dp[n][k];

    }
};
