#include<iostream>
#include<vector>
#include<iomanip>
#include <string>

//Main Menu
//void ShowMainMenu();
//int Choice();

//End Program
//bool QuitProgram(bool &End);

//Shopping clac
//void Shoppingcalc();
void ShoppingcalcMenu();
char ShopChoice();
void ShowallItems(const std::vector<std::string> &Items, const std::vector<double> &ItemCost, double &Budget);
void AddItemsAndPrices(std::vector<std::string> &Items, std::vector<double> &ItemCost);
double BudgetAmount();
void TotalCost(std::vector<double> Items, double Budg);
void ClearAll(std::vector<std::string> &Items,std::vector<double> &ItemCost, double &Budget);
bool QuitApp(bool &ShopDone);

int main()
{
	bool ShopDone = true;
	std::vector<std::string> Items{};
	std::vector<double> ItemCost{};
	double Budget{ 0 };
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	Welcome to the Shopping Calc Program" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl << std::endl;
	do
	{
		ShoppingcalcMenu();
		char ShopSelect = ShopChoice();
		if (ShopSelect == 'A' || ShopSelect == 'a')
		{
			ShowallItems(Items, ItemCost, Budget);
		}
		else if (ShopSelect == 'B' || ShopSelect == 'b')
		{
			AddItemsAndPrices(Items, ItemCost);
		}
		else if (ShopSelect == 'C' || ShopSelect == 'c')
		{
			Budget = BudgetAmount();
		}
		else if (ShopSelect == 'D' || ShopSelect == 'd')
		{
			TotalCost(ItemCost, Budget);
		}
		else if (ShopSelect == 'E' || ShopSelect == 'e')
		{
			ClearAll(Items, ItemCost, Budget);
		}
		else if (ShopSelect == 'F' || ShopSelect == 'f')
		{
			QuitApp(ShopDone);
		}
		else
		{
			std::cout << "Not an option!" << std::endl;
		}
	} while (ShopDone == true);
	return 0;
}


//int Choice()
//{
//	int Pick;
//	std::cout << "What would you like to choose? : ";
//	std::cin >> Pick;
//	std::cout << std::endl;
//	return Pick;
//}
//
//bool QuitProgram(bool &End)
//{
//	End = false;
//	return End;
//}

//****************************************************************************************



void ShoppingcalcMenu()
{	
	std::cout << std::endl;
	std::cout << "a) Show all items and price" << std::endl;
	std::cout << "b) Add items and prices" << std::endl;
	std::cout << "c) add budget (optional)" << std::endl;
	std::cout << "d) Calculate total prices" << std::endl;
	std::cout << "e) Clear all items and prices" << std::endl;
	std::cout << "f) Quit Program" << std::endl << std::endl;
}

char ShopChoice()
{
	char Choice;
	std::cout << "Choose an Option: ";
	std::cin >> Choice;
	std::cout << std::endl;
	return Choice;
}

void ShowallItems(const std::vector<std::string> &Items, const std::vector<double> &ItemCost, double &Budget)
{
	if (Items.size() == 0)
	{
		std::cout << "There are no Items\n\n";
	}
	else
	{
		std::cout << "All your Items: " << std::endl;
		for (int i = 0; i < Items.size(); i++)
		{
			std::cout << "[ " << Items.at(i) << " ]" << "\t"  << "[ $" << ItemCost.at(i) << " ]" << std::endl;
		}
	}
	if (Budget != 0)
	{
		std::cout << "Budget: " << "[ $" << Budget << " ]\n\n";
	}
}

void AddItemsAndPrices(std::vector<std::string> &Items, std::vector<double> &ItemCost)
{
	int Amount{};
	std::string ShopItem{};
	double Price{};
	std::cout << "How many items would you like to add: ";
	std::cin >> Amount;
	for (int i = 0; i < Amount; i++)
	{
		std::cout << "Enter an item: ";
		std::cin >> ShopItem;
		Items.push_back(ShopItem);
		std::cout << "Enter the price: ";
		std::cin >> Price;
		ItemCost.push_back(Price);
	}
}

double BudgetAmount()
{
	double Amount;
	std::cout << "Enter budget amount: ";
	std::cin >> Amount;
	return Amount;
}

void TotalCost(std::vector<double> Items, double Budg)
{
	double TotalAmount{0};
	for (int i = 0; i < Items.size(); i++)
	{
		TotalAmount = TotalAmount + Items.at(i);
	}
	std::cout << "Your total amount is " << TotalAmount << std::endl;
	
	if (Budg != 0)
	{
		if (TotalAmount < Budg)
		{
			std::cout << TotalAmount << "\t" << Budg;
			std::cout << "It's in your budget range.\n\n";
		}
		else
		{
			std::cout << TotalAmount << "\t" << Budg;
			std::cout << "It's not in your budget range.\n\n";
		}
	}
}

void ClearAll(std::vector<std::string> &Items, std::vector<double> &ItemCost, double &Budget)
{
	Items.clear();
	ItemCost.clear();
	Budget = 0;
}

bool QuitApp(bool &ShopDone)
{
	ShopDone = false;
	return ShopDone;
}

































/*
1. Displays Menu
A) -------------------------------------------------
				  Chose your options
   ------------------------------------------------- 
	
	1) Shopping Clac
		a) Show all items and price
		b) Add items and prices
		c) add budget (optional)
		d) Calculate total prices
		e) Clear all items and prices
		f) Back to main menu
		e) Quit Program
	
	2) Time management Calc 
		a) Show all Activities and time
		b) Add activity and time
		c) show all activities and total time
		d) clear all
		e) back to main menu
		f) Quit Program
	
	3) Music Theory
		a) Show all Major Scales
		b) Show all minor Scales
		c) Test on major scales
		d) Test on minor scales
		f) Back to main menu
		g) Quit Program

*/