//
//  Add some things
//
.global _start             // Provide program starting address to linker
.align 4

_start:
    // Load mya1 into X2 register
    ADRP X1, mya1@PAGE
    ADD X1, X1, mya1@PAGEOFF
    LDR W2, [X1]

    // Load mya2 into X4 register
    ADRP X3, mya2@PAGE
    ADD X3, X3, mya2@PAGEOFF
    LDR W4, [X3]

    // Add 'em up
    ADD X2, X4, X2

    //  Shove it back into memory
    ADRP X5, mys1@PAGE
    ADD X5, X5, mys1@PAGEOFF
    STR X2, [X5]

    // Breakpoint
    BRK #2

.data
mya1:  .word  17
mya2:  .word  25
mys1:  .word  0
