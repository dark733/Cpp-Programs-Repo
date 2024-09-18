#include <iostream>
#include <stack>
int stack_function();
int queue_function();
int reverseStack(std::string s);

#define n 100
class stack {
    int *arr;
    int top;

public:
    stack() {

        arr=new int[n];
        top=-1;
    }
    void push(int x) {
        //100-1=99 (0-99)
        if(top==n-1) {
            std::cout<<"stack overflow"<<std::endl;
            return;
        }
        top++;
        arr[top]=x;
        std::cout<<"element - "<<x<<" Pushed!";

    }
    void pop() {
        if(top==-1) {
            std::cout<<"stack underflow"<<std::endl;
            return;
        }
        std::cout<<""<<arr[top];
        top --;

    }
    int top_f() {
        if(top==-1) {
            std::cout<<"No element in stack"<<std::endl;
            return -1;
        }
        return arr[top];
    }
    bool empty() {
        return top==-1;
    }
    void deallocate() {
        std::cout<<"Deallocating array success!"<<std::endl;
        delete[] arr;
    }

};
class queue {
    int *arr;
    int front;
    int back;

public:
    queue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x) {
        if (back == n - 1) {  // Back pointer should be checked for overflow
            std::cout << "queue overflow" << std::endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1) {
            front = 0;  // Initialize front to 0 when the first element is added
        }
        std::cout << "Element - " << x << " Enqueued!" << std::endl;
    }

    void dequeue() {
        if (front == -1 || front > back) {
            std::cout << "queue underflow" << std::endl;
            return;
        }
        std::cout << "Element - " << arr[front] << " Dequeued!" << std::endl;
        front++;
        if (front > back) {
            front = back = -1;  // Reset pointers when the queue becomes empty
        }
    }

    int peak() {
        if (front == -1 || front > back) {
            std::cout << "no elements in queue" << std::endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        return front == -1;
    }

    void deallocate() {
        std::cout << "Deallocating queue array success!" << std::endl;
        delete[] arr;
    }
};


int main() {
    std::string string_rev = "hello from cpp";
    int input;
    std::cout << "Stack and Queue Program" << std::endl;
    std::cout<<"1)Stack Implementation using arrays"<<std::endl;
    std::cout<<"=2)Queue Implementation using arrays"<<std::endl;
    std::cout<<"3)Reverse Stack using lib Implementation"<<std::endl;
    std::cout<<"Choose Option:"<<std::endl;
    std::cin>>input;
    if(input==1) {
        stack_function();
    }
    else if(input==2) {
        queue_function();

    }
    else if(input==3) {
        reverseStack(string_rev);
    }
    else {
        std::cout<<"Wrong Option"<<std::endl;
        return -1;
    }

    return 0;
}
int stack_function() {
    std::cout << "Stack Function" << std::endl;
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);
    st.push(90);
    st.push(100);
    std::cout<<"top most element before pop - "<<st.top_f()<<std::endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    std::cout<<"top most element after pop(5x) - "<<st.top_f()<<std::endl;
    st.deallocate();



    return 0;
}
int queue_function() {
    std::cout << "Queue Function" << std::endl;
    queue qt;
    qt.enqueue(10);
    qt.enqueue(20);
    qt.enqueue(30);
    qt.enqueue(40);
    qt.enqueue(50);

    int peak_el = qt.peak();
    std::cout << "Queue front pointer before dequeue is called = " << peak_el << std::endl;

    qt.dequeue();
    peak_el = qt.peak();
    std::cout << "Queue front pointer after one dequeue = " << peak_el << std::endl;

    qt.dequeue();
    peak_el = qt.peak();
    std::cout << "Queue front pointer after second dequeue = " << peak_el << std::endl;

    qt.deallocate();
    return 0;
}
int reverseStack(std::string s) {

    std::stack<std::string> string_stack_obj;
    for(int i=0;i<s.length();i++) {
        std::string word = " ";
        while(s[i] != ' ' && i<s.length()) {
            word += s[i];
            i++;
        }
        string_stack_obj.push(word);
    }
    while(!string_stack_obj.empty()) {
        std::cout<<string_stack_obj.top()<<std::endl;
        string_stack_obj.pop();
    }
    std::cout<<"Reverse Stack" << std::endl;
    return 0;
}


