#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
*/
class Solution {
public:
    struct RandomListNode {
        int label;
        RandomListNode *next, *random;
        RandomListNode(int x) : label(x), next(NULL), random(NULL) {}       
    };
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> map;
        return copyList(map, head);
    }
private:
    RandomListNode *copyList(unordered_map<RandomListNode *, RandomListNode *>&map, RandomListNode *head) {
        if (head == NULL)
            return NULL;
        auto iter = map.find(head);
        if (iter != map.end()) {
            return iter->second;
        }
        iter=map.insert(make_pair(head, new RandomListNode(head->label))).first;
        iter->second->next = copyList(map, head->next);
        iter->second->random = copyList(map, head->random);
        return iter->second;
    }
};
int main() {
    Solution s;
    system("pause");
    return 0;
}