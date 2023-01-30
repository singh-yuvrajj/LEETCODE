/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Area {
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
            ans = max(ans, currArea);
        }
        return ans;
    }
};
class Solution : Area {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = largestRectangleArea(matrix[0][0]);
        for(int i=0;i<matrix.size();i++){
         for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j] != 0){
                matrix[i][j]+=matrix[i-1][j];
            }
         }
         ans = max(ans , largestRectangleArea(matrix[i][j]));
        }
        return ans;
    }
};
// @lc code=end

