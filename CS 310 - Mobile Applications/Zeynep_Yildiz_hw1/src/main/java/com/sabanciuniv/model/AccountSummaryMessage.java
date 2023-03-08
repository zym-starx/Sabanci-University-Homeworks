package com.sabanciuniv.model;

import java.time.LocalDateTime;
import java.util.List;

public class AccountSummaryMessage {
	
	private String message;
	private summaryData data;
	
	public AccountSummaryMessage() {
		// TODO Auto-generated constructor stub
	}
	
	public AccountSummaryMessage(String message, summaryData data) {
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

	public summaryData getData() {
		return data;
	}

	public void setData(summaryData data) {
		this.data = data;
	}

}
