package com.sabanciuniv.repo;

import java.util.List;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

import com.sabanciuniv.model.Transaction;

@Repository
public interface TransactionRepository extends MongoRepository<Transaction, String>{
	
	public List<Transaction> findAll();
	public List<Transaction> findByfromID(String fromID);
	public List<Transaction> findBytoID(String toID);
	public Transaction findBytranID(String tranID);
	public List<Transaction> findByfromIDContainsIgnoreCase(String fromID);
	public List<Transaction> findBytoIDContainsIgnoreCase(String toID);
}
