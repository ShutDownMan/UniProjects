


Lista* insere(Lista *l, int info){
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = info;

	if(vazia(l)){
		novo->prox = novo;
		novo->ant = novo;
		return novo;
	} else {
		novo->prox = l;
		novo->ant = l->ant;
		l->ant->prox = novo;
		l->ant = novo;
		return l;
	}
}

void imprime(Lista *l){
	Lista* ptr = l;

	if(!l) {
		printf("Lista vazia\n");
		return;
	}

	while(ptr != l->ant) {
		printf("-> %d", ptr->info);
		ptr = ptr->prox;
	}
	printf("-> %d", ptr->info);

}