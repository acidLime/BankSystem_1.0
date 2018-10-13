#include <iostream>
#include <list>
#include "BankSystem.h"
using namespace std;

void main()
{
	int seleteMenu = 0;
	BankSystem::GetInstance()->Load();
	while (true)
	{
		system("cls");

		cout << "1.계좌 개설" << endl;
		cout << "2.입금" << endl;
		cout << "3.출금" << endl;
		cout << "4.전체고객 잔액조회" << endl;
		cout << "5.종료" << endl;
		cout << "선택: ";
		cin >> seleteMenu;

		system("cls");

		switch ((Menu)seleteMenu)
		{
		case CreateAccount: // 계좌개설
			BankSystem::GetInstance()->CreateAccount();
			break;
		case Deposit: // 입금
			BankSystem::GetInstance()->Deposit();
			break;
		case WithDrawal: // 출금
			BankSystem::GetInstance()->WithDrawal();
			break;
		case BalanceInquiry: // 전체고객 잔액조회
			BankSystem::GetInstance()->BalanceInquiry();
			break;
		case EXIT:
			BankSystem::GetInstance()->Save();
			break;
		default:
			break;
		}
		system("pause");
	}
}