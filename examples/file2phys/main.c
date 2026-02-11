//
//  main.c
//  file2phys
//
//  Created by Mike Mull on 2/7/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char * argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct log2phys l2p;
    off_t current_logical_offset = 0;
    off_t file_size = lseek(fd, 0, SEEK_END);
    
    // Reset to beginning
    lseek(fd, 0, SEEK_SET);

    printf("%-15s | %-15s | %-15s\n", "Logical Offset", "Physical Offset", "Length (Bytes)");
    printf("------------------------------------------------------------------\n");

    while (current_logical_offset < file_size) {
        // Set up the query: we want to know about the extent starting at this offset
        l2p.l2p_contigbytes = file_size - current_logical_offset;  // For F_LOG2PHYS_EXT: IN = bytes to query, OUT = contiguous bytes
        l2p.l2p_devoffset = current_logical_offset;  // For F_LOG2PHYS_EXT: IN = offset into file

        // F_LOG2PHYS_EXT queries the physical info for a given logical offset
        if (fcntl(fd, F_LOG2PHYS_EXT, &l2p) == -1) {
            // Some system files or compressed files might not support this
            if (errno == ENOTSUP) {
                fprintf(stderr, "Operation not supported on this file system.\n");
            } else {
                perror("fcntl F_LOG2PHYS");
            }
            break;
        }

        printf("%-15lld | %-15lld | %-15lld\n",
                current_logical_offset,
                l2p.l2p_devoffset,
                l2p.l2p_contigbytes);

        // Move the offset forward by the number of contiguous bytes found
        // If contigbytes is 0 (shouldn't happen on valid data), break to avoid infinite loop
        if (l2p.l2p_contigbytes <= 0) break;
        
        current_logical_offset += l2p.l2p_contigbytes;
    }

    close(fd);
    return 0;
}
