#include "Pharmacy.h"
#include "Drug.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include <direct.h>
using namespace std;
//������� �������� ������
std::string Pharmacy::GetPharmName()
{
	return Pharmacy::namePharm;
}
//������ �������� ������
void Pharmacy::SetPharmName(std::string name)
{
	Pharmacy::namePharm = name;
}
//������� ���������� ����� � ����
int Pharmacy::GetPharmCount()
{
	return Pharmacy::countPharm;
}
//������ ���������� ����� � ����
void Pharmacy::SetPharmCount(int count)
{
	Pharmacy::countPharm = count;
}
//�������� �������� � ����� ������
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
//������� �������� ����� pos �� ������
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
		cout << "�������� �����:" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else
	{
		cout << "����� �������� �� ������" << endl;
	}
}
//������� ��� ��������� � ������ name
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
		cout << "�������� �����:" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else
	{
		cout << "����� �������� �� ������" << endl;
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
			cout << "�������� �����:" << endl;
			(*item).PrintDrugInfo();
			Pharmacy::drug.erase(item);
		}
		else
		{
			cout << "����� �������� �� ������" << endl;
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
		cout << "�������" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else if(once_find)
	{
		RemoveDrugExpensiveThan(price);
	}
	else
	{
		cout << "����� �������� �� ������" << endl;
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
		cout << "�������" << endl;
		(*item).PrintDrugInfo();
		Pharmacy::drug.erase(item);
	}
	else if (once_find)
	{
		RemoveDrugCheaperThan(price);
	}
	else
	{
		cout << "����� �������� �� ������" << endl;
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
//����������� ������ �� ID(1 - ��������, 2 - �����������)
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
//�������� �� �����
void Pharmacy::Load()
{
	Pharmacy::drug.clear();
	int id = 0;
	std::string name = "test";//������������ ���������
	int count = 0;//���������� ��������� �� ������
	bool recipe = true;//������������� �������
	int type = 0;//��� ���������
	float price = 0.0f;//���� ���������
	int number = 0;//���������� ��������
	int weight = 0;//����� ��������
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
//���������� � ����
void Pharmacy::Save()
{
	Pharmacy::SortDrugForId(2);//��������� ������ �� ID � ������� �����������
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
//������� ��������� �� �����
void Pharmacy::PrintDrugs()
{
	for(auto it: Pharmacy::drug) it.PrintDrugInfo();
}
//����������� ������
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
//������� ��� ���� ���������
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
	std::cout << "����� �������� �������� � ������:\t " << countDrug << " ��." << std::endl;
	//�� 10 ���
	if(countPrice < 10000)std::cout << "����� ��������� ����������:\t\t " << std::setprecision(2) << std::fixed << countPrice << " ���."<< std::endl;
	//�� 1 ���.
	else if(countPrice < 1000000)std::cout << "����� ��������� ����������:\t\t " << std::setprecision(0) << std::fixed << countPrice/1000 << " ���. ���." << std::endl;
	else std::cout << "����� ��������� ����������:\t\t " << std::setprecision(0) << std::fixed << countPrice / 1000000 << " ���. ���." << std::endl;
	std::cout << "������� ���� ���������:\t\t\t " << std::setprecision(2) << std::fixed << averagePrice << " ���."<< std::endl;
	std::cout << "������� ����� ��������:\t\t\t " << std::setprecision(2) << std::fixed << averageWeight << " ��." << std::endl;
	std::cout << "����� ����� ����������:\t\t\t " << std::setprecision(2) << std::fixed << countWeight/1000000 << " ��." << std::endl;
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
	std::cout << "������� ��� ���������:";
	while (_name == "") 
	{
		std::cin >> _name;
	}
	std::cin.ignore(32767, '\n');
	while(_count<0)_count = getValue<int>("�������� � �������");
	int temp_recipe = -1;
	while(!(temp_recipe == 1 || temp_recipe == 0))	temp_recipe = getValue<int>("����������� �� �������(0/1)?");
	_recipe = static_cast<bool>(temp_recipe);
	printf("1.��������������� ����� � ����� �������\n");
	printf("2.������������� � �����\n");
	printf("3.�������� - ���������� �������\n");
	printf("4.������������\n");
	printf("5.����������� ������� � ������� �������\n");
	printf("6.������� ��� ���������� ����������(�������� ������� ������� � ��������)\n");
	printf("7.���������������� ��������� ��� ���������� ����������\n");
	printf("8.����������������� ��������� � ����������������\n");
	printf("9.������ - �������� �������\n");
	printf("10.������� �������\n");
	printf("11.������������������� ���������, ����������� � ����������\n");
	printf("12.����������� �������\n");
	printf("13.��������� ��� ������� ����������� ������� ������\n");
	printf("14.������ ���������\n");
	printf("15.������������ - �������� �������(����)\n");
	std::cout << "��� ���������(1-15)?";
	while(!(_type>0 && _type < 16))_type = getValue<int>("��� ���������(1-15)?");
	_type--;
	while(!(_price > 0.0001f))_price = getValue<float>("����");
	while (_number < 1)_number = getValue<int>("���������� ��������");
	while (_weight < 1)_weight = getValue<int>("����� ��������");
	Pharmacy::AddDrug(_name,_count, _recipe, _type, _price, _number, _weight);
	Pharmacy::Save();
	return 0;
}
std::string Pharmacy::drug_type[15] = {
	"��������������� ����� � ����� �������",
	"������������� � �����",
	"�������� - ���������� �������",
	"������������",
	"����������� ������� � ������� �������",
	"������� ��� ���������� ����������(�������� ������� ������� � ��������)",
	"���������������� ��������� ��� ���������� ����������",
	"����������������� ��������� � ����������������",
	"������ - �������� �������",
	"������� �������",
	"������������������� ���������, ����������� � ����������",
	"����������� �������",
	"��������� ��� ������� ����������� ������� ������",
	"������ ���������",
	"������������ - �������� �������(����)" };



