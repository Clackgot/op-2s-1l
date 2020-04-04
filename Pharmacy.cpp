#include "Pharmacy.h"
#include "Drug.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include <direct.h>
using namespace std;
//Вернуть название аптеки
std::string Pharmacy::GetPharmName()
{
	return Pharmacy::namePharm;
}
//Задать название аптеки
void Pharmacy::SetPharmName(std::string name)
{
	Pharmacy::namePharm = name;
}
//Вернуть количество аптек в сети
int Pharmacy::GetPharmCount()
{
	return Pharmacy::countPharm;
}
//Задать количество аптек в сети
void Pharmacy::SetPharmCount(int count)
{
	Pharmacy::countPharm = count;
}
//Добавить препарат в конец списка
void Pharmacy::AddDrug(int id, std::string name, int count, bool recipe, int type, float price, int number, int weight)
{
	drug.push_back(Drug(id, name, count, recipe, type, price, number, weight));
}
void Pharmacy::AddDrug(std::string name, int count, bool recipe, int type, float price, int number, int weight)
{
	drug.push_back(Drug(Pharmacy::drug.back().GetDrugId()+1, name, count, recipe, type, price, number, weight));
	
}
void Pharmacy::AddDrug()
{
	drug.push_back(Drug());
}
//Удалить препарат номер pos из списка
void Pharmacy::RemoveDrugForId(int id)
{
	auto item = find_if(Pharmacy::drug.begin(), Pharmacy::drug.end(),
		[&](Drug &d)->bool 
		{
			return d.GetDrugId() == id;
		}
	);
	if (item != Pharmacy::drug.end()) 
	{
		cout << "Препарат удалён:" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else
	{
		cout << "Такой препарат не найден" << endl;
	}
}
//Удалить все препараты с именем name
void Pharmacy::RemoveDrugForName(std::string name)
{
	auto item = find_if(Pharmacy::drug.begin(), Pharmacy::drug.end(),
		[&](Drug& d)->bool
		{
			return d.GetDrugName() == name;
		}
	);
	if (item != Pharmacy::drug.end())
	{
		cout << "Препарат удалён:" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else
	{
		cout << "Такой препарат не найден" << endl;
	}
}
void Pharmacy::RemoveDrugForRecipe(bool recipe)
{
	for (int i = 0; i < Pharmacy::drug.size(); i++)
	{
		auto item = find_if(Pharmacy::drug.begin(), Pharmacy::drug.end(),
			[&](Drug& d)->bool
			{
				return d.GetDrugRecipe() == recipe;
			}
		);
		if (item != Pharmacy::drug.end())
		{
			cout << "Препарат удалён:" << endl;
			(*item).PrintDrugInfo();
			Pharmacy::drug.erase(item);
		}
		else
		{
			cout << "Такой препарат не найден" << endl;
			return;
		}
	}
}
void Pharmacy::RemoveDrugExpensiveThan(float price)
{
	bool once_find = false;

	auto item = find_if(Pharmacy::drug.begin(), Pharmacy::drug.end(),
		[&](Drug& d)->bool
		{
			return d.GetDrugPrice() > price;
		});

	if (item != Pharmacy::drug.end())
	{
		cout << "Удалено" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else if(once_find)
	{
		RemoveDrugExpensiveThan(price);
	}
	else
	{
		cout << "Такой препарат не найден" << endl;
		return;
	}
	
}
void Pharmacy::RemoveDrugCheaperThan(float price)
{
	bool once_find = false;

	auto item = find_if(Pharmacy::drug.begin(), Pharmacy::drug.end(),
		[&](Drug& d)->bool
		{
			return d.GetDrugPrice() < price;
		});

	if (item != Pharmacy::drug.end())
	{
		cout << "Удалено" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else if (once_find)
	{
		RemoveDrugCheaperThan(price);
	}
	else
	{
		cout << "Такой препарат не найден" << endl;
		return;
	}

}
void Pharmacy::SortDrugForNumber(int mode)
{
	if(mode == 1)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool
	{
		return a.GetDrugNumber() > b.GetDrugNumber();
	});
	if (mode == 2)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool
		{
			return a.GetDrugNumber() < b.GetDrugNumber();
	});
}
void Pharmacy::SortDrugForPrice(int mode)
{
	if (mode == 1)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugPrice() > b.GetDrugPrice();
		});
	if (mode == 2)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugPrice() < b.GetDrugPrice();
		});
}
void Pharmacy::SortDrugForWeight(int mode)
{
	if (mode == 1)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool
		{
			return a.GetDrugWeight() > b.GetDrugWeight();
		});
	if (mode == 2)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool
		{
			return a.GetDrugWeight() < b.GetDrugWeight();
		});
}
void Pharmacy::SortDrugForCount(int mode)
{
	if (mode == 1)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugCount() > b.GetDrugCount();
		});
	if (mode == 2)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugCount() < b.GetDrugCount();
		});

}
//Сортировать вектор по ID(1 - убывание, 2 - возрастание)
void Pharmacy::SortDrugForId(int mode)
{
	if (mode == 1)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool
		{
			return a.GetDrugId() > b.GetDrugId();
		});
	if (mode == 2)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool
		{
			return a.GetDrugId() < b.GetDrugId();
		});
}
void Pharmacy::SortDrugForRecipe(int mode)
{
	if (mode == 1)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugRecipe() > b.GetDrugRecipe();
		});
	if (mode == 2)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugRecipe() < b.GetDrugRecipe();
		});
}
void Pharmacy::SortDrugForName(int mode)
{
	if (mode == 1)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugName() > b.GetDrugName();
		});
	if (mode == 2)sort(drug.begin(), drug.end(), [](Drug a, Drug b)->bool {
		return a.GetDrugName() < b.GetDrugName();
		});
}
//Загрузка из файла
void Pharmacy::Load()
{
	Pharmacy::drug.clear();
	int id = 0;
	std::string name = "test";//Наименование препарата
	int count = 0;//Количество препарата на складе
	bool recipe = true;//Необходимость рецепта
	int type = 0;//Тип препарата
	float price = 0.0f;//Цена препарата
	int number = 0;//Количество таблеток
	int weight = 0;//Масса таблетки
	std::ifstream fp;
	fp.open(Pharmacy::dataBase);
	while (!fp.eof())
	{
		fp >> id;
		fp >> name;
		fp >> count;
		fp >> recipe;
		fp >> type;
		fp >> price;
		fp >> number;
		fp >> weight;
		Pharmacy::AddDrug(id, name, count, recipe, type, price, number, weight);
	}
	fp.close();
}
//Сохранение в файл
void Pharmacy::Save()
{
	Pharmacy::SortDrugForId(2);//сортируем список по ID в порядке возрастания
	std::ofstream fp;
	fp.open(dataBase, std::ios_base::trunc| std::ios::out);
	for (size_t i = 0; i < Pharmacy::drug.size(); i++)
	{
		fp << Pharmacy::drug[i].GetDrugId();
		fp << " ";
		fp << Pharmacy::drug[i].GetDrugName();
		fp << " ";
		fp << Pharmacy::drug[i].GetDrugCount();
		fp << " ";
		fp << Pharmacy::drug[i].GetDrugRecipe();
		fp << " ";
		fp << Pharmacy::drug[i].GetDrugType();
		fp << " ";
		fp << Pharmacy::drug[i].GetDrugPrice();
		fp << " ";
		fp << Pharmacy::drug[i].GetDrugNumber();
		fp << " ";
		fp << Pharmacy::drug[i].GetDrugWeight();
		if(i != Pharmacy::drug.size()-1)fp << std::endl;
	}
}
//Вывести препараты на экран
void Pharmacy::PrintDrugs()
{
	for(auto it: Pharmacy::drug) it.PrintDrugInfo();
}
//Конструктор аптеки
Pharmacy::Pharmacy(std::string name, int count)
{
	char buff[66];
	char *temp = _getcwd(buff, sizeof(buff));
	std::string dataBase = buff;
	for (auto& it : dataBase)
	{
		if (it == '/') it = '\\';
	}
	Pharmacy::namePharm = name;
	Pharmacy::countPharm = count;
}
//Вернуть имя типа препарата
std::string Pharmacy::GetType(int i)
{
	if (i >= 0 && i < 15)return Pharmacy::drug_type[i];
	else return Pharmacy::drug_type[13];
}
void Pharmacy::PrintDrugsStatistic()
{
	int countDrug = 0;
	float countPrice = 0;
	float averagePrice = 0;
	float countWeight = 0;
	float averageWeight = 0;
	for (size_t i = 0; i < Pharmacy::drug.size(); i++)
	{
		countDrug+=Pharmacy::drug.at(i).GetDrugCount();
		countPrice += Pharmacy::drug.at(i).GetDrugPrice()* Pharmacy::drug.at(i).GetDrugCount();
		averagePrice += Pharmacy::drug.at(i).GetDrugPrice();
		countWeight += Pharmacy::drug.at(i).GetDrugWeight() * Pharmacy::drug.at(i).GetDrugNumber()* Pharmacy::drug.at(i).GetDrugCount();
		averageWeight += Pharmacy::drug.at(i).GetDrugWeight();
	}
	averagePrice /= Pharmacy::drug.size();
	averageWeight /= Pharmacy::drug.size();;
	std::cout << "Всего упаковок лекарств в аптеке:\t " << countDrug << " ед." << std::endl;
	//до 10 тыс
	if(countPrice < 10000)std::cout << "Общая стоимость препаратов:\t\t " << std::setprecision(2) << std::fixed << countPrice << " руб."<< std::endl;
	//до 1 млн.
	else if(countPrice < 1000000)std::cout << "Общая стоимость препаратов:\t\t " << std::setprecision(0) << std::fixed << countPrice/1000 << " тыс. руб." << std::endl;
	else std::cout << "Общая стоимость препаратов:\t\t " << std::setprecision(0) << std::fixed << countPrice / 1000000 << " млн. руб." << std::endl;
	std::cout << "Средняя цена препарата:\t\t\t " << std::setprecision(2) << std::fixed << averagePrice << " руб."<< std::endl;
	std::cout << "Средняя масса таблетки:\t\t\t " << std::setprecision(2) << std::fixed << averageWeight << " мг." << std::endl;
	std::cout << "Масса нетто препаратов:\t\t\t " << std::setprecision(2) << std::fixed << countWeight/1000000 << " кг." << std::endl;
}
int Pharmacy::readAdd()
{
	Pharmacy::Load();
	setlocale(LC_CTYPE, "Russian");
	std::cin.clear();
	setlocale(LC_CTYPE, "Russian");
	std::string _name = "";
	int _count = -1;
	bool _recipe = true;
	int _type = -1;
	float _price = -1.0f; 
	int _number = -1;
	int _weight = -1;
	std::cout << "Введите имя препарата:";
	while (_name == "") 
	{
		std::cin >> _name;
	}
	std::cin.ignore(32767, '\n');
	while(_count<0)_count = getValue<int>("Упаковок в наличии");
	int temp_recipe = -1;
	while(!(temp_recipe == 1 || temp_recipe == 0))	temp_recipe = getValue<int>("Отпускается по рецепту(0/1)?");
	_recipe = static_cast<bool>(temp_recipe);
	printf("1.Пищеварительный тракт и обмен веществ\n");
	printf("2.Кроветворение и кровь\n");
	printf("3.Сердечно - сосудистая система\n");
	printf("4.Дерматология\n");
	printf("5.Мочеполовая система и половые гормоны\n");
	printf("6.Гормоны для системного применения(исключая половые гормоны и инсулины)\n");
	printf("7.Противомикробные препараты для системного применения\n");
	printf("8.Противоопухолевые препараты и иммуномодуляторы\n");
	printf("9.Костно - мышечная система\n");
	printf("10.Нервная система\n");
	printf("11.Противопаразитарные препараты, инсектициды и репелленты\n");
	printf("12.Дыхательная система\n");
	printf("13.Препараты для лечения заболеваний органов чувств\n");
	printf("14.Прочие препараты\n");
	printf("15.Биологически - активные добавки(БАДы)\n");
	std::cout << "Тип лекарства(1-15)?";
	while(!(_type>0 && _type < 16))_type = getValue<int>("Тип лекарства(1-15)?");
	_type--;
	while(!(_price > 0.0001f))_price = getValue<float>("Цена");
	while (_number < 1)_number = getValue<int>("Количество таблеток");
	while (_weight < 1)_weight = getValue<int>("Масса таблетки");
	Pharmacy::AddDrug(_name,_count, _recipe, _type, _price, _number, _weight);
	Pharmacy::Save();
	return 0;
}
std::string Pharmacy::drug_type[15] = {
	"Пищеварительный тракт и обмен веществ",
	"Кроветворение и кровь",
	"Сердечно - сосудистая система",
	"Дерматология",
	"Мочеполовая система и половые гормоны",
	"Гормоны для системного применения(исключая половые гормоны и инсулины)",
	"Противомикробные препараты для системного применения",
	"Противоопухолевые препараты и иммуномодуляторы",
	"Костно - мышечная система",
	"Нервная система",
	"Противопаразитарные препараты, инсектициды и репелленты",
	"Дыхательная система",
	"Препараты для лечения заболеваний органов чувств",
	"Прочие препараты",
	"Биологически - активные добавки(БАДы)" };



