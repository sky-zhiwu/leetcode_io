/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=21913
 *
 * [42] 接雨水
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        /* 1. 前后缀分解
           2. 相向双指针
           3. 单调栈*/
        // 1 时间复杂度O(n); 空间复杂度O(n) -->空间上可以优化（方法2）
        int n = height.size();
        /*
        vector<int> pre(n, 0), suf(n, 0); 
        pre[0] = height[0];
        for (int i = 1; i < n; i ++) pre[i] = max(height[i], pre[i - 1]);

        suf[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i --) suf[i] = max(suf[i + 1], height[i]);

        int sum = 0;
        for (int i = 0; i < n; i ++) sum += min(suf[i], pre[i]) - height[i];

        return sum; */

        // 2 时间复杂度O(n); 空间复杂度O(1)
        /*int sum = 0, l = 0, r = n - 1, pre_max = 0, suf_max = 0;
        while (l < r) {
            pre_max = max(pre_max, height[l]); //更新前后缀最大值
            suf_max = max(suf_max, height[r]);
            if (pre_max < suf_max) {
                sum += pre_max - height[l];
                l ++;
            }
            else {
                sum += suf_max - height[r];
                r --;
            }
        }

        return sum;*/

        // 3
        stack<int> st;
        int res = 0;
        for (int i = 0; i < n; i ++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int t = st.top();
                st.pop();
                if (!st.empty()) res += (i - 1 - st.top()) * (min(height[i], height[st.top()]) - height[t]);
            }
            st.emplace(i);
            
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

