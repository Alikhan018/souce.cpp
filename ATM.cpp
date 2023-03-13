#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
char printIntroMenu(char& startupmain);
char printMainMenu(char& MainMenuMain);
int start(char& startupmain);
int participate();
float request(float& userbalance);
float transfer(float& userbalance);
float withdraw(float& userbalance);
int quit(int count);
int login(int idmain, int passwordmain, string bankcodemain);
int main()
{
	char startupmain, MainMenuMain;
	int idmain, passwordmain, check, count = 0;
	string bankcodemain;
	float userbalance = 20;
	int check2 = 0;
	do
	{
		start(startupmain);
		if (startupmain == 'l' || startupmain == 'L')
		{
			cout << "Please enter your user id: ";
			cin >> idmain;
			cout << "Please enter your password: ";
			cin >> passwordmain;
			cout << "Please enter your bank code: ";
			cin >> bankcodemain;
			check = login(idmain, passwordmain, bankcodemain);
			if (check == 1)
			{
				cout << "Access Granted!\n";
				do {
					printMainMenu(MainMenuMain);
					if (MainMenuMain == 'P' || MainMenuMain=='p')
					{
						if (userbalance >= 10)
						{
							cout << "Enter any number : ";
							participate();
							if (check2 == 1)
							{
								cout << "Number matched the lucky draw number. 10$ have been added to your account.\n";
								userbalance += 10;
							}
							else
							{
								cout << "The number did not match the lucky draw number. 5$ have been deducted from your account.\n";
								userbalance -= 5;
							}
						}
						else
						{
							cout << "Your balance is insufficient\n";
						}
						count++;

					}
					else if (MainMenuMain == 'r' || MainMenuMain=='R')
					{
						cout << request(userbalance) << "$" <<endl;
						count++;
					}
					else if (MainMenuMain == 't' || MainMenuMain=='T')
					{
						if (userbalance >= 0)
						{
							transfer(userbalance);
							cout << endl;
						}
						else
						{
							cout << "Insufficient Balance\n";
						}
						count++;
					}
					else if (MainMenuMain == 'w' || MainMenuMain=='W')
					{
						if (userbalance >= 0)
						{
							withdraw(userbalance);
							cout << endl;
						}
						else
						{
							cout << "Insufficient Balance\n";
						}
						count++;
					}
					else if (MainMenuMain == 'q' || MainMenuMain=='Q')
					{
						quit(count);
						break;
					}
					else
					{
						cout << "Invalid choice. Select the correct option: \n";
					}

				} while (1);
				break;
			}
			else
			{
				cout << "******** LOGIN FAILED! ********\n";
			}
		}
		else if (startupmain == 'q' || startupmain=='Q')
		{
			cout << "thank you!\n";
			break;
		}
		else
		{
			cout << "Invalid Input";
		}
	} while (1);
}

char printIntroMenu(char& startup)
{
	cout << "l-> login\nq-> quit\n";
	cin >> startup;
	return startup;
}
int login(int idmain, int passwordmain, string bankcodemain)
{
	if (idmain == 12 && passwordmain == 2345 && bankcodemain == "0023")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
char printMainMenu(char& MainMenuMain)
{
	cout << " P-> Participate\n t->Transfer\n r->Request\n w->withdraw\n q-> Quit\n";
	cin >> MainMenuMain;
	return MainMenuMain;
}
int participate()
{
	int randomnumber = rand() % 200;
	int usernumber;
	cin >> usernumber;
	if (usernumber == randomnumber)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
float request(float& userbalance)
{
	return userbalance;
}
float transfer(float& userbalance)
{
	float tbalance;
	cout << "Enter the amount to transfer: ";
	cin >> tbalance;
	if (userbalance - tbalance >= 0)
	{
		userbalance = userbalance - tbalance;
		cout << tbalance << "$ transfered successfully\n";
	}
	else
	{
		cout << "transfer failed\n";
	}
	return tbalance;
}
float withdraw(float& userbalance)
{
	float wd;
	cout << "Enter the amount to withdraw: ";
	cin >> wd;
	if (userbalance - wd >= 0)
	{
		userbalance = userbalance - wd;
		cout << "Amount Withdrawed is " << wd << "$\n";
	}
	else
	{
		cout << "withdraw failed\n";
	}
	return userbalance;
}
int start(char& startupmain)
{
	cout << "Please select an option from the menu below : \n";
	printIntroMenu(startupmain);
	return 0;
}
int quit(int count)
{
	cout << "thank you!\n";
	count++;
	cout << "Number of requests made = " << count << endl;
	return count;	
}
