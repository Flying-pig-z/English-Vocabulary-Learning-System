#include"checkSystem.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
using namespace std;


//ͳ���ļ�������
int countlines() {
	fstream wordTxt;
	wordTxt.open("Ӣ��ʻ�.txt", ios::in);
	char buf[100];
	//����,ÿ��ȡһ��������һ
	int count=0;
	while (wordTxt.getline(buf, sizeof(buf))) {
		count++;
	}
	return count;
}
//���Ĺ���
void processOfCheck(char buf[100]) {
	char answer[100] = { 0 };
	char rightAnswer[100] = { 0 };
	int judge = 0;
	for (int i = 0; i <= 99; i++) {

		//.������������˼�����Կ�ʼ��ӡ
		if (buf[i] == '\0')
			break;
		if (judge == 1)
			printf("%c", buf[i]);
		if (buf[i] == ' ')
			judge = 1;
		if (judge == 0)
			rightAnswer[i] = buf[i];


	}
	printf("\n");
	printf("���������˼��Ӧ�ĵ���\n");
	scanf_s("%s", answer, 100);
	if (strcmp(answer, rightAnswer) == 0) {
		printf("�ش���ȷ��\n\n");
	}
	else {
		printf("�ش�����㻹��һ�λ���\n");
		scanf_s("%s", answer, 100);
		if (strcmp(answer, rightAnswer) == 0) {
			printf("�ش���ȷ��\n\n");
		}
		else {
			printf("�ش����,��ȷ����%s\n\n", rightAnswer);
		}
	}
}
void CheckSystem::checkWords() 
{
	//������������
	srand(time(0));
	//�ʵ�һ��������
	int lines = countlines();
	//�����鵥�ʵĸ���
	cout << "������Ҫ��鵥�ʵĸ���"<<endl;
	int num;
	cin >> num;
	
	//������д��
	fstream read;
	ofstream write;
	//ָ��������ļ�
	write.open("�ϴγ��ĵ���.txt", ios::out);
	

	//���num��
	for (int i = 1; i <= num; ) 
	{
		//���������
		int randnum = rand() % lines;
		//д�ļ�ÿ��ѭ�������´򿪣�����ÿһ�δ�ͷ��ʼ��
		read.open("Ӣ��ʻ�.txt", ios::in);
		
		for (int j = 1; j <= randnum; j++)
		{
			read.getline(buf, sizeof(buf));
			
		}
		//��������к��е��ʲ��ǿհ�
		if ((buf[0] >= 97 && buf[0] <= 122) || (buf[0] >= 65 && buf[0] <= 90))
		{
			i++;
			//��鵥�ʵĹ���
			processOfCheck(buf);
			//���浥�ʱ��ڸ�ϰ
			write << buf << endl;
			
		}
		read.close();
	}
	write.close();
	system("pause");

}

void CheckSystem::viewSpotCheck()
{
	ifstream read;
	read.open("�ϴγ��ĵ���.txt", ios::in);
	while (read.getline(this->buf, sizeof(this->buf)))
	{
		printf("%s\n", buf);
	}
	system("pause");
}
void CheckSystem::reviewSpotCheck()
{
	ifstream read;
	read.open("�ϴγ��ĵ���.txt", ios::in);
	char rightAnswer[100]={0};
	char answer[100]={0};
	while (read.getline(this->buf, sizeof(this->buf)))
	{
		int judge = 0;
		for (int i = 0; i <= 99; i++) 
		{

			//.������������˼�����Կ�ʼ��ӡ
			if (buf[i] == '\0')
				break;
			if (judge == 1)
				printf("%c", buf[i]);
			if (buf[i] == ' ')
				judge = 1;
			if (judge == 0)
				rightAnswer[i] = buf[i];
		}
		printf("\n");
		printf("���������˼��Ӧ�ĵ���\n");
		scanf_s("%s", answer, 100);
		if (strcmp(answer, rightAnswer) == 0) {
			printf("�ش���ȷ��\n\n");
		}
		else {
			printf("�ش�����㻹��һ�λ���\n");
			scanf_s("%s", answer, 100);
			if (strcmp(answer, rightAnswer) == 0) {
				printf("�ش���ȷ��\n\n");
			}
			else {
				printf("�ش����,��ȷ����%s\n\n", rightAnswer);
			}
		}

	}
	system("pause");
}