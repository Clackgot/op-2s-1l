#include "Gui.h"

#include <conio.h>


Gui::Gui()
{
    runConfig();
    vectorMenu.push_back(menu());
    vectorMenu.push_back(menu());
    vectorMenu.push_back(menu());
    vectorMenu.push_back(menu());

    AddOption(1, "Вывод препаратов");
    AddOption(1, "Сортировка");
    AddOption(1, "Добавить");
    AddOption(1, "Удалить");
    AddOption(1, "Статистика");
    AddOption(1, "Выход");

    AddOption(2, "Кол-во в упаковке");
    AddOption(2, "Номер");
    AddOption(2, "По рецепту");
    AddOption(2, "Имя");
    AddOption(2, "Цена");
    AddOption(2, "Масса");
    AddOption(2, "Количество");

    AddOption(3, "Возрастание");
    AddOption(3, "Убывание");

    AddOption(4, "Удалить с номером");
    AddOption(4, "Удалить с имя");
    AddOption(4, "Удалить дороже");
    AddOption(4, "Удалить дешевле");
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
        case 119: case 87:case 150: case 230: case 72: case 246: case 214://Вверх
            Up();
            Print();
            break;
        case 115: case 83: case 155: case 235: case 80: case 251: case 219://Вниз
            Down();
            Print();
            break;
        case 97: case 65:case 148: case 228: case 75: case 244: case 212://Влево 244 212
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
        case 100:case 68:case 130:case 162: case 77: case 226: case 194://Вправо 226 194
            
            //Первый уровень Меню
            if (getChain() == 1)
            {
                switch (getOption())
                {
                case 1://Вывод препаратов
                    clear(1);
                    //std::cout << "...Список препаратов..." << std::endl;
                    Gui::apteka.PrintDrugs();
                    system("pause");
                    clear(1);
                    break;
                    /*----------------*/
                case 2://Сортировка
                    clear(1);

                    UpMenu();
                    break;
                case 3://Добавить
                    clear(1);
                    Gui::apteka.readAdd();
                    system("pause");
                    clear(1);
                    break;
                case 4://Удалить
                    clear(1);
                    UpMenu();
                    UpMenu();
                    UpMenu();
                    break;
                case 5://Статистика
                    clear(1);
                    //std::cout << "...Статистика..." << std::endl;
                    apteka.PrintDrugsStatistic();
                    system("pause");
                    clear(1);
                    break;
                case 6://Выход
                    clear(1);
                    apteka.Save();
                    exit(0);
                    system("pause");
                    clear(1);
                    break;

                }

                break;
            }
            //Второй уровень(Сортировка)
            if (getChain() == 2)
            {
                switch (getOption())
                {
                case 1://Кол - во в упаковке
                    clear(1);
                    UpMenu();
                    break;
                case 2://Номер
                    clear(1);
                    UpMenu();
                    break;
                case 3://По рецепту
                    clear(1);
                    UpMenu();
                    break;
                case 4://Имя
                    clear(1);
                    UpMenu();
                    break;
                case 5://Цена
                    clear(1);
                    UpMenu();
                    break;
                case 6://Масса
                    clear(1);
                    UpMenu();
                    break;
                case 7://Количество
                    clear(1);
                    UpMenu();
                    break;
                }


                break;
            }
            //Третий уровень(Сортировка тип)
            if (getChain() == 3)
            {

                switch (getOption())
                {
                case 1://Возрастание
                    clear(1);
                    std::cout << "Отсортировали " << getName(2, getOption(2)) << " по возрастанию" << std::endl;
                    
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
                case 2://Убывание
                    clear(1);
                    std::cout << "Отсортировали " << getName(2, getOption(2)) << " по убыванию." << std::endl;
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
            //Четвёртый уровень(Удалить)
            if (getChain() == 4)
            {
                switch (getOption())
                {
                case 1://Удалить с номером
                    clear(1);
                    Gui::apteka.RemoveDrugForId(Pharmacy::getValue<int>("Номер удаляемого элемента"));
                    system("pause");
                    clear(1);
                    break;
                case 2://Удалить с имя
                    clear(1);

                    Gui::apteka.RemoveDrugForName(  []()->std::string{
                        std::string temp_name = "";
                        std::cout << "Введите имя препарата:";
                        while (temp_name == "")
                        {
                            std::cin >> temp_name;
                        }
                        return temp_name;
                        }() );
                    system("pause");
                    clear(1);
                    break;
                case 3://Удалить дороже
                    clear(1);
                    Gui::apteka.RemoveDrugExpensiveThan(Pharmacy::getValue<float>("Удалить все элементы дороже"));
                    system("pause");
                    clear(1);
                    break;
                case 4://Удалить дешевле
                    clear(1);
                    Gui::apteka.RemoveDrugCheaperThan(Pharmacy::getValue<float>("Удалить все элементы дешевле"));
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
        //cci.dwSize = 99; //размер курсора
        cci.bVisible = true; //видимость курсора
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

