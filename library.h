#pragma once
#include<iostream>
#include<fstream>
using namespace std;
enum class authority{borrower,manager,unlogin};//Ȩ��
//��Ա��
class People
{
public:
	friend class LibOperate;
	People(string n="С��", string s="��", int a=18) :name(n), sex(s), age(a) {}//���캯��
	bool operator==(People& p);
	void regist();//ע����Ϣ����
	void showInfo();//��Ϣ��ʾ
	string getUser();//�����û���
	string getPass();//��������
	friend void writefile();//д����Ա��Ϣ�ļ�
	friend void readfile();//��ȡ��Ա��Ϣ�ļ�
private:
	string name;//����
	string sex;//�Ա�
	int age;//����
	string username;//�û���
	string password;//����
};
//����
class Book
{
public:
	friend class LibOperate;
	Book(string o="NULL",string c="0000",string n="��",string a="��",bool s = true) :code(c),name(n),author(a),state(s) ,owner(o){}
	void input();//�����鼮����
	void showInfo();//��ʾ�鼮����
	friend void writefile_book();//д���鼮��Ϣ
	friend void readfile_book();//��ȡ�鼮��Ϣ
	string getName();//��������
	string getAuthor();//��������
	bool getState();//���ؽ���״̬
private:
	string code;//����
	string name;//����
	string author;//����
	bool state;//״̬�����߻�δ���ģ�
	string owner;//�鼮ӵ����
};
//ͼ��ݲ�����
class LibOperate
{
public:
	//�ຯ��
	authority getAuthority() { return auth; }//����Ȩ��
	LibOperate(authority a = authority::unlogin) :auth(a) {}//���캯��
	//��ͨ�û�����Ȩ��
	void regist(authority a);//�û�ע��
	bool sign();//�û���¼
	void exit();//�˳���¼
	void browse();//�������ͼ��
	void check();//��ѯͼ��
	void borrow();//����
	void send_back();//����
	void info();//��Ա��Ϣ
	//����ԱȨ��
	void add();//����鼮
	void del();//ɾ��ͼ��
	void change();//�޸�ͼ������
	void del_all();//ɾ������ͼ��
	void del_ppl();//ɾ����Ա��Ϣ
private:
	authority auth;//ͼ���Ȩ��
};
void readfile();
void writefile();
void readfile_book();
void writefile_book();