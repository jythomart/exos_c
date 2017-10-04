#include <stdio.h> // for printf
#include <stdlib.h> // for malloc and free

// include assert, it is used to check the validity of an expression
// void assert(int expression);
// if the expression is evaluated as false it will stop the program and display an error message
#include <assert.h>

#ifndef NULL
# define NULL 0  // define the value for a null pointer
#endif

// warming up part 1: strlen
// - returns the length of the null terminated string str
// - see man strlen
int my_strlen(const char *str) {
    return 0;   // TODO: replace this line with the actual code
}


// warming up part 2: strcmp
// - compare the strings s1 and s2
// - iterate at the same time s1 and s2 and returns the difference between the first different char
// - returns 0 if the s1 and s2 are identical
// - for instance: my_strcmp("abc", "acc") returns 'b' - 'c'
// - see man strcmp
int my_strcmp(const char *s1, const char *s2) {
    return 0;   // TODO: replace this line with the actual code
}


// let's start using malloc: strdup
// - returns a copy of s1
// - this function first allocates just enough memory to store a copy of s1
// - then copy every characters from s1 into the newly allocated memory
// - returns a pointer to the first element of the new string
// - don't forget to end your new string with '\0'
// - don't forget to free the memory
// - see man strdup
char *my_strdup(const char *s1) {
    return NULL;
}


// Let's test everything !
int main(int argc, char **argv) {
    // declare strings to test our functions
    const char *origin = "abcdef";
    const char *empty = "";

    printf("BEGINNING TESTS\n");

    // test my_strlen
    assert(my_strlen(origin) == 6);
    assert(my_strlen(empty) == 0);

    printf("33%%: my_strlen is working !\n");

    // test my_strcmp
    assert(my_strcmp(origin, "abcdef") == 0);          // s1 and s2 are equal
    assert(my_strcmp(origin, "abcxyz") != 0);          // s1 and s2 are not equal
    assert(my_strcmp(origin, "abcd") == 'e' - '\0');   // s1 is longer than s2
    assert(my_strcmp(empty, origin) == -'a');          // s1 is shorter than s2

    printf("66%%: my_strcmp is working !\n");

    // test my_strdup
    // normal string
    char *copy = my_strdup(origin);
    assert(my_strcmp(origin, copy) == 0);           // check origin and copy are equal
    ++copy;                                         // increment pointer
    assert(*copy == 'b');                           // check pointed character is 'b'
    --copy;                                         // decrement pointer back to the first element
    free(copy);                                     // free the allocated memory to store "abcdef"

    copy = my_strdup("");
    assert(*copy == '\0');                          // check the end of string character is present
    assert(my_strcmp(copy, empty) == 0);               // check empty and copy are equal
    free(copy);                                     // free the allocated memory

    printf("100%%: my_strcmp is working !\n");

    printf("ALL GOOD ! GG !!!\n");

    return 0;
}