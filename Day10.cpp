/* 3440. Reschedule Meetings for Maximum Free Time II :

You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, 
each of length n.
These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, 
where the ith meeting occurs during the time [startTime[i], endTime[i]].
You can reschedule at most one meeting by moving its start time while maintaining the same duration, 
such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.
Return the maximum amount of free time possible after rearranging the meetings.
Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.
Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting. */


class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray; //store durations of free gaps

        //ith event
        //ith start - i-1th ka end = free gap duration
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);
        for(int i = n-2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }

        int result = 0;
        //Iterating on the freeArray
        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1]; //duration of event = d

            //Case-1 Moving completely out
            if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])) {
                result = max(result, freeArray[i-1] + currEventTime + freeArray[i]);
            }

            //case-2 shift left or right
            result = max(result, freeArray[i-1] + freeArray[i]);
        }

        return result;
    }
};
