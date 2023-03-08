package com.sabanciuniv.model;

import java.time.LocalDateTime;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document
public class Account {
	
	@Id
	private String id;
	private String owner;
	private LocalDateTime createDate;
	
	public Account() {
		// TODO Auto-generated constructor stub
	}
	
	

	public Account(String id, String owner) {
		super();
		this.id = id;
		this.owner = owner;
		this.createDate = LocalDateTime.now();
	}



	public Account(String id, String owner, LocalDateTime createDate) {
		super();
		this.id = id;
		this.owner = owner;
		this.createDate = createDate;
	}

	public Account(String owner, LocalDateTime createDate) {
		super();
		this.owner = owner;
		this.createDate = createDate;
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
	
	

}
