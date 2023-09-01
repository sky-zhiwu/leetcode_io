// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=852 lang=cpp
 * @lcpr version=21913
 *
 * [852] 山脉数组的峰顶索引
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
    int peakIndexInMountainArray(vector<int>& arr) {
            int l = 0, r = arr.size() - 1;
            while (l <= r ) {
                int mid = l + r >> 1;

                if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) return mid;
                if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) l = mid;
                else r = mid;
                // cout << mid << ' ' << l << " " << r << '\n'; 
        }
            return l;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [24,69,100,99,79,78,67,36,26,19]\n
// @lcpr case=end

// @lcpr case=start
// [3,5,3,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,10,5,2]\n
// @lcpr case=end

 */

