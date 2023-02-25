	.file	"Test2.c"
	.text
	.globl	n
	.data
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.long	100
	.globl	sum
	.bss
	.align 4
	.type	sum, @object
	.size	sum, 4
sum:
	.zero	4
	.section	.rodata
.LC0:
	.string	"Sum is %d"
.LC1:
	.string	"Shivani patil"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	sum(%rip), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, sum(%rip)
	addl	$1, -4(%rbp)
.L2:
	movl	n(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L3
	movl	sum(%rip), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
