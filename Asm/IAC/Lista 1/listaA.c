#include <stdio.h>

//2018 a - 3

int i1, i2, i3;

int main(int argc, char *argv[])
{
// expr0
   i1 = 10*i2 + 5;
	  asm (".intel_syntax noprefix	\n\t\
		mov ebx, _i2			\n\t\
	 	lea eax, [ebx*8+5] 		\n\t\
		lea eax, [eax+ebx*2] 	\n\t\
		mov _i1, eax			\n\t\
		.att_syntax prefix	  	\n"
		);

// expr1
   i3 = i1 + 8*i2 + 6;
	asm (".intel_syntax noprefix	\n\t\
		mov eax, _i2			\n\t\
	 	lea eax, [eax*8+6] 		\n\t\
	 	mov ebx, _i1			\n\t\
	 	adc eax, ebx 			\n\t\
		mov _i1, eax			\n\t\
		.att_syntax prefix	  	\n"
		);

// expr2
   i1--;
    asm (".intel_syntax noprefix	\n\t\
		mov eax, _i1			\n\t\
		dec eax     			\n\t\
		mov _i1, eax			\n\t\
		.att_syntax prefix	  	\n"
		);

// expr3
   i2 = i1-2;
    asm (".intel_syntax noprefix	\n\t\
    	mov eax, _i1			\n\t\
    	sub eax, 2        		\n\t\
    	mov _i2, eax			\n\t\
    	.att_syntax prefix	  	\n"
		);

// expr4
   i1-=5;
    asm (".intel_syntax noprefix	\n\t\
    	mov eax, _i1			\n\t\
    	sub eax, 5        		\n\t\
    	mov _i1, eax			\n\t\
	    .att_syntax prefix	  	\n"
		);

// expr5
	i2 = i1*10 + i2*31 + 100;
	 asm (".intel_syntax noprefix	\n\t\
	 	mov ebx, _i1			\n\t\
	 	lea eax, [ebx*8+100] 	\n\t\
		lea eax, [eax+ebx*2] 	\n\t\
		mov ebx, _i2			\n\t\
		lea ebx, [ebx*8]		\n\t\
		lea ebx, [ebx*4]		\n\t\
		neg ebx					\n\t\
		adc eax, ebx			\n\t\
		mov _i2, eax			\n\t\
	 	.att_syntax prefix	  	\n"
		);
}