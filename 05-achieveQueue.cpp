/*用两个栈实现一个队列*/
#include <assert.h>
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        assert(stack2.size()>0);
        int res=stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;//用于入队
    stack<int> stack2;//用于出队
};
