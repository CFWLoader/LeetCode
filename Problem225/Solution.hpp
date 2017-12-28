#include <queue>

using std::queue;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        
        if(this->empty())
        {
            queue1.push(x);

            return;
        }

        if(queue1.empty())
        {
            queue1.push(x);

            while(!queue2.empty())
            {
                queue1.push(queue2.front());

                queue2.pop();
            }
        }
        else
        {
            queue2.push(x);

            while(!queue1.empty())
            {
                queue2.push(queue1.front());

                queue1.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        
        if(queue1.empty())
        {
            queue2.pop();
        }
        else
        {
            queue1.pop();
        }

    }

    // Get the top element.
    int top() {
        
        if(queue1.empty())
        {
            return queue2.front();
        }
        else
        {
            return queue1.front();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue1.empty() && queue2.empty();
    }

private:

    queue<int> queue1;

    queue<int> queue2;
};