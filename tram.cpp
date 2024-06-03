#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <vector>

using namespace std;


//funtion prototypes	
void genCard();
void topUp();
void operation(); 
void cardIdCheck(char& , int& );
void checkBalance();
void adminPanel();
void countCards();
void adminOptions();
void incomeCalc();
void peopleDetail();
char isEqual(char[]);
bool entryCheck(const string&, char);


//global variables
const int MAX = 9999;
int numF{ 0 };
int numLS{ 0 };
int numL{ 0 };
char Exit = 'a';
char chk = 'k';

class card {   //base class , abstract class

protected:
	string fName;
	string lName;
	int age;
	int date;
	int month;
	int year;
	char id[10];

public:

	card(): fName(""), lName(""), age(0), date(0), month(0), year(0000) {} //default constructor

	void getData() {
		bool chk;
		bool chk1;
		bool chk2;

		do {
			cout << "\nEnter your First and Last name: ";
			cin >> fName >> lName;
			chk = entryCheck(fName, 'n');
			chk1 = entryCheck(lName, 'n');

			if (chk == true || chk1 == true) {
				cout << "Name must not have digits!\n" << endl;
			}
		} while (chk == true || chk1 == true);
				
		
		do {
			string entry;
			cout << "Enter your Age: ";
			cin >> entry;
			chk2 = entryCheck(entry, 'a');

			if (chk2 == true) {
				cout << "The Age must be in digits!\n" << endl;
			}
			else {
				age = stoi(entry);
			}
		} while (chk2 == true);
		
		do {
			string entryD, entryM, entryY;
			cout << "Enter your Date of Birth (eg. 12 03 2000): ";
			cin >> entryD >> entryM >> entryY;

			chk= entryCheck(entryD, 'a');
			chk1 = entryCheck(entryM, 'a');
			chk2 = entryCheck(entryY, 'a');

			if (chk == true || chk1 == true || chk2 == true) {
				cout << "\nError! It must contain digits only" << endl;
			}
			else {
				date = stoi(entryD);
				month = stoi(entryM);
				year = stoi(entryY);
			}

			if ((date < 0 || date > 31) || (month < 0 || month > 12) || (year < 0 || year > 2024 || (year != 2024-age && month<8))) {
				cout << "\nInvalid Date of Birth entered. Try again." << endl;
			}

		} while ((date < 0 || date > 31) || (month < 0 || month > 12) || (year < 0 || year > 2024 || (year != 2024 - age && month < 8)) || (chk == true || chk1 == true || chk2 == true) );
	}

	void showInfo() {
		cout << "\nYour Personal Information registered on this card is: " << endl;
		cout << "\nName: " << fName << " " << lName << endl;
		cout << "Age: " << age << endl;
		printf("Date of Birth: %02d/%02d/%4d", date, month, year);
		cout << endl;

	}

	
};


class payment {

protected:
	int amount;
	int balance;
	char userAns;
	int cardForPrice;
	int cardLocStdPrice;
	int cardLocPrice;
	char cardId[12];

public:
	payment(): amount(0), balance(0), userAns('a'), cardForPrice(500), cardLocStdPrice(250), cardLocPrice(350) {}

	void guidelines() {

		cout << "\n\nMoving to next step...\n" << endl;
		cout << "Please insert Money in the slot given." << endl;
		cout << "Insert only Bank note." << endl;
		cout << "The machine does not return any change" << endl;

	}

	void cardPayment(char type) {
		string entry;
		bool chk;
		char retry;

		do {
			do {
				cout << "Enter the amount to pay: "; cin >> entry; //gets the amount to be entered

				chk = entryCheck(entry, 'a'); //checks for non-numeric entry
				if (chk == true) {
					cout << "\nError! Wrong entry" << endl;
				}
				else {
					amount = stoi(entry);
				}
			} while (chk == true);

			if (type == 'F') {  //balance assigned to given card type
				balance = amount - cardForPrice;
			}
			else if (type == 'S') {
				balance = amount - cardLocStdPrice;
			}
			else if (type == 'L') {
				balance = amount - cardLocPrice;
			}

			if (balance < 0) {

				cout << "\nThe amount entered is not sufficient. Please try Again!" << endl;
				retry = 'y';

			}
			else {
				retry = 'n';
				cout << "\nYour transaction is completed.\nCongratulations on having new KarachiKart.\n" << endl;
				cout << "You paid:         Rs. " << amount << endl;
				cout << "The Card Balance: Rs. " << balance << endl;
			}

		} while (retry == 'y');

	}

