#include <iostream>

using namespace std;

struct node{
	node* next;
	int key;
};

struct stack{
private:
	node* head = NULL;
public:
	void push(int new_count)
	{
		if (head == NULL){
			head = new node;
			head->next = NULL;
			head->key = new_count;

		}
		else{
			node* new_one = new node;
			new_one->next = head;
			new_one->key = new_count;
			head = new_one;
		}
	}
	void pop()
	{
		if (head != NULL){
			if (head->next != NULL)
			{
				node* fordel = head;
				head = head->next;
				delete(fordel);
			}
			else
				head = NULL;
		}
	}
	void peek()
	{
		if (head){
			node* forwhile = head;
			while (forwhile && forwhile->next)
			{
				cout << forwhile->key << " ";
				forwhile = forwhile->next;

			}
			cout << forwhile->key;
			cout << '\n';
		}
	}
};

struct queue{
private:
	node* tail = NULL;
	node* head = NULL;
public:
	void push(int new_number)
	{
		if (head)
		{
			if (head == tail)
			{
				node* new_elem = new node;
				tail = new_elem;
				tail->next = NULL;
				tail->key = new_number;
				head->next = tail;
				//delete(new_elem);
			}
			else
			{
				node* new_elem = new node;
				tail->next = new_elem;
				new_elem->next = NULL;
				new_elem->key = new_number;
				tail = new_elem;
				//delete(new_elem);
			}
		}
		else
		{
			head = new node;
			head->next = NULL;
			head->key = new_number;
			tail = head;
		}
	}
	void pop()
	{
		if (tail)
		{
			if (tail == head)
			{
				delete(tail);
				tail = NULL;
				head = NULL;
			}
			else
			{
				node* elem_del = head;
				head = head->next;
				delete(elem_del);
			}
		}
	}
	void peek()
	{
		if (head)
		{
			node* run_elem = head;
			while (run_elem->next != NULL)
			{
				cout << run_elem->key << " ";
				run_elem = run_elem->next;
			}
			cout << run_elem->key << '\n';
		}
	}
};

struct element
{
	int key;
	element* next;
	element* prev;
};

struct dls
{
private:
	element* head = NULL;
	element* tail = NULL;
public:

	//head_0 <-> elem_1 <-> tail_2
	void push(int key_c)
	{
		if (tail)
		{
			if (head == tail)
			{
				element* new_ = new element;
				new_->key = key_c;
				tail = new_;
				head->next = tail;
				tail->prev = head;
				tail->next = NULL;
			}
			else
			{
				element* new_ = new element;
				new_->key = key_c;
				tail->next = new_;
				new_->prev = tail;
				new_->next = NULL;
				tail = new_;
			}
		}
		else
		{
			head = new element;
			tail = head;
			head->next = NULL;
			head->prev = NULL;
			head->key = key_c;
		}
	}
	void pop()
	{
		if (tail)
		{
			if (tail == head)
			{
				delete(tail);
				tail = NULL;
				head = NULL;
			}
			else
			{
				element* fordel = tail;
				tail = tail->prev;
				delete(fordel);
			}
		}
	}
	void peek()
	{
		if (head)
		{
			element* cur = head;
			while (cur->next != NULL)
			{
				cout << cur->key << " ";
				cur = cur->next;
			}
			cout << cur->key;
		}
	}
	bool find(int key)
	{
		bool is_bad = true;
		if (head){
			element* cur = head;
			while (cur->next != NULL)
			{
				if (cur->key == key)
				{
					is_bad = false;
					return true;
				}
				cur = cur->next;
			}
		}
		if (is_bad)
			return false;
	}
	void delete_key(int key)
	{
		if (head)
		{
			if (head == tail && head->key == key)
			{
				delete(head);
				head = tail = NULL;
			}
			else
			{
				if (head->key == key)
				{
					element* cur = head;
					head = head->next;
					head->prev = NULL;
					delete(cur);
				}
				else{
					if (tail->key == key)
					{
						element* cur = tail;
						tail = tail->prev;
						tail->next = NULL;
						delete(cur);
					}
					else{
						element* cur = head;
						while (cur->next != NULL)
						{
							if (cur->key == key)
							{
								cur->prev->next = cur->next;
								cur->next->prev = cur->prev;
								delete(cur);
							}
							else
							{
								cur = cur->next;
							}
						}
					}
				}
			}
		}
	}
	void push_after(int number, int key) // add element with key after element with key - number
	{
		if (head)
		{
			if (tail->key == number)
			{
				element* new_elem = new element;
				tail->next = new_elem;
				new_elem->prev = tail;
				new_elem->next = NULL;
				new_elem->key = key;
				tail = new_elem;
			}
			else
			{
				element* cur = head;
				while (cur->next != NULL)
				{
					if (cur->key == number)
					{
						element* new_elem = new element;
						new_elem->next = cur->next;
						new_elem->prev = cur;
						cur->next = new_elem;
						new_elem->next->prev = new_elem;
					}
				}
			}
		}
	}
};

int main()
 {
	//stack my;
	//queue my;
	dls my;
	my.push(1);
	my.push(2);
	my.push(3);
	my.push(5);
	my.peek();
	cout << '\n';
	if (my.find(5))
		cout << "5";
	cout << '\n';
	my.peek();
	cout << '\n';
	my.delete_key(5);
	my.delete_key(1);
	my.peek();
	cout << '\n';
	my.push_after(3, 8);
	my.peek();
	system("pause");
	EXIT_SUCCESS;
}