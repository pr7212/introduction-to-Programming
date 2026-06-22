#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    char buf[64];
    char *endptr;
    long age;

    printf("Please enter your age: ");
    if (!fgets(buf, sizeof(buf), stdin)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    errno = 0;
    age = strtol(buf, &endptr, 10);
    if (endptr == buf || (*endptr != '\n' && *endptr != '\0')) {
        printf("Invalid input — please enter an integer.\n");
        return 1;
    }
    if (errno == ERANGE) {
        printf("Number out of range\n");
        return 1;
    }

    if (age < 0) {
        printf("You are not born yet\n");
    } else if (age > 120) {
        printf("You are too old\n");
    } else if (age >= 18) {
        printf("You are an adult\n");
    } else {
        printf("You are a child\n");
    }

    return 0;
}
