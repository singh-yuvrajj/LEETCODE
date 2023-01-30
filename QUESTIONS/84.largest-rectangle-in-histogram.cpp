/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
    public:
    vector<int> nextSmaller;
    vector<int> prevSmaller;
    private:
    void previousSmallerElement(vector<int> &arr, int n)
    {
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++){
         while(st.top()!=-1 && arr[st.top()] >=arr[i]) st.pop();
         prevSmaller[i] = st.top();
         st.push(i);
    }
    }
    void nextSmallerElement(vector<int> &arr, int n)
   {
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        
         while(st.top()!=-1 && arr[st.top()] >=arr[i]) st.pop();
         nextSmaller[i] = st.top();
         st.push(i);
    }
   }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        nextSmaller.resize(n);
        prevSmaller.resize(n);
        nextSmallerElement(heights,n);
        previousSmallerElement(heights,n);
        int ans = 0;
        for(int i = 0;i<n;i++){
            int widthEnd = nextSmaller[i];
            int widthStart = prevSmaller[i];
            if(widthEnd==-1) widthEnd = n;
            int currArea = (widthEnd - widthStart-1)*heights[i];
            if(currArea<=0) currArea = heights[i];
            ans = max(ans, currArea);
        }
        return ans;
    }
};
// @lc code=end

