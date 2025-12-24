#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i, len;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);


    for (i = 0; i < len; i++) {
        push(str[i]);
    }


    for (i = 0; i < len; i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);

    return 0;
}

