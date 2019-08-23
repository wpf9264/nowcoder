/*包含min函数的栈*/
class Solution {
public:
    stack<int> realS;
    stack<int> helpS;
    void push(int value) {
        realS.push(value);
        if (helpS.empty() || value<=helpS.top()){
            helpS.push(value);
        }
    }
    void pop() {
        if (!realS.empty()){
            if (helpS.top()==realS.top()){
                helpS.pop();
            }
            realS.pop();
        }
    }
    int top() {
        if (!realS.empty())
            return realS.top();
    }
    int min() {
        if (!realS.empty())
            return helpS.top();
    }
};
