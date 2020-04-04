#pragma once

#include <string>
#include <vector>
#include "Drug.h"




class Pharmacy
{

private:
	//�������� ������
	std::string namePharm;
	//���������� ����� � ����
	int countPharm;
	//���� � ��
	std::string dataBase = "C:\\Users\\Anicate\\source\\repos\\CourseWork\\db.txt";
	//������������� ������� ����� ����� ����������
	static std::string drug_type[15];
	//������ ���������� ������
	std::vector <Drug> drug;
protected:
	//��������� ������� ������
	std::string GetPharmName();
	void SetPharmName(std::string);
	int GetPharmCount();
	void SetPharmCount(int count);
public:
	//�������� �������� � ������
	void AddDrug(int id, std::string name, int count, bool recipe, int type, float price, int number, int weight);
	void AddDrug(std::string name, int count, bool recipe, int type, float price, int number, int weight);
	void AddDrug();
	template<typename type > static type getValue(std::string s);
	//������� �������� ����� pos �� ������
	void RemoveDrugForId(int pos);
	//������� ��� ��������� � ������������� text
	void RemoveDrugForName(std::string text);
	//������� ��� ��������� � �������� ��� ���
	void RemoveDrugForRecipe(bool recipe);
	//������� ��� ��������� ������ ��� recipe
	void RemoveDrugExpensiveThan(float price);
	//������� ��� ��������� ������� ��� recipe
	void RemoveDrugCheaperThan(float price);
	/*������ ����������*/
	//����������� ������ �� ���-�� ��������(1 - �����������, 2 - ��������)
	void SortDrugForNumber(int mode);
	//C���������� ��� ��������� �� ID(1 - �����������, 2 - ��������)
	void SortDrugForId(int mode);
	//C���������� ��� ��������� �� �������(1 - �����������, 2 - ��������)
	void SortDrugForRecipe(int mode);
	//C���������� ��� ��������� �� �����(1 - �����������, 2 - ��������)
	void SortDrugForName(int mode);
	//C���������� ��� ��������� �� ����(1 - �����������, 2 - ��������)
	void SortDrugForPrice(int mode);
	//����������� ��� ��������� �� ���� ��������(1 - �����������, 2 - ��������)
	void SortDrugForWeight(int mode);
	//����������� ��� ��������� �� ���������� �� ������(1 - �����������, 2 - ��������)
	void SortDrugForCount(int mode);
	/*����� ����������*/
	//��������� ���� � ���������
	void Load();
	//��������� ��������� � ����
	void Save();
	//������� ��� ��������� �� �����
	void PrintDrugs();
	//������� ��������� ������
	Pharmacy(std::string, int count);
	//������� ��� ���������
	static std::string GetType(int i);
	void PrintDrugsStatistic();
	int readAdd();
};
template<typename T>
inline static T Pharmacy::getValue(std::string s)
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ����� ���������� ��������
	{
		std::cout << s << ": ";
		T a;
		std::cin >> a;
		if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			system("cls");
			std::cin.clear(); // �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n'); // ������� �������� ����������� ����� �� �������� ������
		}
		else // E��� �� ������, �� ���������� a
			return a;
	}
}

