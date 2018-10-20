package model;

import java.util.regex.Pattern;

import util.WrapperInt;

public abstract class Node {
		
	private String name;
	
	protected Node left;
	protected Node right;
	
	public Node ( String name ) {
		this.name = name;
		this.right = null;
		this.left = null;
	}
	
	public void setLeft ( Node left ) {
		this.left = left;
	}
	
	public void setRight ( Node right ) {
		this.right = right;
	}

	private static boolean isDouble(String s){
		String reg = "^(-?\\d+)(\\.\\d+)?$";
		Pattern pattern = Pattern.compile(reg);
		return pattern.matcher(s).matches();
	}
	
		
	private static boolean isInteger(String s){
		String reg = "^(-?\\d+)$";
		Pattern pattern = Pattern.compile(reg);
		return pattern.matcher(s).matches();
	}
	
	private static  Node montaExpressaoRec ( String sl[], WrapperInt i) {
		Node node = null;
		if (i.value()<sl.length) {
			if ( isInteger ( sl [ i.value() ] ) ) {
				return new Inteiro ( Integer.parseInt(sl [ i.value() ]) );
			}
			if ( isDouble( sl [ i.value() ] ) ) {
				return new Numero ( Double.parseDouble(sl [ i.value() ]) );
			}
			switch (sl [ i.value() ] ) {
			case "+": node = new Soma(); break;
			case "-": node = new Subtracao(); break;
			case "*": node = new Multiplicacao(); break;
			case "/": node = new Divisao(); break;
			}
			node.setLeft( montaExpressaoRec(sl, i.inc() ) );
			node.setRight( montaExpressaoRec(sl, i.inc() ) );			
			
		}
		return node;
	}
	
	public static Node montaExpressaoPreFix ( String expressao ) {
		return montaExpressaoRec ( expressao.split(" "), new WrapperInt(0) );				
	}
	
	public abstract double processa ( );
	
	public String toString () {
		String s="";
		if (this.left!=null) {
			s += this.left;
		}
		s += this.name;
		
		if (this.right!=null) {
			s += this.right;
		}
		return s;
	}
}
