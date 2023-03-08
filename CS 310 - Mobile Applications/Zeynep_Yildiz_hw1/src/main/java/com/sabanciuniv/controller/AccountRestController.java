package com.sabanciuniv.controller;

import java.time.LocalDateTime;
import java.util.ArrayList;
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
import com.sabanciuniv.model.AccountSummaryMessage;
import com.sabanciuniv.model.InOutTransactionsMsg;
import com.sabanciuniv.model.TranSummaryData;
import com.sabanciuniv.model.Transaction;
import com.sabanciuniv.model.summaryData;
import com.sabanciuniv.repo.AccountRepository;
import com.sabanciuniv.repo.TransactionRepository;

@RestController
@RequestMapping("/account")
public class AccountRestController {
	
	
	@Autowired private AccountRepository accRepo;
	@Autowired private TransactionRepository tranRepo;
	
	@GetMapping("/All")
	public List<Account> AllAccounts(){
		return accRepo.findAll();
	}
	
	private static final Logger logger = LoggerFactory.getLogger(AccountRestController.class);
	
	@PostConstruct
	public void init() {
		
		if(accRepo.count() ==0) {
			logger.info("Database is empty, initializing..");
			Account acc1 = new Account("1111", "Saeran Choi", LocalDateTime.now());
			Account acc2 = new Account("2222", "Nagito Komaeda", LocalDateTime.now());
			
			accRepo.save(acc1);
			accRepo.save(acc2);
			
			List<Account> accounts = accRepo.findAll();
							
			logger.info("All sample data saved!");
		}
	}
	
	@PostMapping("/save")
	public AccountMessage saveAccount(@RequestBody Account acc) {
		
		AccountMessage responseMessage = new AccountMessage();
		if (acc.getId() == null || acc.getOwner() == null) {
			responseMessage.setAcc(null);
			responseMessage.setMessage("ERROR:missing fields");
		}
		else {
			acc.setCreateDate(LocalDateTime.now());
			Account savedAccount = accRepo.save(acc);
			responseMessage.setAcc(savedAccount);
			responseMessage.setMessage("SUCCESS");
		}
		
		return responseMessage;
	}
	
	@GetMapping("/{accountID}")
	public AccountSummaryMessage accountSummary(@PathVariable String accountID) {
		
		AccountSummaryMessage sumMsg = new AccountSummaryMessage();
		Account foundAccount = accRepo.findByid(accountID);
		
		if (foundAccount == null) {
			sumMsg.setMessage("ERROR:account doesnt exist!");
			sumMsg.setData(null);
		}
		else {
			sumMsg.setMessage("SUCCESS");
			summaryData data = new summaryData();
			data.setId(accountID);
			data.setOwner(foundAccount.getOwner());
			data.setCreateDate(foundAccount.getCreateDate());
			
			List<Transaction> transIn = 
					tranRepo.findBytoIDContainsIgnoreCase(accountID);
			
			List<TranSummaryData> transInData = new ArrayList<TranSummaryData>();
			
			
			transIn.forEach(transaction->{
				
				TranSummaryData dummy = new TranSummaryData(transaction.getTranID(), 
						accRepo.findByid(transaction.getFromID()), 
						accRepo.findByid(transaction.getToID()),
						transaction.getTransactionDate(),
						transaction.getAmount());
				
				transInData.add(dummy);
				
				
				 double a = data.getBalance();
				 a += transaction.getAmount();
				 
				 data.setBalance(a);
			});
			
			data.setTransactionsIn(transInData);
			
			List<Transaction> transOut = 
					tranRepo.findByfromIDContainsIgnoreCase(accountID);
			
			List<TranSummaryData> transOutData = new ArrayList<TranSummaryData>();
			
			transOut.forEach(transaction->{
				
				TranSummaryData dummy = new TranSummaryData(transaction.getTranID(), 
						accRepo.findByid(transaction.getFromID()), 
						accRepo.findByid(transaction.getToID()),
						transaction.getTransactionDate(),
						transaction.getAmount());
				
				transOutData.add(dummy);
				
				 double a = data.getBalance();
				 a = a - transaction.getAmount();
				 
				 data.setBalance(a);
			});
			
			data.setTransactionsOut(transOutData);
			sumMsg.setData(data);
		}
		
		return sumMsg;
		
	}
	
	
}
