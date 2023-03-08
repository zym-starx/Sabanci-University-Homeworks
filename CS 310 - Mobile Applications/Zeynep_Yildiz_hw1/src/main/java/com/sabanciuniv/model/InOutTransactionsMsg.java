package com.sabanciuniv.model;

import java.util.List;

public class InOutTransactionsMsg {
	
	private String message;
	private List<Transaction> data;
	
	public InOutTransactionsMsg() {
		// TODO Auto-generated constructor stub
	}

	public InOutTransactionsMsg(String message, List<Transaction> data) {
		super();
		this.message = message;
		this.data = data;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public List<Transaction> getData() {
		return data;
	}

	public void setData(List<Transaction> data) {
		this.data = data;
	}
	
	

}
