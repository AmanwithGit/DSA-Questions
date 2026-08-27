// LeetCode 84
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int current = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > current) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                ans = max(ans, h * width);
            }

            st.push(i);
        }

        return ans;
    }
};