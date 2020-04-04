#include "Drug.h"
#include "Pharmacy.h"
#include <iostream>


//������ ���������� � ���������
Drug::Drug(int id, std::string name, int count, bool recipe, int type, float price, int number, int weight)
{
	Drug::SetDrugId(id);
	Drug::SetDrugName(name);
	Drug::SetDrugCount(count);
	Drug::SetDrugRecipe(recipe);
	Drug::SetDrugType(type);
	Drug::SetDrugPrice(price);
	Drug::SetDrugNumber(number);
	Drug::SetDrugWeight(weight);
}
//�����������-�������� ���������
Drug::Drug()
{
	Drug::id = 0;
	Drug::name = "�������� ���������";
	Drug::count = 0;//���������� �� ������
	Drug::recipe = 0;
	Drug::type = 0;
	Drug::price = 0;
	Drug::number = 0;
	Drug::weight = 0;
}

//������ ����������� ����� ���������
void Drug::SetDrugId(int id)
{
	Drug::id = id;
}
//������� ����������� ����� ���������
int Drug::GetDrugId()
{
	return Drug::id;
}

//������ ��� ���������
void Drug::SetDrugName(std::string name)
{
	Drug::name = name;
}
//������� ��� ���������
std::string Drug::GetDrugName()
{
	return Drug::name;
}


//������ ���������� ��������� � ������
void Drug::SetDrugCount(int count)
{
	Drug::count = count;
}
//������� ���������� ��������� � ������
int Drug::GetDrugCount()
{
	return Drug::count;
}

//������ ������������ �������
void Drug::SetDrugRecipe(bool needRecipe)
{
	Drug::recipe = needRecipe;
}
//������� ������������ �������
bool Drug::GetDrugRecipe()
{
	return Drug::recipe;
}

//���������� ��� ���������
void Drug::SetDrugType(int type)
{
	Drug::type = type;
}
//������� ��� ���������
int Drug::GetDrugType()
{
	return Drug::type;
}

//���������� ���� ���������
void Drug::SetDrugPrice(float price)
{
	Drug::price = price;
}

//������� ���� ���������
float Drug::GetDrugPrice()
{
	return Drug::price;
}

//���������� ���������� ��������
void Drug::SetDrugNumber(int number)
{
	Drug::number = number;
}
//������� ���������� ��������
int Drug::GetDrugNumber()
{
	return Drug::number;
}

//���������� ����� ��������
void Drug::SetDrugWeight(int weight)
{
	Drug::weight = weight;
}
//������� ����� ��������
int Drug::GetDrugWeight()
{
	return Drug::weight;
}


//����� ���������� � ���������
void Drug::PrintDrugInfo()
{
	std::cout << "-------------" << GetDrugId() << "----------------" << std::endl;
	std::cout << "������������: " << GetDrugName() << std::endl;
	
	std::cout << "� �������: " << GetDrugCount() << " ��." << std::endl;
	
	if (GetDrugRecipe())std::cout << "�� �������" << std::endl;
	else std::cout << "��� �������" << std::endl;

	std::cout << "���: " << Pharmacy::GetType(GetDrugType()) << std::endl;

	std::cout << "����: " << GetDrugPrice() << " ���." << std::endl;

	std::cout << "��������: " << GetDrugNumber() << " ��." << std::endl;

	std::cout << "����� ��������: " << GetDrugWeight() << " ��." << std::endl;

}
