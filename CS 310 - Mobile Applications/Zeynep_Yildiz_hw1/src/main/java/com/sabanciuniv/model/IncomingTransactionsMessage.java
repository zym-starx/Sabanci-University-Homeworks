package com.sabanciuniv.model;

import java.util.List;

public class IncomingTransactionsMessage {
	
	private String message;
	private List<Transaction> transactions;
	
	public IncomingTransactionsMessage() {
		// TODO Auto-generated constructor stub
	}

	public IncomingTransactionsMessage(String message, List<Transaction> transactions) {
		super();
		this.message = message;
		this.transactions = transactions;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public List<Transaction> getTransactions() {
		return transactions;
	}

	public void setTransactions(List<Transaction> transactions) {
		this.transactions = transactions;
	}
	
	

}
