package model;

public class Numero extends Node {
	
	private double value;
	
	public Numero ( double value ){
		super(String.valueOf(value));
		this.value = value;		
	}

	@Override
	public double processa() {
		return value;
	}


}
