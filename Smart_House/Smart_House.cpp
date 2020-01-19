#include <locale.h>
#include <string>
#include "Device.h"
#include "ProxyDevice.h"
#include "RealDevice.h"
#include "Sensor.h"
#include "Thermometer.h"
#include "HumidityMeter.h"
#include "Rule.h"
#include "AirСonditioning.h"
#include "RuleLogger.h"
#include "SmartLampAdapter.h"



//Тестирование прокси
void test_proxy() {
	ProxyDevice *prox1 = new ProxyDevice(), *prox2 = new ProxyDevice();
	RealDevice *app1 = new RealDevice("Прибор 1"), *app2 = new RealDevice("Прибор 2"), *app3 = new RealDevice("Прибор 3");
	prox1->init_device(app1);

	const int N = 3;
	IDevice* apps[N] = { prox1, prox2, app3 };

	for (int i = 0; i < N; i++) {
		printf("Прибор %d: ", i + 1);
		apps[i]->get_status();
		printf("\n");
	}

	printf("\n\n");

	//Инициализация проксируемых приборов
	app1->turn_on();	//Вкл
	app2->block();		//Заблок.
	prox1->init_device(app1);
	prox2->init_device(app2);

	for (int i = 0; i < N; i++) {
		printf("Прибор %d: ", i + 1);
		apps[i]->get_status();
		printf("\n");
	}
}


//Тестирование делегирования
void test_delegate() {
	//Создать датчики
	Thermometer *term1 = new Thermometer(20);
	HumidityMeter *humid1 = new HumidityMeter(30);



	//Вывод начальных показателей датчиков
	printf("Температура на датчике = %d C\n", term1->get_value());
	printf("Влажность воздуха на датчике = %d %\n", humid1->get_value());

	AirСonditioning *cond = new AirСonditioning("Кондиционер", 20);
	
	Command *comm = new Command(cond, "Сделай холоднее");

	Rule* rule = new Rule(term1, comm, 25);

	RuleLogger *logger = new RuleLogger("log.txt");

	rule->add_listener(logger);


	//Изменить показания датчика
	term1->set_value(25);
	rule->check();

	printf("Температура на датчике = %d C\n", term1->get_value());

}



int main()
{

	setlocale(LC_CTYPE, "Rus");

	//test_proxy();
	test_delegate();
    return 0;
}

