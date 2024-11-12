#include "user.h"
#include "common/rand.c"

void main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: rand <tickets>\n");
    }

    int tickets = atoi(argv[1]);

    if (set_tickets(tickets) != 0) {
        printf("set_tickets failed\n");
        exit(1);
    }
    printf("my tickets: %d\n", tickets);

    long total = 0;
    while(1) {
        total += rand();
        if (total > 0) {
            total = 0;
        }
    }
}
