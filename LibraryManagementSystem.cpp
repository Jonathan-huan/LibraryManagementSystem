#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include"mylist.h"
#include"library.h"
using std::cout;
using std::cin;
using std::system;
LibOperate lib;
void menu()//���˵���ʾ������
{
	if (lib.getAuthority() == authority::unlogin)
	{
		int num;
		cout << "********ע���¼ҳ��********" << endl;
		cout << "1.ע���û�" << endl;
		cout << "2.��¼ϵͳ" << endl;
		cout << "0.�˳�ϵͳ" << endl;
		while (1)
		{	
			cout << "�������������ţ�";
			cin >> num;
			if (num == 1)
			{
				lib.regist(authority::borrower); 
				cout << "һ����Զ��˳�������";
				Sleep(1000);
				system("cls");
				menu();
			}
			else if (num == 2)
			{
				if (lib.sign())
				{
					cout << "һ����Զ��˳�������";
					Sleep(1000);
					system("cls");
					menu();
				}
			}
			else if (num == 0)
			{
				exit(0);
			}
			else cout << "����������������룡";
		}
	}
	else if (lib.getAuthority() == authority::borrower)
	{
		int num;
		cout << "********ͼ�����ϵͳ********" << endl;
		cout << "1.�������ͼ��" << endl;
		cout << "2.��ѯͼ��" << endl;
		cout << "3.�����鼮" << endl;
		cout << "4.�黹�鼮" << endl;
		cout << "5.�û���Ϣ�鿴" << endl;
		cout << "0.�˳���¼" << endl;
		cout << "��ã������ˣ�" << endl;
		while (1)
		{
			cout << "�������������ţ�";
			cin >> num;
			switch (num)
			{
			case 1:
				system("cls");
				lib.browse();
				system("pause");
				system("cls");
				menu();
				break;
			case 2:
				system("cls");
				lib.check();
				system("pause");
				system("cls");
				menu();
				break;
			case 3:
				system("cls");
				lib.borrow();
				system("pause");
				system("cls");
				menu();
				break;
			case 4:
				system("cls");
				lib.send_back();
				system("pause");
				system("cls");
				menu();
				break;
			case 5:
				system("cls");
				cout << "��ã������ˣ�" << endl;
				lib.info();
				system("pause");
				system("cls");
				menu();
				break;
			case 0:
				system("cls");
				lib.exit();
				menu();
				break;
			}
		}
		
	}
	else
	{
		int num;
		cout << "********ͼ�����ϵͳ********" << endl;
		cout << "1.�������ͼ��" << endl;
		cout << "2.��ѯͼ��" << endl;
		cout << "3.�����鼮" << endl;
		cout << "4.�黹�鼮" << endl;
		cout << "5.�û���Ϣ�鿴" << endl;
		cout << "6.���ͼ��" << endl;
		cout << "7.ɾ��ͼ��" << endl;
		cout << "8.ɾ������ͼ��" << endl;
		cout << "9.�޸�ͼ��" << endl;
		cout << "10.����Ա�Ǽ�" << endl;
		cout << "11.��Աɾ��" << endl;
		cout << "0.�˳���¼" << endl;
		cout << "��ã������ߣ�" << endl;
		while (1)
		{
			cout << "�������������ţ�";
			cin >> num;
			switch (num)
			{
			case 1:
				system("cls");
				lib.browse();
				system("pause");
				system("cls");
				menu();
				break;
			case 2:
				system("cls");
				lib.check();
				system("pause");
				system("cls");
				menu();
				break;
			case 3:
				system("cls");
				lib.borrow();
				system("pause");
				system("cls");
				menu();
				break;
			case 4:
				system("cls");
				lib.send_back();
				system("pause");
				system("cls");
				menu();
				break;
			case 5:
				system("cls");
				cout << "��ã������ˣ�" << endl;
				lib.info();
				system("pause");
				system("cls");
				menu();
				break;
			case 6:
				system("cls");
				lib.add();
				system("pause");
				system("cls");
				menu();
				break;
			case 7:
				system("cls");
				lib.del();
				system("pause");
				system("cls");
				menu();
				break;
			case 8:
				system("cls");
				lib.del_all();
				system("pause");
				system("cls");
				menu();
				break;
			case 9:
				system("cls");
				lib.change();
				system("pause");
				system("cls");
				menu();
				break;
			case 10:
				system("cls");
				lib.regist(authority::manager);
				system("pause");
				system("cls");
				menu();
				break;
			case 11:
				system("cls");
				lib.del_ppl();
				system("pause");
				system("cls");
				menu();
				break;
			case 0:
				system("cls");
				lib.exit();
				menu();
				break;
			default:
				system("cls");
				cout << "����������������룡" << endl;
				menu();
				break;
			}
		}
	}
}
int main()
{
	//�����ļ�
	readfile();
	readfile_book();
	//�쳣����
	try {

		menu();
	}
	catch (int)
	{
		cerr << "error��" << endl;
		exit(0);
	}
	//�˳�ǰ�ٴ�д���ļ�
	writefile();
	writefile_book();
}