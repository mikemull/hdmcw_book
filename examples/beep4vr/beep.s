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

// Setup the parameters to exit the program
// and then call the kernel to do it.
//	MOV     W0, #0          // Use 0 return code
//    MOV     X16, #1         // System call number 1 terminates this program
//    SVC     #0x80           // Call kernel to terminate the program

bel:      .byte  0x07
