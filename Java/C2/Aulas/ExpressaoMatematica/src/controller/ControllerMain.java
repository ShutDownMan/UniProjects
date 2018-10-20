package controller;

import model.Node;

public class ControllerMain {

	
	public static void main(String[] args) {
		
		/*String s = "+ + 7 8 15.8";
		String a[] = s.split(" ");
		for (String string : a) {
			System.out.println(string);
		}*/
		
		//Node e = Node.montaExpressaoPreFix("+ + 7 8 15.8");
		Node e = Node.montaExpressaoPreFix("* + 5 6 - 3 + -10 15");
				
		System.out.println(e.processa());
		
		System.out.println(e);
		
	}
}
