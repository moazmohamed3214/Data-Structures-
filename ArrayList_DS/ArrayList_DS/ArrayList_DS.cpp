#include <iostream>
using namespace std;
class Array {
private:
	int size;
	int* myArray;
	int lenght;
public:
	Array(int arrSize)
	{
		size = arrSize;
		lenght = 0;
		myArray = new int[arrSize];
	}
	void Fill()
	{
		cout << "How many items you want to fill ? ";
		int numOfItems;
		cin >> numOfItems;
		if (numOfItems > size)
		{
			cout << "you canot exceed the array size" << endl;
			return;
		}
		else
		{
			for (int i = 0; i < numOfItems; i++)
			{
				cout << "Enter item no" << i + 1 << " : ";
				cin >> myArray[i];
				lenght++;
			}

		}
		
		
	}
	void display()
	{
		cout << "Array content\n";
		if (lenght == 0)cout << "The array is Empty." << endl;
		else
		{
			for (int i = 0; i <lenght; i++)
			{
				cout << myArray[i]<<"\t";
			}
		}
		cout << endl;
	}
	int getSize()
	{
		return size;
	}
	int getLength()
	{
		return lenght;
	}
	int search(int key)
	{
		int index = -1;
		
		for (int i = 0; i < lenght; i++)
		{
			if (myArray[i] == key)
			{
				index = i+1;
				break;
			}
			

		}
		return index;
		
	}
	void Append(int newitem)
	{
		if (lenght < size)
		{
			myArray[lenght] = newitem;
			lenght++;
		}
		else cout << "Array is Full";

	}
	void insert(int index, int newItem)
	{
		index -= 1;
		if (index>=0&&index<=size)
		{
			
			for (int i = lenght; i >index; i--)
			{
				myArray[i] = myArray[i - 1];
			}
			myArray[index] = newItem;
			lenght++;
		}
		else cout << "Error-Index out of range."<<endl;
	}
	void Delete(int index)
	{
		index -= 1;
		if (index >= 0 && index <= size)
		{

			for (int i = index; i<lenght-1; i++)
			{
				myArray[i] = myArray[i+1];
			}
			
			lenght--;
		}

	}
	void Enlarge(int newArraySize)
	{
		int* old = myArray;
		int* myArray = new int[newArraySize];
		if (newArraySize >size)
		{
			for (int i = 0; i < lenght; i++)
			{
				myArray[i] = old[i];
			}
			size = newArraySize;
			delete[]old; 
		}
		else
		{
			cout << "New Size must be larger than current size.";
			return;
		}



	}
	void Merge(Array other)
	{
		int newSize = size + other.getSize();
		size = newSize;
		int* old = myArray;
		myArray = new int[size];
		int i;
		for (i = 0; i <lenght; i++)
		{
			myArray[i] = old[i];
		}
		delete[] old;
		int j = i;
		for (int i= 0; i < other.getLength(); i++)
		{
			myArray[j++] = other.myArray[i];
			
		}
		lenght += other.getLength();
	}
};

int main()
{
	cout << "Hello This is ArrayADT demo,.. " << endl;
	cout << "Enter the size Array : ";
	int n;
	cin >> n;
	Array list(n);
	list.Fill();
	list.display();
	//displau the size and length
	cout <<"Array size = "<< list.getSize() << "\tArray Length : " << list.getLength() << endl;
	//search for one element 
	cout << "Enter the value to search for : ";
	int key;
	cin >> key;
	int ind=list.search(key);
	if (ind == -1)cout << "The value is not exist."<<endl;
	else cout << "The value is exist @ postion in"<<ind<<endl;
	//add element from end 
	cout << "Enter new item from the end : ";
	int newItem;
	cin >> newItem;
	list.Append(newItem);
	list.display();
	//insert new item 
	cout << "To insert new item ,Enter index and item : ";
	int index, item;
	cin >> index >> item;
	list.insert(index, item);
	list.display();
	cout << "Array size = " << list.getSize() << "\tArray Length : " << list.getLength() << endl;
	//delete element by index
	cout << "Enter the index to delete : ";
	int deleteIndex;
	cin >> deleteIndex;
	list.Delete(deleteIndex);
	list.display();
	cout << "Array size = " << list.getSize() << "\tArray Length : " << list.getLength() << endl;
	//create new size of array 
	cout << "Enter new size : ";
	int newSize;
	cin >> newSize;
	list.Enlarge(newSize);
	cout << "Array size = " << list.getSize() << "\tArray Length : " << list.getLength() << endl;
	//merge between two array
	Array other(5);
	other.Fill();
	list.Merge(other);
	list.display();
	cout << "Array size = " << list.getSize() << "\tArray Length : " << list.getLength() << endl;

}

