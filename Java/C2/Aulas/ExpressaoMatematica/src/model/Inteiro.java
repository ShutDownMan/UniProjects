package model;

public class Inteiro extends Node {

	private int value;
	
	public Inteiro(int value) {
		super(String.valueOf(value));
		this.value = value;		
	}

	@Override
	public double processa() {
		return this.value;
	}

}
