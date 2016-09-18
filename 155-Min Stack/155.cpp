#include <iostream>
#include <list>
using namespace std;
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
• push(x) -- Push element x onto stack.
• pop() -- Removes the element on top of the stack.
• top() -- Get the top element.
• getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack():minstack(),minelem() {

    }

    void push(int x) {
        if (minstack.empty()) {
            minstack.push_back(x);
            minelem.push_back(x);
        }else{
            minstack.push_back(x);
            if (x <= minelem.back())
                minelem.push_back(x);
        }
    }

    void pop() {
        if (!minstack.empty()) {
            if (minstack.back() == minelem.back())
                minelem.pop_back();
            minstack.pop_back();
        }
    }

    int top() {
        return minstack.back();
    }

    int getMin() {
        return minelem.back();
    }
private:
    list<int> minstack;
    list<int> minelem;
};
int main() {
    MinStack s;
    system("pause");
    return 0;
}