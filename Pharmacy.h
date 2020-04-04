#pragma once

#include <string>
#include <vector>
#include "Drug.h"




class Pharmacy
{

private:
	//Название аптеки
	std::string namePharm;
	//Количество аптек в сети
	int countPharm;
	//Путь к БД
	std::string dataBase = "C:\\Users\\Anicate\\source\\repos\\CourseWork\\db.txt";
	//Инициализация массива строк типов препаратов
	static std::string drug_type[15];
	//Вектор препаратов аптеки
	std::vector <Drug> drug;
protected:
	//Сигнатуры методов аптеки
	std::string GetPharmName();
	void SetPharmName(std::string);
	int GetPharmCount();
	void SetPharmCount(int count);
public:
	//Добавить препарат в вектор
	void AddDrug(int id, std::string name, int count, bool recipe, int type, float price, int number, int weight);
	void AddDrug(std::string name, int count, bool recipe, int type, float price, int number, int weight);
	void AddDrug();
	template<typename type > static type getValue(std::string s);
	//Удалить препарат номер pos из списка
	void RemoveDrugForId(int pos);
	//Удалить все препараты с наименованием text
	void RemoveDrugForName(std::string text);
	//Удалить все препараты с рецептом или без
	void RemoveDrugForRecipe(bool recipe);
	//Удалить все препараты дороже чем recipe
	void RemoveDrugExpensiveThan(float price);
	//Удалить все препараты дешевле чем recipe
	void RemoveDrugCheaperThan(float price);
	/*НАЧАЛО СОРТИРОВКИ*/
	//Сортировать вектор по кол-во таблеток(1 - возрастание, 2 - убывание)
	void SortDrugForNumber(int mode);
	//Cортировать все препараты по ID(1 - возрастание, 2 - убывание)
	void SortDrugForId(int mode);
	//Cортировать все препараты по рецепту(1 - возрастание, 2 - убывание)
	void SortDrugForRecipe(int mode);
	//Cортировать все препараты по имени(1 - возрастание, 2 - убывание)
	void SortDrugForName(int mode);
	//Cортировать все препараты по цене(1 - возрастание, 2 - убывание)
	void SortDrugForPrice(int mode);
	//Сортировать все препараты по весу таблетки(1 - возрастание, 2 - убывание)
	void SortDrugForWeight(int mode);
	//Сортировать все препараты по количеству на складе(1 - возрастание, 2 - убывание)
	void SortDrugForCount(int mode);
	/*КОНЕЦ СОРТИРОВКИ*/
	//Загрузить файл в программу
	void Load();
	//Сохранить препараты в файл
	void Save();
	//Вывести все препараты на экран
	void PrintDrugs();
	//Создать экземпляр аптеки
	Pharmacy(std::string, int count);
	//Вернуть тип препарата
	static std::string GetType(int i);
	void PrintDrugsStatistic();
	int readAdd();
};
template<typename T>
inline static T Pharmacy::getValue(std::string s)
{
	while (true) // Цикл продолжается до тех пор, пока пользователь не введёт корректное значение
	{
		std::cout << s << ": ";
		T a;
		std::cin >> a;
		if (std::cin.fail()) // Если предыдущее извлечение оказалось неудачным,
		{
			system("cls");
			std::cin.clear(); // То возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // Удаляем значения предыдущего ввода из входного буфера
		}
		else // Eсли всё хорошо, то возвращаем a
			return a;
	}
}

