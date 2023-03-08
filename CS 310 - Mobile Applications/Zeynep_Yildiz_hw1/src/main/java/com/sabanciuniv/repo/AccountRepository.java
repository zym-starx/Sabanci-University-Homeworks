package com.sabanciuniv.repo;

import java.util.List;

import org.springframework.data.mongodb.repository.MongoRepository;

import com.sabanciuniv.model.Account;
import com.sabanciuniv.model.Transaction;

public interface AccountRepository extends MongoRepository<Account,String>{

	public List<Account> findAll();
	public Account findByOwner(String owner);
	public Account findByid(String id);
	public List<Account> findByidContainsIgnoreCase(String id);
	public List<Account> findByownerContainsIgnoreCase(String owner);
	

}
