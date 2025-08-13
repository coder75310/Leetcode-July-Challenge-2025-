/* 1353. Maximum Number of Events That Can Be Attended :

You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.
Return the maximum number of events you can attend.
 */


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        // Min heap to store end days of events available to attend
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int i = 0;  // Index in events
        int res = 0;
        int n = events.size();
        
        // Find the maximum end day to know how long we need to simulate
        int lastDay = 0;
        for (const auto& event : events)
            lastDay = max(lastDay, event[1]);
        
        // Loop through each day
        for (int day = 1; day <= lastDay; ++day) {
            // Add all events that start today
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                ++i;
            }
            
            // Remove all events that have already expired
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            
            // Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                ++res;
            }
        }
        
        return res;
    }
};
