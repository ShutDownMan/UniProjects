#include <stdio.h>
#include "strlib.h"
#include <stdlib.h>

int main(){		
	char *str = NULL;//(char *)malloc(sizeof(char) * 1000);
	// printf("Digite a entrada: ");
	// scanf("%[^\n]", str);
	// str = NULL;
	str = "isabela";
	printf("str = %s\n", str);

/*OUTRA STRING*/
	char *strb = NULL;//(char *)malloc(sizeof(char) * 1000);
	// printf("Digite a entrada: ");
	// scanf("%*c%[^\n]", strb);
	// strb = NULL;
	strb = "isabelaa";

	printf("strb = %s\n", strb);

/*OUTRO CARACTER*/
	// char c;
	// scanf("%*c");
	// printf("Digite o caracter: ");
	// scanf("%c", &c);
	// printf("c = %c\n", c);

/*COMPARE*/
	printf("compare = %d\n", str_compare(str, strb));

/*LENGTH*/	
	// printf("len = %d\n", str_length(str));
	
/*DUPLICATE*/	
	// char *aux = str_duplicate(str);
	// printf("aux = %s\n", aux);
	// free(aux);

	char *str1 = NULL;
	char *str2 = ".";
	char *str3 = "...............";
	char *str4 = "0987655432123456781234567890";
	char *str5 = "LOREM IPSUM IS SIMPLY DUMMY TEXT OF THE PRINTING AND TYPESETTING INDUSTRY. LOREM IPSUM HAS BEEN THE INDUSTRY'S STANDARD DUMMY TEXT EVER SINCE THE 1500S, WHEN AN UNKNOWN PRINTER TOOK A GALLEY OF TYPE AND SCRAMBLED IT TO MAKE A TYPE SPECIMEN BOOK. IT HAS SURVIVED NOT ONLY FIVE CENTURIES, BUT ALSO THE LEAP INTO ELECTRONIC TYPESETTING, REMAINING ESSENTIALLY UNCHANGED. IT WAS POPULARISED IN THE 1960S WITH THE RELEASE OF LETRASET SHEETS CONTAINING LOREM IPSUM PASSAGES, AND MORE RECENTLY WITH DESKTOP PUBLISHING SOFTWARE LIKE ALDUS PAGEMAKER INCLUDING VERSIONS OF LOREM IPSUM.";
	char *str6 =  "IT IS A LONG ESTABLISHED FACT THAT A READER WILL BE DISTRACTED BY THE READABLE CONTENT OF A PAGE WHEN LOOKING AT ITS LAYOUT. THE POINT OF USING LOREM IPSUM IS THAT IT HAS A MORE-OR-LESS NORMAL DISTRIBUTION OF LETTERS, AS OPPOSED TO USING 'CONTENT HERE, CONTENT HERE', MAKING IT LOOK LIKE READABLE ENGLISH. MANY DESKTOP PUBLISHING PACKAGES AND WEB PAGE EDITORS NOW USE LOREM IPSUM AS THEIR DEFAULT MODEL TEXT, AND A SEARCH FOR 'LOREM IPSUM' WILL UNCOVER MANY WEB SITES STILL IN THEIR INFANCY. VARIOUS VERSIONS HAVE EVOLVED OVER THE YEARS, SOMETIMES BY ACCIDENT, SOMETIMES ON PURPOSE (INJECTED HUMOUR AND THE LIKE). . string modificada = CONTRARY TO POPULAR BELIEF, LOREM IPSUM IS NOT SIMPLY RANDOM TEXT. IT HAS ROOTS IN A PIECE OF CLASSICAL LATIN LITERATURE FROM 45 BC, MAKING IT OVER 2000 YEARS OLD. RICHARD MCCLINTOCK, A LATIN PROFESSOR AT HAMPDEN-SYDNEY COLLEGE IN VIRGINIA, LOOKED UP ONE OF THE MORE OBSCURE LATIN WORDS, CONSECTETUR, FROM A LOREM IPSUM PASSAGE, AND GOING THROUGH THE CITES OF THE WORD IN CLASSICAL LITERATURE, DISCOVERED THE UNDOUBTABLE SOURCE. LOREM IPSUM COMES FROM SECTIONS 1.10.32 AND 1.10.33 OF DE FINIBUS BONORUM ET MALORUM (THE EXTREMES OF GOOD AND EVIL) BY CICERO, WRITTEN IN 45 BC. THIS BOOK IS A TREATISE ON THE THEORY OF ETHICS, VERY POPULAR DURING THE RENAISSANCE. THE FIRST LINE OF LOREM IPSUM, LOREM IPSUM DOLOR SIT AMET.., COMES FROM A LINE IN SECTION 1.10.32.";

/*REVERSE*/
	char str_buff[1024] = { 0 };

    int i;
  
    // initializing array elements
    for (i = 0; i < 1023; i++){
        str_buff[i] = 1;
    }

	printf("str_copy = %d\n", str_length(str_buff));
	printf("str_copy = %d\n", str_copy(str_buff, str5));

	str_reverse(str_buff);
	printf("reverse = %s\n", str_buff);	

/*UPPER*/
	printf("upper = %d\n", str_upper(str));	

/*LOWER*/
	printf("lower = %d\n", str_lower(str));

/*COPY*/
	// printf("copy = %d\n", str_copy(str, strb));

/*CONCATENATE*/
	char *aux1 = str_concatenate(str, NULL);
	printf("aux = %s\n", aux1);
	// free(aux1);

/*FIND FIRST*/
	// int result = str_find_first(str, c);
	// if(result == -1 ) printf("STRING NULA.\n");
	// else printf("Posicao = %d\nStr[%d] = %c\n", result+1, result, c);

/*FIND LAST*/
	// int result1 = str_find_last(str, c);
	// if(result1 == -1 ) printf("STRING NULA.\n");
	// else printf("Posicao = %d\nStr[%d] = %c\n", result1+1, result, c);

/*COUNT WORDS*/
	// printf("words = %d\n", str_count_words(str));

	// free(str);
	// free(strb);
	return 0;
}