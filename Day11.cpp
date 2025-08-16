/* 2402. Meeting Rooms III :   
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time
interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration
as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b. */


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Priority queue for available rooms (min-heap by room number)
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i)
            availableRooms.push(i);

        // Priority queue for occupied rooms (min-heap by end time)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupiedRooms;

        // Count of meetings for each room
        vector<int> roomUsage(n, 0);

        for (const auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            long long duration = end - start;

            // Free up rooms that have become available
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                int freedRoom = occupiedRooms.top().second;
                occupiedRooms.pop();
                availableRooms.push(freedRoom);
            }

            if (!availableRooms.empty()) {
                // Assign to available room with smallest number
                int room = availableRooms.top();
                availableRooms.pop();
                roomUsage[room]++;
                occupiedRooms.push({end, room});
            } else {
                // Delay the meeting until the earliest available room
                auto [freeTime, room] = occupiedRooms.top();
                occupiedRooms.pop();
                roomUsage[room]++;
                occupiedRooms.push({freeTime + duration, room});
            }
        }

        // Find the room with max usage
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomUsage[i] > roomUsage[maxRoom])
                maxRoom = i;
        }
        
        return maxRoom;
    }
};
