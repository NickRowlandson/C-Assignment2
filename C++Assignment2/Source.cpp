#include "Header.h"

User user1;
HighScoreManager score1;

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
	string user;
	cout << "WELCOME TO: High Score Manager!" << endl
		<< "Enter your username: ";
	cin >> user;
	cin.ignore();

	if (!user1.CheckIfUserExist(user))
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

void User::UpdateUserVector() {
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
void HighScoreManager::UpdateScoreVector() {
	// clear elements in vector
	lines2.clear();
	// open file stream
	ifstream file("highScore.dat");

	string line2;
	// add each line in names.txt to the vector
	while (getline(file, line2))
	{
		if (!line2.empty())
		{
			lines2.push_back(line2);
		}
	}
}

void User::DeleteUser(string user) {
	user1.UpdateUserVector();
	//DELETE USER
}
void User::UpdateUserInfo(string user) {
	string name;
	user1.UpdateUserVector();
	cout << endl << "Enter you first and last name: ";
	cin >> name;
	// UPDATE name to new name
}

void User::SetHighScore(string user) {
	int newScore;

	user1.UpdateUserVector();
	score1.UpdateScoreVector();

	cout << endl << "Enter your new high score: ";
	cin >> newScore;
	// UPDATE TXT AND DAT FILE WITH NEW HIGH SCORE HERE.
}


// MAIN
int main(){
	int selection;
	bool cont = true;
	
	user1.Login();

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
			user1.SetHighScore(currentUser);
			cont = true;
			cout << "HIGH SCORE UPDATED" << endl;
		}
		else if (selection == 2) {
			user1.UpdateUserInfo(currentUser);
			cont = true;
			cout << "USER UPDATED" << endl;
		}
		else if (selection == 3) {
			user1.DeleteUser(currentUser);
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

