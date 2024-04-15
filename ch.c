#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct LinkedList LinkedList;
typedef struct hash_node hash_node;
typedef struct Hash Hash;
//CASH
node* create_node();
LinkedList* List(int size);
node* create_node2(int data);

//HASH
//CASH
struct node
{
	int val;
	node * next;
	node * prev;
};

struct LinkedList
{
	int size;
	int n_size;
	node * head;
	node * tail;
};

struct hash_node
{
	int value;
	node * point;
};

struct Hash
{
	int capacity;
	hash_node **array;
};

//CASH
LinkedList* List(int size)
{
	node * Node;
	node * tmp;
	LinkedList * list;
	list = (LinkedList*) malloc((sizeof(LinkedList)));
	int i;
	Node = create_node();
	list->head = Node;
	list->size = size;
	tmp = Node;
	for (i = 1; i < size; i++)
	{
		tmp->next = create_node();
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}

	list->tail = tmp;
	return list;
}

hash_node* create_node_h()
{
	hash_node * tmp;
	tmp = (hash_node*) malloc(sizeof(hash_node));
	tmp->value = 0;
	tmp->point = NULL;
	return tmp;
}

node* create_node()
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->val = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void list_free(LinkedList *list)
{
	node *tmp = NULL;
	int i = 0;
	for (i = 0; i < list->size; i++)
	{
		tmp = list->tail->prev;
		free_node(list->tail);
		list->tail = tmp;
	}

	list->size = 0;
	free(list);
	return;
}

void free_node(node *node)
{
	node->next = NULL;
	node->val = 0;
	free(node);
	return;
}

void add_to_List_and_hash_and_delete_tail(LinkedList *list, Hash *hash, int page)
{
	node *tmp = NULL;
	if (list->size == list->n_size)
	{
		hash->array[list->tail->val] = NULL;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}

	tmp = create_node2(page);
	tmp->next = list->head;

	if (list->size == 0)
		list->tail = list->head = tmp;
	else
	{
		list->head->prev = tmp;
		list->head = tmp;
	}

	hash->array[page]->point = tmp;

	list->size++;

}

int main()
{
	int m, n, i, result;
	LinkedList *list = NULL;
	Hash *hash = NULL;
	int *arr = 0;
	result = 0;
	scanf("%d", &m);
	scanf("%d", &n);

	arr = (int*) malloc(m);

	list = ListH();
	hash = createHash(n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		result += Insert_value(list, hash, arr[i], n);
	}

	printf("%d", result);
	hash_free(hash);
	list_free(list);
}

int Insert_value(LinkedList *list, Hash *hash,
	int page)
{
	node *pointer = search_for_place_in_cash(int value, LinkedList *list);
	if (pointer == NULL)
		add_to_List_and_hash(list, hash, page);
	if (pointer != list->head)
	{
		poiner->prev->next = pointer->next;
		if (pointer->next != NULL)
		{
			pointer->next->prev = pointer->prev;
		}

		if (pointer == list->tail)
		{
			list->rtail = pointer->prev;
			list->tail->next = NULL;
		}

		pointer->next = list->head;
		pointer->prev = NULL;
		pointer->next->prev = pointer;
		list->head = pointer;
		result += 1;
	}

	if (pointer == list->head)
	{
		result += 1;
	}

	return result;
}

//search_for_place_in_cash

node* search_for_place_in_list(int page, LinkedList *list)
{
	node *tmp = NULL;
	tmp = list->head;
	while (tmp->value != page)
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			return NULL;
		}
	}

	return tmp;
}

node* create_node2(int data)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->val = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}
