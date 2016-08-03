#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <regex>

using namespace std;
string currentUser;
vector<string> lines;

// HighScoreManager class
class HighScoreManager {
public:
	//HighScoreManager();
	void CreateHighScore();
	void UpdateHighScore();
	void PrintHighScore();

private:
	string username;
	int score;
	string date;
};

// User class
class User {
public:
	//User();
	void Login();
	bool CheckIfUserExist(string);
	void UpdateUserList(string);
	void DeleteUser(string);
	void SetHighScore(string);

private:
	string username;
	string firstNameLastName;
};

#endif