// LinkList_2taraf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

class linklist
{
	node* head;
public:
	linklist()
	{
		head = NULL;
	}

	void Insert_afterHead(int item)
	{
		node* temp = new node;
		if (head == NULL)
		{
			temp->data = item;
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			return;
		}
		temp->data = item;
		temp->next = head->next;
		temp->prev = head;
		head->next = temp;
		head->next->prev = temp;

		//delete temp;
		return;
	}

	void Delete(int item)
	{
		int data;
		node* Copy = head;
		if (Copy == NULL)
		{
			cout << "\n!!! Don't have any List\n";
			return;
		}
		if (Copy->data == item)
		{
			cout << "[" << Copy->prev << "]," << Copy->data << ",[" << Copy->next << "]\t";
			head = head->next;
			head->prev = NULL;
			delete Copy;
			return;
		}
		while (Copy->next != NULL)
		{
			data = Copy->data;
			if (data == item)
			{
				cout << "[" << Copy->prev << "]," << Copy->data << ",[" << Copy->next << "]\t";
				Copy->prev->next = Copy->next;
				Copy->next->prev = Copy->prev;
				delete Copy;
				return;
			}
			Copy = Copy->next;
		}
		if (Copy->next == NULL)
		{
			if (item == Copy->data)
			{
				cout << "[" << Copy->prev << "]," << Copy->data << ",[" << Copy->next << "]\t";
				Copy->prev->next = NULL;
				delete Copy;
				return;
			}
		}
		cout << "\n*** Don't have thid Number\n";
		//delete Copy;
		return;
	}

	void Show()
	{
		node* Copy = head;
		if (Copy == NULL)
		{
			cout << "\n!!! We Don't have any List\n";
			return;
		}

		while (Copy != NULL)
		{
			cout << "[" << Copy->prev << "]," << Copy->data << ",[" << Copy->next << "]\t";
			Copy = Copy->next;
		}
		cout << "\n";

		Copy = head;
		return;
	}
};



int main()
{
	int ch, item;
	linklist a;

	do
	{
		cout << "\n1: Insert after Head\n2: Show\n3: Delete With Data\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			cout << "Enter Item: ";
			cin >> item;
			a.Insert_afterHead(item);
			break;
		}
		case 2:
		{
			cout << "\n**** Show List\n";
			a.Show();
			break;
		}
		case 3:
		{
			cout << "Enter one Data fo Delete:";
			cin >> item;
			a.Delete(item);
			break;
		}
		default:
			break;
		}
	} while (ch == 1 || ch == 2 || ch == 3);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
