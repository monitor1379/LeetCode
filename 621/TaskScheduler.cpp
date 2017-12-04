#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// https://leetcode.com/problems/task-scheduler/description/

template<typename T>
void display_vector(vector<T> &v) {
    for (T i: v)
        cout << i << ", ";
    cout << endl;
}

class Solution {
public:
    /*
     * Approach: Priority queue.
     *
     * Assume there are four tasks:
     *      A B C D
     *      4 2 2 1
     * and n is 2, '*' mean idle.
     *
     * Then the best schedule is:
     *      A B C
     *      A B C
     *      A D *
     *      A
     *
     */
    int leastInterval(vector<char>& tasks, int n) {
        // 统计每种任务的数量
        map<char, int> m;
        for(auto c: tasks) m[c] += 1;

        // 使用优先队列维护任务数量
        priority_queue<int> q;
        for(auto ite: m) q.push(ite.second);

        int result = 0;
        vector<int> tmp;
        while(!q.empty()) {
            int validInsert = 0;
            // 开始一轮调度，一轮调度跑n+1个任务
            for(int i = 0; i <= n; ++i) {
                if(!q.empty()) {
                    if(q.top() > 1) tmp.push_back(q.top() - 1);
                    q.pop();
                    ++validInsert;
                }
            }
            // 由于最后一轮任务无需idle，因此需要记录与判断有效的任务
            if(!tmp.empty())
                result += n + 1;
            else
                result += validInsert;

            for(auto i: tmp) q.push(i);
            tmp.clear();
        }
        return result;
    }
};


int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D'};
    Solution s;
    cout << s.leastInterval(tasks, 3) << endl;
    return 0;
}