	int getBalance() {
		return balance;
	}
};

class topUp {
protected:
	int addAmount;
	string creditNo;
	string CVC;
	string exp;

public:

	topUp():addAmount(0), creditNo(""), CVC(""), exp("") {}

	void pay() {
		char retry;
		do {
			retry = 'n';
			cout << "\n\nHow much balance do you want to Top up?" << endl;
			string entry;
			cin >> entry;
			
			bool chk = entryCheck(entry, 'a');
			if (chk == true) {
				cout << "Error! Wrong Entry\n" << endl;
			}
			else {
				addAmount = stoi(entry);
			}
			if (addAmount < 1) {
				cout << "Insufficient amount entered" << endl;
				retry = 'r';
			}
		} while (chk == true || retry == 'r');
		
	}

	void getBankDetails() {
		bool ans;

		cout << "\nEnter Your Bank details: " << endl << endl;
		
		do {
			cout << "Enter your credit card number: "; cin >> creditNo;
			ans = entryCheck(creditNo, 'a');;

			if (ans == true) {
			cout << "\nIt must be digits only!\n " << endl;
			}
			else if (creditNo.length() != 16) {
				cout << "\nLength of Credit Card number must be of 16 digits!\n " << endl;
			}
			
		} while (creditNo.length() != 16 || ans == true);

		
		do {
			cout << "Enter CVC: "; cin >> CVC;
			ans = entryCheck(CVC, 'a');

			if (ans == true) {
			cout << "\nIt must be digits only!\n " << endl;
			}
			else if (CVC.length() != 3) {
				cout << "\nLength of CVC must be of 3 digits!\n " << endl;
			}
			
		} while (CVC.length() != 3 || ans == true);

		do {
			cout << "Enter the card's Expiry number: "; cin >> exp;
			ans = entryCheck(exp, 'a');

			if (ans == true) {
			cout << "\nIt must be digits only!\n " << endl;
			}
			else if (exp.length() != 4) {
				cout << "\nLength of Expiry Number must be of 4 digits!\n " << endl;
			}
			
		} while (exp.length() != 4 || ans == true);


	}
	
	void dispData() {
		cout << "\nYour bank Details are: " << endl;
		cout << "Credit Card Number: " << creditNo << endl;
		cout << "CVC: " << CVC << endl;
		cout << "Expiry Number: " << exp << endl;
	}
};




class cardForeign: private card, public payment, public topUp { //multiple inheritance; first child class

protected:
	string nationality;
	string ppNo;

public:
	
	cardForeign() : card(), payment(), topUp(), nationality(""), ppNo("") {}

	void getData();

	void displayData() {
		
		payment::guidelines();
		cout << "\nThe price of Foreign KarachiKart is: Rs." << cardForPrice << endl; //derived class can access protected data members of the base class
	}

	void generateId() { //get current year
		sprintf_s(cardId, "%dF-%04d", year+age, numF); //converting int into c-string
		cout << fName << " " << lName << " your Foreign KarachiKart id is: " << cardId << endl;// num used is 1 greater than the actual index
	}

	void showInfo() { //function overriding
		card::showInfo();
		cout << "Nationality: " << nationality << endl;
		cout << "Passport Number: " << ppNo << endl;
	}

	string getName() {
		return fName;
	}

	void addTopUp() {
		balance += addAmount;
	}

	friend ostream& operator << (ostream&, cardForeign&);

};

class cardLocStd : private card, public payment, public topUp { //multiple inheritance; second child class; for local student

protected:
	string institute;
	long int idNo;

public:

	cardLocStd() : card(), payment(), topUp(), institute(""), idNo(0) {}

	void getData();

	void displayData() {

		payment::guidelines();
		cout << "\nThe price of Student KarachiKart is: Rs." << cardLocStdPrice << endl;
	}
	
	void generateId() {
		
		sprintf_s(cardId, "%dLS-%04d", year+age, numLS);
		cout << fName << " " << lName << " your Student KarachiKart id is : " << cardId << endl;
	}

	void showInfo() { //function overriding
		card::showInfo();
		cout << "Educational Institute: " << institute << endl;
		cout << "ID Card Number: " << idNo << endl;
	}

	string getName() {
		return fName;
	}

	void addTopUp() {
		balance += addAmount;
	}

	friend ostream& operator << (ostream&, cardLocStd&);
};


