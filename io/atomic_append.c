//
// Created by alekseinovikov on 26.02.2026.
//

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <../lib/tlpi_hdr.h>

int
main(int argc, char **argv) {
    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        usageErr("%s file numBytes {x|(<empty>)}\n", argv[0]);
    }

    char *file_name = argv[1];
    long bytesNum = atol(argv[2]);
    int rights = S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP;
    int o_flags = O_CREAT | O_WRONLY | O_APPEND;
    bool append = true;
    if (argc >= 4 && strcmp(argv[3], "x") == 0) {
        o_flags &= ~O_APPEND;
        append = false;
    }

    int fd = open(file_name, o_flags, rights);
    if (fd == -1) {
        errExit("open");
    }

    uint8_t b = 'w';
    for (int i = 0; i < bytesNum; ++i) {
        if (!append) {
            off_t seeked = lseek(fd, 0, SEEK_END);
            if (seeked == -1) {
                errExit("lseek");
            }
        }

        int written = write(fd, &b, 1);
        if (written == -1) {
            errExit("write");
        }
    }

    close(fd);
    exit(EXIT_SUCCESS);
}
