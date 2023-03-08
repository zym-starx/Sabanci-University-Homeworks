package com.sabanciuniv.model;

public class AccountMessage {
	
	private String message;
	private Account acc;
	
	public AccountMessage() {
		// TODO Auto-generated constructor stub
	}

	public AccountMessage(String message, Account acc) {
		super();
		this.message = message;
		this.acc = acc;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public Account getAcc() {
		return acc;
	}

	public void setAcc(Account acc) {
		this.acc = acc;
	}
	
	

}
