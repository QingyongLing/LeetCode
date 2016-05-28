Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.     
You may not alter the values in the nodes, only nodes itself may be changed.     
Only constant memory is allowed.     
For example,     
Given this linked list: 1->2->3->4->5     
For k = 2, you should return: 2->1->4->3->5      
For k = 3, you should return: 3->2->1->4->5      

1. 去除意外条件，如k==1或者head==NULL的情况

2. 定义一个函数找到从起始指针到第k个指针
```cpp
auto KthList = [](ListNode* &start,int k)->ListNode*{
    ListNode* temp = start;
    while (start != NULL&&--k)
        start = start->next;
    return temp;
};
```
函数参数`start`指起始指针，`k`为从起始点第k个中的k，返回起始指针，同时将参数修改为原来的第K个指针。注意使用`--k`。     

3. 定义一个反转函数，将`left`到`right`之间的序列反转     
```cpp
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
```
定义三个指针，behind指向第一个，left指向第二个，front指向left之后的一个指针，将left指向behind，再改变temp，left的值，使其向前移动，直到left==right，最后将left指向前一个节点，完成反转

4. Kth反转    
三个步骤     
（1）获取第一次Kth，若NULL结束，若不是NULL进入下一步     
（2）反转，更新指向，重新寻找Kth    
（3）若Kth为NULL，将剩余部分连接，否则重新进入2     
```cpp
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
```
`front`用于保存反转前的Kth的下一个节点，`before`是指反转前存在的序列的末尾       
这里采用了一个无用的`ListNode nothing = ListNode(0);`用来初始化`before`指针，即假设在一开始就有一个节点要和完成反转的序列进行连接。     
首先获取从起始点第Kth节点，`before->next = right;`,更新指向      
进行反转操作，将`before`设置为`first`，此时的末尾为`first`      
将`right`更新为`front`，然后以此为基准重新寻找kth，直到Kth为`NULL`      
当Kth为`NULL`，如果`first`不为空则还要连接剩余的部分，否则退出       
