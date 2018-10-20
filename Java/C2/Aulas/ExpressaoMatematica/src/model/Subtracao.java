package model;

public class Subtracao extends Node {

	public Subtracao() {
		super(" - ");
	}

	@Override
	public double processa() {
		return this.left.processa() - this.right.processa();
	}


}
