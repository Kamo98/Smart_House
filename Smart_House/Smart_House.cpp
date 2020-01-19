#include <locale.h>
#include <string>
#include "Device.h"
#include "ProxyDevice.h"
#include "RealDevice.h"
#include "Sensor.h"
#include "Thermometer.h"
#include "HumidityMeter.h"
#include "Rule.h"
#include "Air�onditioning.h"
#include "RuleLogger.h"
#include "SmartLampAdapter.h"



//������������ ������
void test_proxy() {
	ProxyDevice *prox1 = new ProxyDevice(), *prox2 = new ProxyDevice();
	RealDevice *app1 = new RealDevice("������ 1"), *app2 = new RealDevice("������ 2"), *app3 = new RealDevice("������ 3");
	prox1->init_device(app1);

	const int N = 3;
	IDevice* apps[N] = { prox1, prox2, app3 };

	for (int i = 0; i < N; i++) {
		printf("������ %d: ", i + 1);
		apps[i]->get_status();
		printf("\n");
	}

	printf("\n\n");

	//������������� ������������ ��������
	app1->turn_on();	//���
	app2->block();		//������.
	prox1->init_device(app1);
	prox2->init_device(app2);

	for (int i = 0; i < N; i++) {
		printf("������ %d: ", i + 1);
		apps[i]->get_status();
		printf("\n");
	}
}


//������������ �������������
void test_delegate() {
	//������� �������
	Thermometer *term1 = new Thermometer(20);
	HumidityMeter *humid1 = new HumidityMeter(30);



	//����� ��������� ����������� ��������
	printf("����������� �� ������� = %d C\n", term1->get_value());
	printf("��������� ������� �� ������� = %d %\n", humid1->get_value());

	Air�onditioning *cond = new Air�onditioning("�����������", 20);
	
	Command *comm = new Command(cond, "������ ��������");

	Rule* rule = new Rule(term1, comm, 25);

	RuleLogger *logger = new RuleLogger("log.txt");

	rule->add_listener(logger);


	//�������� ��������� �������
	term1->set_value(25);
	rule->check();

	printf("����������� �� ������� = %d C\n", term1->get_value());

}



int main()
{

	setlocale(LC_CTYPE, "Rus");

	//test_proxy();
	test_delegate();
    return 0;
}

