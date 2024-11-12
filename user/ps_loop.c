#include "kernel/param.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int tickets = atoi(argv[1]);
        if (set_tickets(tickets) != 0) {
            printf("set_tickets failed\n");
            exit(1);
        }
        printf("my tickets: %d\n", tickets);
    }

    struct pstat pstat;
    int time = 0;
    while (1) {
        if (get_proc_info(&pstat) != 0) {
            printf("get_proc_info failed\n");
            exit(1);
        }

        printf("\nTime: %d\n", time);
        printf("Total tickets in system: %d\n", pstat.total_tickets);
        for (int i = 0; i < NPROC; i++) {
            if (pstat.inuse[i]) {
                printf("pid: %d, tickets: %d, total ticks: %d\n", pstat.pid[i], pstat.tickets[i],
                       pstat.ticks[i]);
            }
        }

        sleep(10);
        time += 1;
    }
}
