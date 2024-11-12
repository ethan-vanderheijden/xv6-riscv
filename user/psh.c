#include "kernel/param.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int tickets = 1;
    if (argc == 2) {
        tickets = atoi(argv[1]);
    }

    if (set_tickets(tickets) != 0) {
        printf("set_tickets failed\n");
        exit(1);
    }
    printf("my tickets: %d\n", tickets);

    struct pstat pstat;
    if (get_proc_info(&pstat) != 0) {
        printf("get_proc_info failed\n");
        exit(1);
    }

    for(int i = 0; i < NPROC; i++) {
        if (pstat.inuse[i]) {
            printf("\npid: %d, tickets: %d\n", pstat.pid[i], pstat.tickets[i]);
            printf("ticks used: %d\n", pstat.ticks[i]);
        }
    }
}
