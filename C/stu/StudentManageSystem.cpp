//ѧ���ɼ�����ϵͳ
//�������ԣ�C����
//�������ߣ�Visual Studio 2019
//����ʱ�䣺2019.4.14
//�����ߣ�summer

#include "StudentManageSystem.h"

/*
<> ֱ�Ӵ�ϵͳĿ¼�²��Ұ�������ļ�
"" �ȴӹ��̵���ĿĿ¼�²�����������û�У��ٵ�ϵͳĿ¼�²���
*/

int main() {
	while (1)
	{
		//��ӡ�˵�
		Menu();
		//��ȡһ���ַ� ����,�ַ����ڴ���ӳ��ΪASCII��
		char ch = _getch();

		switch (ch)
		{
		case '1'://1.¼��ѧ����Ϣ
			InputStudent();
			break;
		case '2'://2.��ӡѧ����Ϣ
			PrintStudent();
			break;
		case '3'://3.����ѧ����Ϣ
			SaveStudent();
			break;
		case '4'://4.��ȡѧ����Ϣ
			ReadStudent();
			break;
		case '5'://5.ͳ������ѧ������
			CountStudent();
			break;
		case '6'://6.����ѧ����Ϣ
			FindStudent();
			break;
		case '7'://7.�޸�ѧ����Ϣ
			ChangeStudent();
			break;
		case '8'://8.ɾ��ѧ����Ϣ
			DeleteStudent();
			break;
		case '0'://0.�˳�ϵͳ
			return 0;
			break;
		default:
			printf("��������û�иù���\n\n");
			system("pause");  //��ͣ
			system("cls");    //����
			break;
		}
	}

	return 0;
}

//�˵�
void Menu() {
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t*\n");
	printf("*\t\t��ѡ����\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.��ȡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.ͳ������ѧ������\t\t*\n");
	printf("*\t\t6.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t7.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t8.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("*************************************************\n");
}

//1.¼��ѧ����Ϣ
void InputStudent() {
	//����һ���ˣ��ڶ��з����ڴ�
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	//ָ����һ��ָ���
	pNewNode->pNext = NULL;

	//���������β���
	Node* p = g_pHead;
	while (g_pHead != NULL && p->pNext != NULL)
	{
		p = p->pNext;
	}

	//�ѽڵ�嵽�����β�ڵ�
	if (g_pHead == NULL) {
		g_pHead = pNewNode;
	}
	else {
		p->pNext = pNewNode;
	}

	//¼��ѧ����Ϣ
	printf("������ѧ��������\n");
	scanf_s("%s", pNewNode->stu.szName, sizeof(pNewNode->stu.szName));
	printf("�������Ա�\n");
	scanf_s("%s", pNewNode->stu.szSex, sizeof(pNewNode->stu.szSex));
	printf("������ѧ�����䣺\n");
	scanf_s("%d", &pNewNode->stu.nAge);
	printf("������ѧ�ţ�\n");
	scanf_s("%d", &pNewNode->stu.nStuNo);
	printf("������ɼ���\n");
	scanf_s("%d", &pNewNode->stu.nScore);

	printf("ѧ����Ϣ¼��ɹ���\n\n");
	system("pause");
	system("cls");
}

//2.��ӡѧ����Ϣ
void PrintStudent() {

	system("cls");
	//��������
	Node* p = g_pHead;
	if (p == NULL) {
		printf("ϵͳ������ѧ����Ϣ����¼���������ӡ�鿴��\n\n");
	}
	else {
		printf("*********************************************************************************\n");
		printf("*\t\t\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t\t\t*\n");
		printf("*********************************************************************************\n");
		printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
		printf("*********************************************************************************\n");

		while (p != NULL)
		{
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore
			);

			//��һ���ڵ�
			p = p->pNext;
			printf("*********************************************************************************\n");
		}
	}

	system("pause");
	system("cls");
}

//3.����ѧ����Ϣ
void SaveStudent() {
	//���ļ�
	FILE* pFile;
	pFile = fopen(".\\stuinfo.dat", "w");
	
	if (pFile == NULL) {
		printf("���ļ�ʧ�ܡ�\n");
		return;
	}

	//д������
	Node* p = g_pHead;
	while (p != NULL)
	{
		//fwrite(&p->stu, sizeof(Node), 1, pFile);
		fprintf(pFile,"*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
			p->stu.nStuNo,
			p->stu.szName,
			p->stu.szSex,
			p->stu.nAge,
			p->stu.nScore);
		p = p->pNext;
	}
	//�ر��ļ�
	fclose(pFile);

	printf("���ݱ���ɹ���\n");
	system("pause");
	system("cls");
}

//4.��ȡѧ����Ϣ
void ReadStudent() {
	system("cls");

	//���ļ�
	FILE* pFile;
	pFile = fopen(".\\stuinfo.dat", "r");

	if (pFile == NULL) {
		printf("���ļ�ʧ�ܡ�\n");
		return;
	}
	
	//����һ���ˣ��ڶ��з����ڴ�
	Node* p = (Node*)malloc(sizeof(Node));
	p->pNext = NULL;
	//���½�������
	g_pHead = p;

	//������ʶ����ı�����
	char str[200];
	int i = 0;
	while (fscanf(pFile, "%s", str) != EOF) {  //���ļ� 
		//���ʲ���*���߿�ʱ�����и�ֵ
		if (strcmp(str, "*") && str != NULL) {
			switch (i)
			{
			case 0:
				p->stu.nStuNo = atoi(str);
				break;
			case 1:
				strcpy(p->stu.szName, str);
				break;
			case 2:
				strcpy(p->stu.szSex, str);
				break;
			case 3:
				p->stu.nAge = atoi(str);
				break;
			case 4:
				p->stu.nScore = atoi(str);
				break;
			default:
				Node* pNewNode = (Node*)malloc(sizeof(Node));
				pNewNode->pNext = NULL;
				p->pNext = pNewNode;
				p = pNewNode;
				p->stu.nStuNo = atoi(str);
				i = 0;
				break;
			}
			i++;
		}
	}
	//��ӡ��ȡ���
	PrintStudent();
}

