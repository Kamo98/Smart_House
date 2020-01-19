#include "SmartLamp.h"



SmartLamp::SmartLamp()
{
	//���������� ��������� �� ���������
	isTurnOn = false;
	intensity = 4;
	colorB = colorG = colorR = 255;		//����� ����
}


SmartLamp::~SmartLamp()
{
}


bool SmartLamp::turnOn()
{
	if (isTurnOn)
		return false;
	printf("����� ����� ������� ��������\n");
	isTurnOn = true;
	return true;
}


bool SmartLamp::turnOff()
{
	if (!isTurnOn)
		return false;
	printf("����� ����� ������� ���������\n");
	isTurnOn = false;
	return true;
}


void SmartLamp::change_intensity(int newIntensity)
{
	intensity = newIntensity;
	printf("����� ������������� ����� ����� = %d\n", newIntensity);
}


void SmartLamp::change_color(int r, int g, int b)
{
	colorR = r;
	colorG = g;
	colorB = b;
	printf("����� ���� ����� ����� = (%d, %d, %d)\n", colorR, colorG, colorB);
}
