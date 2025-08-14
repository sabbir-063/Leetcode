class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int n = num.size();

        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] and num[i] == num[i+2]){
                if(ans.size() == 0) ans = num.substr(i, 3);
                else if(num[i] > ans[0]) ans = num.substr(i, 3);
            }
        }

        return ans;
    }
};

//Time Complexity O(N)
//Space Complexity O(1)
