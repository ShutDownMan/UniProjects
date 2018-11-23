
void reorganiza(FILE *fm, FILE *ft, FILE *fm_novo) {
	int mIter, tIter, hasRegs = 0;
	Funcionario *currentFuncionario = le_reg_funcionario(fm, 0);
	Transacao *currentTransacao = le_reg_transacao(ft, 0);

	for(mIter = tIter = 1; hasRegs;) {
		if(currentFuncionario && currentTransacao) {
			if(currentFuncionario->codigo == currentTransacao->funcionario.codigo) {
				if(currentTransacao->operacao == 'A') {
					/// escreve no nfm registro alterado
					escreve_reg_funcionario(fm_novo, &currentTransacao->funcionario);
				}
				if(currentTransacao->operacao == 'R') {
					printf("Funcionario %s removido dos registros!\n", currentFuncionario->nome);
				}
				/// atualiza currentFuncionario
				free(currentFuncionario);
				currentFuncionario = le_reg_funcionario(fm, mIter++);
				/// atualiza currentTransacao
				free(currentTransacao);
				currentTransacao = le_reg_transacao(ft, tIter++);
			} else if(currentFuncionario->codigo < currentTransacao->funcionario.codigo) {
				/// escreve no nfm registro inalalterado
				escreve_reg_funcionario(fm_novo, currentFuncionario);
				/// atualiza currentFuncionario
				free(currentFuncionario);
				currentFuncionario = le_reg_funcionario(fm, mIter++);
			} else if(currentTransacao->operacao == 'I') {
				/// escreve no nfm novo funcionario
				escreve_reg_funcionario(fm_novo, &currentTransacao->funcionario);
				free(currentTransacao);
				/// atualiza currentTransacao
				currentTransacao = le_reg_transacao(ft, tIter++);
			}
		} else {
			if(currentFuncionario) {
				/// escreve no nfm registro inalalterado
				escreve_reg_funcionario(fm_novo, currentFuncionario);
				/// atualiza currentFuncionario
				free(currentFuncionario);
				currentFuncionario = le_reg_funcionario(fm, mIter++);
			}
			if(currentTransacao) {
				/// escreve no nfm novo funcionario
				escreve_reg_funcionario(fm_novo, &currentTransacao->funcionario);
				free(currentTransacao);
				/// atualiza currentTransacao
				currentTransacao = le_reg_transacao(ft, tIter++);
			}
		}


		hasRegs = (!feof(fm) || !feof(ft));
	}

}