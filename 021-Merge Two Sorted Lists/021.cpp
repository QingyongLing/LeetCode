/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

author=Ling date=2016.5.24
*/
#include <stdio.h>
class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
public:
    //Runtime: 8 ms
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL)
        {
            return l1 == NULL ? l2 : l1;
        }
        ListNode *basenext = NULL, *insertnext = NULL, *baselist = NULL, *insertlist = NULL;
        if (l1->val < l2->val)
        {
            baselist = l1;
            insertlist = l2;
        }
        else
        {
            baselist = l2;
            insertlist = l1;
        }
        while (1)
        {
            if (insertlist == NULL)
                break;
            if (baselist->next == NULL&&insertlist != NULL)
            {
                baselist->next = insertlist;
                break;
            }
            if (baselist->next->val < insertlist->val)
            {
                baselist = baselist->next;
            }
            else
            {
                /*
                baselist   ---> basenext
                insertlist ---> insertnext
                => baselist ---> insertlist(new baselist) ---> basenext
                   insertnext(new insertlist) --->  ...
                */
                basenext = baselist->next;
                insertnext = insertlist->next;
                baselist->next = insertlist;
                insertlist->next = basenext;
                baselist = baselist->next;
                insertlist = insertnext;
            }
        }
        return l1->val < l2->val ? l1 : l2;
    }
};
