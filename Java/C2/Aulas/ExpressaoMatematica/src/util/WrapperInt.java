package util;

public class WrapperInt {
	
	private int i;
	
	public WrapperInt ( ) {
		this.i = 0;		
	}
	
	public WrapperInt ( int i ) {
		this.i = i;		
	}
	
	public WrapperInt inc () {
		this.i++;
		return this;
	}
	
	public WrapperInt inc ( int i) {
		this.i += i;
		return this;
	}
	
	public int value () {
		return this.i;		
	}

}
