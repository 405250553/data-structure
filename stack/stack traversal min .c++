// C++ code
#include <iostream>
#include <stack>        // std::stack<>

class MinStack{ // 宣告了兩個stack
private: 
    std::stack<int> data; // 第一個stack ，存放所有data
    std::stack<int> minstack; // 第二個stack , 
                              // 如果新增的data < minstack.top() 才放入 
public:
    MinStack(){};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
    int getMin();
};

/********
  some function  is already in include<stack> 
  ex: empty(), push(), top()
*********/

void MinStack::Push(int x){

    data.push(x);
    if (minstack.empty() || x < minstack.top()) { // 如果minstack為空 或是 新的data 小於 minstack.top()
        minstack.push(x); // 放入新的(最小)的數值
    }
    else {
        minstack.push(minstack.top()); // 重複放原本(最小)的數值
    }
}

void MinStack::Pop(){

    if (data.empty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    // 將兩個 stack 做 pop 
    data.pop();
    minstack.pop();
}

int MinStack::getMin(){

    if (data.empty()) {
        std::cout << "Stack is empty.\n";
        return -1;
    }

    return minstack.top();
}

bool MinStack::IsEmpty(){

    return data.empty();
}

int MinStack::Top(){

    if (data.empty()) {
        std::cout << "Stack is empty.\n";   // sorry for the bad exception handling
        return -1;                          
    }

    return data.top();
}

int MinStack::getSize(){

    if (data.empty()) {
        std::cout << "Stack is empty.\n";
        return -1;
    }

    return (int)data.size();
}

int main(){

    MinStack s;
    s.Pop();
    s.Push(6);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(13);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(9);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Push(1);
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nmin: " << s.getMin() << std::endl;

    system("pause");
    return 0;
}