#include<graphics.h>//调用easyx函数库
#include<conio.h>//_getch()函数
#include<stdio.h>
#include<cmath>
#include<string.h>
#include<cstdlib>
#define pi 3.1415926
IMAGE img;//定义图片
IMAGE img1;
MOUSEMSG M;//定义鼠标 
#pragma comment(lib,"Winmm.lib") // 引用 Windows Multimedia API,用于播放音乐 
#pragma warning (disable: 4996)//防止vs报c4996错误
typedef struct
{
	char name[20];
	float english;
	float math;
	float computer;
	float sum;
	float pj;
}student;//文件学生结构体
typedef struct {
	char type;
	char time[3];
	int  num;
	short head_size;
	short jilu_size;
	char kong[20];
}Head;//文件头结构体
typedef struct {
	char name[10];
	char emtyc;
	char type;
	int start;
	char kd;
	char xs;
	char kong[14];
}Field;//读文件
int l = 0, n;//go函数给确定值,n为学生人数
long fly;//文件头长度+n条记录的长度
student stu[20] = { 0 };
student s;//用于排成绩时做临时变量
int StartPage_Mouse();//起始页鼠标
void StartPage();//起始页
void sector();//画扇型图
void DealFiles();//用于读取文件并处理文件中数据
void searchpage(char *p, int I);//起始搜索框
                                                         //char *p文件名指针 int l传递文件名是否正确
void EndPage();//末尾页 字幕动画
void MUSICE();//读音乐
int MouseAndKeyboard(int a);//用于获取键盘或鼠标信息
														//int a判断第几页
