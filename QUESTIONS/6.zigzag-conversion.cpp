/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans="";
        int n = s.length();
        int nxt = 2*(numRows - 1);
        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j+=nxt){
                 ans+=s[j];
                 if(i>0 && i<numRows-1 && (j + nxt - 2*i) < n) ans+=s[j + nxt - 2*i];
            }
        }
        return ans;
    }
};


// @lc code=end

