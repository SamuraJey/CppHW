#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class VersionStack {
public:
    VersionStack() {
        stacks.push_back(stack<int>());
        current_stack = 0;
        next_version = 1;
    }

    void Push(int value) {
        stacks.push_back(stacks[current_stack]);
        current_stack++;
        stacks[current_stack].push(value);
        next_version++;
    }

    void Pop() {
        stacks.push_back(stacks[current_stack]);
        current_stack++;
        stacks[current_stack].pop();
        next_version++;
    }

    void Rollback(int version) 
    {
        if (version < 0 || version >= next_version)
        {
            return;
        }
        current_stack = version;
    }

    void Forget() 
    {
        stacks.clear();
        stacks.push_back(stack<int>());
        current_stack = 0;
        next_version = 1;
    }

    int Top()
    {
        if (stacks[current_stack].empty())
        {
            return -1;
        }
        return stacks[current_stack].top();
    }

private:
    vector<stack<int>> stacks;
    int current_stack;
    int next_version;
};
