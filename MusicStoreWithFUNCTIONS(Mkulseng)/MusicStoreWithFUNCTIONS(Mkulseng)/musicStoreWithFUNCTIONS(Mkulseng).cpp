// This is the individual version of group lab #2
// This is the Music Store with Functions lab
// by Marisha Kulseng
// last modified 10/30/2018 at 11:30 pm


#include <iostream>
#include <iomanip>
using namespace std;

// function declarations
void printBanner();
void printMenu();
void formatOutput();
void printInfo(char, double, double, int);
void showSurchargeMessage(double, double, int);
void assignPackageVariables(char, double&, double&, int&);
void finalBill(double, double);
void clearPackageVariables(double&, double&, int&);
bool isABC(char);
bool isInt(double);
bool isPositive(double);
bool isExceeded(double, int);
char getValidPackage();
int getPosInt();
double calcSongSurcharge(int, double, double);
double getNum();

// global constants
const double
SALES_TAX = 0.06,
A_BASE_PRICE = 4.99,
A_SONG_SURCHARGE = 0.99,
B_BASE_PRICE = 9.99,
B_SONG_SURCHARGE = 0.59,
C_BASE_PRICE = 14.99,
C_SONG_SURCHARGE = 0.29;

const int
A_FREE_SONGS = 10,
B_FREE_SONGS = 20,
C_FREE_SONGS = 30;


int main()
{
	// system setup
	system("color 57");
	system("title .  Music Store with Functions       by M. Kulseng");

	// declare variables 
	double songSurcharge = 0, numDownloadedSongs = 0.0, basePrice = 0;
	int freeSongs = 0;
	char packageSelection;

	// wysiwyg banner
	printBanner();


	while (true)
	{
		formatOutput();

		// prompt/menu
		printMenu();

		cout << "\n Please select the option package that you have? ";
		packageSelection = getValidPackage();

		// assigns values to basePrice, songSurcharge, and freeSongs based on package selection
		assignPackageVariables(packageSelection, basePrice, songSurcharge, freeSongs);

		cout << " How many songs did you download this month? ";
		numDownloadedSongs = getPosInt();

		songSurcharge = calcSongSurcharge(freeSongs, numDownloadedSongs, songSurcharge);

		finalBill(basePrice, songSurcharge);
		showSurchargeMessage(songSurcharge, numDownloadedSongs, freeSongs);

		clearPackageVariables(basePrice, songSurcharge, freeSongs);

		// THIS IS DESIGNED TO TEST THE getNum FUNCTION 
		/*cout << "\n\n\n ***Number test***\n\tEnter a number: ";
		getNum(); */

		cout << "\n\n";
		system("pause");
		cout << "\n\n         **************************************************\n\n";
	}
	return 0;
}


// function definitions 



// banner function
void printBanner()
{
	cout << "\n"
		<< "                           Group FUNCTIONS Lab                            \n"
		<< "                            Online music store                            \n"
		<< "                    revisits the switch case group lab                    \n"
		<< "                   but divides each task into a function                  \n"
		<< "                               by M. Kulseng                              \n\n\n";
}

// prints menu/info for the packages
void printMenu()
{
	cout << "Here are the possible option packages offered in our store: \n";
	printInfo('A', A_BASE_PRICE, A_SONG_SURCHARGE, A_FREE_SONGS);
	printInfo('B', B_BASE_PRICE, B_SONG_SURCHARGE, B_FREE_SONGS);
	printInfo('C', C_BASE_PRICE, C_SONG_SURCHARGE, C_FREE_SONGS);
}


// check to see if it's char A, B, or C
bool isABC(char ch)
{
	// cout << "this is the abc fctn: " << ((ch >= 'A' && ch <= 'C') || (ch >= 'a' && ch <= 'c') ? true : false);
	// comment in/out the above statement to test truth value in this function

	return ((ch >= 'A' && ch <= 'C') || (ch >= 'a' && ch <= 'c') ? true : false);
}


