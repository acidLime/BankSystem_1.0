#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	int _accountNum;
	string *_name;
	double _money;
public:
	Account(int accountNum, string name, double money);
	~Account();
	void ShowData();
	int GetAccountNum() { return _accountNum; }
	string GetName() { return *_name; }
	double GetMoney() { return _money; }
	void ReciveMoney(int money) { _money += money; }
	void SendMoney(int money) { _money -= money; }
};

