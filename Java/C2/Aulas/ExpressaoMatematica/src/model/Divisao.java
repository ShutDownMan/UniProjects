package model;

public class Divisao extends Node {

	public Divisao() {
		super(" / ");
	}

	@Override
	public double processa() {
		return this.left.processa() / this.right.processa();
	}

}
