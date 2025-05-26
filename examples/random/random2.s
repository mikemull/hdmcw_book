
.global _start
.align 4

_start: 

    MOVZ W0, #0x8405
    MOVK W0, #0x0808, LSL 16
    MOV W1, #1
    MOV W3, #111
    ; Calculate the next state

    MOV W5, #10  ; Number of iterations

    ADRP X6, randos@PAGE  ; Load the page address of randos into X6
    ADD X6, X6, randos@PAGEOFF

loop:
    MUL W4, W3, W0  ; R4 = a * current_state
    ADD W3, W4, W1  ; R4 = (a * current_state) + c

    STR W3, [X6]    ; Store the new value in the array
    ADD X6, X6, #4
    SUBS W5, W5, #1
    B.NE loop

    MOV W5, #10  ; Reset the counter for summation
    ADRP X6, randos@PAGE  ; Load the page address of randos into X6
    ADD X6, X6, randos@PAGEOFF

    MOV X3, #0      ; Initialize sum to 0
sum:
    LDR W4, [X6], 4    ; Load the value from the array
    ADD X3, X3, W4, SXTW  ; Add it to the sum
    SUBS W5, W5, #1
    B.NE sum

bail:
    mov     X0, #0      // Use 0 return code
    mov     X16, #1     // Service command code 1 terminates this program
    svc     0           // Call MacOS to terminate the program

.data
randos:     .fill   10, 4, 0
