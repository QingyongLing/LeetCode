/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
author=Ling
date=2016.5.27
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
  struct ListNode
  {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 //Runtime: 44 ms
ListNode* mergeKLists(vector<ListNode*>& lists) {
    for (auto c = lists.begin(); c != lists.end();)
        *c == NULL ? c = lists.erase(c) : ++c;
    if (lists.size() == 0)
        return NULL;
    if (lists.size() == 1)
        return lists[0];
    //define min heap compare function
    auto compare = [](ListNode* a, ListNode* b){return a->val > b->val; };
    //find the smallest ListNode as the base List，then insert other node
    make_heap(lists.begin(), lists.end(), compare);
    ListNode* baselist = lists[0];
    ListNode* result = baselist;
    pop_heap(lists.begin(), lists.end(), compare);
    lists.pop_back();
    while (lists.size() != 0)
    {
        ListNode* thesmaller = lists[0];
        //find the place to insert
        while (baselist->next != NULL&&baselist->next->val <= thesmaller->val)
           baselist = baselist->next;
        if (baselist->next == NULL)
        {
            baselist->next = thesmaller;
            pop_heap(lists.begin(), lists.end(), compare);
            lists.pop_back();
            baselist = baselist->next;
            continue;
        }
        //delete the root of min heap
        pop_heap(lists.begin(), lists.end(), compare);
        //get the reference of old root of heap,then  arrange the nodes
        ListNode* &thesmallerref = lists.back();
        ListNode* temp = baselist->next;
        baselist->next = thesmallerref;
        thesmallerref = thesmallerref->next;
        baselist = baselist->next;
        baselist->next = temp;
        if (thesmallerref == NULL)
            lists.pop_back();
        else
            push_heap(lists.begin(), lists.end(), compare);
    }
    return result;
 }
//Runtime: 36 ms
ListNode* mergeKLists2(vector<ListNode*>& lists) {
    vector<ListNode*> allnums;
    for (auto &c : lists)
    {
        while (c != NULL)
        {
            allnums.push_back(c);
            c = c->next;
        }
    }
    if (allnums.size() == 0)
        return NULL;
    if (allnums.size() == 1)
        return allnums[0];
     sort(allnums.begin(), allnums.end(), [](ListNode* &a, ListNode* &b)
    {
        return a->val < b->val;
    });
    for (int i = 0; i < allnums.size()-1; ++i)
    {
        allnums[i]->next = allnums[i + 1];
    }
    allnums[allnums.size() - 1]->next = NULL;
    return allnums[0];
}
};
int main() {
    Solution s;
    using ListNode=Solution::ListNode;
    ListNode a1[] = { -1, 1 };
    ListNode a2[] = { -3, 1, 4 };
    ListNode a3[] = { -2, -1, 0, 2 };
    for (auto i = begin(a1); i < end(a1)-1; ++i)
    {
        i->next = i + 1;
    }
    for (auto i = begin(a2); i < end(a2) - 1; ++i)
    {
        i->next = i + 1;
    }
    for (auto i = begin(a3); i < end(a3) - 1; ++i)
    {
        i->next = i + 1;
    }
    vector<ListNode*> vecl;
    vecl.push_back(a1);
    vecl.push_back(a2);
    vecl.push_back(a3);
    auto result=s.mergeKLists(vecl);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
