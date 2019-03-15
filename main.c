#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>


#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main()
{
        int sock, rc;
        struct sockaddr_in addr;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
                handle_error("socket");

        addr.sin_family      = AF_INET;
        addr.sin_port        = htons(8000);
        addr.sin_addr.s_addr = INADDR_ANY;

        rc = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (rc)
                handle_error("bind");

        rc = listen(sock, 5);
        if (rc)
                handle_error("listen");

        printf("Listening on port 8000\n");
        fflush(stdout);
        while (1) {
                /* Wait 1 second */
                struct timeval time;
                time.tv_sec  = 1;
                time.tv_usec = 0;

                rc = select(1, NULL, NULL, NULL, &time);
                if (rc == -1)
                        handle_error("select");
        }

        exit(EXIT_SUCCESS);
}
