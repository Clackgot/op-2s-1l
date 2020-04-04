#pragma once
#include "Pharmacy.h"
#include <vector>
#include <string>
#include <Windows.h>

class menu
{
private:
    int countOption = 0;
    std::vector <std::string> optionText;
    int optionSelect = 1;
public:
    menu(){}
    static void clear(byte mode);
    void Add(std::string optionName)
    {
        optionText.push_back(optionName);
        countOption++;
    }
    int getOptionCount()
    {
        return countOption;
    }
    int getOptionSelect()
    {
        return optionSelect;
    }
    std::string getOptionName(int index)
    {
        return optionText[index];
    }
    void Up()
    {
        if (optionSelect > 1)optionSelect--;
    }
    void Down()
    {
        if (optionSelect < countOption)optionSelect++;
    }
    void Print()
    {
        clear(2);
        for (int i = 0; i < countOption; i++)
        {
            if (optionSelect == (i + 1))std::cout << "->";
            else std::cout << "  ";
            std::cout << optionText[i] << std::endl;
        }
    }
};

class Gui
{
private:  
    std::vector <menu> vectorMenu;
    int chainSelect = 1;
    Pharmacy apteka = Pharmacy("Социальная", 5);
public:
    Gui();
    static void clear(byte mode);
    void AddOption(int menu, std::string name);
    void Print();
    void Up();
    void Down();
    std::string getName(int chain, int option);
    void PrintChain();
    void UpMenu();
    void DownMenu();
    int getChain();
    int getOption();
    int getOption(int chain);
    void Loop();

    static void visibleCursor(bool cur);
    static void runConfig();
};



