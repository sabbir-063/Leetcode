/*
Problem : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

Author : Sabbir Musfique
Time Complexity : O(n)
Space Complexity : O(1)
*/


class Solution {
public:
    int strStr(string hay, string need) {
        int n=hay.size(), k=need.size();
        int indx=-1;
        for(int i=0;i<n-k+1;i++){
            string temp=hay.substr(i,k);
            if(temp == need){
                indx=i; break;
            }
        }
        return indx;
    }
};
