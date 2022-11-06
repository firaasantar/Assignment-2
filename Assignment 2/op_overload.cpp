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

    /*
    requires: 2 stacks 
    effects: returns a new stack with the values of both previous 
    stacks
    testing strategy:
    1) calling on 1 empty stack
    2) calling on 2 empty stacks
    3) have one stack shorter than the other
    4) have both stacks of equal size
    5) concatinating sevral stacks
    */
    Stack<T> operator+(const Stack<T> &other)
    {
        Stack<T> newStack;
        for (int i = 0; i < stack.size(); i++)
        {
            newStack.push(stack[i]);
        }
        for (int i = 0; i < other.stack.size(); i++)
        {
            newStack.push(other.stack[i]);
        }
        return newStack;
    }

private:
    vector<T> stack;
};

int main()
{
    Stack<int> a, b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack<int> c = a + b + a;
    cout << c.top() << endl;
    return 0;
}
