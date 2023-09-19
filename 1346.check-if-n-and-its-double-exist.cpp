/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 * @lcpr version=21913
 *
 * [1346] 检查整数及其两倍数是否存在
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
    bool checkIfExist(vector<int>& arr) {
        /*auto it = find(arr.begin(), arr.end(), 0);
        if (distance(arr.begin(), it) == arr.size() - 1 - distance(arr.rbegin(), find(arr.rbegin(), arr.rend(), 0))) {
            arr.erase(it);
        }
        vector<float> a;
        for (auto ar : arr) {
            a.push_back(ar * 1.0 / 2);
        }
        
        // sort(a.begin(), a.end());
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < a.size(); i ++) {
            int l = 0, r = arr.size() - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (arr[mid] == a[i]) return true;
                else if (arr[mid] < a[i]) l = mid + 1;
                else r = mid;
            }
            if (a[i] == arr[l]) return true;
        }
        return false;*/
    
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i ++) {
            int l = 0, r = arr.size() - 1;
            while (l < r) {
                int mid = l + r >> 1;
                //mid != i为了防止0
                if (arr[mid] == arr[i] * 2 && mid != i) return true;
                if (arr[mid] < arr[i] * 2) l = mid + 1;
                else r = mid;
            }
            if (arr[l] == arr[i] * 2 && l != i) return true;
        }
        return false;


    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,1,14,11]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,10,-19,4,6,-8]\n
// @lcpr case=end

 */

