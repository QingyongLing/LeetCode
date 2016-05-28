/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
 Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

author=Ling
date=2016.5.28
*/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
//Runtime: 24 ms
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL||head->next==NULL||k<=1)
        return head;
    auto KthList = [](ListNode* &start,int k)->ListNode*{
        ListNode* temp = start;
        while (start != NULL&&--k)
            start = start->next;
        return temp;
    };
    auto rever = [](ListNode* left, ListNode* right)
    {
        ListNode* behind = NULL, *front = NULL;
        do
        {
            front = left->next;
            left->next = behind;
            behind = left;
            left = front;
        } while (left!=right);
        right->next = behind;
    };
    ListNode* result = head;
    ListNode* left = KthList(result, k);
    if (result == NULL)
        return head;
    else
    {
        ListNode* right = result;
        ListNode* front = result->next;
        ListNode  nothing = ListNode(0);
        ListNode* before = &nothing;
        while (1)
        {
            before->next = right;
            rever(left, right);
            before = left;
            right = front;
            left = KthList(right, k);
            if (right == NULL)
            {
                if (left != NULL)
                    before->next = left;
                break;
            }
            front = right->next;
        }
    }
    return result;
  }
};
int main(int argc, char const *argv[])
{
    Solution s;
    using ListNode=Solution::ListNode;
    ListNode a3[] = { -2, -1, 0, 2 };
    for (auto i = begin(a3); i < end(a3) - 1; ++i)
    {
        i->next = i + 1;
    }
    auto result=s.reverseKGroup(a3,3);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
