#include <iostream>
using namespace std;
const int maxSize = 100;
template<class t>
class Stack {
    int top;
    t items[maxSize];
public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return(top == maxSize-1);
    }
    void push(t x)
    {
        if (isFull())cout << "Stack is full,No items to insert." << endl;
        else
        {
            top++;
            items[top] = x;
        }
    }
    void pop()
    {
        if(isEmpty())cout << "Stack is empty,No items to delete." << endl;
        else top--;
        
    }
    int popThenVal()
    {
        t val = -1;
        if (isEmpty())return val;
        else
        {
            val = items[top];
            top--;
            return val;
        }

    }

    void getTop()
    {
        if (isEmpty())cout << "stack is Empty" << endl;
        else cout<<items[top]<<endl;
    }
    void Display()
    {
        if (isEmpty())cout << "stack is Empty" << endl;
        else
        {
           for (int i = top; i >=0; i--)cout << items[i] << "\t";
           cout << endl;
        }
       
    }


};
int main()
{
    Stack<double> s;
    int n;
    double num;
    cout << "Enter the number of element to inset in stack : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter th number " << i << " to insert : ";
        cin >> num;
        s.push(num);
        s.Display();

    }

    cout << "the elelment in top is :"; 
    s.getTop();
 
    cout << "The stack after deleting one element : ";
    s.pop();
    s.Display();
    
}

