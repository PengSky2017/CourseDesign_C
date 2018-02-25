#include <stdio.h>

void signin_manage();  //声明登录功能函数
//定义横线打印函数
void printf_hx()
{
	for (int i = 0; i < 120; i++) {
		printf("-");
	}
	printf("\n");
}
//定义登录视图函数
void signin_view()
{
	//打印欢迎界面
	printf_hx();
	printf("\t\t\t\t\t\t欢迎来到实验室设备管理系统！\n\n");
	printf_hx();
	//账号密码登陆
	signin_manage();

	
}
//定义主视图函数
void main_view()
{
	printf_hx();
	printf("\t\t\t\t\t\t欢迎进入实验室设备管理系统！\n\n");
	printf_hx();
	printf("\t\t\t\t\t\t选择您的操作\n\n");
	printf("\t\t\t\t\t\t<1>查看设备\n");
	printf("\t\t\t\t\t\t<2>录入设备\n");
	printf("\t\t\t\t\t\t<3>查询设备\n");
	printf("\t\t\t\t\t\t<4>修改设备\n");
	printf("\t\t\t\t\t\t<5>统计设备\n");
	printf("\t\t\t\t\t\t<6>退出系统\n");
	printf("请输入您想要的操作序号：");
}