class cardLoc : private card, public payment, public topUp { //multiple inheritance; third child class; for local non-student

protected:
	int idNo;

public:

	cardLoc(): card(), payment(), topUp(), idNo(0) {}

	void getData(); //function prototype

	void displayData() {
		payment::guidelines();
		cout << "\nThe price of Citizen KarachiKart is: Rs." << cardLocPrice << endl;
	}

	void generateId() {
		sprintf_s(cardId, "%dL-%04d", year+age, numL);
		cout << fName << " " << lName << " your Local KarachiKart id is: " << cardId << endl;
	}

	void showInfo() { //function overriding
		card::showInfo();
		cout << "ID Card Number: " << idNo << endl;	
	}

	string getName() {
		return fName;
	}

	void addTopUp() {
		balance += addAmount;
	}

	friend ostream& operator << (ostream&, cardLoc&);

};
//defining outside class through scope resolution operator


void cardForeign::getData() {
	bool chk1;

	card::getData();  // calling function member of base class
	do {
		cout << "Enter your Nationality: ";
		cin >> nationality;
		chk1 = entryCheck(nationality, 'n');
		
		if (chk1 == true) {
			cout << "Error!, Nationality must not contain digits\n" << endl;
		}
	} while (chk1 == true);

	
	cout << "Enter your Passport Number: ";
	cin >> ppNo;

}

void cardLocStd::getData() {
	bool chk1;
	string entry;
	card::getData();  // calling function member of base class
	
	do {
		cout << "Enter the name of your educational institute: ";
		cin >> institute;
		chk1 = entryCheck(institute, 'n');

		if (chk1 == true) {
			cout << "Error!, Institute name must not contain digits\n" << endl;
		}
	} while (chk1 == true);

	do {

		cout << "Enter your ID card number: ";
		cin >> entry;
		chk1 = entryCheck(entry, 'a');

		if (chk1 == true) {
			cout << "Error!, ID Number must contain digits only!\n" << endl;
		}
		else {
			idNo = stoi(entry);
		}
	} while (chk1 == true);


}

void cardLoc::getData() { 
	bool chk1;
	string entry;	
	card::getData();

	do {

		cout << "Enter your ID card number: ";
		cin >> entry;
		chk1 = entryCheck(entry, 'a');

		if (chk1 == true) {
			cout << "Error!, ID card number must contain digits only!\n" << endl;
		}
		else {
			idNo = stoi(entry);
		}
	} while (chk1 == true);

}

//friend function of cout operator overloading of all 3 derived classes

ostream& operator << (ostream& print, cardForeign &f1) {
	
	print << "\n\n\nKarachiKart Account Detail:\n " << endl;

	print << setw(12) << "Current Balance: " << setw(6) << "Rs." << f1.balance;
	print << setw(12) << "    Last TopUp: " << setw(6) << "Rs." << f1.addAmount;

	return print;
}

ostream& operator << (ostream& print, cardLocStd &s1) {

	print << "\n\n\nKarachiKart Account Detail:\n " << endl;

	print << setw(12) << "Current Balance: " << setw(6) << "Rs." << s1.balance;
	print << setw(12) << "    Last TopUp: " << setw(6) << "Rs." << s1.addAmount;

	return print;
}


ostream& operator << (ostream& print, cardLoc &l1) {

	print << "\n\n\nKarachiKart Account Detail:\n " << endl;

	print << setw(15) << "Current Balance: " << setw(10) << "Rs." << l1.balance;
	print << setw(15) << "   Last TopUp: " << setw(10) << "Rs." << l1.addAmount;

	return print;
}

cardForeign cardsFList[MAX]; //array of objects created to allow multiple entries of the same card type
cardLocStd cardsLSList[MAX];
cardLoc cardsLList[MAX];
payment p1;


int main() {
	
	operation();                                                                                                                     
}


