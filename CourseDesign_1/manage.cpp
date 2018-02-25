#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct message		//定义结构体
{
	long id;	              //定义设备编号
	char machine[10];	      //定义设备类型
	char machine_type[20];	  //定义设备型号
	int buy_date[3];	      //定义设备购买日期
	float price;			  //定义设备购买价格
	char manager[20];		  //定义设备设备管理员
	char operation_type[10];  //定义设备状态
	
};
struct message mac[100];      //定义结构体数组，存储设备信息


void main_view();		      //声明主视图函数
void locatedata();			  //声明定位函数
void printf_hx();			  //声明横线打印函数


//设备信息查看函数
void view_f()
{
	FILE *fp;
	int i = 0;  //定义循环变量i
	if ((fp = fopen("machine_data.dat", "r")) == NULL)
	{
		printf("文件夹读取失败。");
		exit(0);
	}
	while (!feof(fp))  //从文件中按格式读取数据存储到结构体数组，直到文件尾。
	{
		fscanf(fp, "%ld %s %s %d %d %d %f %s %s\n", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
		printf("%d%12s%7s  %4d-%d-%d   %-7.1f%-7s%-7s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
		i++;
	}
	fclose(fp);
	printf("\n");
}
//设备信息添加函数
void add_f()
{
	FILE *fp;
	int i, n;  //定义循环变量i、录入设备数n。
	
	if ((fp = fopen("machine_data.dat", "a")) == NULL)  //以追加的形式打开文件
	{
		printf("文件夹读取失败。");
		exit(0);
	}
	printf("请输入录入设备数量：\n");
	scanf("%d", &n);
	printf("请按照以下格式输入信息(以空格分隔）。\n");
	printf("设备编号（唯一) ,设备类型（笔记本、台式机、平板电脑、投影仪、扫描仪、打印机、照相机、摄像机），设备型号，购买日期（年、月、日），购入价格，管理员，以及设备状态（良好、需维修、待报废）\n");
	for (i = 0; i<n; i++)  //循环n次，读取输入的设备信息存入结构体数组
	{
		scanf("%ld %s %s %d %d %d %f %s %s", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
	}
	for (i = 0; i<n; i++)  //循环n次，将结构体数组信息以追加的形式写入文件
	{
		fprintf(fp, "%ld %s %s %d %d %d %f %s %s\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
		printf("保存成功！\n");
	}
	fclose(fp);
}
//设备信息查询函数
void ack_f()
{
	locatedata();
}
//设备信息修改函数
void alter_f()
{
	FILE *fp;
	int i = 0;  //定义循环变量i
	int count_i;  //用于存储每次从文件中读取的设备数
	if ((fp = fopen("machine_data.dat", "r+")) == NULL)  //以读写的形式打开文件
	{
		printf("文件夹读取失败。");
		exit(0);
	}
	while (!feof(fp))  //从文件中按格式读取数据存储到结构体数组，直到文件尾。
	{
		fscanf(fp, "%ld %s %s %d %d %d %f %s %s\n", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
		i++;
	}
	fclose(fp);
	count_i = i;  //存储设备数
	int flag_1 = 1;  //定义符号变量，用于判断修改的设备编号是否存在
	int id_alter;  //用于存储要修改的设备编号

	if ((fp = fopen("machine_data.dat", "w")) == NULL) //以写的形式打开文件
	{
		printf("文件夹读取失败。");
		exit(0);
	}
	
	printf("请输入要修改的设备编号：");
	scanf("%d", &id_alter);
	for (i = 0; i < 100; i++) {
		if (mac[i].id == id_alter) { 
			printf("修改的原信息如下：\n\n");
			printf("%d %7s %7s %4d-%d-%d %7.1f %7s %7s\n\n", mac[i].id, mac[i].machine, mac[i].machine_type, mac[i].buy_date[0], mac[i].buy_date[1], mac[i].buy_date[2], mac[i].price, mac[i].manager, mac[i].operation_type);
			printf("请按照以下格式输入信息(以空格分隔）。\n");
			printf("%d ,设备类型（笔记本、台式机、平板电脑、投影仪、扫描仪、打印机、照相机、摄像机），设备型号，购买日期（年、月、日），购入价格，管理员，以及设备状态（良好、需维修、待报废）\n", mac[i].id);
			scanf("%ld %s %s %d %d %d %f %s %s", &mac[i].id, mac[i].machine, mac[i].machine_type, &mac[i].buy_date[0], &mac[i].buy_date[1], &mac[i].buy_date[2], &mac[i].price, mac[i].manager, mac[i].operation_type);
			for (int n = 0; n < count_i; n++) {
				fprintf(fp, "%ld %s %s %d %d %d %f %s %s\n", mac[n].id, mac[n].machine, mac[n].machine_type, mac[n].buy_date[0], mac[n].buy_date[1], mac[n].buy_date[2], mac[n].price, mac[n].manager, mac[n].operation_type);
				printf("%d % 12s % 7s % 4d - %d - %d   %-7.1f%-7s%-7s\n", mac[n].id, mac[n].machine, mac[n].machine_type, mac[n].buy_date[0], mac[n].buy_date[1], mac[n].buy_date[2], mac[n].price, mac[n].manager, mac[n].operation_type);
				printf("第%d条信息保存成功！\n", n+1);
			}
			flag_1 = 0;
		}
	}
	if (flag_1 == 1) {
		printf("设备编号不存在！\n");
	}
	fclose(fp);
	
}
//设备信息统计函数
void count_f()
{
	FILE *fp;
	int i = 0;
	if ((fp = fopen("machine_data.dat", "r")) == NULL)
	{
		printf("文件夹读取失败。");
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
	printf("\n实验室设备总数：%d\n", count_1);
	printf("实验室设备总价：%d\n\n", count_2);
}
//实验室管理系统登录函数
void signin_manage()
{
	char username[10] = "admin";//定义用户名数组
	char password[10] = "1234";//定义密码数组
	char u[10];
	char p[10];
	int flag = 0; int n = 3;//定义密码重输次数
	do
	{
		printf("请输入用户名(默认admin）：");
		scanf_s("%s", u, 10);
		getchar();
		printf("请输入密码（初始密码1234）：");
		//实现密码的输入隐藏
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
			printf("登录成功！\n");
			flag = 1;
			break;
		}
		else
		{
			printf("登录失败\n");
			n--;
		}
	} while (n>0);
	if (flag) {
		printf("按任意键继续...");
		getchar();
		system("cls");
	}
	else
		printf("对不起，您输入的次数已到，再见！\n");
}
//实验室管理系统主功能函数
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
			case 6:printf("谢谢您的使用，再见！"); return;
			default:printf("请确认您输入的是正确的编号！\n"); printf("请重新输入:"); flag = 1;
			}
		}
		printf("是否继续管理设备：<1/0>:");
		scanf("%d", &stop);
		if (stop == 1) {
			flag = 1;
			system("cls");
			printf("请输入您想要的操作序号：");
		}
	} while (stop == 1);
}
//设备信息定位函数
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
		printf("文件夹读取失败。");
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
	printf("\t\t\t\t\t\t欢迎来到实验室设备管理系统！\n\n");
	printf_hx();
	printf("\t\t\t\t\t\t<1>按设备编号查询\n\t\t\t\t\t\t<2>按设备类型查询\n\t\t\t\t\t\t<3>按设备型号查询\n\t\t\t\t\t\t<4>按购买日期查询\n\t\t\t\t\t\t<5>按购入价格查询\n\t\t\t\t\t\t<6>按管理人员查询\n\t\t\t\t\t\t<7>按设备状态查询\n");
	printf("请输入您的操作编号：");
	scanf("%d", &select);
	if(select == 1) {
		printf("请输入要查询的设备编号:");
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
			printf("设备编号不存在！\n");
		}
		else
		{
			printf("共有1条记录\n");
		}
	}
	if (select == 2) {
		printf("请输入要查询的设备类型:");
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
			printf("设备类型不存在！\n");
		}
		else
		{
			printf("共有%d条记录\n", count);
		}

		

	}
	if (select == 3) {
		printf("请输入要查询的设备型号:");
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
			printf("设备型号不存在！\n");
		}
		else
		{
			printf("共有%d条记录\n", count);
		}
	}
	if (select == 4) {
		printf("请输入要查询的设备日期，以年-月-日的形式，例如2018-1-2:");
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
			printf("设备日期不存在！\n");
		}
		else
		{
			printf("共有%d条记录\n", count);
		}
	}
	if (select == 5) {
		printf("请输入要查询的设备价格:");
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
			printf("设备价格不存在！\n");
		}
		else
		{
			printf("共有%d条记录\n", count);
		}
	}
	if (select == 6) {
		printf("请输入要查询的管理员:");
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
			printf("管理员不存在！\n");
		}
		else
		{
			printf("共有%d条记录\n", count);
		}
	}
	if (select == 7) {
		printf("请输入要查询的设备状态:");
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
			printf("设备状态不存在！\n");
		}
		else
		{
			printf("共有%d条记录\n", count);
		}
	}

}

