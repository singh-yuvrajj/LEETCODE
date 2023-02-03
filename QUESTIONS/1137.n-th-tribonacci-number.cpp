/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    vector<int> dp;
    int calc(int n){
        if(n<=2) return n==0?0:1;
        if(dp[n]==-1) dp[n] = calc(n-3) + calc(n-2) + calc(n-1);
        return dp[n];
    }
    int tribonacci(int n) {
        dp.resize(n+1,-1);
        return calc(n);
    }
};
// @lc code=end

