	.file	"source.cpp"
 # GNU C++17 (Rev13, Built by MSYS2 project) version 15.2.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 15.2.0, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.3.1, isl version isl-0.27-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=generic -march=nocona
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB0:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
 # source.cpp:4: int main(){
	call	__main	 #
 # source.cpp:5:     int a = 5;
	movl	$5, -4(%rbp)	 #, a
 # source.cpp:6:     int b = 10;
	movl	$10, -8(%rbp)	 #, b
 # source.cpp:7:     int c = a + b;
	movl	-4(%rbp), %edx	 # a, tmp105
	movl	-8(%rbp), %eax	 # b, tmp106
	addl	%edx, %eax	 # tmp105, c_4
	movl	%eax, -12(%rbp)	 # c_4, c
 # source.cpp:8:     int x = a + b * c;
	movl	-8(%rbp), %eax	 # b, tmp107
	imull	-12(%rbp), %eax	 # c, tmp107
	movl	%eax, %edx	 # tmp107, _1
 # source.cpp:8:     int x = a + b * c;
	movl	-4(%rbp), %eax	 # a, tmp111
	addl	%edx, %eax	 # _1, x_5
	movl	%eax, -16(%rbp)	 # x_5, x
 # source.cpp:9:     return 0;
	movl	$0, %eax	 #, _6
 # source.cpp:10: }
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev13, Built by MSYS2 project) 15.2.0"
