Lista *remover_enesimo(Lista *l, int n) {
	Lista *aux = NULL;

	if(!l) return NULL;

	// se n é diferente de 0
	if(--n) {
		// se n == 1, ou seja, é pra remover o proximo
		if(n == 1) {
			if(l->prox) {
				aux = l->prox->prox;
				free(l->prox);
			}
			l->prox = aux;
		} else { //< se não, vai pro próximo
			remover_enesimo(l->prox, n);
		}
	} else { //< se não, é pra remover a cabeça
		aux = l->prox;
		free(l);
		return aux;
	}
	return l;
}