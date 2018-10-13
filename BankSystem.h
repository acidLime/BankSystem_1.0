#pragma once
#define Safe_Delete(i) if(i != nullptr) delete i; i = nullptr;
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include "Account.h"
#include <memory>
#include <fstream>
using namespace std;
enum Menu
{
	None,
	CreateAccount,
	Deposit,
	WithDrawal,
	BalanceInquiry,
	EXIT
};
typedef shared_ptr<Account> ACCOUNT;
class BankSystem
{
private:
	BankSystem() {};
	BankSystem(const BankSystem& copy);

	static BankSystem* _instance;
	static void Destroy() { delete _instance; }

	list<ACCOUNT> accountList;

	string _name;
	int _accountNum;
	int _myAccount;
	int _money;

	char _buffer[64];

	void SendMoney(int accountNum, int money);
	void ReciveMoney(int accountNum, int money);
public:
	~BankSystem();
	static BankSystem* GetInstance();

	void CreateAccount();
	void Deposit();
	void WithDrawal();
	void BalanceInquiry();
	void Load();
	void Save();
	
};