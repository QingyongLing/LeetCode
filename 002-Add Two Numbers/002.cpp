//   You are given two linked lists representing two non - negative numbers.
//The digits are stored in reverse order and each of their nodes contain
//a single digit.Add the two numbers and return it as a linked list.
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//   Output : 7 -> 0 -> 8

#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *list = NULL, *listtemp = NULL;
		bool flag = false;
		list = new ListNode(0);
		listtemp = list;
		while (l1 != NULL||l2 != NULL)
		{
			int temp, templ1, templ2;
			templ1 = l1 != NULL ? l1->val : 0;
			templ2 = l2 != NULL ? l2->val : 0;
			temp = templ1 + templ2 + flag;
			flag = temp / 10;
			//temp = temp % 10;
			temp = flag ? temp - 10 : temp;
			listtemp->next = new ListNode(temp);
			listtemp = listtemp->next;
			l1 = l1 != NULL ? l1->next : l1;
			l2 = l2 != NULL ? l2->next : l2;
		}
		listtemp->next = flag ? new ListNode(1) : NULL;
		listtemp = list->next;
		delete list;
		return listtemp;
	}
};
int main()
{

}
