	.file	"main.c"
	.intel_syntax noprefix
	.comm	_y1, 8, 3
	.comm	_y2, 8, 3
	.comm	_x1, 4, 2
	.comm	_x2, 4, 2
	.comm	_x3, 4, 2
	.comm	_x, 4, 2
	.comm	_y, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "x = %d\12\0"
LC1:
	.ascii "y = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	sub	esp, 16
	call	___main
	mov	DWORD PTR _x, 5
/APP
 # 23 "main.c" 1
	.intel_syntax noprefix
	MOV eax, _x
	LEA eax, [eax+eax*4]
	LEA eax, [eax+eax*4]
	MOV _y, eax
	att_syntax prefix
 # 0 "" 2
/NO_APP
	mov	eax, DWORD PTR _x
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_printf
	mov	eax, DWORD PTR _y
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:LC1
	call	_printf
	mov	eax, 0
	leave
	ret
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
