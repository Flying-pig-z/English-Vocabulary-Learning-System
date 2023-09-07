#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
#include <windows.h>
#include"wordManagement.h"
#include"systemManagement.h"
using namespace std;

//�ж������Ƿ���ȷ
int judgeInput(char* word)
{
	//���ǰ�浥�ʲ���Ӣ�ĵ��ʴ���
	if (word[0] < 97 || word[0]>122)
		return 0;
	else 
	{
		//���û�д���
		int count = 0;
		for (int i = 0; i <= 99; i++)
		{
			if (word[i] == '.')
				count++;
		}
		if (count == 1)
			return 1;
		else 
			return 0;
	}
}

//�ж�����ĵ����Ƿ����ļ���ȡ������������һ����ͬ����ͬ����1,��ͬ����0
int compareInputAndBuf(char* buf, char* word)
{
	int localJudgement = 1;//������ֲ�ƥ�䣬��˱�����Ϊ0

	for (int i = 0; i <= 99; i++)
	{
		//������ֶ�ȡ��ϣ���������
		if (buf[i] == ' ' && word[i] == 0)
			break;
		else
		{
			//�����������һ��Ӣ���ַ���ͬ���������������ı�localJudgement��ֵ
			if (buf[i] != word[i])
			{
				localJudgement = 0;
				break;
			}
		}

	}
	if (buf[0] == 0 || buf[0] == ' ')//ȷ����һ�п�ͷ����Ӣ��
		localJudgement = 0;
	return localJudgement;
}


//�жϵ����Ƿ���ڵĺ��������ڷ������ڵ������������ڷ���0
int wordExit(char* word)
{

	char buf[100] = { 0 };
	int count=0;
	//�ļ�������
	ifstream ifs;
	ifs.open("Ӣ��ʻ�.txt", ios::in);
	//һ��һ�ж�ȡ�����ж�
	while (ifs.getline(buf, sizeof(buf)))
	{
		int localJudgement = 0;
		count++;
		//�Ƚ϶�ȡ������ĵ��ʣ���ͬ��������
		if (compareInputAndBuf( buf, word) == 1)
		{
			ifs.close();
			return count;
		}

	}
	//�Ҳ�����ͬ����0
	ifs.close();
	return 0;
}





/*

add module


*/


//instructions for how to add words
void addInstructions() {
	
	cout << "��������Ҫ��ӵĵ���" << endl;
	cout << "ע�����";
	cout << "�����水�ո�ʽ���룬��Ȼ�ᵼ�³�鹦�ܳ���" << endl;
	cout << "����" << endl;
	cout << "able adj.�������ģ���ɫ��" << endl;
}
//the function of add words
void addword() 
{
	//����Ҫ��ӵĵ���
	char a[500] = { 0,0 };
	for (int i = 0; i <= 499; i++)
	{
		scanf_s("%c", &a[i], 1);
		if (a[i] == '\n')
			break;
	}
	//���ļ�������
	ofstream ofs;
	ofs.open("Ӣ��ʻ�.txt", ios::app);
	//�ж����뵥�ʸ�ʽ�Ƿ���ȷ����ȷ�򽫸õ��������ĵ������󷢳����Ѳ�����
	if(judgeInput(a))
		ofs << a;
	else
	{
		printf("�����ʽ����\n");
		Sleep(500);
	}
	//�ر��ļ�������
	ofs.close();
}
//Judge whether to exit or continue
void exitOrContinue(int &j) {
	cout << "���������밴1,�˳���0��" << endl;
	cin >> j;
	for (;;)
	{
		if (j != 0 && j != 1)
		{
			cout << "�����������������" << endl;
			cin >> j;
		}
		else
			break;
	}
}
void WordManagement::add() {
	for (;;)
	{
		system("cls");
		systemmanagement.displayManageInterface();
		getchar();
		//instructions for how to add words
		addInstructions();
		//the function of add words
		addword();
		//judge whether exit or continue
		int j;
		exitOrContinue(j);
		if (j == 0)
			break;
	}
}


