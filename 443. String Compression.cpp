/*
Problem : https://leetcode.com/problems/string-compression/description/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n == 1) return 1;

        int cnt=1, i=0, j=0;

        while(i < n){
            while(i<n-1 and chars[i] == chars[i+1]) 
                cnt++, i++;

            chars[j++] = chars[i++];
            if(cnt > 1){
                string len=to_string(cnt);
                for(auto c : len)
                    chars[j++] = c;
                cnt=1;
            }
        }

        return j;
    }
};
