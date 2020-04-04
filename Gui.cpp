#include "Gui.h"

#include <conio.h>


Gui::Gui()
{
    runConfig();
    vectorMenu.push_back(menu());
    vectorMenu.push_back(menu());
    vectorMenu.push_back(menu());
    vectorMenu.push_back(menu());

    AddOption(1, "����� ����������");
    AddOption(1, "����������");
    AddOption(1, "��������");
    AddOption(1, "�������");
    AddOption(1, "����������");
    AddOption(1, "�����");

    AddOption(2, "���-�� � ��������");
    AddOption(2, "�����");
    AddOption(2, "�� �������");
    AddOption(2, "���");
    AddOption(2, "����");
    AddOption(2, "�����");
    AddOption(2, "����������");

    AddOption(3, "�����������");
    AddOption(3, "��������");

    AddOption(4, "������� � �������");
    AddOption(4, "������� � ���");
    AddOption(4, "������� ������");
    AddOption(4, "������� �������");
}

void Gui::clear(byte mode)
{
    if (mode == 1)
    {
        system("cls");
    }
    else if (mode == 2)
    {
        COORD coord;
        coord.X = 0;
        coord.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}

void menu::clear(byte mode)
{
    if (mode == 1)
    {
        system("cls");
    }
    else if (mode == 2)
    {
        COORD coord;
        coord.X = 0;
        coord.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}

void Gui::AddOption(int menu, std::string name)
{
    Gui::vectorMenu[menu - 1].Add(name);
}

void Gui::Print()
{
    Gui::vectorMenu[chainSelect - 1].Print();
}

void Gui::Up()
{
    Gui::vectorMenu[Gui::chainSelect - 1].Up();
}
void Gui::Down()
{
    Gui::vectorMenu[Gui::chainSelect - 1].Down();
}

std::string Gui::getName(int chain, int option)
{
    return Gui::vectorMenu[chain - 1].getOptionName(option - 1);
}

void Gui::PrintChain()
{
    system("cls");
    for (int i = 0; i < 4; i++) std::cout << Gui::vectorMenu[i].getOptionSelect() << std::endl;
    system("pause");
    system("cls");
}

void Gui::UpMenu()
{
    if (Gui::chainSelect < 4)Gui::chainSelect++;
    clear(1);
}
void Gui::DownMenu()
{
    if (Gui::chainSelect > 1)Gui::chainSelect--;
    Gui::clear(1);
}

int Gui::getChain()
{
    return Gui::chainSelect;
}
int Gui::getOption()
{
    return Gui::getOption(Gui::chainSelect);
}


int Gui::getOption(int chain)
{
    return Gui::vectorMenu[chain - 1].getOptionSelect();
}

void Gui::Loop()
{
    apteka.Load();
    int keyCode = 0;
    while (true)
    {
        Print();
        keyCode = _getch();
        switch (keyCode)
        {
        case 119: case 87:case 150: case 230: case 72: case 246: case 214://�����
            Up();
            Print();
            break;
        case 115: case 83: case 155: case 235: case 80: case 251: case 219://����
            Down();
            Print();
            break;
        case 97: case 65:case 148: case 228: case 75: case 244: case 212://����� 244 212
            if (getChain() == 4)
            {
                DownMenu();
                DownMenu();
                DownMenu();
            }
            if (getChain() == 2)
            {
                DownMenu();
            }

            if (getChain() == 3)
            {
                DownMenu();
            }
            break;
        case 100:case 68:case 130:case 162: case 77: case 226: case 194://������ 226 194
            
            //������ ������� ����
            if (getChain() == 1)
            {
                switch (getOption())
                {
                case 1://����� ����������
                    clear(1);
                    //std::cout << "...������ ����������..." << std::endl;
                    Gui::apteka.PrintDrugs();
                    system("pause");
                    clear(1);
                    break;
                    /*----------------*/
                case 2://����������
                    clear(1);

                    UpMenu();
                    break;
                case 3://��������
                    clear(1);
                    Gui::apteka.readAdd();
                    system("pause");
                    clear(1);
                    break;
                case 4://�������
                    clear(1);
                    UpMenu();
                    UpMenu();
                    UpMenu();
                    break;
                case 5://����������
                    clear(1);
                    //std::cout << "...����������..." << std::endl;
                    apteka.PrintDrugsStatistic();
                    system("pause");
                    clear(1);
                    break;
                case 6://�����
                    clear(1);
                    apteka.Save();
                    exit(0);
                    system("pause");
                    clear(1);
                    break;

                }

                break;
            }
            //������ �������(����������)
            if (getChain() == 2)
            {
                switch (getOption())
                {
                case 1://��� - �� � ��������
                    clear(1);
                    UpMenu();
                    break;
                case 2://�����
                    clear(1);
                    UpMenu();
                    break;
                case 3://�� �������
                    clear(1);
                    UpMenu();
                    break;
                case 4://���
                    clear(1);
                    UpMenu();
                    break;
                case 5://����
                    clear(1);
                    UpMenu();
                    break;
                case 6://�����
                    clear(1);
                    UpMenu();
                    break;
                case 7://����������
                    clear(1);
                    UpMenu();
                    break;
                }


                break;
            }
            //������ �������(���������� ���)
            if (getChain() == 3)
            {

                switch (getOption())
                {
                case 1://�����������
                    clear(1);
                    std::cout << "������������� " << getName(2, getOption(2)) << " �� �����������" << std::endl;
                    
                    switch (getOption(2))
                    {
                    case 1:
                        apteka.SortDrugForNumber(2);
                        break;
                    case 2:
                        apteka.SortDrugForId(2);
                        break;
                    case 3:
                        apteka.SortDrugForRecipe(2);
                        break;
                    case 4:
                        apteka.SortDrugForName(2);
                        break;
                    case 5:
                        apteka.SortDrugForPrice(2);
                        break;
                    case 6:
                        apteka.SortDrugForWeight(2);
                        break;
                    case 7:
                        apteka.SortDrugForCount(2);
                        break;
                    default:
                        break;
                    }
                    system("pause");
                    clear(1);
                    break;
                case 2://��������
                    clear(1);
                    std::cout << "������������� " << getName(2, getOption(2)) << " �� ��������." << std::endl;
                    switch (getOption(2))
                    {
                    case 1:
                        apteka.SortDrugForNumber(1);
                        break;
                    case 2:
                        apteka.SortDrugForId(1);
                        break;
                    case 3:
                        apteka.SortDrugForRecipe(1);
                        break;
                    case 4:
                        apteka.SortDrugForName(1);
                        break;
                    case 5:
                        apteka.SortDrugForPrice(1);
                        break;
                    case 6:
                        apteka.SortDrugForWeight(1);
                        break;
                    case 7:
                        apteka.SortDrugForCount(1);
                        break;
                    default:
                        break;
                    }
                    system("pause");
                    clear(1);
                    break;

                }


                break;
            }
            //�������� �������(�������)
            if (getChain() == 4)
            {
                switch (getOption())
                {
                case 1://������� � �������
                    clear(1);
                    Gui::apteka.RemoveDrugForId(Pharmacy::getValue<int>("����� ���������� ��������"));
                    system("pause");
                    clear(1);
                    break;
                case 2://������� � ���
                    clear(1);

                    Gui::apteka.RemoveDrugForName(  []()->std::string{
                        std::string temp_name = "";
                        std::cout << "������� ��� ���������:";
                        while (temp_name == "")
                        {
                            std::cin >> temp_name;
                        }
                        return temp_name;
                        }() );
                    system("pause");
                    clear(1);
                    break;
                case 3://������� ������
                    clear(1);
                    Gui::apteka.RemoveDrugExpensiveThan(Pharmacy::getValue<float>("������� ��� �������� ������"));
                    system("pause");
                    clear(1);
                    break;
                case 4://������� �������
                    clear(1);
                    Gui::apteka.RemoveDrugCheaperThan(Pharmacy::getValue<float>("������� ��� �������� �������"));
                    system("pause");
                    clear(1);
                    break;

                }
                break;
            }
            break;
        case 13:
            break;
        }

    }

    
}

void Gui::visibleCursor(bool cur)
{
    if (!cur)
    {
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 1;
        cci.bVisible = false;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    else
    {
        CONSOLE_CURSOR_INFO cci;
        //cci.dwSize = 99; //������ �������
        cci.bVisible = true; //��������� �������
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }

}

void Gui::runConfig()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    visibleCursor(false);
}

