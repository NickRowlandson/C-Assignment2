#include "Header.h"

// HIGHSCOREMANAGER CLASS METHODS
void HighScoreManager::CreateHighScore() {
	//FUNCTION NOT REQUIRED
}

void HighScoreManager::UpdateHighScore() {
	//FUNCTION NOT REQUIRED
}


void HighScoreManager::PrintHighScore() {

	// LOOP THROUGH DAT FILE AND PRINT TABLE OF HIGH SCORES
}

// USER CLASS METHODS
void User::Login() {
	// FUNCTION NOT REQUIRED
}

bool User::CheckIfUserExist(string username) {
	currentUser = username;
	bool userFound = false;
	bool endLoop = true;
	ifstream file("names.txt");
	string name;

	// loop through names.txt
	while (getline(file, name) && endLoop)
	{
		// if there is already user in names.txt, display previous score and set oldScore global variable
		if (name.find(username) != string::npos)
		{
			userFound = true;
			endLoop = false;
		}
	}

	// if no user is found, display welcome message and return false
	if (!userFound)
	{
		return false;
	}
	// if user found, display welcome back message and return true
	else 
	{
		return true;
	}
}

void User::UpdateUserList(string user) {
	// clear elements in vector
	lines.clear();
	// open file stream
	ifstream file("names.txt");

	string line;
	// add each line in names.txt to the vector
	while (getline(file, line))
	{
		if (!line.empty())
		{
			lines.push_back(line);
		}
	}
}

void User::DeleteUser(string user) {

}

void User::SetHighScore(string user) {
	int newScore;
	cout << endl << "Enter your new high score: ";
	cin >> newScore;
	// UPDATE TXT AND DAT FILE WITH NEW HIGH SCORE HERE.
}


// MAIN
int main(){
	User user1;
	HighScoreManager score1;
	string user;
	int selection;
	bool cont;
	cout << "WELCOME TO: High Score Manager!" << endl
	<< "Enter your username: ";
	cin >> user;
	cin.ignore();

	if(!user1.CheckIfUserExist(user))
	{
		ofstream out;
		// append new user name and empty score to names.txt
		out.open("names.txt", ios::app);

		out << endl << user;
		out << endl << "$" << 0;
		out << endl << "#";

		cout << "Welcome, " + currentUser + "!" << endl;
	}
	else 
	{
		cout << "Welcome back, " + currentUser + "!" << endl;
	}

	while (cont)
	{
		cout << endl << "Menu" << endl
			<< "1. Enter your new high score" << endl
			<< "2. Update your information" << endl
			<< "3. Delete information" << endl
			<< "4. Print all high scores" << endl
			<< "5. Exit" << endl
			<< "Enter your selection number: ";
		cin >> selection;

		if (selection == 1) {
			user1.SetHighScore(user);
			cont = true;
			cout << "HIGH SCORE UPDATED" << endl;
		}
		else if (selection == 2) {
			user1.UpdateUserList(user);
			cont = true;
			cout << "USER UPDATED" << endl;
		}
		else if (selection == 3) {
			user1.DeleteUser(user);
			cont = false;
			cout << "USER DELETED: Terminating Session" << endl;
		}
		else if (selection == 4) {
			score1.PrintHighScore();
			cont = true;
		}
		else if (selection == 5) {
			cout << "Thank you for using High Score Manager.";
			cont = false;
		}
		else {
			cout << "ERROR! Invalid Selection";
			cont = true;
		}
	} //ENDWHILE
	
};

