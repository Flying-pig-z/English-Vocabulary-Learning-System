#include<iostream>
#include<fstream>
#include"systemManagement.h"
using namespace std;
int countW()
{
	fstream wordTxt;
	wordTxt.open("Ӣ��ʻ�.txt", ios::in);
	char buf[100];
	//����,ÿ��ȡһ��������һ
	int count = 0;
	while (wordTxt.getline(buf, sizeof(buf))) {
		if ((buf[0] >= 97 && buf[0] <= 122) || (buf[0] >= 65 && buf[0] <= 90))
			count++;
	}
	return count;
}
//display interface
void systemManagement::displayInterface() {
	cout << "-------------------------------------------" << endl;
	cout << "          �ļ��ʻ��������ϵͳ              "<<endl;
	cout << "                 0.�˳�ϵͳ                 " << endl;
	cout << "               1.�ʻ����ϵͳ                 "<<endl;
	cout << "               2.�ʻ���ϵͳ                 "<<endl;
	cout << "-------------------------------------------" << endl;
	cout << "ps:�ܵĴʻ���" << countW() << "��" << endl;
};
void systemManagement::displayManageInterface() {
	cout << "-------------------------------------------" << endl;
	cout << "              0.�����ϼ�Ŀ¼                 " << endl;
	cout << "                1.��ӵ���                 " << endl;
	cout << "                2.ɾ������                 " << endl;
	cout << "                3.�޸ĵ���                 " << endl;
	cout << "                4.��ѯ����                 " << endl;
	cout << "-------------------------------------------" << endl;
}
void systemManagement::displayCheckInterface() {
	cout << "-------------------------------------------" << endl;
	cout << "              0.�����ϼ�Ŀ¼                 " << endl;
	cout << "              1.����µĵ���                 " << endl;
	cout << "              2.�鿴�ϴγ��                 " << endl;
	cout << "              3.��ϰ�ϴγ��                 " << endl;
	cout << "-------------------------------------------" << endl;
}