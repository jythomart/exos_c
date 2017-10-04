#include <stdlib.h>
#include "char-list.h"

#ifndef NULL
# define NULL 0  // define the value for a null pointer
#endif

// Create a list of one element and init its data to the value of char c
// do not forget to set it as the last element of the list
t_list_node*	list_create(const char c) {
    return NULL;
}


// Add a new element at the end of list with data = c
// returns the first element of the list
t_list_node*	list_append(t_list_node* list, const char c) {
    return NULL;
}


// free every elements of a list
// please note the **
// sets *list to NULL
void	        list_destroy(t_list_node** list) {

}


// returns the length of list (number of elements)
// if the pointer list is NULL then the list has a length of 0
unsigned int	list_length(const t_list_node* list) {
    return 42;
}


// copy one by one every element of list and return a new one
// this method allocates memory for the newly created list
// returns the created list
t_list_node*	list_copy(const t_list_node* list) {
    return NULL;
}


// concatenate l2 to l1
// this method does not allocate new elements
// the last element of l1 will point to the first element of l2
// returns a pointer to the first element of l1
t_list_node*	list_concat(t_list_node* l1, const t_list_node* l2) {
    return NULL;
}


// insert l2 into l1 at the 'at'th element
// for instance  if l1 = 'a'->'b'->'c'->'d' and l2 = 'x'->'y' and at is 2
//   the result will be 'a'->'b'->'x'->'y'->'c'->'d'
t_list_node*	list_insert(t_list_node* l1, const t_list_node* l2, unsigned int at) {
    return NULL;
}


// this method will apply the function pointed by the pointer on function callback to every element of list
// returns a pointer to the first element of list
t_list_node*    list_apply(t_list_node* list, t_callback callback) {
    return NULL;
}
