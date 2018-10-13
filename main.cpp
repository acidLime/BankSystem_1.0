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

		cout << "1.���� ����" << endl;
		cout << "2.�Ա�" << endl;
		cout << "3.���" << endl;
		cout << "4.��ü�� �ܾ���ȸ" << endl;
		cout << "5.����" << endl;
		cout << "����: ";
		cin >> seleteMenu;

		system("cls");

		switch ((Menu)seleteMenu)
		{
		case CreateAccount: // ���°���
			BankSystem::GetInstance()->CreateAccount();
			break;
		case Deposit: // �Ա�
			BankSystem::GetInstance()->Deposit();
			break;
		case WithDrawal: // ���
			BankSystem::GetInstance()->WithDrawal();
			break;
		case BalanceInquiry: // ��ü�� �ܾ���ȸ
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