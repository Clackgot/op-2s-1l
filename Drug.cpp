#include "Drug.h"
#include "Pharmacy.h"
#include <iostream>


//Задать информацию о препарате
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
//Конструктор-заглушка препарата
Drug::Drug()
{
	Drug::id = 0;
	Drug::name = "Название препарата";
	Drug::count = 0;//Количество на складе
	Drug::recipe = 0;
	Drug::type = 0;
	Drug::price = 0;
	Drug::number = 0;
	Drug::weight = 0;
}

//Задать инвентарный номер препарата
void Drug::SetDrugId(int id)
{
	Drug::id = id;
}
//Вернуть инвентарный номер препарата
int Drug::GetDrugId()
{
	return Drug::id;
}

//Задать имя препарата
void Drug::SetDrugName(std::string name)
{
	Drug::name = name;
}
//Вернуть имя препарата
std::string Drug::GetDrugName()
{
	return Drug::name;
}


//Задать количество препарата в аптеке
void Drug::SetDrugCount(int count)
{
	Drug::count = count;
}
//Вернуть количество препарата в аптеке
int Drug::GetDrugCount()
{
	return Drug::count;
}

//Задать необхоимость рецепта
void Drug::SetDrugRecipe(bool needRecipe)
{
	Drug::recipe = needRecipe;
}
//Вернуть необхоимость рецепта
bool Drug::GetDrugRecipe()
{
	return Drug::recipe;
}

//Установить тип препарата
void Drug::SetDrugType(int type)
{
	Drug::type = type;
}
//Вернуть тип препарата
int Drug::GetDrugType()
{
	return Drug::type;
}

//Установить цену препарата
void Drug::SetDrugPrice(float price)
{
	Drug::price = price;
}

//Вернуть цену препарата
float Drug::GetDrugPrice()
{
	return Drug::price;
}

//Установить количество таблеток
void Drug::SetDrugNumber(int number)
{
	Drug::number = number;
}
//Вернуть количество таблеток
int Drug::GetDrugNumber()
{
	return Drug::number;
}

//Установить массу таблетки
void Drug::SetDrugWeight(int weight)
{
	Drug::weight = weight;
}
//Вернуть массу таблетки
int Drug::GetDrugWeight()
{
	return Drug::weight;
}


//Вывод информации о препарате
void Drug::PrintDrugInfo()
{
	std::cout << "-------------" << GetDrugId() << "----------------" << std::endl;
	std::cout << "Наименование: " << GetDrugName() << std::endl;
	
	std::cout << "В наличии: " << GetDrugCount() << " ед." << std::endl;
	
	if (GetDrugRecipe())std::cout << "По рецепту" << std::endl;
	else std::cout << "Без рецепта" << std::endl;

	std::cout << "Тип: " << Pharmacy::GetType(GetDrugType()) << std::endl;

	std::cout << "Цена: " << GetDrugPrice() << " руб." << std::endl;

	std::cout << "Таблеток: " << GetDrugNumber() << " шт." << std::endl;

	std::cout << "Масса таблетки: " << GetDrugWeight() << " мг." << std::endl;

}
