/*
 * @lc app=leetcode.cn id=901 lang=cpp
 * @lcpr version=21917
 *
 * [901] 股票价格跨度
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
class StockSpanner {
private:
    int idx = -1;
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        st.emplace(-1, INT_MAX); // 不需要再判断栈为空
    }
    
    int next(int price) {
        this->idx ++;
        
        while (price >= st.top().second) { //空时INT_MAX，会跳出循环
            st.pop();
        }
        int res = idx - st.top().first;
        st.emplace(idx, price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end



/*
// @lcpr case=start
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"][[], [100], [80], [60], [70], [60], [75], [85]]\n
// @lcpr case=end

 */

