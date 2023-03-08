package com.sabanciuniv.model;

import java.time.LocalDateTime;

public class TranSummaryData {
	
	private String id;
	private Account fromAcc;
	private Account toAcc;
	private LocalDateTime createDate;
	private double amount;
	
	public TranSummaryData() {
		// TODO Auto-generated constructor stub
	}

	public TranSummaryData(String id, Account fromAcc, Account toAcc, LocalDateTime createDate, double amount) {
		super();
		this.id = id;
		this.fromAcc = fromAcc;
		this.toAcc = toAcc;
		this.createDate = createDate;
		this.amount = amount;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public Account getFromAcc() {
		return fromAcc;
	}

	public void setFromAcc(Account fromAcc) {
		this.fromAcc = fromAcc;
	}

	public Account getToAcc() {
		return toAcc;
	}

	public void setToAcc(Account toAcc) {
		this.toAcc = toAcc;
	}

	public LocalDateTime getCreateDate() {
		return createDate;
	}

	public void setCreateDate(LocalDateTime createDate) {
		this.createDate = createDate;
	}

	public double getAmount() {
		return amount;
	}

	public void setAmount(double amount) {
		this.amount = amount;
	}
	
	

}
