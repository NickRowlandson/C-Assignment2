#include "Header.h"

// HIGHSCOREMANAGER CLASS METHODS
void HighScoreManager::CreateHighScore() {

}

void HighScoreManager::UpdateHighScore() {

}


void HighScoreManager::PrintHighScore() {

}

// USER CLASS METHODS
void User::Login() {

}

bool User::CheckIfUserExist(string username) {
	currentUser = username;
	bool userFound = false;
	bool endLoop = true;

	// write questions from quiz.txt
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

	// if no user is found, append new user to names.txt
	if (!userFound)
	{
		cout << "Welcome, " + currentUser + "!" << endl;
		return false;
	}
	else {
		cout << "Welcome back, " + currentUser + "!" << endl;
		return true;
	}
}

void User::UpdateUserList() {
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

void User::DeleteUser() {

}

void User::SetHighScore() {

}


// MAIN
int main(){
	User user1;
	string user;
	int selection;
	bool cont;
	cout << "WELCOME TO: High Score Manager!" << endl;
	cout << "Enter your username: ";
	cin >> user;

	if(user1.CheckIfUserExist(user))
	{
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

			if (selection == 1){

				cont = false;
			}
			else if (selection == 2){

				cont = false;
			}
			else if (selection == 3){

				cont = false;
			}
			else if (selection == 4){

				cont = false;
			}
			else if (selection == 5){

				cont = false;
			}
			else{
				cout << "ERROR! Invalid Selection";
				cont = true;
			}
		} //ENDWHILE
	}
	else
	{
		ofstream out;
		// append new user name and empty score to names.txt
		out.open("names.txt", ios::app);

		out << endl << user;
		out << endl << "$" << 0;
		out << endl << "#";
	}
	
};

