package model;

public class Soma extends Node {

	public Soma( ) {
		super(" + ");
	}

	@Override
	public double processa() {
		return this.left.processa() + this.right.processa();
	}

}
