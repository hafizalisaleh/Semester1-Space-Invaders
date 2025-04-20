#include "mygraphics.h"
#include "myconsole.h"
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
void maximizeWindow() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
int main() {
	bool o = true;
	int color[5][11];
	int xi[5][11], xf[5][11], yi[5][11], yf[5][11];  //delaration of arrays having coordinats of enemies
	int x1, x2, y1, y2,c=0, w, h, k, q, p, t=1, count, count2, m=1, s=1, bcol, bx1, by1, bx2, by2, b, scr, count3, lx1, lx2, ly1, ly2, r, lives;
	int ebx1, ebx2, eby1, eby2, rnd, ebcol, ef, e;
	maximizeWindow();
	GetWindowDimensions(w, h);
	system("cls");
	x1 = w - w / 2; x2 = x1 + 40; y1 = h - 45; y2 = h - 25; k = 0; q = 30; p = 2; t = 15, m = 30, count3 = 1, lx1 = 10, lx2 = w - 10, ly1 = 10, ly2 = h - 20, lives = 3;
	b = 20, bx1 = (x1 + x2) / 2, bx2 = bx1; by2 = y1 + 10; by1 = y1, bcol = 255, scr = 0;
	ebcol = 255, rnd = 0, ef = 0, e = 10;
	for (count = 0; count < 5; count++) {
		for (count2 = 0; count2 < 11; count2++) {
			xi[count][count2] = q; yi[count][count2] = m;    //coordinates are assigned to the array
			xf[count][count2] = xi[count][count2] + 30;
			yf[count][count2] = yi[count][count2] + 40;
			q += 70;
		}
		q = 30; m += 50;
	}

	for (count = 0; count < 5; count++) {
		for (count2 = 0; count2 < 11; count2++) {				//assigning color to the enenies
			color[count][count2] = 255;
		}
	}
	while (o) {
		if (count3 % 20 == 0) {
			myLine(lx1, ly1, lx1, ly2, (255, 255, 255));
			myLine(lx1, ly2, lx2, ly2, (255, 255, 255));		//drawing border lines
			myLine(lx1, ly1, lx2, ly1, (255, 255, 255));
			myLine(lx2, ly1, lx2, ly2, (255, 255, 255));
			myRect(x1 += k, y1, x2 += k, y2, ( 14, 255, 255), (150, 150, 150));
			for (count = 0; count < 5; count++) {
				for (count2 = 0; count2 < 11; count2++) {
					myRect(xi[count][count2] += p, yi[count][count2], xf[count][count2] += p, yf[count][count2], (color[count][count2], 210, 240), (200, 200, 200));
				}
			}
			if (xf[1][10] >= lx2 - 10 || xi[1][0] <= 20) {
				for (count = 0; count < 5; count++) {
					for (count2 = 0; count2 < 11; count2++) {              //Increment in Y of the aleins
						yi[count][count2] += t;
						yf[count][count2] += t;
					}
					p *= -1;
				}
			}
			if (count3 % 20 == 0) {							//Enemy fire
				while (ef == 0) {
					rnd = (rand() % 10);
					if (color[4][rnd] == 255) {
						ef = 1;
						ebx1 = (xi[4][rnd] + xf[4][rnd]) / 2; ebx2 = ebx1; eby2 = yf[4][rnd]; eby1 = eby2 - 10;
					}
					myLine(bx1, by1 -= b, bx2, by2 -= b, (210, bcol, 210));
				}
				if (ef == 1) {

					myLine(ebx1,  eby1 += e, ebx2, eby2 += e, (ebcol, 50, 52));
				}
				if (ebx2 >= x1 && ebx2 <= x2 && eby2 >= y1 && eby2 <= y2 && ebcol == 255) {
					lives--;
					ebx1 = (xi[4][rnd] + xf[4][rnd]) / 2; 
					ebx2 = ebx1;
					eby2 = yf[4][rnd];
					eby1 = eby2 - 10;
				}
				if (s == 1) {										//player fire
					bcol = 255;
					myLine(bx1, by1 -= b, bx2, by2 -= b, (210, bcol,210 ));
				}
				if (eby1 > h) {									//reinitializing enemy fire 
					ef = 0;
				}
				if (bcol == 0) {
					bx1 += k;
					bx2 += k;
				}
				if (by1 == 100) {					//reinitializing player fire
					bcol = 0;
					s = 0;
					bcol = 0;
					bx1 = (x1 + x2) / 2;
					bx2 = bx1;
					by2 = y1;
					by1 = y1 - 10;
				}
				for (count = 0; count < 5; count++) {						//Collision detection
					for (count2 = 0; count2 < 11; count2++) {
						if (bx1 >= xi[count][count2] && bx1 <= xf[count][count2] && by1 <= yf[count][count2] && by1 >= yi[count][count2] && color[count][count2] == 255) {
							color[count][count2] = 0;
							s = 0;
							bcol = 0;
							bx1 = (x1 + x2) / 2;
							bx2 = bx1;
							by2 = y1;
							by1 = y1 - 10;
							scr = scr + 100;
						}
					}
				}
				PlaceCursor(0,0);
				cout << " Score: " << scr << "    Lives: " << lives;              //Score and lives output
				if (by1 <= 30) {
					s = 0;
					bx1 = (x1 + x2) / 2; bx2 = bx1; by2 = y1; by1 = y1 - 10;
				}
				if (lives == 0) { o = false; }
				//delay(15);
				for (count = 0; count < 5; count++) {
					for (count2 = 0; count2 < 11; count2++) {										//Player lost
						if (yf[count][count2] >= h - 50 && color[count][count2] == 255) {
							o = false;
						}
					}
				}
				ClearScreen();
			    k = 0 ;
			}
		}
		count3++;
		if (_kbhit())						//Button press control
			c = _getch();
		if (c == 'p') {
			char yn;
			PlaceCursor(10,50);
            cout<< "game paused, do you want to continue? y/n"; 
            cin>> yn;
            if (yn=='y')
            o=true;
            else if (yn=='n')
            break;
		}
		if (c == 'a') {
			myRect(x1 += k, y1, x2 += k, y2, ( 12,12,12), (12,12,12));
			k = -20;
		}
		if (c == 'd') {
			myRect(x1 += k, y1, x2 += k, y2, ( 12,12,12), (12,12,12));
			k = 20;
		}
		if (c == 'w'){
			myRect(x1 += k, y1, x2 += k, y2, ( 12,12,12), (12,12,12));
			y1=y1-20;
			y2=y2-20;
		}
		if (c == 's'){
			myRect(x1 += k, y1, x2 += k, y2, ( 12,12,12), (12,12,12));
			y1=y1+20;
			y2=y2+20;
		}
		if (c == ' ') {
			s = 1;
			bx1 = (x1 + x2) / 2; bx2 = bx1; by2 = y1; by1 = y1 - 10;
		}
		c = '\0';
		r = 0;
		for (count = 0; count < 5; count++) {
			for (count2 = 0; count2 < 11; count2++) {
				if (color[count][count2] == 0) { r++; }					//win or lose 
				if (r == 55) { o = false; }
			}
		}
}
	system("cls");

	PlaceCursor(10, 50);
	if (r < 50) { cout << "You lost    Score: " << scr; }
	else { cout << "You win "; }
	c = _getch();
	if (c == 'q') {
		return 0;
	}
	ofstream high;
	high.open("savescore.txt",ios::out | ios::app);
	high << scr << endl;
	high.close();
	system("pause");
	return 0;
}