void mouse_style_blue()
{
	HMODULE hmod = GetModuleHandle(NULL);  // 获取当前进程的句柄
	HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("BLUE.cur")
		, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	HWND hwnd = GetHWnd();							// 获取绘图窗口句柄
	SetClassLong(hwnd, GCL_HCURSOR, (long)hcur);	// 设置窗口类的鼠标样式
	SetWindowText(hwnd, _T("陈森森 2018213499"));//设置标题
} 
void mouse_style_red()
{
	HMODULE hmod = GetModuleHandle(NULL);  // 获取当前进程的句柄
	HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("RED.cur")
		, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	HWND hwnd = GetHWnd();							// 获取绘图窗口句柄
	SetClassLong(hwnd, GCL_HCURSOR, (long)hcur);	// 设置窗口类的鼠标样式
}
void mouse_style_green()
{
	HMODULE hmod = GetModuleHandle(NULL);  // 获取当前进程的句柄
	HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("GREEN.cur")
		, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	HWND hwnd = GetHWnd();							// 获取绘图窗口句柄
	SetClassLong(hwnd, GCL_HCURSOR, (long)hcur);	// 设置窗口类的鼠标样式
}
//以下两个函数用于tchar数组以及char数组转换 char转为tchar适应unicode编码
void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//WideCharToMultiByte用法 
        https://baike.baidu.com/item/WideCharToMultiByte/8794019?fr=aladdin
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}
void CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}
int MouseAndKeyboard(int a)
{
	FlushMouseMsgBuffer();//刷新鼠标信息

	char ch;
	while (1)
	{
		
		if (_kbhit())
		{
			ch = _getch();
			return ch;
		}
		if (MouseHit())//如果鼠标有任何操作
		{
			mouse_style_blue();
			M = GetMouseMsg();//获取鼠标信息
			putimage(0, 0, &img);
			//向上翻页
			if (M.x > 14 && M.x < 39 && M.y>438 && M.y < 462 && a != 1 && a != 4)//a=1 last  左下角
			{
				mouse_style_green();
				setfillstyle(BS_SOLID);
				setfillcolor(RGB(211, 211, 211));//淡灰色 比LIGHTGRAY颜色清
				bar(14, 438, 39, 462);
				setfillcolor(BLACK);
				POINT pts[] = { {33, 442}, {33, 458}, {22, 450} };
				solidpolygon(pts, 3);

				if (M.uMsg == WM_LBUTTONDOWN)
				{
					Sleep(50);
					return 'l';
				}
			}

			if (M.x > 39 && M.x < 64 && M.y>438 && M.y < 462)//a = 2  pass   a=4为扇形函数 跳页 左下中间
			{
				mouse_style_green();
				setfillstyle(BS_SOLID);
				setfillcolor(RGB(211, 211, 211));
				bar(39, 438, 64, 462);
				setfillcolor(BLACK);
				bar(46, 446, 58, 454);
				if (M.uMsg == WM_LBUTTONDOWN)
				{
					Sleep(50);
					return 32;
				}
			}

			if (M.x > 64 && M.x < 89 && M.y>438 && M.y < 462 && a != 2 && a != 4)//a = 2 next a=4为扇形函数 向下翻页
			{
				mouse_style_green();
				setfillstyle(BS_SOLID);
				setfillcolor(RGB(211, 211, 211));
				bar(64, 438, 89, 462);
				setfillcolor(BLACK);
				POINT pts1[] = { {72, 442}, {72, 458}, {83, 450} };
				solidpolygon(pts1, 3);
				if (M.uMsg == WM_LBUTTONDOWN)
				{
					Sleep(50);
					return 'n';
				}
			}

			if (M.x > 601 && M.x < 626 && M.y>438 && M.y < 462)//退出 ×号
			{
				mouse_style_red();
				setfillstyle(BS_SOLID);
				setfillcolor(LIGHTRED);
				bar(601, 438, 626, 462);

				setlinestyle(PS_SOLID, 3);
				line(607, 443, 620, 457);
				line(620, 443, 607, 457);
				setlinestyle(PS_SOLID, 1);
				if (M.uMsg == WM_LBUTTONDOWN)
				{
					Sleep(50);
					return 27;
				}
			}
			if (M.uMsg == WM_MOUSEWHEEL&&a!=4)//如果滑轮有信息
			{
				if (M.wheel > 0)//滑轮向上
				{
					Sleep(50);
					return 'l';
				}
				if (M.wheel < 0)//滑轮向下
				{
					Sleep(50);
					return 'n';
				}
			}
			if (M.uMsg == WM_MBUTTONDOWN)
				return 32;
		}
		
	}
	
	

}
void Histogram(student *p, int n,int x)
{
	setlinestyle(PS_SOLID, 1);//设置划线 实现宽度一个像素
	mouse_style_blue();
	char ch;
	wchar_t Name[20];//将文件中的char数组转为Unicode的宽字符 用以输出
	int a,k = 0, j, i = 0, m = 80, l;
	if (x == -1)
		j = 0;
	else
		j = x;
	settextstyle(20, 0, _T("宋体"));//设置字体 高度为20 宽度自适应 字体样式为宋体
	for (; j <= (n / 3 - 1); )
	{
		Sleep(10);
		a = 100;
		setfillstyle(BS_SOLID);
		setfillcolor(WHITE);
		bar(0, 0, 640, 480);//画背景
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);//输出字体透明
		settextstyle(30, 0, _T("楷体"));
		outtextxy(20, 20, L"学生成绩直方图");//设置页面标题
		settextstyle(20, 0, _T("宋体"));
		i = j * 3;
		for (k = 0; k < 3; k++)
		{
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			setlinecolor(BLACK);
			line(50, 400, 460, 400);
			line(460, 400, 455, 405);
			line(460, 400, 455, 395);
			line(50, 400, 50, 90);
			line(50, 90, 45, 95);
			line(50, 90, 55, 95);
			for (l = 370; l >= 100; l -= 30)
				line(48, l, 52, l);
			outtextxy(35, 400, L"0");
			outtextxy(30, 340, L"20");
			outtextxy(30, 280, L"40");
			outtextxy(30, 220, L"60");
			outtextxy(30, 160, L"80");
			outtextxy(23, 100, L"100");
			outtextxy(25, 65, L"score");
			
			rectangle(450, 50, 600, 150);
			outtextxy(530, 70, L"英语");
			setfillstyle(BS_SOLID);
			setfillcolor(RED);
			bar(470, 70, 500, 80);

			setfillstyle(BS_SOLID);
			setfillcolor(BROWN);
			outtextxy(530, 95, L"数学");
			bar(470, 95, 500, 105);

			setfillstyle(BS_SOLID);
			setfillcolor(YELLOW);
			outtextxy(530, 120, L"计算机");
			bar(470, 120, 500, 130);

			setfillstyle(BS_SOLID);
			setfillcolor(RED);
			bar3d(80 + k * 120, 399 - ((p + i)->english) * 3, 80 + k * 120 + 20, 399, 10, 1);
			floodfill(80 + k * 120 + 20 + 2, 399 - 2, BLACK, 0);
			floodfill(80 + k * 120 + 12, 399 - ((p + i)->english) * 3 - 4, BLACK, 0);

			setfillstyle(BS_SOLID);
			setfillcolor(BROWN);
			bar3d(100 + k * 120, 399 - ((p + i)->math) * 3 - 5, 100 + k * 120 + 20, 399, 10, 1);
			floodfill(100 + k * 120 + 20 + 2, 399 - 2, BLACK, 0);
			floodfill(100 + k * 120 + 15, 399 - ((p + i)->math) * 3 - 8, BLACK, 0);

			setfillstyle(BS_SOLID);
			setfillcolor(YELLOW);
			bar3d(120 + k * 120, 399 - ((p + i)->computer) * 3, 120 + k * 120 + 20, 399, 10, 1);
			floodfill(120 + k * 120 + 12, 399 - ((p + i)->computer) * 3 - 4, BLACK, 0);
			floodfill(120 + k * 120 + 20 + 2, 399 - 2, BLACK, 0);
		

			CharToTchar((p + i)->name, Name);
			outtextxy(90 + k * 120, 405, Name);
			i++;
		}
		if (j != 0)//不是第一页
		{
			setfillcolor(BLACK);
			POINT pts[] = { {33, 442}, {33, 458}, {22, 450} };
			solidpolygon(pts, 3);
		}
		if (j == 0)
			a = 1;

		setfillcolor(BLACK);
		bar(46, 446, 58, 454);

		if (j != (n / 3 - 1)+1 && n % 3 != 0)
		{
			setfillcolor(BLACK);
			POINT pts1[] = { {72, 442}, {72, 458}, {83, 450} };
			solidpolygon(pts1, 3);
		}
		if (j == (n / 3 - 1) && n % 3 == 0)
			a = 2;

		setfillstyle(BS_SOLID);
		setfillcolor(RED);
		bar(601, 438, 626, 462);
		setlinestyle(PS_SOLID, 3);
		line(607, 443, 620, 457);
		line(620, 443, 607, 457);
		setlinestyle(PS_SOLID, 1);

		getimage(&img, 0, 0, 640, 480);
		while (1)
		{
			ch = MouseAndKeyboard(a);//获取鼠标或键盘信息
			if (ch == 32)
			{
				cleardevice();
				sector();
			}
			if (ch == 27)
				exit(1);//如果为esc键 退出程序
			if (ch == 'l'&&j != 0)
			{
				j--;
				cleardevice();
				break;
			}
			if (ch == 'n')
			{
				j++;
				cleardevice();
				break;
			}


		}
	}
	if (n % 3 != 0)
	{
		Sleep(10);
		a = 2;
		setfillstyle(BS_SOLID);
		setfillcolor(WHITE);
		bar(0, 0, 640, 480);

		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, _T("楷体"));
		outtextxy(20, 20, L"学生成绩直方图");
		settextstyle(20, 0, _T("宋体"));
		for (k = 0; i < n; k++)
		{
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			setlinecolor(BLACK);

			line(50, 400, 460, 400);
			line(460, 400, 455, 405);
			line(460, 400, 455, 395);
			line(50, 400, 50, 90);
			line(50, 90, 45, 95);
			line(50, 90, 55, 95);
			for (l = 370; l >= 100; l -= 30)
				line(48, l, 52, l);
			outtextxy(35, 400, L"0");
			outtextxy(30, 340, L"20");
			outtextxy(30, 280, L"40");
			outtextxy(30, 220, L"60");
			outtextxy(30, 160, L"80");
			outtextxy(23, 100, L"100");
			outtextxy(25, 65, L"score");

			rectangle(450, 50, 600, 150);
			outtextxy(530, 70, L"英语");
			setfillstyle(BS_SOLID);
			setfillcolor(RED);
			bar(470, 70, 500, 80);

			setfillstyle(BS_SOLID);
			setfillcolor(BROWN);
			outtextxy(530, 95, L"数学");
			bar(470, 95, 500, 105);

			setfillstyle(BS_SOLID);
			setfillcolor(YELLOW);
			outtextxy(530, 120, L"计算机");
			bar(470, 120, 500, 130);

			setfillstyle(BS_SOLID);
			setfillcolor(RED);
			bar3d(80 + k * 120, 399 - ((p + i)->english) * 3, 80 + k * 120 + 20, 399, 10, 1);
			floodfill(80 + k * 120 + 20 + 2, 399 - 2, BLACK, 0);
			floodfill(80 + k * 120 + 12, 399 - ((p + i)->english) * 3 - 4, BLACK, 0);

			setfillstyle(BS_SOLID);
			setfillcolor(BROWN);
			bar3d(100 + k * 120, 399 - ((p + i)->math) * 3, 100 + k * 120 + 20, 399, 10, 1);
			floodfill(100 + k * 120 + 20 + 2, 399 - 2, BLACK, 0);
			floodfill(100 + k * 120 + 15, 399 - ((p + i)->math) * 3 - 5, BLACK, 0);

			setfillstyle(BS_SOLID);
			setfillcolor(YELLOW);
			bar3d(120 + k * 120, 399 - ((p + i)->computer) * 3, 120 + k * 120 + 20, 399, 10, 1);
			floodfill(120 + k * 120 + 20 + 2, 399 - 2, BLACK, 0);
			floodfill(120 + k * 120 + 12, 399 - ((p + i)->computer) * 3 - 4, BLACK, 0);

			CharToTchar((p + i)->name, Name);
			outtextxy(90 + k * 120, 405, Name);
			i++;
		}

		setfillcolor(BLACK);
		POINT pts[] = { {33, 442}, {33, 458}, {22, 450} };
		solidpolygon(pts, 3);

		setfillcolor(BLACK);
		bar(46, 446, 58, 454);

		setfillstyle(BS_SOLID);
		setfillcolor(RED);
		bar(601, 438, 626, 462);
		setlinestyle(PS_SOLID, 3);
		line(607, 443, 620, 457);
		line(620, 443, 607, 457);
		setlinestyle(PS_SOLID, 1);

		getimage(&img, 0, 0, 640, 480);
		while (1)
		{
			
			ch = MouseAndKeyboard(a);
			if (ch == 32)
			{
				cleardevice();
				sector();
			}
			if (ch == 27)
				exit(1);
			if (ch == 'l')
			{
				j--;
				cleardevice();
				Histogram(p, n,j);
			}
			if (ch == 32)
			{
				cleardevice();
				sector();
				break;
			}
		}
	}

}
void sector()
{
	mouse_style_blue();
	int i,a=4;
	int b[5] = { 0 };
	double c[5] = { 0 };

	for (i = 0; i <= 9; i++)
	{
		stu[i].pj = (stu[i].math + stu[i].english + stu[i].computer) / 3;
		if (stu[i].pj < 60)
			b[0] += 1;
		if (stu[i].pj >= 60 && stu[i].pj < 70)
			b[1] += 1;
		if (stu[i].pj >= 70 && stu[i].pj < 80)
			b[2] += 1;
		if (stu[i].pj >= 80 && stu[i].pj < 90)
			b[3] += 1;
		if (stu[i].pj >= 90 && stu[i].pj <= 100)
			b[4] += 1;

	}
	for (i = 0; i < 5; i++)
		c[i] = (float)b[i] / 10;
	double x = 0;
	{
		setfillstyle(BS_SOLID);
		setfillcolor(WHITE);
		bar(0, 0, 640, 480);
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		setlinecolor(BLACK);

		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		settextstyle(30, 0, _T("楷体"));
		outtextxy(20, 20, L"学生平均分区段饼状图");
		settextstyle(20, 0, _T("宋体"));

		rectangle(490, 50, 630, 200);
		outtextxy(570, 70, L"0~60");
		setfillstyle(BS_SOLID);
		setfillcolor(BLUE);
		bar(510, 70, 560, 80);

		setfillstyle(BS_SOLID);
		setfillcolor(GREEN);
		outtextxy(570, 95, L"60~70");
		bar(510, 95, 560, 105);

		setfillstyle(BS_SOLID);
		setfillcolor(CYAN);
		outtextxy(570, 120, L"70~80");
		bar(510, 120, 560, 130);

		setfillstyle(BS_SOLID);
		setfillcolor(RED);
		outtextxy(570, 145, L"80~90");
		bar(510, 145, 560, 155);

		setfillstyle(BS_SOLID);
		setfillcolor(BROWN);
		outtextxy(570, 170, L"90~100");
		bar(510, 170, 560, 180);

		setfillstyle(BS_SOLID);
		setfillcolor(BLACK);
		bar(46, 446, 58, 454);
	}
	if (c[0] != 0)
	{
		setfillstyle(BS_SOLID);
		setfillcolor(BLUE);
		fillpie(150, 140, 350, 340, 0, c[0] * 2 * pi);
	}
	x += c[0] * 2 * pi;
	if (c[1] != 0)
	{

		setfillstyle(BS_SOLID);
		setfillcolor(GREEN);
		fillpie(150, 140, 350, 340, x, c[1] * 2 * pi + x);
	}
	x += c[1] * 2 * pi;
	if (c[2] != 0)
	{

		setfillstyle(BS_SOLID);
		setfillcolor(CYAN);
		fillpie(150, 140, 350, 340, x, c[2] * 2 * pi + x);
	}
	x += c[2] * 2 * pi;
	if (c[3] != 0)
	{

		setfillstyle(BS_SOLID);
		setfillcolor(RED);
		fillpie(150, 140, 350, 340, x, c[3] * 2 * pi + x);
	}
	x += c[3] * 2 * pi;
	if (c[4] != 0)
	{

		setfillstyle(BS_SOLID);
		setfillcolor(BROWN);
		fillpie(150, 140, 350, 340, x, c[4] * 2 * pi + x);
	}
	for (i = 0; i < 5; i++)
	{
		c[i] = c[i] * 10 * 36;
	}
	for (i = 0; i < 5; i++)
	{
		double xx = 0;
		double P = 180;
		xx = c[i];

		char cc[10];
		wchar_t ccc[10];
		if (c[i] == 0)
			continue;
		sprintf(cc, "%5.2f", c[i] / 10 / 36 * 100);
		cc[5] = '%', cc[6] = 0;
		CharToTchar(cc, ccc);
		outtextxy(220 + 150 * cos(double((xx / 2 + x) / P * pi)), 240 - 150 * sin(double(xx / 2 + x) / P * pi), ccc);
		x += c[i];

	}
	setfillcolor(BLACK);
	bar(46, 446, 58, 454);

	setfillstyle(BS_SOLID);
	setfillcolor(RED);
	bar(601, 438, 626, 462);
	setlinestyle(PS_SOLID, 3);
	line(607, 443, 620, 457);
	line(620, 443, 607, 457);
	setlinestyle(PS_SOLID, 1);

	getimage(&img, 0, 0, 640, 480);
	char ch;
	while (1)
	{
		ch = MouseAndKeyboard(a);
		if (ch == 27)
			exit(1);
		if (ch == 32 || ch == 'n')
			EndPage();
	}
}
int StartPage_Mouse()
{
	char ch;
	int i = 40,a=0;
	FlushMouseMsgBuffer();
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			return ch;
		}
		if (MouseHit())
		{
			M = GetMouseMsg();
			putimage(0, 0, &img);
			if (M.x > 95 && M.x < 282 && M.y > 76 && M.y < 107)
			{
				setfillcolor(RGB(135, 206, 250));
				bar(95, 76, 282, 107);
				settextstyle(20, 0, _T("宋体"));
				setfillstyle(BS_SOLID);
				setfillcolor(RGB(65, 105, 225));
				POINT pts[] = { {98,86}, {113, 86}, {113, 80} ,{130,90},{113, 100},{113,94},{98,94} };
				polygon(pts, 7);
				outtextxy(140, 80, L"进入程序(回车)");
				if (M.uMsg == WM_LBUTTONDOWN || M.uMsg == WM_LBUTTONUP)
				{
					Sleep(50);
					DealFiles();
				}
			}
			if (M.x > 95 && M.x < 282 && M.y > 114 && M.y < 145)
			{
				setfillcolor(RGB(135, 206, 250));
				bar(95, 114, 282, 145);
				setfillcolor(RGB(65, 105, 225));
				POINT pts1[] = { {98,86 + i}, {113, 86 + i}, {113, 80 + i} ,{130,90 + i},{113, 100 + i},{113,94 + i},{98,94 + i} };
				fillpolygon(pts1, 7);
				outtextxy(150, 80 + i, L"程序说明(h)");
				if (M.uMsg == WM_LBUTTONDOWN || M.uMsg == WM_LBUTTONUP)
				{
					setfillstyle(BS_SOLID);
					setfillcolor(RGB(255, 228, 196));
					bar(0, 0, 600, 330);
					setbkmode(0);
					settextstyle(20, 0, _T("宋体"));
					settextcolor(RGB(186, 85, 211));
					outtextxy(10, 20, L"1.'n'键以及界面左下角的右三角为向下翻页.");
					outtextxy(10, 40, L"2.'l'键以及界面左下角的左三角为向前翻页.");
					outtextxy(10, 60, L"3.空格键以及鼠标中间按下或界面左下角的");
					outtextxy(30, 80, L"黑块为跳过");
					outtextxy(10, 100, L"4.鼠标滑轮上下滑动可上下翻页");
					outtextxy(40, 140, L"该程序可显示学生成绩直方图和学生成绩");
					outtextxy(10, 160, L"分段扇形图");
					
					while (1)
					{
						settextcolor(RGB(255, a  % 228, 196));
						outtextxy(80, 200, L"按任意键或点击两侧退出");//闪烁文字
						a++;
						if (_kbhit())
							break;
						if (MouseHit())
						{
							M = GetMouseMsg();
							if ((M.x > 0 && M.x < 100) || (M.x > 310 && M.x < 410))
								if (M.uMsg == WM_LBUTTONDOWN)
								{
									Sleep(50);
									break;
								}
						}
					}
				}
			}
			if (M.x > 95 && M.x < 282 && M.y > 153 && M.y < 185)
			{
				setfillcolor(RGB(135, 206, 250));
				bar(95, 153, 282, 185);
				setfillcolor(RGB(255, 64, 64));
				fillcircle(110, 80 + 2 * i + 10, 11);
				setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);//画线 实线 线两端为圆头 宽度为3
				line(111 + 4.2, 80 + 2 * i + 10 - 4.2, 111 - 4.2, 80 + 2 * i + 10 + 4.2);
				line(111 - 4.2, 80 + 2 * i + 10 - 4.2, 111 + 4.2, 80 + 2 * i + 10 + 4.2);
				outtextxy(160, 80 + 2 * i, L"退出(ESC)");
				if (M.uMsg == WM_LBUTTONDOWN || M.uMsg == WM_LBUTTONUP)
					exit(1);
			}
		}
	}
	
}//起始页鼠标   
void StartPage()
{
	int i = 40, x = 1,w,xx=0,a=0;
	char ch;
	initgraph(410, 230);
	mouse_style_blue();
	while (1)
	{
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(218, 112, 214));
		bar(0, 0, 133, 230);
		setfillcolor(RGB(255, 192, 203));
		bar(133, 0, 272, 230);
		setfillcolor(RGB(255, 105, 180));
		bar(272, 0, 410, 230);

		setbkmode(0);
		settextstyle(30, 0, _T("宋体"));
		settextcolor(BLACK);
		outtextxy(100, 20, L"程序实践作业");

		settextstyle(20, 0, _T("宋体"));
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(65, 105, 225));
		POINT pts[] = { {98,86}, {113, 86}, {113, 80} ,{130,90},{113, 100},{113,94},{98,94} };
		fillpolygon(pts, 7);
		outtextxy(140, 80, L"进入程序(回车)");

		POINT pts1[] = { {98,86 + i}, {113, 86 + i}, {113, 80 + i} ,{130,90 + i},{113, 100 + i},{113,94 + i},{98,94 + i} };
		fillpolygon(pts1, 7);
		outtextxy(150, 80 + i, L"程序说明(h)");

		setfillcolor(RGB(255, 64, 64));//画×
		fillcircle(110, 80 + 2 * i + 10, 11);
		setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);
		line(111 + 4.2, 80 + 2 * i + 10 - 4.2, 111 - 4.2, 80 + 2 * i + 10 + 4.2);
		line(111 - 4.2, 80 + 2 * i + 10 - 4.2, 111 + 4.2, 80 + 2 * i + 10 + 4.2);
		outtextxy(160, 80 + 2 * i, L"退出(ESC)");
		getimage(&img, 0, 0, 410, 230);
		setlinestyle(PS_SOLID, 1);
		while (1)
		{
			ch = StartPage_Mouse();
			if (ch == 13)
				DealFiles();
			if (ch == 'h')
			{

				setfillstyle(BS_SOLID);
				setfillcolor(RGB(255, 228, 196));
				bar(0, 0, 600, 330);
				setbkmode(0);
				settextstyle(20, 0, _T("宋体"));
				settextcolor(RGB(186, 85, 211));
				outtextxy(10, 20, L"1.'n'键以及界面左下角的右三角为向下翻页.");
				outtextxy(10, 40, L"2.'l'键以及界面左下角的左三角为向前翻页.");
				outtextxy(10, 60, L"3.空格键以及鼠标中间按下或界面左下角的");
				outtextxy(30, 80, L"黑块为跳过");
				outtextxy(10, 100, L"4.鼠标滑轮上下滑动可上下翻页");
				outtextxy(40, 140, L"该程序可显示学生成绩直方图和学生成绩");
				outtextxy(10, 160, L"分段扇形图");
				xx = 0;
				while (1)
				{
					settextcolor(RGB(255, a % 228, 196));
					outtextxy(80, 200, L"按任意键或点击两侧退出");
					a++;
					if (_kbhit())
						break;
					if (MouseHit())
					{
						M = GetMouseMsg();
						if((M.x > 0 && M.x < 100 )|| (M.x > 310 && M.x < 410))
							if (M.uMsg == WM_LBUTTONDOWN)
						{
							xx = 1;
							break;
						}
					}
				}

			}
			if (xx != 0)
				break;
			else
				if (ch == 27)
					exit(1);
		}
	}	 
 }
