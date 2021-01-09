#include"library.h"
#include"myList.cpp"
#include<iostream>
#include<iomanip>
#include<vector>
using std::cout; using std::cin;
vector<People> pb;//������
vector<People>pm;//������Ա
vector<People>::iterator it;//����������
myList<Book>b;//����һ��������б�
People currPpl;//���浱ǰ�˻���Ϣ��

//�ຯ������
void writefile()
{
	ofstream f1("borrower.txt"),f2("manager.txt");
	if (f1.good())
	{
		for (it = pb.begin(); it < pb.end(); it++)
		{
			f1 << (*it).name<<"\t" << (*it).sex << "\t" << (*it).age << "\t" << (*it).username << "\t" << (*it).password << endl;
		}
		for (it = pm.begin(); it < pm.end(); it++)
		{
			f2<< (*it).name << "\t" << (*it).sex << "\t" << (*it).age << "\t" << (*it).username << "\t" << (*it).password << endl;
		}
	}
	f1.close();
	f2.close();
}
void readfile()
{
	People p1,p2;
	ifstream f1("borrower.txt"),f2("manager.txt");
	if (f1.good())
	{
		while (f1 >> p1.name >> p1.sex >> p1.age >> p1.username >> p1.password)
		{
			pb.push_back(p1);
		}
	}
	else
	{
		f1.close();
		cout << "error��" << endl;
		return;
	}
	f1.close();
	if (!f2.bad())
	{
		while (f2 >> p2.name >> p2.sex >> p2.age >> p2.username >> p2.password)
		{
			pm.push_back(p2);
		}
	}
	else
	{
		f2.close();
		cout << "error��" << endl;
		return;
	}
	f2.close();
}
void People::showInfo()
{
	cout << "������" << name << endl;
	cout << "�Ա�" << sex << endl;
	cout << "���䣺" << age << endl;
}
void People::regist()
{
	cout << "����������\t�Ա�\t����\t�˺�\t����" << endl;
	cin >> name >> sex >> age >> username >> password;
}
string People::getUser() { return username; }
string People::getPass() { return password; }
bool People::operator==(People& p)
{
	if (name==p.name && sex == p.sex && age == p.age)return true;
	else return false;
}
void Book::input()
{
	cout << "���������\t����\t����" << endl;
	cin >> code >> name >> author;
}
void Book::showInfo()
{
	cout << setw(10) << std::left<< code << setw(20) << std::left << name << setw(10) << std::left << author;
}
void writefile_book()
{
	ofstream f1("book.txt");
	if (f1.good())
	{
		for (int i = 0; i < b.size(); i++)
		{
			f1 << b[i]->data.code << "\t " << b[i]->data.name << "\t " << b[i]->data.author << "\t" << b[i]->data.state << "\t" << b[i]->data.owner << endl;
		}
	}
	f1.close();
}
void readfile_book()
{
	ifstream f1("book.txt");
	Book b1;
	if (f1.good())
	{
		while (f1 >> b1.code >> b1.name >> b1.author >> b1.state >> b1.owner)
		{
			b.push_back(b1);
		}
	}
	else
	{
		f1.close();
		cout << "error��" << endl;
		return;
	}
	f1.close();
	
}
string Book::getAuthor() { return author; }
string Book::getName() { return name; }
bool Book::getState() { return state; }
bool LibOperate::sign()
{
	string user, psword;

	cout << "�������˺ţ�";
	cin >> user;
	cout << "���������룺";
	cin >> psword;
	for (it = pb.begin(); it < pb.end(); it++)
	{
		if (user == (*it).getUser() && psword == (*it).getPass())
		{
			cout << "��¼�ɹ���" << endl;
			auth = authority::borrower;
			currPpl = *it;
			return true;
		}
		else
		{
			continue;
		}
	}
	for (it = pm.begin(); it < pm.end(); it++)
	{
		if (user == (*it).getUser() && psword == (*it).getPass())
		{
			cout << "��¼�ɹ���" << endl;
			auth = authority::manager;
			currPpl = *it;
			return true;
		}
		else
		{
			continue;
		}
	}
	cout << "�˺Ż������������������" << endl;
	return false;
}
void LibOperate::regist(authority a)
{
	People p1;
	p1.regist();
	if (a == authority::borrower)
	{
		for (it = pb.begin(); it < pb.end(); it++)
		{
			if (p1.username == (*it).username)
			{
				cout << "���û����Ѵ��ڣ�" << endl;
				return;
			}
		}
		pb.push_back(p1);
		writefile();
		cout << "ע��ɹ���" << endl;
	}
	else if (a == authority::manager)
	{
		for (it = pm.begin(); it < pm.end(); it++)
		{
			if (p1.username == (*it).username)
			{
				cout << "���û����Ѵ��ڣ�" << endl;
				return;
			}
		}
		pm.push_back(p1);
		writefile();
		cout << "ע��ɹ���" << endl;
	}
}
void LibOperate::add()
{
	Book b1;
	b1.input();
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i]->data.name == b1.name && b[i]->data.author == b1.author)
			{
				cout << "���鼮�Ѵ��ڣ�" << endl;
				return;
			}
	}
	b.push_back(b1);
	writefile_book();
	cout << "��ӳɹ���" << endl;
}
void LibOperate::exit()
{
	auth = authority::unlogin;
}
void  LibOperate::browse()
{
	cout << setw(10)<<std::left<<"����" << setw(20) << std::left << "����" << setw(10) << std::left << "����" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i]->data.getState() == true)
		{
			b[i]->data.showInfo();
			cout << endl;
		}
		else
		{
			b[i]->data.showInfo();
			cout << "(�ѱ�����)"<<endl;
		}
	}
}
void LibOperate::check()
{
	string str; bool flag = false;
	cout << "���������������߽��м�����" << endl;
	cin >> str;
	cout << "���\t����\t����" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		if (str == b[i]->data.getAuthor() || str == b[i]->data.getName())
		{
			if (b[i]->data.getState() == true)
			{
				b[i]->data.showInfo();
				cout << endl;
			}
			else
			{
				b[i]->data.showInfo();
				cout << "(�ѱ�����)" << endl;
			}
			flag = true;
		}
		else continue;
	}
	if(flag==false)cout << "������鼮��" << endl;
}
void LibOperate::borrow()
{
	string str; bool flag = false;
	cout << "������Ҫ���ĵ��鼮���ƣ�";
	cin >> str;
	for (int i = 0; i < b.size(); i++)
	{
		if (str == b[i]->data.getName())
		{
			if (b[i]->data.getState() == true)b[i]->data.showInfo();
			else
			{
				b[i]->data.showInfo();
				cout << "(�ѱ�����)";
				system("pause");
				return;
			}
			b[i]->data.state = false;
			b[i]->data.owner = currPpl.username;
			writefile_book();
			cout << "\t���ĳɹ���" << endl;
			flag = true;
		}
		else continue;
	}
	if (flag == false)cout << "������鼮��" << endl;
}
void LibOperate::send_back()
{
	string str;
	cout << "������Ҫ�黹���鼮���ƣ�";
	cin >> str;
	for (int i = 0; i < b.size(); i++)
	{
		if (str == b[i]->data.name&&b[i]->data.owner==currPpl.username)
		{
			b[i]->data.state = true;
			writefile_book();
			cout << "�黹�ɹ���" << endl;
			return;
		}
	}
	cout << "�޴�ͼ��!" << endl;
}
void LibOperate::info()
{
	cout << "������" << currPpl.name << endl;
	cout << "�Ա�" << currPpl.sex << endl;
	cout<< "���䣺" << currPpl.age << endl;
	cout << "���ڽ��ĵ��鼮��" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i]->data.owner == currPpl.username)
		{
			b[i]->data.showInfo(); 
			cout << endl;
			return;
		}
	}
	cout << "��" << endl;
}
void LibOperate::del()
{
	cout << "������Ҫɾ����ͼ�����ƣ�" << endl;
	string str;
	cin >> str;
	for (int i = 0; i < b.size(); i++)
	{
		if (str == b[i]->data.name)
		{
			/*if (b[i]->data.state == false)
			{
				cout << "�������ڱ����ģ�����ɾ��!" << endl;
				return;
			}*/
			b.erase(i);
			cout << "�����ɹ���" << endl;
			writefile_book();
			return;
		}
	}
	cout << "������鼮��" << endl;
}
void LibOperate::change()
{
	string str;
	cout << "���������������߽��м�����" << endl;
	cin >> str;
	cout << "���\t����\t����" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		if (str == b[i]->data.getName()||str==b[i]->data.getAuthor())
		{
			if (b[i]->data.getState() == true)
			{
				b[i]->data.showInfo();
				cout << endl;
				cout << "�������µı��\t����\t����"<< endl;
				Book b1;
				cin >> b1.code >> b1.name >> b1.author;
				b[i]->data = b1;
				writefile_book();
				cout << "�޸ĳɹ���" << endl;
				return;
			}
			else
			{
				b[i]->data.showInfo();
				cout << "(�ѱ�����)" << endl;
				cout << "�������µı��\t����\t����" << endl;
				Book b1;
				cin >> b1.code >> b1.name >> b1.author; b1.state = b[i]->data.state;
				b[i]->data = b1;
				writefile_book();
				cout << "�޸ĳɹ���" << endl;
				return;
			}
		}
		else continue;
	}
	cout << "������鼮��" << endl;

}
void LibOperate::del_all()
{
	cout << "���������棬ȷ��ɾ����(ȷ������1���˳�����0��" << endl;
	cout << "�����룺";
	bool flag;
	cin >> flag;
	if (flag == 1)
	{
		for (int i = b.size()-1; i >=0; i--)
		{
			b.erase(i);
		}
		writefile_book();
		cout << "�����ɹ�!" << endl;
	}
	else return;
}
void LibOperate::del_ppl()
{
	cout << "������Ҫɾ�����˻�����";
	string str;
	cin >> str;
	for (it = pb.begin(); it < pb.end(); it++)
	{
		if (str == (*it).username)
		{
			cout << "ɾ���ɹ���" << endl;
			pb.erase(it);
			writefile();
			return;
		}
	}
	for (it = pm.begin(); it < pm.end(); it++)
	{
		if (str == currPpl.username)
		{
			cout << "����ɾ���Լ���" << endl;
		}
		else
		{
			if (str == (*it).username)
			{
				cout << "ɾ���ɹ���" << endl;
				pm.erase(it);
				writefile();
				return;
			}
		}
	}
	cout << "�޴��˻���" << endl;
}