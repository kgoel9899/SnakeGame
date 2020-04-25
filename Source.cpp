#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
using namespace std;
//make the output window full screen
int main() {
	vector<int> snakex = { 10, 11, 12, 13 }, snakey = { 5, 5, 5, 5 };
	char dir = 'R';
	int c = 0, x = 1, y = 0, fx = 20, fy = 10, food = 1, score = 0, over = 0, done = 0;
	while (true) {
		Sleep(10);
		system("cls");
		for (int i = 0; i < 15; i++) {
			cout << " ";
		}
		cout << "WELCOME TO SNAKE GAME" << endl;
		for (int i = 0; i < 14; i++) {
			cout << " ";
		}
		cout << "Use arrow keys to play" << endl;
		if (food == 0) {
			fx = rand() % 51 + 1;
			fy = rand() % 24 + 1;
			food = 1;
		}
		for (int i = 0; i < 52; i++) {
			cout << "#";
		}
		cout << endl;
		for (int i = 0; i < 25; i++) {
			cout << "#";
			for (int j = 0; j < 50; j++) {
				if (i == fy && j == fx) cout << "F";
				else {
					done = 0;
					for (int k = 0; k < snakex.size(); k++) {
						if (i == snakey[k] && j == snakex[k]) {
							cout << 'O';
							done = 1;
							break;
						}
					}
					if (done == 0) cout << " ";
				}
			}
			cout << "#" << endl;
		}
		for (int i = 0; i < 52; i++) {
			cout << '#';
		}
		cout << endl;
		for (int i = 0; i < 20; i++) {
			cout << " ";
		}
		cout << "SCORE = " << score << endl;
		if (over == 1) break;
		if (_kbhit()) {
			c = _getch();
			c = _getch();
			if (c == 72) {
				if (dir != 'D') {
					y = -1;
					x = 0;
					dir = 'U';
				}
			}
			else if (c == 80) {
				if (dir != 'U') {
					y = 1;
					x = 0;
					dir = 'D';
				}
			}
			else if (c == 77) {
				if (dir != 'L') {
					x = 1;
					y = 0;
					dir = 'R';
				}
			}
			else if (c == 75) {
				if (dir != 'R') {
					x = -1;
					y = 0;
					dir = 'L';
				}
			}
		}
		int savex = snakex[0];
		int savey = snakey[0];
		for (int i = 0; i < snakex.size() - 1; i++) {
			snakex[i] = snakex[i + 1];
			snakey[i] = snakey[i + 1];
		}
		snakex[snakex.size() - 1] += x;
		snakey[snakex.size() - 1] += y;
		over = 0;
		if (snakex[snakex.size() - 2] == 50 || snakex[snakex.size() - 2] == -1 || snakey[snakex.size() - 2] == -1 || snakey[snakex.size() - 2] == 25) break;
		for (int i = 0; i < snakex.size() - 1; i++) {
			if (snakex[i] == snakex[snakex.size() - 1] && snakey[i] == snakey[snakex.size() - 1]) {
				over = 1;
				break;
			}
		}
		if (snakex[snakex.size() - 1] == fx && snakey[snakey.size() - 1] == fy) {
			food = 0;
			snakex.insert(snakex.begin(), savex);
			snakey.insert(snakey.begin(), savey);
			score += 1;
		}
	}
}