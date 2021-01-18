#include <windows.h>



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2,int color) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,2,RGB(color,color,color)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	

}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whickKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whickKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whickKey = 2;		// 2 if up key is pressed
		return true;
	}
	
	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whickKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whickKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(83);
	if (key == 1)
	{

		whickKey = 5;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(76);
	if (key == 1)
	{

		whickKey = 6;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{

		whickKey = 13;   // to break the LOOP
		return true;
	}
	return false;
}

void myRect(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR,FG,FB)); //Fill color is passed as parameter to the function!!!
	
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
		

}

// Function to get a ColorFilled Diamond in a Box
void myDiamondin(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R,G,B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);

	MoveToEx(device_context, (x1 + x2)/2, y1+3, NULL);
	LineTo(device_context, x2-3, (y1 + y2) / 2);
	LineTo(device_context, (x1 + x2)/2, y2-3);
	LineTo(device_context, x1+3, (y1 + y2) / 2);
	LineTo(device_context, (x1 + x2) / 2, y1+3);

	/*MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y1);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x1, y1);*/

	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2;
	FloodFill(device_context, mid, mid1, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	DeleteObject(FloodFill);
}
// Function to get a ColorFilled Triangle in a Box
void myTrianglein(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R,G,B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);

	MoveToEx(device_context, (x1 + x2) / 2, y1+5, NULL);
	LineTo(device_context, x2-5, y2-5);
	LineTo(device_context, x1+5, y2-5);
	LineTo(device_context, (x1 + x2) / 2, y1+5);

	/*MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y1);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x1, y1);*/

	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2;
	FloodFill(device_context, mid, mid1, RGB(R,G,B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	DeleteObject(FloodFill);
}
// Function to get a ColorFilled Circle in a Box
void myCircleIn(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);

	SelectObject(device_context, brush);
	Ellipse(device_context, x1+4, y1+4, x2-4, y2-4);

	/*MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y1);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x1, y1);*/

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myRectIn(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	/*Rectangle(device_context, x1+4, y1+4, x2-4, y2-4);*/

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}

void myCube(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	Rectangle(device_context, x1 +15, y1 + 15, x2 + 15, y2 + 15);

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myStar(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)// bhai star print karta hai
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);
	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2, mid3 = mid + (x2 - mid) / 2, mid4 = x1 + (mid - x1) / 2, mid5 = (y1 + mid1) / 2, mid6 = (y2 + mid1) / 2, mid7 = (mid6 + y2) / 2;
	MoveToEx(device_context, mid, y1, NULL);
	LineTo(device_context, mid3, mid1);
	LineTo(device_context, x2, mid1);
	LineTo(device_context, mid3, mid6);
	LineTo(device_context, x2, y2);
	LineTo(device_context, mid, mid7);
	LineTo(device_context, x1, y2);

	LineTo(device_context, mid4, mid6);
	LineTo(device_context, x1, mid1);
	LineTo(device_context, mid4, mid1);
	LineTo(device_context, mid, y1);
	FloodFill(device_context, mid, mid1, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	DeleteObject(FloodFill);

}
void myFRect(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myFEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}

// Function to get a ColorFilled Diamond in a Box
void myFDiamondin(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);

	MoveToEx(device_context, (x1 + x2) / 2, y1 + 3, NULL);
	LineTo(device_context, x2 - 3, (y1 + y2) / 2);
	LineTo(device_context, (x1 + x2) / 2, y2 - 3);
	LineTo(device_context, x1 + 3, (y1 + y2) / 2);
	LineTo(device_context, (x1 + x2) / 2, y1 + 3);

	/*MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y1);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x1, y1);*/

	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2;
	FloodFill(device_context, mid, mid1, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	DeleteObject(FloodFill);
}
// Function to get a ColorFilled Triangle in a Box
void myFTrianglein(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);

	MoveToEx(device_context, (x1 + x2) / 2, y1 + 5, NULL);
	LineTo(device_context, x2 - 5, y2 - 5);
	LineTo(device_context, x1 + 5, y2 - 5);
	LineTo(device_context, (x1 + x2) / 2, y1 + 5);

	/*MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y1);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x1, y1);*/

	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2;
	FloodFill(device_context, mid, mid1, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	DeleteObject(FloodFill);
}
void myFStar(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)// bhai star print karta hai
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));

	SelectObject(device_context, brush);
	int mid = (x1 + x2) / 2, mid1 = (y1 + y2) / 2, mid3 = mid + (x2 - mid) / 2, mid4 = x1 + (mid - x1) / 2, mid5 = (y1 + mid1) / 2, mid6 = (y2 + mid1) / 2, mid7 = (mid6 + y2) / 2;
	MoveToEx(device_context, mid, y1, NULL);
	LineTo(device_context, mid3, mid1);
	LineTo(device_context, x2, mid1);
	LineTo(device_context, mid3, mid6);
	LineTo(device_context, x2, y2);
	LineTo(device_context, mid, mid7);
	LineTo(device_context, x1, y2);

	LineTo(device_context, mid4, mid6);
	LineTo(device_context, x1, mid1);
	LineTo(device_context, mid4, mid1);
	LineTo(device_context, mid, y1);
	FloodFill(device_context, mid, mid1, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	DeleteObject(FloodFill);
}
void myFCircleIn(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);

	SelectObject(device_context, brush);
	Ellipse(device_context, x1 + 4, y1 + 4, x2 - 4, y2 - 4);

	/*MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y1);
	LineTo(device_context, x2, y2);
	LineTo(device_context, x1, y2);
	LineTo(device_context, x1, y1);*/

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myFRectIn(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 6, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	/*Rectangle(device_context, x1+4, y1+4, x2-4, y2-4);*/

	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}