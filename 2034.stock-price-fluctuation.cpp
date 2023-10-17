/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 * @lcpr version=21917
 *
 * [2034] 股票价格波动
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class StockPrice {
private:
    map<int, int> map;
    vector<queue<int>> q;
    int newtime; //记录最新的时间戳
public:

    StockPrice() {
        newtime = 0;
    }
    
    void update(int timestamp, int price) {
        if (map.find(timestamp) != map.end()) map[timestamp] = price;
        else {
            map.emplace(timestamp, price);
            newtime = timestamp;
        }
    }
    
    int current() {
        return map[newtime];
    }
    
    int maximum() {
        int resmax = 0;
        for (auto it = map.begin(); it != map.end(); it ++) {
            resmax = max(resmax, it->second);
        }
        return resmax;
    }
    
    int minimum() {
        int resmin = INT_MAX;
        for (auto it = map.begin(); it != map.end(); it ++) {
            resmin = min(resmin, it->second);
        }
        return resmin;

    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end



/*
// @lcpr case=start
// ["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"][[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]\n
// @lcpr case=end

 */

