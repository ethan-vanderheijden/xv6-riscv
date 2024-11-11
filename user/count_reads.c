#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void) {
    printf("Number of reads: %d\n", count_reads());
    return 0;
}
