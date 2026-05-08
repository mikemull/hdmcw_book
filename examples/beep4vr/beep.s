//
//  Send BEL to stdout ad infinitum or Ctrl-C
//
.global _start             // Provide program starting address to linker
.align 4

_start: 

	MOV X4, #(20 * 4294967296)
loop:

	SUBS X4, X4, #1
	B.NE loop

beep4eva:
	MOV X0, #1      // 1 = StdOut
    ADR X1, bel     // string to print
    MOV X2, #1      // length of our string
    MOV X16, #4     // MacOS write system call
    SVC 0

	B beep4eva

bel:      .byte  0x07
