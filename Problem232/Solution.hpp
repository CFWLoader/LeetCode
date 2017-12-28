#include <stack>

using std::stack;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        
        if(this->empty())
        {
            stack1.push(x);

            return;
        }

        while(!stack1.empty())
        {
            stack2.push(stack1.top());

            stack1.pop();
        }

        stack1.push(x);

        while(!stack2.empty())
        {
            stack1.push(stack2.top());

            stack2.pop();
        }

        printf("Stack Size: %d.\n", stack1.size());
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack1.pop();
    }

    // Get the front element.
    int peek(void) {
        return stack1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack1.empty() && stack2.empty();
    }

private:

    stack<int> stack1;

    stack<int> stack2;
};