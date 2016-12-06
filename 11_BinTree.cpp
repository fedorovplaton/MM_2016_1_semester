#include <iostream>

using namespace std;

struct node
{
	node* parent;
	int key;
	int depth;
	node* right;
	node* left;

};

struct Bin_Tree{
private:
	node* head = NULL;
public:
	void push(int key)
	{
		if(head)
		{
			node* cur = head;
			while (true)
			{
				if (cur->right && key > cur->key)
				{
					cur = cur->right;
				}
				else{
					if (cur->left && key < cur->key)
					{
						cur = cur->left;
					}
					else
						break;
				}
			}
			if (key > cur->key)
			{
				node* new_elem = new node;
				cur->right = new_elem;
				new_elem->right = NULL;
				new_elem->left = NULL;
				new_elem->parent = cur;
				new_elem->key = key;
				new_elem->depth = new_elem->parent->depth + 1;
			}
			else
			{
				node* new_elem = new node;
				cur->left = new_elem;
				new_elem->right = NULL;
				new_elem->left = NULL;
				new_elem->parent = cur;
				new_elem->key = key;
				new_elem->depth = new_elem->parent->depth + 1;
			}
		}
		else
		{
			head = new node;
			head->key = key;
			head->right = NULL;
			head->left = NULL;
			head->parent = NULL;
			head->depth = 1;
		}
	}
	bool find(int key)
	{
		if (head)
		{
			node* cur = head;
			while (true)
			{
				if (cur->key == key)
					return true;
				if (cur->right && key > cur->key)
				{
					cur = cur->right;
				}
				else
				{
					if (cur->left && key < cur->key)
					{
						cur = cur->left;
					}
					else return false;
				}
			}
		}
	}
	void pop(int key)
	{
		if (head)
		{
			bool deleted = false;
			node* cur = head;
			while (true)
			{
				if (cur->key == key)
				{
					if (cur->left == NULL && cur->right == NULL )
					{
						deleted = true;
						if (cur == head)
						{
							delete(cur);
							head = NULL;
						}
						else
						{
							if (cur->key > cur->parent->key){
								cur->parent->right = NULL;
								delete(cur);
							}
							else{
								cur->parent->left = NULL;
								delete(cur);
							}
						}
					}
					if (cur->right != NULL && cur->left == NULL && !deleted)
					{
						deleted = true;
						if (cur == head)
						{
							head = head->right;
							delete(cur);
						}
						if (cur->key > cur->parent->key){
							cur->parent->right = cur->right;
							delete(cur);
						}
						else{
							cur->parent->left = cur->right;
							delete(cur);
						}
					}
					if (cur->right == NULL && cur->left != NULL && !deleted)
					{
						deleted = true;
						if (head == cur)
						{
							head = head->left;
							delete(cur);
						}
						if (cur->key > cur->parent->key){
							cur->parent->right = cur->left;
							delete(cur);
						}
						else{
							cur->parent->left = cur->left;
							delete(cur);
						}
					}
					if (cur->right != NULL && cur->left != NULL && !deleted)
					{
						deleted = true;
						node* findleft = cur->right;
						while (findleft->left != NULL)
							findleft = findleft->left;
						//swap
						cur->key = findleft->key;
						delete(findleft);
					}
					if (deleted)
						break;
				}
				if (cur->right && key > cur->key)
				{
					cur = cur->right;
				}
				else
				{
					if (cur->left && key < cur->key)
					{
						cur = cur->left;
					}
					else break;
				}
			}
		}
	}
	int go_down(node* cur)
	{
		if (cur->left != NULL && cur->right != NULL)
		{
			if (go_down(cur->left) > go_down(cur->right))
				return go_down(cur->left);
			else
				return go_down(cur->right);
		}
		else
		{
			if(cur->left == NULL && cur->right != NULL)
				return go_down(cur->right);
			if (cur->left != NULL && cur->right == NULL)
				return go_down(cur->left);
			if (cur->left == NULL && cur->right == NULL)
				return cur->depth;
		}
	}
	int depth()
	{
		return go_down(head);
	}
};

int main()
{
	struct Bin_Tree my;
	my.push(2);
	my.push(4);
	my.push(6);
	my.push(5);
	my.push(7);
	for (int i = 0; i < 20; i++)
	{
		if (my.find(i))
			cout << i << " ";
	}
	cout << '\n';
	//my.pop(4);
	//my.pop(2);
	//my.pop(7);
	for (int i = 0; i < 20; i++)
	{
		if (my.find(i))
			cout << i << " ";
	}
	cout << '\n';
	cout << my.depth();
	system("pause>>find");
	EXIT_SUCCESS;
}