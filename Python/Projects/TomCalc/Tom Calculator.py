# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import collections

lista_toms = collections.OrderedDict()

def setup_dict():
	lista_toms.update({'A':	0.5})
	lista_toms.update({'A#':0.5})
	lista_toms.update({'B':	0.5})
	lista_toms.update({'C':	0.5})
	lista_toms.update({'C#':0.5})
	lista_toms.update({'D':	0.5})
	lista_toms.update({'D#':0.5})
	lista_toms.update({'E':	0.5})
	lista_toms.update({'F':	0.5})
	lista_toms.update({'F#':0.5})
	lista_toms.update({'G':	0.5})
	lista_toms.update({'G#':0.5})


def tom(tom_atual, novo_tom):

	setup_dict()

	try:
		if lista_toms[tom_atual] == None:
			return
			pass
		if lista_toms[novo_tom] == None:
			return
			pass
	except:
		print 'Argumentos são toms em escala A-G!'
		return

	diferenca_de_tom = 0

	print 'seu tom atual é ' + tom_atual
	
	tom_atual_encontrado = False
	novo_tom_encontrado = False

	for tom, v in lista_toms.items():
		print tom
		print diferenca_de_tom
		if tom == tom_atual.upper() or tom_atual_encontrado == True:
			tom_atual_encontrado = True
			diferenca_de_tom += v
			pass
	
		if tom == novo_tom.upper() or novo_tom_encontrado == True:
			novo_tom_encontrado= True
			diferenca_de_tom -= v
			pass

		if tom_atual_encontrado == True and novo_tom_encontrado == True:
			break


	if diferenca_de_tom == 0:
		print 'Naum mim zoa infiliz'
		return diferenca_de_tom

	if diferenca_de_tom > 0:
		print 'Deverá subir ' + str(diferenca_de_tom) + ' toms para alcançar'
		return diferenca_de_tom
	else:
		print 'Deverá descer ' + str(abs(diferenca_de_tom)) + ' toms para alcançar'
		return diferenca_de_tom