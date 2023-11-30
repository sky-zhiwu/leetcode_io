/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 * @lcpr version=30110
 *
 * [2336] 无限集中的最小数字
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
class SmallestInfiniteSet {
private:
    unordered_set<int> set;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        auto it = min_element(set.begin(), set.end());
        int ans = *it;
        set.erase(it);
        return ans;
    }
    
    void addBack(int num) {
        if (set.find(num) == set.end()) set.emplace(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end



