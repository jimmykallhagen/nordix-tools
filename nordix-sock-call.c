/*============================================================*
 * SPDX-License-Identifier:  GPL-3.0-or-later                 *
 * Nordix license - https://www.gnu.org/licenses/gpl-3.0.html *
 * Copyright (c) 2025 Jimmy Källhagen                         *
 * Part of Nordix - https://github.com/jimmykallhagen/Nordix  *
 *============================================================*/

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <socket-path> <message>\n", argv[0]);
        return 1;
    }

    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) return 1;

    struct sockaddr_un addr = {.sun_family = AF_UNIX};
    snprintf(addr.sun_path, sizeof(addr.sun_path), "%s", argv[1]);

    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        close(fd);
        return 1;
    }

    write(fd, argv[2], strlen(argv[2]));
    shutdown(fd, SHUT_RDWR);
    close(fd);
    return 0;
}
