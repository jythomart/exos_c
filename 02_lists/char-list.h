#ifndef __CHAR_LIST_H__
# define __CHAR_LIST_H__


// This our list type
// it only contains a character (data) to keep it simple
// it also has a pointer (next) to its next element
// when next is NULL (value of 0) then the element is the last of the list
typedef struct s_list_node
{
	char				data;
	struct s_list_node*	next;
} t_list_node;

// Create a list of one element and init its data to the value of char c
// do not forget to set it as the last element of the list
t_list_node*	list_create(const char c);


// Add a new element at the end of list with data = c
// returns the first element of the list
t_list_node*	list_append(t_list_node* list, const char c);


// free every elements of a list
// please note the **
// sets *list to NULL
void	        list_destroy(t_list_node** list);


// returns the length of list (number of elements)
// if the pointer list is NULL then the list has a length of 0
unsigned int	list_length(const t_list_node* list);


// copy one by one every element of list and return a new one
// this method allocates memory for the newly created list
// returns the created list
t_list_node*	list_copy(const t_list_node* list);


// concatenate l2 to l1
// the last element of l1 will point to the first element of l2
// returns a pointer to the first element of l1
t_list_node*	list_concat(t_list_node* l1, const t_list_node* l2);


// insert l2 into l1 at the 'at'th element
// for instance  if l1 = 'a'->'b'->'c'->'d' and l2 = 'x'->'y' and at is 2
//   the result will be 'a'->'b'->'x'->'y'->'c'->'d'
t_list_node*	list_insert(t_list_node* l1, const t_list_node* l2, unsigned int at);


// let's introduce a scary beast: pointer on function
// this line defines a new type t_callback of variable to play with
// it will be used to apply a function on every element of a list
// see list_apply below
typedef char(*t_callback)(char *c);


// this method will apply the function pointed by the pointer on function callback to every element of list
// returns a pointer to the first element of list
t_list_node*    list_apply(t_list_node* list, t_callback callback);

#endif // __CHAR_LIST_H__