// multiply.s - ARM64 macOS Assembly
// To assemble: as -o multiply.o multiply.s
// To link: ld -macosx_version_min 11.0.0 -o multiply multiply.o -lSystem

.global _main             // Entry point for macOS
.align 4

_main:
    // 1. Load the first constant into register d0
    adrp    x0, const1@PAGE
    ldr     s0, [x0, const1@PAGEOFF]

    // 2. Load the second constant into register d1
    adrp    x0, const2@PAGE
    ldr     s1, [x0, const2@PAGEOFF]

    // 3. Multiply: d2 = d0 * d1
    fmul    s2, s0, s1

bail:
    mov     x16, #1         // macOS syscall for exit
    svc     #0x80           // Invoke supervisor call

.section __DATA,__data
.align 3
const1: .float 0.1
const2: .float 4.0
