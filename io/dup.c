//
// Created by alekseinovikov on 26.02.2026.
//

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <../lib/tlpi_hdr.h>

static int my_dup(int oldfd);
static int my_dup2(int oldfd, int newfd);

int
main(int argc, char *argv[]) {

}

static int my_dup(int oldfd) {
    int flags = fcntl(oldfd, F_GETFL);
    if (flags == -1) {
        errno = EBADF;
        return -1;
    }

    return fcntl(oldfd, F_DUPFD, 0);
}

static int my_dup2(int oldfd, int newfd) {
    int flags = fcntl(oldfd, F_GETFL);
    if (flags == -1) {
        errno = EBADF;
        return -1;
    }

    if (newfd == oldfd) {
        return oldfd;
    }

    int existing_new = fcntl(newfd, F_GETFD);
    if (existing_new == -1 && errno == EBADF) {
        close(newfd);
    }

    return fcntl(oldfd, F_DUPFD, newfd);
}