/*

delete module


*/
//���ļ�������ȫ��ɾ���ĺ���
void allDelete() 
{
	ofstream ofs;
	//ios::trunc----����ɾ���ļ��ٴ���
	ofs.open("Ӣ��ʻ�.txt", ios::trunc);
	ofs << "";
	ofs.close();
	cout << "�Ѿ�ȫɾ";
}

//ȷ���Ƿ�ȫɾ
void ask()
{
	cout << "��ȷ��Ҫȫɾ�����������𣿣���" << endl;
	cout << "����0ȡ��ȫɾ������1ȫɾ" << endl;
}


void WordManagement::deleteW() {
	for (;;)
	{
		//ˢ�½���
		system("cls");
		systemmanagement.displayManageInterface();
		//ѡ�����
		cout << "��ѡ��ģʽ��" << endl
			<< "0.����" << endl
			<< "1.���ȫ�������ã�������������" << endl
			<< "2.�����������" << endl;


		int localJudge1=0;//����ѡ���¼�ڱ�����
		cin >> localJudge1;


		//ȫɾ������������� 
		if (localJudge1 == 1) //ȫɾ
		{
			
			ask();
			int judge2;
			cin >> judge2;
			if (judge2 == 0)
				break;
			else 
			{
				ask();
				cin >> judge2;
				if (judge2 == 0)
					break;
				else 
				{
					allDelete();
				}
			}
		}
		else if (localJudge1 == 2)
		{
			//���뵥��
			cout << "��������Ҫ����ĵ���\n";
			char word[100] = { 0 };
			scanf_s("%s", word, 100);
			//���ʲ�����
			if (wordExit(word) == 0)
			{
				cout << "���ʲ�����" << endl << "���ڷ����ϼ�Ŀ¼" << endl;
				Sleep(1000);
				break;
			}
			//���ʴ���
			else
			{
				printf("���ʴ���,����ɾ��\n");
				//ԭ���������ļ����Ƚ��ʻ���г��Ǹ��������������ƶ����м��ļ�
				//�ٽ��м�����д��ʻ��
				fstream wordTxt;
				fstream mTxt;


				//��һ��������Ƿ����Ǹ����ʣ�������ǽ������ƶ�������һ���ļ�
				wordTxt.open("Ӣ��ʻ�.txt", ios::in);
				mTxt.open("�м��ļ�.txt", ios::out);
				char buf[100];
				while (wordTxt.getline(buf, sizeof(buf)))
				{
					
						if (compareInputAndBuf(buf, word) ==0)
						{
							//������뵥�����ȡ�����е��ʲ�ͬ�����ƶ����м��ļ�
							mTxt << buf << endl;
						}
						
				}
				wordTxt.close();
				mTxt.close();


				//�ٽ��м�����д��ʻ��
				wordTxt.open("Ӣ��ʻ�.txt", ios::out);
				mTxt.open("�м��ļ�.txt", ios::in);
				while (mTxt.getline(buf, sizeof(buf)))
				{
					wordTxt << buf << endl;
				}


				//��������˳�
				system("cls");
				printf("ɾ���ɹ�");
				Sleep(1000);
				break;
			}

		}
		else if (localJudge1 == 0)
			break;
		else {
			printf("�������,���ڷ��ء�");
			Sleep(500);
			break;
		}
	}
}




/*

modify module


*/

