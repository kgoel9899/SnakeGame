#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main() {
	vector<int> snakex = { 10, 11, 12, 13 };
	vector<int> snakey = { 5, 5, 5, 5 };
	int sx = 10, sy = 10;
	char dir = 'R';
	int c = 0;
	int x = 1, y = 0;
	int fx = 20;
	int fy = 10;
	int fruit = 1;
	int score = 0;
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
		if (fruit == 0) {
			fx = rand() % 51 + 1;
			fy = rand() % 24 + 1;
			fruit = 1;
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
					int done = 0;
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
		int flag = 1;
		if (_kbhit()) {
			c = _getch();
			c = _getch();

			switch (c) {
			case 72:
				if (dir == 'D') {
					flag = 0;
					break;
				}
				y = -1;
				x = 0;
				sy--;
				dir = 'U';
				break;
			case 80:
				if (dir == 'U') {
					flag = 0;
					break;
				}
				y = 1;
				x = 0;
				sy++;
				dir = 'D';
				break;
			case 77:
				if (dir == 'L') {
					flag = 0;
					break;
				}
				x = 1;
				y = 0;
				sx++;
				dir = 'R';
				break;
			case 75:
				if (dir == 'R') {
					flag = 0;
					break;
				}
				x = -1;
				y = 0;
				sx--;
				dir = 'L';
				break;
			default: flag = 0;
			}
		}
		else {
			flag = 0;
		}
		int savex = snakex[0];
		int savey = snakey[0];
		for (int i = 0; i < snakex.size() - 1; i++) {
			snakex[i] = snakex[i + 1];
			snakey[i] = snakey[i + 1];
		}
		snakex[snakex.size() - 1] += x;
		snakey[snakex.size() - 1] += y;
		if (snakex[snakex.size() - 2] == 50 || snakex[snakex.size() - 2] == -1 || snakey[snakex.size() - 2] == -1 || snakey[snakex.size() - 2] == 25) {
			break;
		}
		if (snakex[snakex.size() - 1] == fx && snakey[snakey.size() - 1] == fy) {
			fruit = 0;
			snakex.insert(snakex.begin(), savex);
			snakey.insert(snakey.begin(), savey);
			score += 1;
		}
	}
	return 0;
}
