	.file	"main.c"
	.intel_syntax noprefix
	.comm	_y1, 8, 3
	.comm	_y2, 8, 3
	.comm	_x1, 4, 2
	.comm	_x2, 4, 2
	.comm	_x3, 4, 2
	.comm	_x, 4, 2
	.comm	_y, 4, 2
	.comm	_z, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	push	ebx
	and	esp, -16
	call	___main
	mov	eax, DWORD PTR _x
	mov	ebx, DWORD PTR _y
	cdq
	idiv	ebx
	mov	ebx, eax
	mov	ecx, DWORD PTR _x
	mov	edx, 1717986919
	mov	eax, ecx
	imul	edx
	sar	edx, 2
	mov	eax, ecx
	sar	eax, 31
	sub	edx, eax
	mov	eax, edx
	sal	eax, 2
	add	eax, edx
	add	eax, eax
	sub	ecx, eax
	mov	edx, ecx
	lea	eax, [ebx+edx]
	mov	DWORD PTR _z, eax
/APP
 # 36 "main.c" 1
	.intel_syntax noprefix
	
	att_syntax
 # 0 "" 2
/NO_APP
	mov	eax, 0
	mov	ebx, DWORD PTR [ebp-4]
	leave
	ret
	.ident	"GCC: (tdm64-1) 5.1.0"
