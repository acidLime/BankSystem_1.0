#include "BankSystem.h"

BankSystem* BankSystem::_instance = nullptr;

BankSystem::~BankSystem()
{
	Save();
}

BankSystem * BankSystem::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new BankSystem();
	}
	atexit(Destroy);
	return _instance;
}
void BankSystem::CreateAccount()
{
	cout << "이름 입력: ";
	cin >> _name;
	cout << "계좌번호 입력: ";
	cin >> _accountNum;
	cout << "첫 입금 금액: ";
	cin >> _money;
	ACCOUNT account(new Account(_accountNum,_name, _money));
	accountList.push_back(account);
	cout << "계좌 개설 완료" << endl;
}
void BankSystem::Deposit()
{
	cout << "입금할 계좌: ";
	cin >> _myAccount;
	cout << "입금할 금액: ";
	cin >> _money;
	SendMoney(_myAccount, _money);
}
void BankSystem::WithDrawal()
{
	cout << "출금할 계좌: ";
	cin >> _myAccount;
	cout << "출금할 금액: ";
	cin >> _money;
	ReciveMoney(_myAccount, _money);
}
void BankSystem::BalanceInquiry()
{
	for (auto i : accountList)
	{
		cout << "------------" << endl;
		i->ShowData();
		cout << "------------" << endl;
	}
}
void BankSystem::Load()
{
	ifstream loadFile("Account.txt");
	if (loadFile.is_open() == true)
	{
		loadFile.getline(_buffer, strlen(_buffer));
		while (!loadFile.eof())
		{
			loadFile >> _accountNum;
			loadFile >> _name;
			loadFile >> _money;
			ACCOUNT account(new Account(_accountNum, _name, _money));
			accountList.push_back(account);
		}
		loadFile.close();
	}
}
void BankSystem::SendMoney(int accountNum, int money)
{
	for (auto i : accountList)
	{
		if (i->GetAccountNum() == accountNum)
		{
			i->ReciveMoney(money);
			cout << "현재 잔액: " << i->GetMoney() << endl;
		}
	}
}
void BankSystem::ReciveMoney(int accountNum, int money)
{
	for (auto i : accountList)
	{
		if (i->GetAccountNum() == accountNum)
		{
			i->SendMoney(money);
			cout << "현재 잔액: " << i->GetMoney() << endl;
		}
	}
}
void BankSystem::Save()
{
	ofstream saveFile;
	saveFile.open("Account.txt", ios_base::out);
	for (auto i : accountList)
	{
		saveFile << endl << i->GetAccountNum() << endl;
		saveFile << i->GetName() << endl;
		saveFile << i->GetMoney();
	}
	saveFile.close();
}
