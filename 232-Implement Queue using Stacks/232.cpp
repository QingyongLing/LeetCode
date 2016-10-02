#include <iostream>
#include <stack>
using namespace std;
/*
Implement the following operations of a queue using stacks.
• push(x) -- Push element x to the back of queue.
• pop() -- Removes the element from in front of queue.
• peek() -- Get the front element.
• empty() -- Return whether the queue is empty.
Notes:
•You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
•Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
•You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        nums.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp;
        while (!nums.empty()) {
            temp.push(nums.top());
            nums.pop();
        }
        temp.pop();
        while (!temp.empty()) {
            nums.push(temp.top());
            temp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> temp;
        int value;
        while (!nums.empty()) {
            temp.push(nums.top());
            nums.pop();
        }
        value = temp.top();
        while (!temp.empty()) {
            nums.push(temp.top());
            temp.pop();
        }
        return value;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return nums.empty();
    }
private:
    stack<int> nums;
};
int main() {    
    system("pause");
    return 0;
}