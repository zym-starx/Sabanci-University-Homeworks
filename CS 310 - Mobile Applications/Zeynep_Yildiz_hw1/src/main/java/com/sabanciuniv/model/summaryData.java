package com.sabanciuniv.model;

import java.time.LocalDateTime;
import java.util.List;

public class summaryData {
	private String id;
	private String owner;
	private LocalDateTime createDate;
	private List<TranSummaryData> transactionsOut;
	private List<TranSummaryData> transactionsIn;
	private static double balance;
	
	public summaryData() {
		// TODO Auto-generated constructor stub
	}

	public summaryData(String id, String owner, LocalDateTime createDate, List<TranSummaryData> transactionsOut,
			List<TranSummaryData> transactionsIn, double balance) {
		super();
		this.id = id;
		this.owner = owner;
		this.createDate = createDate;
		this.transactionsOut = transactionsOut;
		this.transactionsIn = transactionsIn;
		this.balance = balance;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getOwner() {
		return owner;
	}

	public void setOwner(String owner) {
		this.owner = owner;
	}

	public LocalDateTime getCreateDate() {
		return createDate;
	}

	public void setCreateDate(LocalDateTime createDate) {
		this.createDate = createDate;
	}

	public List<TranSummaryData> getTransactionsOut() {
		return transactionsOut;
	}

	public void setTransactionsOut(List<TranSummaryData> transactionsOut) {
		this.transactionsOut = transactionsOut;
	}

	public List<TranSummaryData> getTransactionsIn() {
		return transactionsIn;
	}

	public void setTransactionsIn(List<TranSummaryData> transactionsIn) {
		this.transactionsIn = transactionsIn;
	}

	public double getBalance() {
		return balance;
	}

	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	
}
