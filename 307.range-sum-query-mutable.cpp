/*
 * @lc app=leetcode.cn id=307 lang=cpp
 * @lcpr version=30109
 *
 * [307] 区域和检索 - 数组可修改
 */


// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class NumArray {
private:
    vector<int> nums;
    vector<int> sums;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        sums.resize(n + 1, 0);
        for (int i = 0; i < nums.size(); i ++) sums[i+1] = sums[i] + nums[i];
    }
    
    void update(int index, int val) {
        int x = val - nums[index];
        nums[index] = val;
        while (index < n) sums[++index] += x;
    }
    
    int sumRange(int left, int right) {
        return sums[right+1] - sums[left];
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumArray", "sumRange", "update", "sumRange"][[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]\n
// @lcpr case=end

 */

