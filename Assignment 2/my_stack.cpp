#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cstddef>
#include <cstdio>

using namespace std;

template <typename T>
class Stack
{
public:
    Stack() {}

    /*
    requires: nothing
    effects: returns true if stack is empty, returns false otherwise
    testing strategy: 
    1) passing a empty stack
    2) passing a non empty stack
    */
    bool empty() const
    {
        return stack.empty();
    }

    /*
    requires: a constant refernce of any type
    effects: pushes the last item in the stack
    testing strategy: 
    1) pushing a non empty stack
    2) pushing an empty stack
    3) pushing an integer
    4) pushing a char
    5) pushing a float
    6) pushing a double
    7) pushing a long
    */
    void push(const T &item)
    {
        stack.push_back(item);
    }

    /*
    requires: nothing
    effects: returns the top element of the stack
    testing strategy: 
    1) calling on a non empty stack
    2) calling on an empty stack
    */
    T &top()
    {
        return stack.back();
    }

    /*
    requires: nothing
    effects: returns the top element of the stack
    testing strategy: 
    1) calling on a non empty stack
    2) calling on an empty stack
    */
    const T &top() const
    {
        return stack.back();
    }

    /*
    requires: nothing
    effects: returns the top element of the stack and removes
    testing strategy: 
    1) calling on a non empty stack
    2) calling on an empty stack
    */
    void pop()
    {
        stack.pop_back();
    }

private:
    vector<T> stack;
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.empty() << endl;
    return 0;
}
