package model;

public class Multiplicacao extends Node {

	public Multiplicacao() {
		super(" * ");
	}

	@Override
	public double processa() {
		return this.left.processa() * this.right.processa();
	}


}
