#include <stdio.h>

char c1, c2, c3;
int i1, i2, i3;
long long int x1, x2, x3;

void setupVars() {
	c1 = 49; c2 = 2; c3 = 3;
	i1 = 11; i2 = 3; i3 = 40;
	x1 = 6; x2 = 0; x3 = 8;
}

void printVars() {
	printf("---------\n");
	printf("c1 = %d\n", c1);
	printf("c2 = %d\n", c2);
	printf("c3 = %d\n", c3);
	printf("---------\n");
	printf("i1 = %d\n", i1);
	printf("i2 = %d\n", i2);
	printf("i3 = %d\n", i3);
	printf("---------\n");
	printf("x1 = %ld\n", x1);
	printf("x2 = %ld\n", x2);
	printf("x3 = %ld\n", x3);
	printf("+++++++++\n");
}

int main(void) {

	setupVars();
	printVars();

	// x2 = i1+i3+10;
/*	asm(".intel_syntax noprefix\n\t"
		"MOV eax, _i2\n\t"
		"CDQ\n\t"
		"MOV ecx, eax\n\t"
		"MOV ebx, edx\n\t"
		"MOV eax, _i3\n\t"
		"CDQ\n\t"
		"ADD eax, ecx\n\t"
		"ADC edx, ebx\n\t"
		"ADD eax, 10\n\t"
		"ADC edx, 0\n\t"
		"MOV dword ptr [_x2], eax\n\t"
		"MOV dword ptr [_x2+4], edx\n\t"
		".att_syntax prefix\n");

	printVars();
*/
/*	// x1 = x2+i1+c1+10;
	asm(".intel_syntax noprefix\n\t"
		/// +c1
		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"CWD\n\t"
		"CDQ\n\t"
		/// movimenta parte baixa -> ECX, parte alta -> EBX
		"MOV EAX, ECX\n\t"
		"MOV EDX, EBX\n\t"
		/// +i1
		"ADD ECX, _i1\n\t"
		"ADC EBX, 0\n\t"
		"ADD ECX, 10\n\t"
		"ADC EBX, 0\n\t"
		/// +x2
		"ADD ECX, DWORD PTR [_x2]\n\t"
		"ADC EBX, DWORD PTR [_x2+4]\n\t"
		/// x1 =
		"MOV DWORD PTR [_x1], ECX\n\t"
		"MOV DWORD PTR [_x1+4], EBX\n\t"
		"\n\t"
		".att_syntax prefix");

	printVars();
*/
/*	// x2 = x2 + x3 + i1*i2 + 10*i3
	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, _i1\n\t"
		"IMUL DWORD PTR _i2\n\t"
		"MOV ECX, EAX\n\t"
		"MOV EBX, EDX\n\t"
		"MOV EAX, 10\n\t"
		"IMUL DWORD PTR _i3\n\t"
		"ADD ECX, EAX\n\t"
		"ADC EBX, EDX\n\t"
		"ADD ECX, DWORD PTR [_x3]\n\t"
		"ADD EBX, DWORD PTR [_x3+4]\n\t"
		"ADD DWORD PTR [_x2], ECX\n\t"
		"ADC DWORD PTR [_x2+4], EBX\n\t"
		"\n\t"
		".att_syntax prefix\n");

	printVars();
*/
/*	// x1 = x2 - x3 + 100*i1
	asm(".intel_syntax noprefix\n\t"
		/// 100*i1
		"MOV EAX, 100\n\t"
		"IMUL DWORD PTR _i1\n\t"
		/// move eax -> ecx / edx -> ebx
		"MOV ECX, EAX\n\t"
		"MOV EBX, EDX\n\t"
		/// -x3
		"SUB EBX, DWORD PTR [_x3+4]\n\t"
		"SBB ECX, DWORD PTR [_x3]\n\t"
		/// +x2
		"ADD ECX, DWORD PTR [_x2]\n\t"
		"ADC EBX, DWORD PTR [_x2+4]\n\t"
		/// x1 =
		"MOV DWORD PTR [_x1], ECX\n\t"
		"MOV DWORD PTR [_x1+4], EBX\n\t"
		".att_syntax prefix\n");

	printVars();
*/
/*	// x2 = i2/i1 + i3/10
	asm(".intel_syntax noprefix\n\t"

		"MOV EAX, _i3\n\t"
		"MOV ECX, 10\n\t"
		"XOR EDX, EDX\n\t"
		"IDIV ECX\n\t"
		"MOV ECX, EAX\n\t"

		"MOV EAX, _i2\n\t"
		"XOR EDX, EDX\n\t"
		"IDIV DWORD PTR _i1\n\t"
		"ADD ECX, EAX\n\t"
		"ADC EBX, 0\n\t"

		"MOV DWORD PTR [_x2], ECX\n\t"
		"MOV DWORD PTR [_x2+4], EBX\n\t"
		".att_syntax prefix\n");

	printVars();
*/
/*	// x1 = i1/(i2-i1) + i1%3;
	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, _i1\n\t"
		"MOV ECX, 3\n\t"

		"XOR EDX, EDX\n\t"
		"IDIV ECX\n\t"
		"MOV ECX, EDX\n\t"

		"MOV EBX, _i2\n\t"
		"MOV EAX, _i1\n\t"
		"SUB EBX, EAX\n\t"

		"XOR EDX, EDX\n\t"
		"IDIV EBX\n\t"

		"CDQ\n\t"
		"ADD ECX, EAX\n\t"
		"MOV EBX, EDX\n\t"
		"ADC EBX, 0\n\t"

		"MOV DWORD PTR [_x1], ECX\n\t"
		"MOV DWORD PTR [_x1+4], EBX\n\t"
		"\n\t"
		".att_syntax prefix\n");
	printVars();
*/

/* if(c1 >= 'a' && c1 <= 'z') //< 97 / 122
		x1 = x2 + x3;
	else
		x1 = x2 - x3
*/
/*	asm(".intel_syntax noprefix\n\t"
		"MOV AL, _c1\n"
		"CBW\n"

		"MOV ECX, DWORD PTR [_x2]\n\t"
		"MOV EBX, DWORD PTR [_x2+4]\n\t"

		"CMP EAX, 97\n"
		"JL FALSE0\n\t"
		"CMP EAX, 122\n\t"
		"JG FALSE0\n\t"

		"\n"
	"TRUE:\n\t"
		"ADD ECX, DWORD PTR [_x3]\n\t"
		"ADC EBX, DWORD PTR [_x3+4]\n\t"
		"JMP END0\n\t"

		"\n"
	"FALSE0:\n\t"
		"SUB EBX, DWORD PTR [_x3+4]\n\t"
		"SBB ECX, DWORD PTR [_x3]\n\t"

		"\n"
	"END0:\n\t"
		"MOV DWORD PTR [_x1], ECX\n\t"
		"MOV DWORD PTR [_x1+4], EBX\n\t"
		".att_syntax prefix\n");

	printVars();
*/

/*	if(c1 >= '0' && c1 <= '9') // 48 / 57
		c1 -= '0';
*/
/*	asm(".intel_syntax noprefix\n\t"
		"MOV AL, _c1\n\t"
		"CMP AL, 48\n\t"
		"JL END\n\t"
		"CMP AL, 57\n\t"
		"JG END\n\t"

		"SUB AL, 48\n\t"
	"END:\n\t"
		"MOV _c1, AL\n\t"

		".att_syntax prefix\n");
	printVars();
*/

/*	if(i1 != 0 && i2 == 0)
		i1 = c1;
	else
		c1 = i2;
*/
/*	asm(".intel_syntax noprefix\n\t"
		"CMP DWORD PTR _i1, 0\n\t"
		"JZ FALSE1\n\t"
		"CMP DWORD PTR _i2, 0\n\t"
		"JNZ FALSE1\n\t"

		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"MOV _i1, EAX\n\t"
		"JMP END1\n\t"

		"\n"
	"FALSE1:\n\t"
		"MOV AL, BYTE PTR _i2\n\t"
		"MOV _c1, AL\n\t"

		"\n"
	"END1:\n\t"
		".att_syntax prefix\n");

	printVars();
*/
/*	if(x1 != 0 && x2 != 0)
		i1 = c1;
	else
		c1 = i2;
*/
/*	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, DWORD PTR [_x1]\n\t"
		"OR EAX, DWORD PTR [_x1+4]\n\t"

		"OR EAX, EAX\n\t"
		"JZ FALSE2\n\t"

		"MOV EAX, DWORD PTR [_x2]\n\t"
		"OR EAX, DWORD PTR [_x2+4]\n\t"

		"OR EAX, EAX\n\t"
		"JZ FALSE2\n\t"

		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"MOV _i1, EAX\n\t"

		"JMP CONTINUE2\n\t"
	"FALSE2:\n\t"
		"MOV AL, BYTE PTR _i2\n\t"
		"MOV _c1, AL\n\t"

	"CONTINUE2:\n\t"
		"\n\t"
		".att_syntax prefix\n");

	printVars();
*/

/*	if(x1 != 0 && x2 != 0)
		i1 = c1;
	else
		c1 = i2;
*/
/*	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, DWORD PTR [_x1]\n\t"
		"OR EAX, DWORD PTR [_x1+4]\n\t"

		"OR EAX, EAX\n\t"
		"JZ FALSE3\n\t"

		"MOV EAX, DWORD PTR [_x2]\n\t"
		"OR EAX, DWORD PTR [_x2+4]\n\t"

		"OR EAX, EAX\n\t"
		"JNZ FALSE3\n\t"

		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"MOV _i1, EAX\n\t"

		"JMP CONTINUE3\n\t"
	"FALSE3:\n\t"
		"MOV AL, BYTE PTR _i2\n\t"
		"MOV _c1, AL\n\t"

	"CONTINUE3:\n\t"
		"\n\t"
		".att_syntax prefix\n");

	printVars();
*/
/*	if(i1++ != 0)
		i1 = c1;
	else
		c1 = i2;
*/
/*	asm(".intel_syntax noprefix\n\t"
		"MOV EAX, _i1\n\t"

		"OR EAX, EAX\n\t"
		"INC DWORD PTR _i1\n\t"
		"JZ FALSE4\n\t"

		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"MOV _i1, EAX\n\t"

		"JMP CONTINUE4\n\t"
	"FALSE4:\n\t"
		"MOV AL, BYTE PTR _i2\n\t"
		"MOV _c1, AL\n\t"

	"CONTINUE4:\n\t"
		"\n\t"
		".att_syntax prefix\n");
	printVars();
*/

/*	if(c1 < 'a' || c1 > 'z')
		i1++;
	else
		i1--;
*/
/*	asm(".intel_syntax noprefix\n\t"
		"MOV AL, _c1\n\t"
		"CBW\n\t"
		"CMP EAX, 97\n\t"
		"JL TRUE5\n\t"
		"CMP EAX, 122\n\t"
		"JG TRUE5\n\t"

		"DEC DWORD PTR _i1\n\t"

		"JMP CONTINUE5\n"
		"\n"
	"TRUE5:\n\t"
		"INC DWORD PTR _i1\n\t"

		"\n"
	"CONTINUE5:\n\t"
		"\n\t"
		".att_syntax prefix\n");
	printVars();
*/

	return 0;
}