/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=21917
 *
 * [146] LRU 缓存
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

class Node {
public:
    int key, val;
    Node *pre, *next;

    Node(int x = 0, int y = 0) : key(x), val(y) {}
};

class LRUCache {
private:
    int n;
    Node* dummy; //哨兵节点
    unordered_map<int, Node*> cache;

    void remove(Node* x) { //删除x节点
        x->pre->next = x->next;
        x->next->pre = x->pre;
    }
    
    void pushfront(Node* x) { 
        x->pre = dummy;
        x->next = dummy->next;
        x->pre->next = x;
        x->next->pre = x;
    } 

    Node* getnode(int key) { //得到key的节点
        auto it = cache.find(key);
        if (it == cache.end()) return nullptr; //没有
        auto node = it->second;
        remove(node); //把这本书拿出来
        pushfront(node);
        return node; //拿出来放到最前面
    }
    
public:
    LRUCache(int capacity) {
        n = capacity;
        //初始化，每个key和value为-1
        dummy = new Node();
        dummy->next = dummy;
        dummy->pre = dummy;
    }
    
    int get(int key) {
        auto node = getnode(key);
        return node ? node->val : -1;
    }
    
    void put(int key, int value) {
        auto node = getnode(key);
        if (node) { //key一开始存在于cache
            node->val = value;
            return;
        }
        else { //key一开始不存在于cache
            cache[key] = node = new Node(key, value);
            pushfront(node);
            if (cache.size() > n) {
                // cache满
                auto backnode = dummy->pre;
                cache.erase(backnode->key);
                remove(backnode);
                delete(backnode); //释放内存
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



