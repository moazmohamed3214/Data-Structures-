#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;

};
class LinkedList {
public:
	Node* head;
	LinkedList()
	{
		head = NULL;
	}
	bool isEmpty()
	{
		return(head == NULL);
	}
	void insertFirst(int data)
	{
		Node* temp=new Node();
		temp->data = data;
		temp->next = NULL;
		if (isEmpty())head = temp;
		else
		{
			temp->next = head;
			head = temp;

		}

	}
	void insertBefore(int item,int newItem)
	{
		if (isEmpty())insertFirst(newItem);
		else
		{

			if (IsFound(item))
			{
				Node* temp = head;
				Node* newNode = new Node();
				newNode->data = newItem;
				while (temp != NULL)
				{
					if (temp->next->data == item)
					{
						break;

					}
					temp = temp->next;

				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
			else cout << "The item is not found.";

		}
	}
	void Append(int data)
	{
		if (isEmpty())insertFirst(data);
		else
		{
			Node* newNode = new Node();
			newNode->data = data;
			Node* temp=head;
			while (temp->next != NULL)temp = temp->next;
			temp->next = newNode;
			newNode->next = NULL;

		}
	}
	void Display()
	{
		Node* temp=head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;


		}
		cout << endl;
	}
	int Count()
	{
		Node* temp = head;
		int counter = 0;
		while (temp != NULL)
		{
			counter++;
			temp = temp->next;


		}
		return counter;
	}
	bool IsFound(int item)
	{
		bool found=false;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == item)
			{
				found = true;
				break;
			}
			temp = temp->next;
			

		}
		return found;
		
	}
	void Delete(int item)
	{
		Node* delptr = head;
		if (isEmpty())cout << "The list is empty,No Item to delete ";
		if (head->data == item)
		{
			
			head = head->next;
			delete delptr;
		}
		else
		{
			Node* prev = NULL;
			while (delptr->data != item)
			{
				prev = delptr;
				delptr = delptr->next;
				
			}
			prev->next = delptr->next;
			delete delptr;




		}
	}




};
int main()
{
   
   LinkedList l;
   if (l.isEmpty())cout << "The List is Empty\n";
   else cout << "The list contians : "<<l.Count()<<endl;
   int n,item;
   cout << "Enter The Number of elements to insert in list : ";
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
	   cout << "Enter item"<<i<<" to List : ";
	   cin >> item;
	   l.insertFirst(item);
	   l.Display();


   }
   cout << "Enter The element to search : ";
   cin >> item;
   if (l.IsFound(item))cout << "the element is found " << endl;
   else cout << "the element is not found " << endl;;


   cout << "Append to list ";
   cin >> item;
   l.Append(item);
   l.Display();

   cout << "Enter item to delete : ";
   cin >> item;
   l.Delete(item);
   l.Display();
   
   
}


