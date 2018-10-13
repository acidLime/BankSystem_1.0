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
	cout << "�̸� �Է�: ";
	cin >> _name;
	cout << "���¹�ȣ �Է�: ";
	cin >> _accountNum;
	cout << "ù �Ա� �ݾ�: ";
	cin >> _money;
	ACCOUNT account(new Account(_accountNum,_name, _money));
	accountList.push_back(account);
	cout << "���� ���� �Ϸ�" << endl;
}
void BankSystem::Deposit()
{
	cout << "�Ա��� ����: ";
	cin >> _myAccount;
	cout << "�Ա��� �ݾ�: ";
	cin >> _money;
	SendMoney(_myAccount, _money);
}
void BankSystem::WithDrawal()
{
	cout << "����� ����: ";
	cin >> _myAccount;
	cout << "����� �ݾ�: ";
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
			cout << "���� �ܾ�: " << i->GetMoney() << endl;
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
			cout << "���� �ܾ�: " << i->GetMoney() << endl;
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
