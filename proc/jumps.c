//
// Created by alekseinovikov on 03.03.2026.
//
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

// never do it at home - dangerous!!!!
void prepare_jump() {
    int i = 42;
    if (setjmp(env) == 0) {
        printf("prepared jump! i: %d\n", i);
    } else {
        printf("we are returned! i: %d\n", i);
    }
}

int main(int argc, char *argv[]) {
    // intentionally unexpected behavior for experiment
    prepare_jump();

    longjmp(env, 1);

    // most probably sigsegv :)
    printf("are we gonna reach it at all?");

    exit(0);
}
