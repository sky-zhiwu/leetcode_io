/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 * @lcpr version=21917
 *
 * [2251] 花期内花的数目
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
    int erfen(vector<vector<int>>& flowers, int x) {
        int n = flowers.size();
        int start, end;
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            // 找第一个f[1] >= x 和第一个f[0] > x
            if (mid == n) break;
            if (flowers[mid][1] < x) l = mid + 1;
            else r = mid;
        }
        start = l;
        if (start == n) return 0;
        l = 0; r = n;
        while (l < r) {
            int mid = l + r >> 1;
            // 找第一个f[1] >= x 和第一个f[0] > x
            if (mid == n) break;
            if (flowers[mid][0] <= x) l = mid + 1;
            else r = mid;
        }
        end = r;
        // if (r == n - 1) {
        //     end = (x <= flowers[r][1]) ? n : r;
        // } 
        cout << " start: " << start << " end :" << end << " \n";
        if (start > end) return 0;
        return (start > end) ? 0 : end - start;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        for (auto f : flowers) cout << " " << f[0] << " " << f[1] << "\n";

        for (int i = 0; i < flowers.size() - 1; i ++) {
            if (flowers[i][1] > flowers[i + 1][1]) { // 需要隔断区间
                auto pre = flowers[i][1];
                flowers[i][1] = flowers[i + 1][1];
                if (i + 2 == flowers.size()) {
                    flowers.push_back({flowers[i + 1][1] + 1, pre});
                }
                else flowers.insert(flowers.begin() + i + 2, {flowers[i + 1][1] + 1, pre});
                
            }
        }
        // sort(flowers.begin(), flowers.end());
        // cout << " " << flowers.size() << "\n";
        for (auto f : flowers) cout << " " << f[0] << " " << f[1] << "\n";
        vector<int> res1;
        for (auto p : people) {
            res1.push_back(erfen(flowers, p));
        }
        return res1;


    
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,6],[3,7],[9,12],[4,13]]\n[2,3,7,11,14]\n
// @lcpr case=end

// @lcpr case=start
// [[1,10],[3,3]]\n[3,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [[21,34],[17,37],[23,43],[17,46],[37,41],[44,45],[32,45]]\n[31,41,10,12]\n
// @lcpr case=end

 */