//5.ͳ������ѧ������
void CountStudent() {
	int countStu = 0;

	//��������
	Node* p = g_pHead;
	while (p != NULL)
	{
		countStu++;
		p = p->pNext;
	}
	printf("ѧ����������%d\n\n", countStu);

	system("pause");
	system("cls");
}

//6.����ѧ����Ϣ
void FindStudent() {
	system("cls");
	//��ѧ��Ϊ����ʾ����������Ϣ�������̻�������
	int stuNum;
	printf("���������ѧ��ѧ�ţ�");
	scanf("%d", &stuNum);
	//����������ң����ҵ��������Ϣ��ʾ
	Node* p = g_pHead;
	//�Ա�ͷ����չʾһ��
	bool isShowHead = false;
	//��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.nStuNo) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore
			);
			isFindStu = true;
			printf("*********************************************************************************\n");
		}
		p = p->pNext;
	}

	if (!isFindStu) {
		printf("ѧ����������ϵͳ�����޸�ѧ����Ϣ��\n\n");
	}

	system("pause");
	system("cls");
}

//7.�޸�ѧ����Ϣ
void ChangeStudent() {
	//��ѧ��Ϊ����ʾ����������Ϣ�������̻�������
	int stuNum;
	printf("���������޸�ѧ����ѧ�ţ�");
	scanf("%d", &stuNum);
	//����������ң����ҵ��������Ϣ��ʾ
	Node* p = g_pHead;
	//�Ա�ͷ����չʾһ��
	bool isShowHead = false;
	//��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.nStuNo) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore
			);
			//�޸�ѧ����Ϣ
			printf("������ѧ��������\n");
			scanf_s("%s", p->stu.szName, sizeof(p->stu.szName));
			printf("�������Ա�\n");
			scanf_s("%s", p->stu.szSex, sizeof(p->stu.szSex));
			printf("������ѧ�����䣺\n");
			scanf_s("%d", &p->stu.nAge);
			printf("������ѧ�ţ�\n");
			scanf_s("%d", &p->stu.nStuNo);
			printf("������ɼ���\n");
			scanf_s("%d", &p->stu.nScore);
			isFindStu = true;
			printf("*********************************************************************************\n");
			printf("ѧ����Ϣ�޸ĳɹ�����ע�⼰ʱ���档\n\n");
		}
		p = p->pNext;
	}

	if (!isFindStu) {
		printf("ѧ����������ϵͳ�����޸�ѧ����Ϣ���޷������޸ġ�\n\n");
	}

	system("pause");
	system("cls");
}

//8.ɾ��ѧ����Ϣ
void DeleteStudent() {
	system("cls");
	//��ѧ��Ϊ����ʾ����������Ϣ�������̻�������
	int stuNum;
	printf("������ɾ��ѧ����ѧ�ţ�");
	scanf("%d", &stuNum);
	//����������ң����ҵ��������Ϣ��ʾ
	Node* p = g_pHead;
	//��¼ǰһ���ڵ㣬ɾ��ʱ�������
	Node* beforeNode = g_pHead;

	//�Ա�ͷ����չʾһ��
	bool isShowHead = false;
	//��¼�Ƿ����ҵ���ѧ�ŵ�ѧ����Ϣ
	bool isFindStu = false;
	while (p != NULL)
	{
		if (stuNum == p->stu.nStuNo) {
			if (!isShowHead) {
				printf("*********************************************************************************\n");
				printf("*\tѧ��\t*\t����\t*\t�Ա�\t*\t����\t*\t�ɼ�\t*\n");
				printf("*********************************************************************************\n");
				isShowHead = true;
			}
			printf("*\t%d\t*\t%s\t*\t%s\t*\t%d\t*\t%d\t*\n",
				p->stu.nStuNo,
				p->stu.szName,
				p->stu.szSex,
				p->stu.nAge,
				p->stu.nScore
			);
			isFindStu = true;
			printf("*********************************************************************************\n");

			//ɾ���ڵ�Ϊͷ�ڵ�
			if (p == g_pHead) {
				g_pHead = p->pNext;
			}
			//ɾ���ڵ�Ϊβ�ڵ�
			else if (p->pNext == NULL) {
				p = beforeNode;
				p->pNext = NULL;
			}
			//ɾ���ڵ�Ϊ�м�ڵ�
			else {
				beforeNode->pNext = p->pNext;
			}
			printf("ɾ���ɹ�����ǵñ��档\n\n");
		}
		beforeNode = p;
		p = p->pNext;
	}

	if (!isFindStu) {
		printf("ѧ����������ϵͳ�����޸�ѧ����Ϣ���޷�����ɾ��������\n\n");
	}

	system("pause");
	system("cls");
}