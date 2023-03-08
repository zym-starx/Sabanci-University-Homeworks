package com.sabanciuniv.controller;

import java.time.LocalDateTime;
import java.util.List;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.sabanciuniv.model.Account;
import com.sabanciuniv.model.AccountMessage;
import com.sabanciuniv.model.InOutTransactionsMsg;
import com.sabanciuniv.model.Transaction;
import com.sabanciuniv.model.TransactionMessage;
import com.sabanciuniv.model.summaryData;
import com.sabanciuniv.repo.AccountRepository;
import com.sabanciuniv.repo.TransactionRepository;

@RestController
@RequestMapping("/transaction")
public class TransactionRestController {
	
	
	@Autowired private AccountRepository accRepo;
	@Autowired private TransactionRepository tranRepo;
	
	private static final Logger logger = LoggerFactory.getLogger(AccountRestController.class);
	
	@GetMapping("/All")
	public List<Transaction> AllAccounts(){
		return tranRepo.findAll();
	}
	
	@PostConstruct
	public void init() {
		
		if(tranRepo.count() ==0) {
			logger.info("Database is empty, initializing..");
			Transaction tran1 = new Transaction("1111", "2222", 1500, LocalDateTime.now());
			Transaction tran2 = new Transaction("2222", "1111", 2000, LocalDateTime.now());
			
			tranRepo.save(tran1);
			tranRepo.save(tran2);
			
			List<Transaction> transactions = tranRepo.findAll();
							
			logger.info("All sample data saved!");
		}
		
	}
	
	/*
	@PostMapping("/transaction/save")
	public Transaction saveTransaction(@RequestBody Transaction tran) {
		
		Transaction savedTransaction = tranRepo.save(tran);
		return savedTransaction;
	}
	*/
	
	@PostMapping("/save")
	public TransactionMessage saveAccount(@RequestBody Transaction transaction) {
		
		TransactionMessage responseMessage = new TransactionMessage();
		if (transaction.getFromID() == null || transaction.getToID() == null) {
			responseMessage.setTransaction(null);
			responseMessage.setMessage("ERROR:missing fields");
		}
		else if (accRepo.findByid(transaction.getFromID()) == null || accRepo.findByid(transaction.getToID()) == null) {
			responseMessage.setTransaction(null);
			responseMessage.setMessage("ERROR: account id");
		}
		else {
			transaction.setTransactionDate(LocalDateTime.now());
			Transaction savedTransaction = tranRepo.save(transaction);
			responseMessage.setTransaction(savedTransaction);
			responseMessage.setMessage("SUCCESS");
			
		}
		
		return responseMessage;
	}
	
	
	@GetMapping("/to/{accountID}")
	public InOutTransactionsMsg ListIncomingTransactions(@PathVariable String accountID) {
		
		InOutTransactionsMsg inTranMsg = new InOutTransactionsMsg();
		Account foundAccount = accRepo.findByid(accountID);
		
		if (foundAccount == null) {
			inTranMsg.setMessage("ERROR:account doesnt exist!");
			inTranMsg.setData(null);
		}
		else {
			inTranMsg.setMessage("SUCCESS");
			
			List<Transaction> transIn = 
					tranRepo.findBytoIDContainsIgnoreCase(accountID);
			inTranMsg.setData(transIn);
			
		}
		
		return inTranMsg;
		
	}
	
	@GetMapping("/from/{accountID}")
	public InOutTransactionsMsg ListOutgoingTransactions(@PathVariable String accountID) {
		
		InOutTransactionsMsg outTranMsg = new InOutTransactionsMsg();
		Account foundAccount = accRepo.findByid(accountID);
		
		if (foundAccount == null) {
			outTranMsg.setMessage("ERROR:account doesnt exist!");
			outTranMsg.setData(null);
		}
		else {
			outTranMsg.setMessage("SUCCESS");
			
			List<Transaction> transOut = 
					tranRepo.findByfromIDContainsIgnoreCase(accountID);
			outTranMsg.setData(transOut);
			
		}
		
		return outTranMsg;
		
	}
	
}
