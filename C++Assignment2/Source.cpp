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
		cout << "Welcome, " + currentUser + "!" << endl;
		return false;
	}
	// if user found, display welcome back message and return true
	else 
	{
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
	cout << "WELCOME TO: High Score Manager!" << endl;
	cout << "Enter your username: ";
	cin >> user;

	if(user1.CheckIfUserExist(user)){

	}else{
		ofstream out;
		// append new user name and empty score to names.txt
		out.open("names.txt", ios::app);

		out << endl << user;
		out << endl << 0;
	}
	
};