// character input validation function
char getValidPackage()
{
	cin >> ws;
	char ch = cin.get();
	cin.ignore(120, '\n');

	while (!isABC(ch))
	{
		cout << "\n\t***Sorry we do not offer that package! \n"
			<< "\n\n     **************************************************\n\n";
		printMenu();
		cout << "\n Please select the option package that you have? ";
		cin >> ws;
		ch = cin.get();
		cin.ignore(120, '\n');
		// cout<< " this is the get pkg fctn: " << isABC(ch); // comment this in/out to test the truth value in fctn
	}
	// cout << isABC(ch); // comment this in/out to test this function to ensure it is working properly
	return ch;
}

// int validation
bool isInt(double value1)
{
	return (static_cast<int>(value1) == value1 ? true : false);
}

// positive validation
bool isPositive(double value1)
{
	return (value1 < 0 ? false : true);
}


// positive int validation 
int getPosInt()
{
	double value1 = getNum();

	while (!isInt(value1) || !isPositive(value1))
	{
		cout << "\n\t***That is an incorrect number!\n\t   The number must be a"
			<< (isPositive(value1) ? "" : " POSITIVE")
			<< (isInt(value1) ? "" : " WHOLE")
			<< " number.\n\t Please try again: ";
		value1 = getNum();
	}
	// cout << isInt(value1) << " " << isPositive(value1); // statement to test truth values
	return value1;
}


// function that prints info about a specific package
void printInfo(char ch, double basePrice, double songSurcharge, int freeSongs)
{
	cout << "  Package " << ch << ": Monthly fee $  " << setw(5) << basePrice << ". " << freeSongs
		<< " free songs and $" << songSurcharge << " per song after that. \n";
}

// function to format output
void formatOutput()
{
	cout << fixed << setprecision(2) << showpoint;
}


// function to PERMANENTLY assign variables based on package chosen
void assignPackageVariables(char packageSelection, double &basePrice, double &songSurcharge, int &freeSongs)
{
	switch (packageSelection)
	{
	case 'a':
	case 'A':
		basePrice = A_BASE_PRICE;
		songSurcharge = A_SONG_SURCHARGE;
		freeSongs = A_FREE_SONGS;
		break;
	case 'b':
	case 'B':
		basePrice = B_BASE_PRICE;
		songSurcharge = B_SONG_SURCHARGE;
		freeSongs = B_FREE_SONGS;
		break;
	case 'c':
	case 'C':
		basePrice = C_BASE_PRICE;
		songSurcharge = C_SONG_SURCHARGE;
		freeSongs = C_FREE_SONGS;
		break;
	}
}


// function to check if number of downloaded songs exceeds free songs
bool isExceeded(double numDownloadedSongs, int freeSongs)
{
	return (numDownloadedSongs > freeSongs ? true : false);
}

// function to calculate the surcharge for any extra songs downloaded
double calcSongSurcharge(int freeSongs, double numDownloadedSongs, double songSurcharge)
{
	return songSurcharge *= (isExceeded(numDownloadedSongs, freeSongs) ? (numDownloadedSongs - freeSongs) : 0);
}

// function to print song surcharge message
void showSurchargeMessage(double songSurcharge, double numDownloadedSongs, int freeSongs)
{
	if (isExceeded(numDownloadedSongs, freeSongs))
	{
		cout << "\tYou have $" << songSurcharge << " extra charges for having "
			<< static_cast<int>(numDownloadedSongs - freeSongs)
			<< " more song" << ((numDownloadedSongs - freeSongs) > 1 ? "s" : "")
			<< " \n\tthan your monthly limit of " << freeSongs << " free songs.\n";
	}
}

// function to print default billing information output
void finalBill(double basePrice, double songSurcharge)
{
	cout << "\n\nYour total bill for this month is $" << basePrice + songSurcharge << " + "
		<< (basePrice + songSurcharge) * SALES_TAX
		<< " (for tax) = " << (basePrice + songSurcharge) + (basePrice + songSurcharge) * SALES_TAX << ".\n";
}


// function to clear the variables stored in the package variables so we start fresh with the next iteration
void clearPackageVariables(double &basePrice, double &songSurcharge, int &freeSongs)
{
	basePrice = 0;
	songSurcharge = 0;
	freeSongs = 0;
}

// is it a number test **EXTRA**
double getNum()
{
	double number;
	while (!(cin >> number))
	{
		cin.clear();
		cin.ignore(120, '\n');
		cout << "\n\t***Error! You must enter a NUMBER; characters are not allowed. \n"
			<< "\t Please enter a NUMBER: ";
	}
	return number;
}