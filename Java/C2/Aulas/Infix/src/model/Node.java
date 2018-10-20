package model;

import java.util.Stack;
import java.util.regex.Pattern;

public abstract class Node {

	private String name;

	Node left;
	Node right;

	private static Stack<Node> values = new Stack<>();

	private static Stack<String> ops = new Stack<>();

	Node(String name) {
		this.name = name;
		this.right = null;
		this.left = null;
	}

	public void setLeft(Node left) {
		this.left = left;
	}

	public void setRight(Node right) {
		this.right = right;
	}

	private static boolean isDouble(String s){
		String reg = "^(-?\\d+)(\\.\\d+)?$";
		Pattern pattern = Pattern.compile(reg);
		return pattern.matcher(s).matches();
	}

	private static  Node montaExpressao(String sl[]) {
		Node node = null;

		for(String str : sl) {
			if(isDouble(str)) {
				values.push(new Numero(Double.parseDouble(str)));
			}

			if(str.equals("(")) {
				ops.push(str);
			}
			if(str.equals(")")) {
				node = getOprClass(node);

				if(node != null) {
					node.setLeft(values.pop());
					node.setRight(values.pop());
				}

				values.push(node);
				ops.pop();
			}

			if(str.equals("+") || str.equals("-") || str.equals("*") || str.equals("/")) {
				ops.push(str);
			}
		}

		if(values.firstElement() != values.lastElement()) {
			node = getOprClass(node);

			if(node != null) {
				node.setLeft(values.pop());
				node.setRight(values.pop());
			}

			values.push(node);
		}

		return values.pop();
	}

	private static Node getOprClass(Node node) {
		switch(ops.pop()) {
			case "+": node = new Soma(); break;
			case "-": node = new Subtracao(); break;
			case "*": node = new Multiplicacao(); break;
			case "/": node = new Divisao(); break;
		}
		return node;
	}

	public static Node montaExpressaoInfix(String expressao) {
		return montaExpressao(expressao.split(" "));
	}

	public abstract double processa();

	public String toString () {
		String s = "";

		if(this.left != null) {
			s += this.left;
		}

		s += this.name;

		if(this.right != null) {
			s += this.right;
		}

		return s;
	}
}
