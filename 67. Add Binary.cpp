/*
Problem : https://leetcode.com/problems/add-binary/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string sb = "";

        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;

        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0) {
                int sum = (a[i] - '0') + (b[j] - '0') + carry;
                if(sum&1) sb += '1';
                else sb += '0';
                carry = sum / 2;

                i--;
                j--;
            } else if (i >= 0) {
                int sum = (a[i]- '0') + carry;
                if(sum&1) sb += '1';
                else sb += '0';
                carry = sum / 2;

                i--;
            } else {
                int sum = (b[j] - '0') + carry;
                if(sum&1) sb += '1';
                else sb += '0';
                carry = sum / 2;
                j--;
            }
        }

        if (carry > 0) {
            sb += '1';
        }
        reverse(sb.begin(), sb.end());
        return sb;
    }
};
