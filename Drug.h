#pragma once

#include <iostream>

class Drug
{
private:
	int id;
	std::string name;//Наименование препарата
	int count;//Количество препарата на складе
	bool recipe;//Необходимость рецепта
	int type;//Тип препарата
	float price;//Цена препарата
	int number;//Количество таблеток
	int weight;//Масса таблетки

public:
	Drug(int id, std::string name, int count, bool recipe, int type, float price, int number, int weight);
	Drug();  


	void SetDrugId(int id);
	int GetDrugId();
	//Имя препарата
	void SetDrugName(std::string name);
	std::string GetDrugName();

	//Количество препарата
	void SetDrugCount(int count);
	int GetDrugCount();

	void SetDrugRecipe(bool needRecipe);
	bool GetDrugRecipe();

	void SetDrugType(int type);
	int GetDrugType();

	void SetDrugPrice(float price);
	float GetDrugPrice();

	void SetDrugNumber(int type);
	int GetDrugNumber();
	
	void SetDrugWeight(int weight);
	int GetDrugWeight();

	void PrintDrugInfo();

};

