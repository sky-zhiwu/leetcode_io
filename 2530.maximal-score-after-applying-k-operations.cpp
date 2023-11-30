/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 * @lcpr version=30102
 *
 * [2530] 执行 K 次操作后的最大分数
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        //1.
        // function<int(int)> ceil = [&] (int x) {
        //     return x / 3 + ((x % 3 == 0) ? 0 : 1);
        // };

        // map<int, int> map;
        // for (int n : nums) map[n] ++;
        // long long sum = 0;
        // while (k --) {
        //     auto it = map.end();
        //     it --;
            
        //     sum += (*it).first;
            
        //     map[ceil((*it).first)] ++;
        //     if (-- map[(*it).first] == 0) map.erase(it);
        // }
        // return sum;

        //2.
        // 原地堆化（heapify）可以做到 O(1) 的空间复杂度。
        // priority_queue< type, container, function>
        // priority_queue<int> pq(less<int>(), move(nums));
        // long long sum = 0;
        // while (k --) {
        //     int x = pq.top();
        //     sum += x;
        //     pq.pop();
        //     pq.push((x + 2) / 3);
        // }
        // return sum;

        // 3.
        make_heap(nums.begin(), nums.end()); //原地建堆，默认大顶堆
        long long sum = 0;
        while (k --) {
            pop_heap(nums.begin(), nums.end()); //把最大元素(堆顶)放到最后
            sum += nums.back();
            nums.back() = (nums.back() + 2) / 3;
            push_heap(nums.begin(), nums.end()); //末尾元素入堆
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,10,10,10,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,10,3,3,3]\n3\n
// @lcpr case=end

// @lcpr case=start
[672579538,806947365,854095676,815137524]\n3\n
// @lcpr case=end

 */
