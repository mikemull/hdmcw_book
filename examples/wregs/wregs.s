; wregs.s

.global _start
.align 4

_start: 
    MOVZ W0, #0x8405
    MOVK W0, #0x0808, LSL 16
    MOV W3, #111

    MUL W4, W3, W0

    BRK #2