//��ӡ���ʣ����ѵ��������������ظ�count,���ʴ��ڷ���1�������ڷ���0
int printWord(char* word, int& count)
{
	//��ʼѰ��
	//�ļ����ݶ�ȡ��buf
	char buf[100] = { 0 };
	//�����ļ�������
	fstream read;
	read.open("Ӣ��ʻ�.txt", ios::in);
	if (wordExit(word) == 0)//���ʲ�����
	{
		printf("���ʲ�����,���ڷ���");
		Sleep(500);
		return wordExit(word);
	}
	else//���ʴ���
	{
		
			//һ��һ�ж���Ȼ����бȽ�
			while (read.getline(buf, sizeof(buf)))
			{
				count++;//����˵�������һ��
				//���������ͬ�ĵ��ʣ�����д�ӡ
				if (compareInputAndBuf(buf,word)==1)
				{
						
					printf("%s\n", buf);
					read.close();
					break;
				}
			

			}
			return wordExit(word);
	}
}
//�޸ĵ���
void modifyWord(char *word,int count)
{
	int count1=0;
	fstream read;
	fstream write;
	read.open("Ӣ��ʻ�.txt",ios::in);
	write.open("�м�ʻ�.txt", ios::out);
	char buf[100];
	while (read.getline(buf, sizeof(buf)))
	{
		count1++;
		if (count1 == count)
		{
			write << word << endl;
		}
		else
		{
			write << buf << endl;
		}

	}
	read.close();
	write.close();
	read.open("�м�ʻ�.txt", ios::in);
	write.open("Ӣ��ʻ�.txt", ios::out);
	while (read.getline(buf, sizeof(buf)))
	{
		write << buf << endl;
	}
	read.close();
	write.close();

}
void WordManagement::modify() {
	//ˢ�½���
	system("cls");
	systemmanagement.displayManageInterface();
	//������Ҫ�޸ĵĵ���
	cout << "��������Ҫ�޸ĵĵ���:\n";
	char word[100]={0};
	scanf_s("%s", word, 100);


	int count=0;//���������һ��
	int exit = 1;//�Ƿ����

	//��ӡ���ʣ����ѵ��������������ظ�count,���ʴ��ڷ���1�������ڷ���0
	if (printWord(word, count)) 
	{
		
		//�����µĵ���
		printf("�������㵥���޸ĺ����ʽ:\n");
		char newword[100]={0};
		getchar();


		for (int i = 0; i <= 99; i++)
		{
			scanf_s("%c", &newword[i]);
			if (newword[i] == '\n')
				break;
		}


		if (judgeInput(newword))//������뵥�ʸ�ʽ��ȷ
			//�޸ĵ���
			modifyWord(newword, count);
		else//������뵥�ʸ�ʽ����
		{
			printf("���ʸ�ʽ����,�޸�ʧ��\n�밴�գ�\naboard adv.�ڴ�(��)�ϣ��ϴ�\n�˸�ʽ�����޸�\n");
			system("pause");
		}

		
	}
	

}




/*

find module


*/


void findWord(char* word)
{

	//��ʼѰ��
	//�ļ����ݶ�ȡ��buf
	char buf[100] = { 0 };
	//�����ļ�������
	fstream read;
	read.open("Ӣ��ʻ�.txt", ios::in);
	if (wordExit(word) == 0)//���ʲ�����
	{
		printf("���ʲ�����\n");
		Sleep(200);
	}
	else//���ʴ���
	{

		//һ��һ�ж���Ȼ����бȽ�
		while (read.getline(buf, sizeof(buf)))
		{
			
				//�������ƥ�䣬����д�ӡ
				if (compareInputAndBuf(buf, word)==1)
				{
					read.close();
					printf("%s\n", buf);
					break;
				}
			}
		}
}

void WordManagement::find()
{
	int judge = 1;
	while(judge)
	{
		//ˢ�½���
		system("cls");
		systemmanagement.displayManageInterface();
		//����ҪѰ�ҵĵ���
		printf("��������ҪѰ�ҵĵ���\n");
		char word[100] = { 0 };
		scanf_s("%s", word, 100);
		//Ѱ�Ҳ����û�����
		findWord(word);
		//�ж�Ҫ������ѯ����Ҫ�˳�
		printf("����1����������0�˳�\n");
		cin >> judge;
	}
	printf("�����˳�\n");
	Sleep(500);

}
