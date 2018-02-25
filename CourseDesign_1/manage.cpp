#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct message		//����ṹ��
{
	long id;	              //�����豸���
	char machine[10];	      //�����豸����
	char machine_type[20];	  //�����豸�ͺ�
	int buy_date[3];	      //�����豸��������
	float price;			  //�����豸����۸�
	char manager[20];		  //�����豸�豸����Ա
	char operation_type[10];  //�����豸״̬
	
};
struct message mac[100];      //����ṹ�����飬�洢�豸��Ϣ


void main_view();		      //��������ͼ����
void locatedata();			  //������λ����
void printf_hx();			  //�������ߴ�ӡ����


//�豸��Ϣ�鿴����
void view_f()
{
	FILE *fp;
	int i = 0;  //����ѭ������i
	if ((fp = fopen("machine_data.dat", "r")) == NULL)
	{
		printf("�ļ��ж�ȡʧ�ܡ�");
		exit(0);
	}
	while (!feof(fp))  //���ļ��а���ʽ��ȡ���ݴ洢���ṹ�����飬ֱ���ļ�β��
	{
		fscanf(fp, "%ld %s %s %d %d %d %f %s %s\n", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
		printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
		i++;
	}
	fclose(fp);
	printf("\n");
}
//�豸��Ϣ��Ӻ���
void add_f()
{
	FILE *fp;
	int i, n;  //����ѭ������i��¼���豸��n��
	
	if ((fp = fopen("machine_data.dat", "a")) == NULL)  //��׷�ӵ���ʽ���ļ�
	{
		printf("�ļ��ж�ȡʧ�ܡ�");
		exit(0);
	}
	printf("������¼���豸������\n");
	scanf("%d", &n);
	printf("�밴�����¸�ʽ������Ϣ(�Կո�ָ�����\n");
	printf("�豸��ţ�Ψһ) ,�豸���ͣ��ʼǱ���̨ʽ����ƽ����ԡ�ͶӰ�ǡ�ɨ���ǡ���ӡ���������������������豸�ͺţ��������ڣ��ꡢ�¡��գ�������۸񣬹���Ա���Լ��豸״̬�����á���ά�ޡ������ϣ�\n");
	for (i = 0; i<n; i++)  //ѭ��n�Σ���ȡ������豸��Ϣ����ṹ������
	{
		scanf("%ld %s %s %d %d %d %f %s %s", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
	}
	for (i = 0; i<n; i++)  //ѭ��n�Σ����ṹ��������Ϣ��׷�ӵ���ʽд���ļ�
	{
		fprintf(fp, "%ld %s %s %d %d %d %f %s %s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
		printf("����ɹ���\n");
	}
	fclose(fp);
}
//�豸��Ϣ��ѯ����
void ack_f()
{
	locatedata();
}
//�豸��Ϣ�޸ĺ���
void alter_f()
{
	FILE *fp;
	int i = 0;  //����ѭ������i
	int count_i;  //���ڴ洢ÿ�δ��ļ��ж�ȡ���豸��
	if ((fp = fopen("machine_data.dat", "r+")) == NULL)  //�Զ�д����ʽ���ļ�
	{
		printf("�ļ��ж�ȡʧ�ܡ�");
		exit(0);
	}
	while (!feof(fp))  //���ļ��а���ʽ��ȡ���ݴ洢���ṹ�����飬ֱ���ļ�β��
	{
		fscanf(fp, "%ld %s %s %d %d %d %f %s %s\n", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
		i++;
	}
	fclose(fp);
	count_i = i;  //�洢�豸��
	int flag_1 = 1;  //������ű����������ж��޸ĵ��豸����Ƿ����
	int id_alter;  //���ڴ洢Ҫ�޸ĵ��豸���

	if ((fp = fopen("machine_data.dat", "w")) == NULL) //��д����ʽ���ļ�
	{
		printf("�ļ��ж�ȡʧ�ܡ�");
		exit(0);
	}
	
	printf("������Ҫ�޸ĵ��豸��ţ�");
	scanf("%d", &id_alter);
	for (i = 0; i < 100; i++) {
		if (mac[i].id == id_alter) { 
			printf("�޸ĵ�ԭ��Ϣ���£�\n\n");
			printf("%d %7s %7s %4d-%d-%d %7.1f %7s %7s\n\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
			printf("�밴�����¸�ʽ������Ϣ(�Կո�ָ�����\n");
			printf("%d ,�豸���ͣ��ʼǱ���̨ʽ����ƽ����ԡ�ͶӰ�ǡ�ɨ���ǡ���ӡ���������������������豸�ͺţ��������ڣ��ꡢ�¡��գ�������۸񣬹���Ա���Լ��豸״̬�����á���ά�ޡ������ϣ�\n", mac[i].id);
			scanf("%ld %s %s %d %d %d %f %s %s", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
			for (int n = 0; n < count_i; n++) {
				fprintf(fp, "%ld %s %s %d %d %d %f %s %s\n", mac[n].id, mac[n].machine, mac[n].machine_type, mac[n].buy_date[0], mac[n].buy_date[1], mac[n].buy_date[2], mac[n].price, mac[n].manager, mac[n].operation_type);
				printf("%d % 12s % 7s % 4d - %d - %d   %-7.1f%-7s%-7s\n", mac[n].id, mac[n].machine, mac[n].machine_type, mac[n].buy_date[0], mac[n].buy_date[1], mac[n].buy_date[2], mac[n].price, mac[n].manager, mac[n].operation_type);
				printf("��%d����Ϣ����ɹ���\n", n+1);
			}
			flag_1 = 0;
		}
	}
	if (flag_1 == 1) {
		printf("�豸��Ų����ڣ�\n");
	}
	fclose(fp);
	
}
//�豸��Ϣͳ�ƺ���
void count_f()
{
	FILE *fp;
	int i = 0;
	if ((fp = fopen("machine_data.dat", "r")) == NULL)
	{
		printf("�ļ��ж�ȡʧ�ܡ�");
		exit(0);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%ld %s %s %d %d %d %f %s %s\n", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
		i++;
	}
	fclose(fp);
	int count_1 = 0;
	int count_2 = 0;
	
	for(i = 0; i < 100; i++) {
		if (mac[i].id != 0) {
			count_1++;
			count_2 += mac[i].price;
		}
	}
	printf("\nʵ�����豸������%d\n", count_1);
	printf("ʵ�����豸�ܼۣ�%d\n\n", count_2);
}
//ʵ���ҹ���ϵͳ��¼����
void signin_manage()
{
	char username[10] = "admin";//�����û�������
	char password[10] = "1234";//������������
	char u[10];
	char p[10];
	int flag = 0; int n = 3;//���������������
	do
	{
		printf("�������û���(Ĭ��admin����");
		scanf_s("%s", u, 10);
		getchar();
		printf("���������루��ʼ����1234����");
		//ʵ���������������
		int i = 0;
		for (i = 0; i < 10; i++) {
			p[i] = _getch();
			if (p[i] == '\r') {
				break;
			}
			printf("*");
		}
		p[i] = '\0'; printf("\n");
		if (!strcmp(u, username) && !strcmp(p, password)) {
			printf("��¼�ɹ���\n");
			flag = 1;
			break;
		}
		else
		{
			printf("��¼ʧ��\n");
			n--;
		}
	} while (n>0);
	if (flag) {
		printf("�����������...");
		getchar();
		system("cls");
	}
	else
		printf("�Բ���������Ĵ����ѵ����ټ���\n");
}
//ʵ���ҹ���ϵͳ�����ܺ���
void main_manage()
{
	int choice = 0;
	int flag = 1;
	int stop = 1;
	main_view();
	do
	{
		while (flag)
		{
			flag = 0;
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:view_f(); break;
			case 2:add_f(); break;
			case 3:ack_f(); break;
			case 4:alter_f(); break;
			case 5:count_f(); break;
			case 6:printf("лл����ʹ�ã��ټ���"); return;
			default:printf("��ȷ�������������ȷ�ı�ţ�\n"); printf("����������:"); flag = 1;
			}
		}
		printf("�Ƿ���������豸��<1/0>:");
		scanf("%d", &stop);
		if (stop == 1) {
			flag = 1;
			system("cls");
			printf("����������Ҫ�Ĳ�����ţ�");
		}
	} while (stop == 1);
}
//�豸��Ϣ��λ����
void locatedata()
{
	int select;
	long id_;
	char machine_[10];
	char machine_type_[20];
	int buy_date_[3];
	float price_;
	char manager_[20];
	char operation_type_[10];
	FILE *fp;
	int i = 0, m = 0;
	if ((fp = fopen("machine_data.dat", "r")) == NULL)
	{
		printf("�ļ��ж�ȡʧ�ܡ�");
		exit(0);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%ld %s %s %d %d %d %f %s %s\n", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
		i++;
	}
	fclose(fp);
	system("cls");
	printf_hx();
	printf("\t\t\t\t\t\t��ӭ����ʵ�����豸����ϵͳ��\n\n");
	printf_hx();
	printf("\t\t\t\t\t\t<1>���豸��Ų�ѯ\n\t\t\t\t\t\t<2>���豸���Ͳ�ѯ\n\t\t\t\t\t\t<3>���豸�ͺŲ�ѯ\n\t\t\t\t\t\t<4>���������ڲ�ѯ\n\t\t\t\t\t\t<5>������۸��ѯ\n\t\t\t\t\t\t<6>��������Ա��ѯ\n\t\t\t\t\t\t<7>���豸״̬��ѯ\n");
	printf("���������Ĳ�����ţ�");
	scanf("%d", &select);
	if(select == 1) {
		printf("������Ҫ��ѯ���豸���:");
		int flag_1 = 1; 
		int id_;
		scanf("%d", &id_);
		for (i = 0; i < 100; i++) {
			if (mac[i].id == id_) {
				printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
				flag_1 = 0;
				
			}
		}
		if (flag_1 == 1) {
			printf("�豸��Ų����ڣ�\n");
		}
		else
		{
			printf("����1����¼\n");
		}
	}
	if (select == 2) {
		printf("������Ҫ��ѯ���豸����:");
		int flag_1 = 1; int count = 0;
		char machine_[10];
		scanf("%s", machine_);
		for (i = 0; i < 100; i++) {
			if (!strcmp(mac[i].machine, machine_)) {
				printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
				flag_1 = 0;
				count++;
			}
		}
		if (flag_1 == 1) {
			printf("�豸���Ͳ����ڣ�\n");
		}
		else
		{
			printf("����%d����¼\n", count);
		}

		

	}
	if (select == 3) {
		printf("������Ҫ��ѯ���豸�ͺ�:");
		int flag_1 = 1; int count = 0;
		char machine_t[10];
		scanf("%s", machine_t);
		for (i = 0; i < 100; i++) {
			if (!strcmp(mac[i].machine_type, machine_t)) {
				printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
				flag_1 = 0;
				count++;
			}
		}
		if (flag_1 == 1) {
			printf("�豸�ͺŲ����ڣ�\n");
		}
		else
		{
			printf("����%d����¼\n", count);
		}
	}
	if (select == 4) {
		printf("������Ҫ��ѯ���豸���ڣ�����-��-�յ���ʽ������2018-1-2:");
		int flag_1 = 1; int count = 0;
		int year_, mouth_, day_;
		scanf("%d-%d-%d", &year_, &mouth_, &day_);
		for (i = 0; i < 100; i++) {
			if (mac[i].buy_date[0] == year_ && mac[i].buy_date[1] == mouth_ && mac[i].buy_date[2] == day_) {
				printf("%d %7s %7s %4d-%d-%d %7.1f %7s %7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
				flag_1 = 0;
				count++;
			}
		}
		if (flag_1 == 1) {
			printf("�豸���ڲ����ڣ�\n");
		}
		else
		{
			printf("����%d����¼\n", count);
		}
	}
	if (select == 5) {
		printf("������Ҫ��ѯ���豸�۸�:");
		int flag_1 = 1; int count = 0;
		int price_;
		scanf("%d", &price_);
		for (i = 0; i < 100; i++) {
			if (mac[i].price == price_) {
				printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
				flag_1 = 0;
				count++;
			}
		}
		if (flag_1 == 1) {
			printf("�豸�۸񲻴��ڣ�\n");
		}
		else
		{
			printf("����%d����¼\n", count);
		}
	}
	if (select == 6) {
		printf("������Ҫ��ѯ�Ĺ���Ա:");
		int flag_1 = 1; int count = 0;
		char machine_m[10];
		scanf("%s", machine_m);
		for (i = 0; i < 100; i++) {
			if (!strcmp(mac[i].manager, machine_m)) {
				printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
				flag_1 = 0;
				count++;
			}
		}
		if (flag_1 == 1) {
			printf("����Ա�����ڣ�\n");
		}
		else
		{
			printf("����%d����¼\n", count);
		}
	}
	if (select == 7) {
		printf("������Ҫ��ѯ���豸״̬:");
		int flag_1 = 1; int count = 0;
		char operation_t[10];
		scanf("%s", operation_t);
		for (i = 0; i < 100; i++) {
			if (!strcmp(mac[i].operation_type, operation_t)) {
				printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
				flag_1 = 0;
				count++;
			}
		}
		if (flag_1 == 1) {
			printf("�豸״̬�����ڣ�\n");
		}
		else
		{
			printf("����%d����¼\n", count);
		}
	}

}

