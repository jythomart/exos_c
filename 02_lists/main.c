#include <stdio.h> // for printf
#include <stdlib.h> // for malloc and free
#include <string.h>

// include assert, it is used to check the validity of an expression
// void assert(int expression);
// if the expression is evaluated as false it will stop the program and display an error message
#include <assert.h>

// include our list
#include "char-list.h"


char print_char(char *c) {
    printf("%c", *c);
    return *c;
}

char up_char(char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = *c + 'A' - 'a';
    }
    return *c;
}


// Let's test everything !
int main(int argc, char **argv) {

    printf("BEGINNING TESTS\n");

    /////////////////////////////////////////////
    // test list_create
    /////////////////////////////////////////////
    t_list_node* l1 = list_create('a');
    assert(l1 != NULL);
    assert(l1->data == 'a');
    assert(l1->next == NULL);

    printf("1/8: list_create working !\n");

    /////////////////////////////////////////////
    // test list_append
    /////////////////////////////////////////////
    list_append(l1, 'b');
    assert(l1 != NULL);
    assert(l1->data == 'a');
    assert(l1->next != NULL);
    assert(l1->next->data == 'b');
    assert(l1->next->next == NULL);

    list_append(list_append(l1, 'c'), 'd');
    assert(l1->data == 'a');
    assert(l1->next->next->next->data == 'd');

    printf("2/8: list_append working !\n");

    /////////////////////////////////////////////
    // test list_free
    /////////////////////////////////////////////
    list_destroy(&(l1->next));
    assert(l1->next == NULL);
    list_destroy(&l1);
    assert(l1 == NULL);

    printf("3/8: list_destroy working !\n");

    /////////////////////////////////////////////
    // test list_length
    /////////////////////////////////////////////
    assert(list_length(l1) == 0);
    l1 = list_create('h');
    assert(list_length(l1) == 1);
    list_append(list_append(list_append(list_append(l1, 'e'), 'l'), 'l'), 'o');
    assert(list_length(l1) == strlen("hello"));

    printf("4/8: list_length working !\n");

    /////////////////////////////////////////////
    // test list_copy
    /////////////////////////////////////////////
    t_list_node* l2 = list_copy(l1);
    assert(list_length(l2) == 5);
    assert(l2->data == 'h');
    assert(l2->next->next->data == 'l');

    printf("5/8: list_copy working !\n");

    /////////////////////////////////////////////
    // test list_concat
    /////////////////////////////////////////////
    list_destroy(&l2);
    l2 = list_create('w');
    list_append(list_append(list_append(list_append(l2, 'o'), 'r'), 'l'), 'd');
    l1 = list_concat(l1, l2);
    assert(list_length(l1) == strlen("helloworld"));

    printf("6/8: list_concat working !\n");

    /////////////////////////////////////////////
    // test list_insert
    /////////////////////////////////////////////
    t_list_node* l3 = list_create(' ');
    list_insert(l1, l3, 5);
    assert(list_length(l1) == strlen("hello world"));
    t_list_node* l4 = list_create('!');
    l1 = list_insert(l1, l4, 0);
    assert(list_length(l1) == strlen("!hello world"));
    assert(l1->data == '!');
    assert(l1->next->data == 'h');

    printf("7/8: list_insert working !\n");

    /////////////////////////////////////////////
    // test list_apply
    /////////////////////////////////////////////
    list_append(l1, '\n');
    list_apply(l1, &print_char);    // SHOULD PRINT "!hello world\n"
    list_apply(l1, &up_char);
    list_apply(l1, &print_char);    // SHOULD PRINT "!HELLO WORLD\n"
    assert(l1->data == '!');
    assert(l1->next->data == 'H');

    printf("8/8: list_apply working !\n");
    
    list_destroy(&l1);              // free the allocated memory

    printf("ALL GOOD ! GG !!!\n");

    return 0;
}