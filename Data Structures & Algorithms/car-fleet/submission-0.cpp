class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        /*
        * 1 -> 4 -> 7 -> 10
        * 4 -> 6 -> 8 -> 10
        * -----------------
        * 4 -> 6 -> 8 -> 10
        * 1 -> 3 -> 5 -> 7 -> 9
        * 0 -> 1 -> 2 -> 3 -> ...
        * 7 -> 8 -> 9 -> 10
        */
        vector<float> hrs;
        vector<pair<int,int>> car; // (position, speed)
        for (int i = 0; i < position.size(); ++i)
        {
            car.push_back({position[i],speed[i]});
        }
        sort(car.rbegin(),car.rend());
        vector<float> st;
        int fleet = 0;
        for (auto [p,s] : car)
        {
            float time = (float)(target - p)/s;
            if (st.size() == 0)
            {
                st.push_back(time);
            }
            else if (time > st.back())
            {
                st.push_back(time);
            }
            else if (time < st.back())
            {
                continue;
            }
        }
        return st.size();
    }
};
