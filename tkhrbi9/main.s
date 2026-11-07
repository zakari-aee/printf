	.file	"main.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Befor the va_start : reg_save_area = %d\n"
	.align 8
.LC1:
	.string	"Befor the va_start : overflow_arg_area = %p\n"
	.align 8
.LC2:
	.string	"Befor the va_start : gp_offset = %d\n"
	.align 8
.LC3:
	.string	"Befor the va_start : fp_offset = %d\n"
	.align 8
.LC4:
	.string	"-----------------------------------------------------------------------------------"
	.align 8
.LC5:
	.string	"After the va_start : reg_save_area = %u\n"
	.align 8
.LC6:
	.string	"After the va_start : overflow_arg_area = %u\n"
	.align 8
.LC7:
	.string	"After the va_start : gp_offset = %d\n"
	.align 8
.LC8:
	.string	"After the va_start : fp_offset = %d\n"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 240
	mov	DWORD PTR -228[rbp], edi
	mov	QWORD PTR -168[rbp], rsi
	mov	QWORD PTR -160[rbp], rdx
	mov	QWORD PTR -152[rbp], rcx
	mov	QWORD PTR -144[rbp], r8
	mov	QWORD PTR -136[rbp], r9
	test	al, al
	je	.L2
	movaps	XMMWORD PTR -128[rbp], xmm0
	movaps	XMMWORD PTR -112[rbp], xmm1
	movaps	XMMWORD PTR -96[rbp], xmm2
	movaps	XMMWORD PTR -80[rbp], xmm3
	movaps	XMMWORD PTR -64[rbp], xmm4
	movaps	XMMWORD PTR -48[rbp], xmm5
	movaps	XMMWORD PTR -32[rbp], xmm6
	movaps	XMMWORD PTR -16[rbp], xmm7
.L2:
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -184[rbp], rax
	xor	eax, eax
	mov	DWORD PTR -212[rbp], 1
	mov	rax, QWORD PTR -192[rbp]
	mov	rsi, rax
	lea	rax, .LC0[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	rax, QWORD PTR -200[rbp]
	mov	rsi, rax
	lea	rax, .LC1[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	eax, DWORD PTR -208[rbp]
	mov	esi, eax
	lea	rax, .LC2[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	eax, DWORD PTR -204[rbp]
	mov	esi, eax
	lea	rax, .LC3[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	DWORD PTR -208[rbp], 8
	mov	DWORD PTR -204[rbp], 48
	lea	rax, 16[rbp]
	mov	QWORD PTR -200[rbp], rax
	lea	rax, -176[rbp]
	mov	QWORD PTR -192[rbp], rax
	lea	rax, .LC4[rip]
	mov	rdi, rax
	call	puts@PLT
	mov	rax, QWORD PTR -192[rbp]
	mov	eax, DWORD PTR [rax]
	mov	esi, eax
	lea	rax, .LC5[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	rax, QWORD PTR -200[rbp]
	sub	rax, 56
	mov	eax, DWORD PTR [rax]
	mov	esi, eax
	lea	rax, .LC6[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	eax, DWORD PTR -208[rbp]
	mov	esi, eax
	lea	rax, .LC7[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	mov	eax, DWORD PTR -204[rbp]
	mov	esi, eax
	lea	rax, .LC8[rip]
	mov	rdi, rax
	mov	eax, 0
	call	printf@PLT
	lea	rax, .LC4[rip]
	mov	rdi, rax
	call	puts@PLT
	nop
	mov	rdx, QWORD PTR -184[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 8
	push	100
	push	9
	push	8
	push	7
	push	6
	mov	r9d, 5
	mov	r8d, 4
	mov	ecx, 3
	mov	edx, 2
	mov	esi, 1
	mov	edi, 10
	mov	eax, 0
	call	test
	add	rsp, 48
	mov	eax, 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
