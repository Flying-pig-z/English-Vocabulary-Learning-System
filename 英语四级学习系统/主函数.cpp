#include<iostream>
#include"systemManagement.h"
#include"wordManagement.h"
#include"CheckSystem.h"
using namespace std;
//bug:���������ܳ���������֣�����ᷢ����ѭ��������������
void manage() {
	systemManagement systemmanagement;
	WordManagement wordmanagement;
	
	for (;;)
	{
		system("cls");
		systemmanagement.displayManageInterface();
		int judge1=0;
		cin >> judge1;
		switch (judge1)
		{
		case 0:
			break;
			//��1���е������
		case 1:
			wordmanagement.add();
			break;
			//��2���е���ɾ��
		case 2:
			wordmanagement.deleteW();
			break;
			//��3���е����޸�
		case 3:
			wordmanagement.modify();
			break;
			//��4���е��ʲ�ѯ
		case 4:
			wordmanagement.find();
			break;
		default:
			cout << "����ˣ���������һ��\n" << endl;
			system("pause");
			continue;
		}
		if(judge1==0)
			break;
	}
	system("cls");
	systemmanagement.displayInterface();
}
void check() {
	CheckSystem checksystem;
	systemManagement systemmanagement;
	for (;;)
	{
		
		system("cls");
		systemmanagement.displayCheckInterface();
		int judge2;
		cin >> judge2;
		switch (judge2)
		{
		case 0:
			break;
		case 1:
			checksystem.checkWords();
			break;
		case 2:
			checksystem.viewSpotCheck();
			break;
		case 3:
			checksystem.reviewSpotCheck();
			break;
		default:
			cout << "����ˣ���������һ��\n" << endl;
			system("pause");
			continue;
		}
		if (judge2 == 0)
			break;

	}

	system("cls");
	systemmanagement.displayInterface();
}
int main()
{
	int judge = 0;
	systemManagement systemmanagement;
	//��ʾ����
	systemmanagement.displayInterface();
	for (;;) {
		cin>>judge;
		//��������
		switch (judge)
		{
		//��0�˳�
		case 0:
			break;
		//��1�������ϵͳ
		case 1:
			manage();
			break;
		//��2������ϵͳ
		case 2:
			check();
			break;
		default:
			cout << "����ˣ�������һ��\n" << endl;
			system("pause");
		}
		if (judge == 0)
			break;
	}
}