void searchpage(char *p, int I)
{
	initgraph(640, 480);
	mouse_style_blue();
	int x;
	char ss[50];
	wchar_t s[50] = { 0 };
	wchar_t  ch[10] = { '\0' };
	wcscpy(ch, L"未找到该文件");
	setfillstyle(BS_SOLID);
	setfillcolor(CYAN);
	bar(0, 0, 640, 160);
	setfillcolor(RGB(118,238,198));
	bar(0, 160, 640, 480);
	setfillcolor(RGB(176,224,230));
	bar(0, 320, 640, 480);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("宋体"));
	outtextxy(180, 40, L"文件搜索界面");
	settextstyle(25, 0, _T("宋体"));
	settextcolor(RGB(255,69,0));
	outtextxy(80, 340, L"1.文件名可省略或加上.dbf");
	outtextxy(80, 370, L"2.按取消按钮或ESC或直接输入回车退出程序");
	settextstyle(20, 0, _T("宋体"));
	if (I == 0)
		x = InputBox(s, 10, _T("未找到该文件,请重新输入"), L"文件搜索框", NULL, 0, 0, false);
	//输入框 第一个搜索框正文 第二个参数为输入框名 
	else
	x=InputBox(s, 10, _T("请输入文件名"), L"文件搜索框", NULL, 0, 0, false);
	if (x == false)//如果点击取消
		exit(1);
	TcharToChar(s, ss);
	strcpy(p, ss);

}
void MUSICE()
{
	mciSendString(_T("open \"end1.mp3\" alias mymusic"), NULL, 0, NULL);// 打开音乐
	mciSendString(_T("play mymusic"), NULL, 0, NULL);
	////MCI命令字符串  MCI命令字符串一般为NULL  返回字符串的大小 回调窗口句柄
}
void EndPage()
{
	MUSICE();
	initgraph(640, 480);
	mouse_style_blue();
	int  i, j = 0, k = 0,x=0,a=0;
	wchar_t Wame[200] = { L"此程序为C程序设计作业,于二零一九年五月由陈森完成.最后,感谢王老师的指导与教导" };
	setfillstyle(BS_SOLID);
	setfillcolor(CYAN);
	bar(0, 0, 217, 480);
	setfillcolor(RGB(118, 238, 198));
	bar(217, 0, 430, 480);
	setfillcolor(RGB(176, 224, 230));
	bar(430, 0, 640, 480);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("楷体"));
	for (i = 0; i < wcslen(Wame) ; i++)
	{	
		if (_kbhit())
			exit(1);
		settextcolor(RGB(71,60,139));
		if (50 + i * 35 >= 630 && k <= 17)
			outtextxy(20 + k++ * 30, 230, Wame[i]);
		else if (k > 17)
			outtextxy(20 + x++ * 30, 260, Wame[i]);
		else
			outtextxy(50 + i * 30, 200, Wame[i]);		
		Sleep(300);
	}

	getimage(&img, 0,0,640 ,300);
	for (i = 0; i >= -400 && !_kbhit(); i-=3)
	{
		putimage(0, i, &img);
		Sleep(30);
		setfillstyle(BS_SOLID);
		setfillcolor(CYAN);
		bar(0, 0, 217, 160);
		setfillcolor(RGB(118, 238, 198));
		bar(217, 0, 430, 480);
		setfillcolor(RGB(176, 224, 230));
		bar(430, 0, 640, 480);
		settextcolor(RGB(255, a % 228, 196));
		outtextxy(80, 500, L"按任意键退出");
		a++;
	}
	exit(1);
}
void DealFiles()
{

	Head head;
	Field field[10];
	FILE *fp = NULL;
	int i=3, num, k = 0, m, w = 0, I = 1;
	float cj;
	char ch[20] = { 0 };
	char chl[20] = { 0 };
	char name[100] = { 0 };
	char filename[50];
	char Filename[50]=".dbf";
	while (1)
	{
		searchpage(filename, I);
		if (strlen(filename) == 0)
			exit(1);
		fp = fopen(filename, "rb");
		if (fp == NULL)
		{
			strcat(filename, Filename);
			fp = fopen(filename, "rb");
			if (fp == NULL)
			{
				I = 0;
				i--;
			}
		}
		if (fp != NULL)
			break;
	}
	fread(&head, 32, 1, fp);
	num = (head.head_size - 33) / 32;
	for (i = 1; i <= num; i++)
	{
		fread(&field[0], 32, 1, fp);
		if (strcmp(field[0].name, "姓名") == 0)
			k = 1;
		else if (strcmp(field[0].name, "英语") == 0)
			k = 2;
		else if (strcmp(field[0].name, "数学") == 0)
			k = 3;
		else if (strcmp(field[0].name, "计算机") == 0)
			k = 4;
		else
			k = 0;

		field[k] = field[0];
	}
	i = 0;
	while (l < head.num)
	{
		fly = head.head_size + head.jilu_size*l;
		fseek(fp, fly, 0);
		if (fgetc(fp) == '*')
		{
			l++;
			continue;
		}
		fseek(fp, fly + field[2].start, 0);
		fread(chl, field[2].kd - 1, 1, fp);
		chl[field[2].kd] = 0;
		stu[i].english = atof(chl);


		fseek(fp, fly + field[3].start, 0);
		fread(chl, field[3].kd, 1, fp);
		chl[field[3].kd] = 0;
		stu[i].math = atof(chl);

		fseek(fp, fly + field[4].start, 0);
		fread(chl, field[4].kd, 1, fp);
		chl[field[4].kd] = 0;
		stu[i].computer = atof(chl);

		fseek(fp, fly + field[1].start, 0);
		fread(&ch, field[1].kd, 1, fp);
		for (m = field[2].kd - 1; m >= 0; m--) {
			if (ch[m] == ' ')
				ch[m] = 0;
			else
				break;
		}
		stu[i].sum = stu[i].math + stu[i].english + stu[i].computer;
		strcpy(stu[i].name, ch);
		i++;
		l++;
	}
	n = i;
	int j, max;
	for (i = 0; i < n - 1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (stu[j].sum > stu[max].sum)
				max = j;
			else if (stu[j].sum == stu[max].sum)//如果成绩相同 英语好的在前面
			{
				if (stu[j].english > stu[max].english)
					max = j;
			}
		}
		s = stu[max];
		stu[max] = stu[i];
		stu[i] = s;
	}
	initgraph(640, 480);
	mouse_style_blue();
	Histogram(stu, n,-1);

	_getch();
	closegraph();
}
int main()
{
	StartPage();
	return 0;
}