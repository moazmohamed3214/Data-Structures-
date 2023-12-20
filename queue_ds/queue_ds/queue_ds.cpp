#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class Queue {
public:
	Node* head;
	Node* tail;
	Queue()
	{
		head = tail = NULL;
	}
	bool isEmpty()
	{
		return (head == NULL && tail==NULL);
	}
	void Enqueu(int data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;
		if (isEmpty())head = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		
		}

	}
	int Dequeu()
	{
		int val = -1;
		if (isEmpty())cout << "Queue is empty,No items to delete." << endl;
		else if (head == tail)
		{
			val = head->data;
			delete head;
			head = tail = NULL;
		}
		else{
			Node* temp = head;
			val = temp->data;
			head = head -> next;
			delete temp;



		}
		return val;
	}
	void Display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;

	}
	int getFront()
	{
		return (head->data);
	}
	int getTail()
	{
		return (tail->data);
	}
	int Count()
	{
		int counter = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;
		}
		return counter;

	}
	bool Search(int data)
	{
		bool found=false;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == data)
			{
				found = true;
				break;
			}
			temp = temp->next;
		}
		return found;

	}
	void Clear()
	{
		while (!isEmpty())
		{
			Dequeu();
		}

	}




};
int main()
{
	Queue q;
	cout << "Enter the number of elements to insert : ";
	int n,num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Enter the element " << i << " to insert : ";
		cin >> num;
		q.Enqueu(num);
		q.Display();
	}
	cout << "The Number that is deleted : " << q.Dequeu() << endl;
	q.Display();
	cout << "The Number that is deleted : " << q.Dequeu()<<endl;
	q.Display();
	cout << "The first element : " << q.getFront() << endl;
	cout << "The last element : " << q.getTail() << endl;
	cout << "Enter the element to search : ";
	cin >> num;
	if (q.Search(num))cout << "The element is Found" << endl;
	else cout << "The element is not found"<<endl;
	cout << "The Number of elements in Queue : " << q.Count()<<endl;
	cout << "Clear the items" << endl;
	q.Clear();
	cout << "the queue after clear " << endl;
	q.Display();


	
   
}

