	.file	"main.c"
	.intel_syntax noprefix
	.comm	_x1, 4, 2
	.comm	_x2, 4, 2
	.comm	_x3, 4, 2
	.comm	_x, 4, 2
	.comm	_y, 4, 2
	.comm	_z, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "x1 = %d\12\0"
LC1:
	.ascii "x2 = %d\12\0"
LC2:
	.ascii "x3 = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	sub	esp, 16
	call	___main
	mov	DWORD PTR _x1, 1
	mov	DWORD PTR _x2, 7
	mov	DWORD PTR _x3, 5
	mov	eax, DWORD PTR _x1
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_printf
	mov	eax, DWORD PTR _x2
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	_printf
	mov	eax, DWORD PTR _x3
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
	call	_printf
	mov	eax, 0
	leave
	ret
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