bool entryCheck(const string& str, char type) {
	int numC{};
	int nNumC{};
	
	for (char const& c : str) {
		if (isdigit(c) == 0) {
			nNumC++;
		} //zero means char is not numeric
		else {
			numC++;
		}
	}
	if (type == 'n') {
		if (numC > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (nNumC > 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

void operation() {

	char yesNo = 'n';
	string userOption;
	string ans;

	do { //nested do-while 


	//selecting the operation to perform
		do {
			
			cout << "\nSelect an operation to perform: " << endl;
			cout << "1: Generate a new card" << endl;
			cout << "2: Top up" << endl;
			cout << "3: Check Balance" << endl;
			cout << "4: Open Admin Panel" << endl;
			cout << "5: Exit\n" << endl;
			cin >> ans;
			userOption = ans[0];

			if (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4" && userOption != "5" || ans.length() != 1) {  //error handling
				cout << "\nIncorrect entry, try again!" << endl;
				
			}
			
		} while (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4" && userOption != "5" || ans.length()!=1);
		
		int UserO;
		UserO = stoi(userOption); //converts string to int
		
		switch (UserO) {  //to lead to the program of the option selected
		case 1:
			genCard();
			if (Exit != 'e') {
				cout << "\n\nDo you want to perform another function? (y/n): "; cin >> yesNo;
			}	
			break;

		case 2:
			topUp();
			if (Exit != 'e') {
				cout << "\n\nDo you want to perform another function? (y/n): "; cin >> yesNo;
			}
			break;

		case 3:
			checkBalance();
			if (Exit != 'e') {
				cout << "\n\nDo you want to perform another function? (y/n): "; cin >> yesNo;
			}
			break;

		case 4:
			adminPanel();
			if (Exit != 'e') {
				cout << "\n\nDo you want to perform another function? (y/n): "; cin >> yesNo;
			}
			break;

		case 5:
			cout << "Have a Nice Day!" << endl;
			Exit = 'e';
			yesNo = 'n';
			break;
		}
	} while (yesNo == 'y'); //to allow multiple actions to be taken in one run

}

void genCard() {
	
	string uType;
	string userType;

	cout << "\nAre you a: \n1: Foreigner,\n2: Local Student,\n3: Non-Student Local.\n Choose the correct option.  ";
	cin >> uType;
	userType = uType;

	if (userType == "1") {
		cout << "\nEnter some necessary details:\n " << endl;
		cardsFList[numF].getData(); //obj of cardForeign, function called by object of child class. 
		cardsFList[numF].displayData();
		cardsFList[numF].cardPayment('F');
		cardsFList[numF++].generateId();
		
	}
	else if (userType == "2") {
		cout << "\nEnter some necessary details:\n " << endl;
		cardsLSList[numLS].getData();
		cardsLSList[numLS].displayData();
		cardsLSList[numLS].cardPayment('S');
		cardsLSList[numLS++].generateId();
	}
	else if (userType == "3") {
		cout << "\nEnter some necessary details:\n " << endl;
		cardsLList[numL].getData();
		cardsLList[numL].displayData();
		cardsLList[numL].cardPayment('L');
		cardsLList[numL++].generateId();
	}

	else {
		cout << "\nInvalid entry!, Try Again." << endl;
		genCard();  //call the function again to give user another try
	}
}


void topUp() {

	char type{ 'a' };
	int id{ 0 };
	string ans;
	string userOption;
	string uOption;
	int UserO;
	cardIdCheck(type, id);
	--id;

	do {
		cout << "\nWould you like to Top-up Online (1) or cash(2)? : "; cin >> ans;
		userOption = ans[0];
		
		UserO = stoi(userOption);
		switch (UserO) {
		
		case 1:

			
			if (type == 'F') {

				if ((cardsFList[id].getName()) != "") { //to check if id entered already exists or not
					cout << "ID Matched" << endl;
					cardsFList[id].showInfo();
					cardsFList[id].getBankDetails();
					cardsFList[id].dispData();
					cout << "\n\nProcessing Bank Details...";
					cout << cardsFList[id];
					cardsFList[id].pay();
					cardsFList[id].addTopUp();
					cout << cardsFList[id];
					}
				else {
					cout << "No card is issued on this Card ID." << endl;
					operation();
				}
				
			}

			else if (type == 'S') {
				if ((cardsLSList[id].getName()) != "") { //to check if id entered already exists or not
					cout << "ID Matched" << endl;
					cardsLSList[id].showInfo();
					cardsLSList[id].getBankDetails();
					cardsLSList[id].dispData();
					cout << "\n\nProcessing Bank Details...";
					cout << cardsLSList[id];
					cardsLSList[id].pay();
					cardsLSList[id].addTopUp();
					cout << "Transaction completed." << endl;
					cout << cardsLSList[id];
				}
				else {
					cout << "No card is issued on this Card ID." << endl;
					operation();
				}
			}
			
			else if (type == 'L') {
				if ((cardsLList[id].getName()) != "") { //to check if id entered already exists or not
					cout << "ID Matched" << endl;
					cardsLList[id].showInfo();
					cardsLList[id].getBankDetails();
					cardsLList[id].dispData();
					cout << "\n\nProcessing Bank Details...";
					cout << cardsLList[id];
					cardsLList[id].pay();
					cardsLList[id].addTopUp();
					cout << cardsLList[id];
				}
				else {
					cout << "No card is issued on this Card ID." << endl;
					operation();
				}
			}
			else {
				cout << "\nInvalid Card ID entered" << endl;
				operation();
			}
			break;

		case 2:
			if (type == 'F') {

				if ((cardsFList[id].getName()) != "") { //to check if id entered already exists or not
					cout << "ID Matched" << endl;
					cardsFList[id].showInfo();
					cout << "Kindly Enter the money in Bank Note only." << endl;
					cout << cardsFList[id];
					cardsFList[id].pay();
					cardsFList[id].addTopUp();
					cout << cardsFList[id];
				}
				else {
					cout << "No card is issued on this Card ID." << endl;
					operation();
				}

			}

			else if (type == 'S') {
				if ((cardsLSList[id].getName()) != "") { //to check if id entered already exists or not
					cout << "ID Matched" << endl;
					cardsLSList[id].showInfo();
					cout << "Kindly Enter the money in Bank Note only." << endl;
					cout << cardsLSList[id];
					cardsLSList[id].pay();
					cardsLSList[id].addTopUp();
					cout << "Transaction completed." << endl;
					cout << cardsLSList[id];
				}
				else {
					cout << "No card is issued on this Card ID." << endl;
					operation();
				}
			}

			else if (type == 'L') {
				if ((cardsLList[id].getName()) != "") { //to check if id entered already exists or not
					cout << "ID Matched" << endl;
					cardsLList[id].showInfo();
					cout << "Kindly Enter the money in Bank Note only." << endl;
					cout << cardsLList[id];
					cardsLList[id].pay();
					cardsLList[id].addTopUp();
					cout << cardsLList[id];
				}
				else {
					cout << "No card is issued on this Card ID." << endl;
					operation();
				}
			}
			else {
				cout << "\nInvalid Card ID entered" << endl;
				operation();
			}
			break;


		default:
			cout << "Incorrect entry. Try again!" << endl;
		}


	} while (UserO != 1 && UserO != 2);

}

void checkBalance() {
	char type{ 'a' };
	int id{ 0 };

	cardIdCheck(type, id);
	--id;

	switch (type) {
	case 'F':
		if ((cardsFList[id].getName()) != "") {
			cout << cardsFList[id]; //operator overloading
		}
		else {
			cout << "No card has been issued on this card ID" << endl;
			operation();
		}
		break;

	case 'S':
		if ((cardsLSList[id].getName()) != "") {
			cout << cardsLSList[id];
		}
		else {
			cout << "No card has been issued on this card ID" << endl;
			operation();
		}
		break;

	case 'L':
		if ((cardsLList[id].getName()) != "") {
			cout << cardsLList[id];
		}
		else {
			cout << "No card has been issued on this card ID" << endl;
			operation();
		}
		break;

	default:
		cout << "\nInvalid KarachiKart id" << endl;
	}
	
}

void cardIdCheck(char &t, int &I) {  //pass by reference
	
	char userId[13];
	int i{};
	int x{}, y{};
	
	cout << "\n\nEnter KarachiKart id: " << endl;
	cin >> userId;

	//if (sizeof(userId) > 11) {
	//	cout << "\nInvalid KarachiKart id" << endl; 
	//	topUp();
	//}

	for (i = 0; i < sizeof(userId); i++) {
		if (userId[i] == '-') {
			x = i - 1;
			y = i + 1;
			t = userId[x]; // for determining the type of card
			break;
		}
	}

	//for converting char id into int 
	int multiplier = 10000;
	for (int j = y; j < y + 4; j++) {
		multiplier = multiplier / 10;
		I += ((static_cast<int>(userId[j])) - 48) * multiplier; //for removing 0 before non zero number for accessign index
		
	}

}


char isEqual(char up[]) {
	string pw = "ahmed308";
	char eq1 = 'y';
	for (int y = 0; y < 8; y++) {
		if (up[y] != pw[y]) {
			eq1 = 'n';
			break;
		}

	}
	return eq1;
}

void adminPanel() {
	
	char upw[9];
	char eq;


	cout << "\n\nAccess allowed only to Admin." << endl;
	cout << "\nEnter the password" << endl;
	int i = 3;

	while (i > 0) {
		cout << "\nNumber of tries remaining: " << i << endl;
		int x = 0;
		while (x < 8) {
			upw[x] = _getch();
			if (upw[x] == '\r') {
				break;
			}
			cout << "*";
			x++;
		}
		eq = isEqual(upw);
		if (eq == 'n') {
			cout << "\nWrong Password!" << endl;
			i--;
		}
		else {
			cout << "\nCorrect Password!" << endl;
			break;
		}
	}

	if (eq == 'n') {
		cout << "\nAccess Denied" << endl;
	}
	else {
		cout << "\nAccess Granted" << endl;
		adminOptions();
	}

}

void adminOptions() {
	char yesNo = 'n';
	int adminAns;

	do { //nested do-while 


	//selecting the operation to perform
		do {
			cout << "\nSelect an admin operation to perform: " << endl;
			cout << "1: Check Number of Cards Issued." << endl;
			cout << "2: Total Money Earned. " << endl;
			cout << "3: Details of KarachiKart Buyers. " << endl;
			cout << "4: Exit\n" << endl;

			cin >> adminAns;

			if (adminAns != 1 && adminAns != 2 && adminAns != 3 && adminAns != 4) {  //error handling
				cout << "\nIncorrect entry, try again!" << endl;
			}

		} while (adminAns != 1 && adminAns != 2 && adminAns != 3 && adminAns != 4);

		switch (adminAns) {  //to lead to the program of the option selected
		case 1:
			countCards();
			if (Exit != 'e') {
				cout << "\n\nDo you want to perform another admin function? (y/n): "; cin >> yesNo;
			}
			break;

		case 2:
			incomeCalc();
			if (Exit != 'e') {
				cout << "\n\nDo you want to perform another admin function? (y/n): "; cin >> yesNo;
			}
			break;

		case 3:
			peopleDetail();

		case 4:
			cout << "Exited Admin panel" << endl;
			Exit = 'e';
			yesNo = 'n';
			break;
		}
	} while (yesNo == 'y'); //to allow multiple actions to be taken in one run

}


void countCards() {
	
	int countF = numF; //so that the global num is not affected
	int countLS = numLS;
	int countL = numL;
	int totalCount{};

	totalCount = numF + numLS + numL; //total number of cards issued

	cout << "\n\n";
	cout << "The Total number of KarachiKarts issued are         : " << totalCount << endl;
	cout << "Amongst it: " << endl << endl;
	cout << "The Total number of Foreign KarachiKarts issued are : " << countF << endl;
	cout << "The Total number of Student KarachiKarts issued are : " << countLS << endl;
	cout << "The Total number of Local KarachiKarts issued are   : " << countL << endl;
	

}

void incomeCalc() {

	int CF = numF - 1;
	int CLS = numLS - 1;
	int CL = numL - 1;
	int tot{};

	for (int i = 0; i <= CF; i++) {
		tot += cardsFList[i].getBalance();
	}

	for (int j = 0; j <= CLS; j++) {
		tot += cardsLSList[j].getBalance();
	}

	for (int k = 0; k <= CL; k++) {
		tot += cardsLList[k].getBalance();
	}
	
	int totC = (numF * 500) + (numLS * 250) + (numL * 350);

	cout << "\n\n";
	cout << "Total Amount of money earned through Top - up: Rs." << tot << endl;
	cout << "Total Amount earned through card issuance:     Rs. " << totC << endl;
}

void peopleDetail() {

	int CF = numF - 1;
	int CLS = numLS - 1;
	int CL = numL - 1;

	cout << "\n\nFollowing is the data of all the people who bought KarachiKart\n\n";
	cout << "Foreign KarachiKart\n\n";

	for (int i = 0; i <= CF; i++) {
		cout << " Person: " << i + 1 << endl;
		cardsFList[i].showInfo();
		cout << endl << endl;
	}

	cout << "Student KarachiKart\n\n";

	for (int j = 0; j <= CLS; j++) {
		cout << " Person: " << j + 1 << endl;
		cardsLSList[j].showInfo();
		cout << endl << endl;
	}

	cout << "Local KarachiKart\n\n";

	for (int k = 0; k <= CL; k++) {
		cout << " Person: " << k + 1 << endl;
		cardsLList[k].showInfo();
		cout << endl << endl;
	}

}