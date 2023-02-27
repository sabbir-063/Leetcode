/*
Problem : https://leetcode.com/problems/find-all-anagrams-in-a-string/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    bool isAnagram(int fs[],int fp[]){
        for(int i=0;i<26;i++){
            if(fs[i]!=fp[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        
        int n=s.size(),m=p.size();

        int fs[26]={0},fp[26]={0};

        for(int i=0;i<m;i++){
            fp[p[i]-'a']++;
        }
        
        for(int i=0;i<n;i++){
            fs[s[i]-'a']++;
            if(i < m-1) continue;
            else if(i==m-1){  
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
            else{
                fs[s[i-m]-'a']--;
 
                if(isAnagram(fs,fp)){
                    ans.push_back(i-m+1);
                }
            }
        }
        return ans;        
    }
    // sabbir
};
