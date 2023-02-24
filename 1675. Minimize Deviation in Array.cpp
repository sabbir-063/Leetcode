/*
Problem : https://leetcode.com/problems/minimize-deviation-in-array/

Author : Sabbir Musfique
Time Complexity : O(m log(n)) where (amotised)m always less than n
Space Complexity : O(n)
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int>st;
        for(auto num : nums) st.insert(num);
        
        int mnDev = *st.rbegin() - *st.begin();

        while(*st.begin() % 2 != 0){
            int x=*st.begin();
            st.erase(st.begin());
            st.insert(x*2);
            mnDev = min(mnDev, *st.rbegin() - *st.begin());
        }

        while(*st.rbegin() % 2 == 0){
            auto itt=st.end(); itt--;
            int x=*itt;
            st.erase(itt);
            st.insert(x/2);
            mnDev = min(mnDev, *st.rbegin() - *st.begin());
        }

        while(*st.begin() % 2 != 0){
            int x=*st.begin();
            st.erase(st.begin());
            st.insert(x*2);
            mnDev = min(mnDev, *st.rbegin() - *st.begin());
        }

        return mnDev;
    }
};
