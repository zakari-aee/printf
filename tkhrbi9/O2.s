	.file	"main.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
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
	.p2align 4
	.globl	test
	.type	test, @function
test:
.LFB35:
	.cfi_startproc
	endbr64
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	lea	rsi, .LC0[rip]
	mov	edi, 1
	lea	rbp, .LC4[rip]
	sub	rsp, 32
	.cfi_def_cfa_offset 48
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 24[rsp], rax
	xor	eax, eax
	mov	rdx, QWORD PTR 16[rsp]
	call	__printf_chk@PLT
	mov	rdx, QWORD PTR 8[rsp]
	lea	rsi, .LC1[rip]
	xor	eax, eax
	mov	edi, 1
	call	__printf_chk@PLT
	mov	edx, DWORD PTR [rsp]
	mov	edi, 1
	xor	eax, eax
	lea	rsi, .LC2[rip]
	call	__printf_chk@PLT
	mov	edx, DWORD PTR 4[rsp]
	mov	edi, 1
	xor	eax, eax
	lea	rsi, .LC3[rip]
	call	__printf_chk@PLT
	lea	rax, 48[rsp]
	mov	rdi, rbp
	mov	QWORD PTR 8[rsp], rax
	call	puts@PLT
	mov	rax, QWORD PTR 16[rsp]
	mov	edi, 1
	lea	rsi, .LC5[rip]
	mov	edx, DWORD PTR [rax]
	xor	eax, eax
	call	__printf_chk@PLT
	mov	rax, QWORD PTR 8[rsp]
	mov	edi, 1
	lea	rsi, .LC6[rip]
	mov	edx, DWORD PTR -56[rax]
	xor	eax, eax
	call	__printf_chk@PLT
	mov	edx, DWORD PTR [rsp]
	mov	edi, 1
	xor	eax, eax
	lea	rsi, .LC7[rip]
	call	__printf_chk@PLT
	mov	edx, DWORD PTR 4[rsp]
	mov	edi, 1
	xor	eax, eax
	lea	rsi, .LC8[rip]
	call	__printf_chk@PLT
	mov	rdi, rbp
	call	puts@PLT
	mov	rax, QWORD PTR 24[rsp]
	sub	rax, QWORD PTR fs:40
	jne	.L5
	add	rsp, 32
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	xor	eax, eax
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE35:
	.size	test, .-test
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB36:
	.cfi_startproc
	endbr64
	sub	rsp, 16
	.cfi_def_cfa_offset 24
	mov	ecx, 3
	mov	edx, 2
	xor	eax, eax
	push	100
	.cfi_def_cfa_offset 32
	mov	r9d, 5
	mov	r8d, 4
	mov	esi, 1
	push	9
	.cfi_def_cfa_offset 40
	mov	edi, 10
	push	8
	.cfi_def_cfa_offset 48
	push	7
	.cfi_def_cfa_offset 56
	push	6
	.cfi_def_cfa_offset 64
	call	test
	xor	eax, eax
	add	rsp, 56
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE36:
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
