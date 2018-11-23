#coding=utf-8
import sys
import os

import math

def main():
	# lê expressão da entrada padrão
	print('Enter your expression')
	lineRead = sys.stdin.readline()

	# printa expressão lida
	print('line = ' + lineRead + '\n')

	# troca operadores escritos pelos de python
	lineRead = replaceOperators(lineRead)

	# printa linha modificada
	print('line = ' + lineRead + '\n')

	# lê da entrada padrão um valor x
	print('Enter x value')
	xValue = sys.stdin.readline()

	# troca ocorrências de x para valor passado
	finalExpression = lineRead.replace('x', '(' + xValue + ')')

	# calcula resultado da expressão
	expressionResult = eval(finalExpression)

	# printa na saída padrão o resultado
	print('expressionResult = ' + str(expressionResult) + '\n')

def replaceOperators(lineRead):
	lineRead = lineRead.replace('^', '**')
	lineRead = lineRead.replace('log10', 'math.log10')

	lineRead = lineRead.replace('sen', 'math.sin')
	lineRead = lineRead.replace('cos', 'math.cos')
	lineRead = lineRead.replace('tan', 'math.tan')

	lineRead = lineRead.replace('asen', 'math.asin')
	lineRead = lineRead.replace('acos', 'math.acos')
	lineRead = lineRead.replace('atan', 'math.atan')

	lineRead = lineRead.replace('sqrt', 'math.sqrt')

	lineRead = lineRead.replace('e', 'math.e')
	lineRead = lineRead.replace('pi', 'math.pi')

	return lineRead

if __name__ == '__main__':
	main()