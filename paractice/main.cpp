#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return(top == NULL);
    }
    void Push(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;

        }


    }
    int Pop()
    {
        int value;
        if (isEmpty())return 0;
        else
        {
            Node* temp = top;
            value = temp->data;
            top = top->next;
            delete temp;
            return value;



        }

    }
    int Peek()
    {
        if (isEmpty())return 0;
        else return top->data;

    }
    void Display()
    {
        if (isEmpty())cout << "The Stack is Empty." << endl;
        else
        {
            cout << "Stack content : ";
            Node* temp = top;
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    int Count()
    {
        int counter = 0;
        Node* temp=top;
        while (temp != NULL)
        {
            counter++;
            temp=temp->next;
        }
        return counter;

    }
    bool Search(int item)
    {
        bool IsFound = false;
        Node* temp = top;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                IsFound = true;
                break;
            }
            else temp = temp->next;
        }
        return IsFound;
    }
    bool isFull()
    {
        Node* ptr = new Node();
        if (ptr == NULL)
        {
            return true;
        }
        else return false;

    }


};

int main()
{
    Stack s1;
    cout << "Enter the number of elements to insert in Stack : ";
    int n,item;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter item to Stack : ";
        cin >> item;
        s1. Push(item);
        s1.Display();
    }

    cout << s1.Pop() <<" deleted from stack." << endl;;
    s1.Display();
    cout << s1.Pop() << "deleted from stack." << endl;;
    s1.Display();
    cout << "Enter element to search for :  ";
    cin >> item;
    if (s1.Search(item))cout << "the element is found." << endl;
    else cout << "The element is not found." << endl;
    cout << "The number of elements in stack " << s1.Count()<<endl;
    if (s1.isFull())cout << "the stack is full." << endl;
    else cout << "the stack is not full" << endl;



}
