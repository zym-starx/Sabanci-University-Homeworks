package com.sabanciuniv.model;

public class TransactionMessage {
	
	private String message;
	private Transaction transaction;
	
	public TransactionMessage() {
		// TODO Auto-generated constructor stub
	}

	public TransactionMessage(String message, Transaction transaction) {
		super();
		this.message = message;
		this.transaction = transaction;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public Transaction getTransaction() {
		return transaction;
	}

	public void setTransaction(Transaction transaction) {
		this.transaction = transaction;
	}
	
	

}
