/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for (auto i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0;
        int j = 0;
        int n = start.size();
        int count = 0;
        int res = 0;
        while (i < n)
        {
            cout << i << ' ';
            if (start[i] < end[j])
            {
                count += 1;
                res = max(count,res);
                ++i;
            }
            else 
            {
                count -= 1;
                ++j;
            }
    
        }
        return res;
    
    }
};
