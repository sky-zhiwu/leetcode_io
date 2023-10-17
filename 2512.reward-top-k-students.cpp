/*
 * @lc app=leetcode.cn id=2512 lang=cpp
 * @lcpr version=21917
 *
 * [2512] 奖励最顶尖的 K 名学生
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
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
         vector<int> score(report.size(), 0);
        unordered_map<string, int> posi, nega;
        for (auto p : positive_feedback) posi[p] ++;
        for (auto n : negative_feedback) nega[n] ++;

        unordered_map<int, int> stu;
        for (int i = 0; i < student_id.size(); i ++) stu[student_id[i]] = i;

        sort(student_id.begin(), student_id.end());
        reverse(student_id.begin(), student_id.end());

        vector<string> report_copy(student_id.size(), "");
        for (int i = 0; i < student_id.size(); i ++) report_copy[i] = report[stu[student_id[i]]];

        int idx = 0;
        for (auto r : report_copy) {
            string s = "";
            for (char c : r) {
                if (c != ' ') s.push_back(c);
                else {
                    if (posi.find(s) != posi.end()) score[idx] += 3;
                    if (nega.find(s) != nega.end()) score[idx] -= 1;
                    s = "";
                }
            }
            if (posi.find(s) != posi.end()) score[idx] += 3;
            if (nega.find(s) != nega.end()) score[idx] -= 1;
            idx ++;
        }

        vector<pair<int, int>> p;
        for (int i = 0; i < score.size(); i ++) p.push_back({score[i],i});
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());

        vector<int> res(k, 0);
       

        for (int i = 0; i < k; i ++) {
            res[i] = student_id[p[i].second];
        }
        return res;

    }
};
// @lc code=end



/*
// @lcpr case=start
// ["smart","brilliant","studious"]\n["not"]\n["this student isstudious","the student is smart"]\n[1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["smart","brilliant","studious"]\n["not"]\n["this student is notstudious","the student is smart"]\n[1,2]\n2\n
// @lcpr case=end

 */

