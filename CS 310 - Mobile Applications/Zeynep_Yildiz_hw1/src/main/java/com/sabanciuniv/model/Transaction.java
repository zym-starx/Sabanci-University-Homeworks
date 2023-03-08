package com.sabanciuniv.model;

import java.time.LocalDateTime;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document
public class Transaction {
	
	@Id
	private String tranID;
	
	private String fromID;
	private String toID;
	private double amount;
	private LocalDateTime transactionDate;
	
	public Transaction() {
		// TODO Auto-generated constructor stub
	}
	

	public Transaction(String fromID, String toID, double amount) {
		super();
		this.fromID = fromID;
		this.toID = toID;
		this.amount = amount;
	}


	public Transaction(String fromID, String toID, double amount, LocalDateTime transactionDate) {
		super();
		this.fromID = fromID;
		this.toID = toID;
		this.amount = amount;
		this.transactionDate = transactionDate;
	}


	public Transaction(String tranID, String fromID, String toID, double amount, LocalDateTime transactionDate) {
		super();
		this.tranID = tranID;
		this.fromID = fromID;
		this.toID = toID;
		this.amount = amount;
		this.transactionDate = transactionDate;
	}


	public String getFromID() {
		return fromID;
	}

	public void setFromID(String fromID) {
		this.fromID = fromID;
	}

	public String getToID() {
		return toID;
	}

	public void setToID(String toID) {
		this.toID = toID;
	}

	public double getAmount() {
		return amount;
	}

	public void setAmount(double amount) {
		this.amount = amount;
	}

	public String getTranID() {
		return tranID;
	}

	public void setTranID(String tranID) {
		this.tranID = tranID;
	}




	public LocalDateTime getTransactionDate() {
		return transactionDate;
	}




	public void setTransactionDate(LocalDateTime transactionDate) {
		this.transactionDate = transactionDate;
	}
	
	

}
