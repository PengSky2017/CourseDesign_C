#include <stdio.h>

void signin_manage();  //������¼���ܺ���
//������ߴ�ӡ����
void printf_hx()
{
	for (int i = 0; i < 120; i++) {
		printf("-");
	}
	printf("\n");
}
//�����¼��ͼ����
void signin_view()
{
	//��ӡ��ӭ����
	printf_hx();
	printf("\t\t\t\t\t\t��ӭ����ʵ�����豸����ϵͳ��\n\n");
	printf_hx();
	//�˺������½
	signin_manage();

	
}
//��������ͼ����
void main_view()
{
	printf_hx();
	printf("\t\t\t\t\t\t��ӭ����ʵ�����豸����ϵͳ��\n\n");
	printf_hx();
	printf("\t\t\t\t\t\tѡ�����Ĳ���\n\n");
	printf("\t\t\t\t\t\t<1>�鿴�豸\n");
	printf("\t\t\t\t\t\t<2>¼���豸\n");
	printf("\t\t\t\t\t\t<3>��ѯ�豸\n");
	printf("\t\t\t\t\t\t<4>�޸��豸\n");
	printf("\t\t\t\t\t\t<5>ͳ���豸\n");
	printf("\t\t\t\t\t\t<6>�˳�ϵͳ\n");
	printf("����������Ҫ�Ĳ�����ţ�");
}