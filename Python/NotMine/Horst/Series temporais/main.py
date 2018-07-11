import scipy.io
import math
import sys

def parseFile(file_name):
	o_list = []
	# carrega arquivo .mat
	mat = scipy.io.loadmat(file_name)

	# para cada lista interna dentro do arquivo
	for inner_list in mat['ghow1']:
		# para cada numero na lista interna
		for number in inner_list:
			# adiciona na lista auxiliar
			o_list.append(number);

	# retorna lista original
	return o_list

def separate_subsequences(o_list, M):
	subsequences_list = []

	# inicializa campos da lista de listas
	for i in xrange(0, M):
		subsequences_list.append([])

	# guarda na lista de listas
	for i in xrange(0, (int)(math.ceil((float)(len(o_list))/M))):
		for j in xrange(0, M):
			ind = i*M + j
			if(ind < len(o_list)):
				subsequences_list[j].append(o_list[ind])

	# retorna lista de listas
	return subsequences_list

if __name__ == '__main__':
	M = None
	o_list = []
	subsequences_list = []

	# le do .mat os dados numeros e guarda numa lista
	o_list = parseFile('ghow1.mat')

	# pede do usuario a quantidade de series temporais que a lista tem que ser dividida
	print 'Digite numero de subsequencias temporais a serem separadas (M):'
	M = int(sys.stdin.readline())

	# separa a lista original e guarda em uma lista de listas
	subsequences_list = separate_subsequences(o_list, M)

	# para cada lista interna na lista de subsequencias
	for inner_list in subsequences_list:
		print '----------------'
		# para cada numero na lista interna
		for number in inner_list:
			# mostra na tela
			print number

	# tamanho da lista original
	print len(o_list)

	sys.stdin.readline()