package controller;

import model.Node;

public class ControllerMain {

	public static void main(String[] args) {

		Node e = Node.montaExpressaoInfix("( 7 + 8 ) * 5");
				
		System.out.println(e.processa());
		
		System.out.println(e);
	}
}
