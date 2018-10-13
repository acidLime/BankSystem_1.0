#include "Account.h"

Account::Account(int accountNum, string name, double money)
{
	_accountNum = accountNum;
	_name = new string(name);
	_money = money;
}
Account::~Account()
{
	delete _name;
}

void Account::ShowData()
{
	cout << _accountNum << endl;
	cout << *_name << endl;
	cout << _money << endl;
}
