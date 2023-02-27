/*
Problem : https://leetcode.com/problems/add-to-array-form-of-integer/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s="", kk=to_string(k);
        int n=num.size(), nn=kk.size();
        vector<int>ans;
        for(int i=0;i<n;i++) s += (num[i] + '0');

        // cout<<kk<<" kk s "<<s<<endl;

        int cary=0, j=nn-1;
        for(int i=n-1;i>=0 or j>= 0;i--){
            if(j>=0 and i<0){
                int temp=(kk[j]-'0')+cary;
                cary=temp/10;
                ans.push_back(temp%10);         
            }
            else if(j >= 0){
                int temp=(s[i]-'0')+(kk[j]-'0')+cary;
                cary=temp/10;
                ans.push_back(temp%10);
            }else{
                int temp=(s[i]-'0')+cary;
                cary=temp/10;
                ans.push_back(temp%10);
            }
            j--;
        }
        if(cary>0) ans.push_back(cary);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
