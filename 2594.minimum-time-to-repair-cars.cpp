/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 * @lcpr version=21913
 *
 * [2594] 修车的最少时间
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
#include<cmath>
// @lc code=start
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        //二分
        
        long long l = 0, r = ranks[0] * pow(cars, 2);
        // long long l = 1, r = 1e14;
        while (l < r)
        {
            long long t = (l + r) / 2;
            long long sum = 0;
            for (int i = 0; i < ranks.size(); i ++) {
                sum += sqrt(t / ranks[i]);
                if (sum >= cars) {r = t; break;}
            }
            
            if (sum < cars) l = t + 1;
        }
        return l;
        

    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,3,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [5,1,8]\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,7,9]\n10\n
// @lcpr case=end

 */

