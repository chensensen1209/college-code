#include<graphics.h>//����easyx������
#include<conio.h>//_getch()����
#include<stdio.h>
#include<cmath>
#include<string.h>
#include<cstdlib>
#define pi 3.1415926
IMAGE img;//����ͼƬ
IMAGE img1;
MOUSEMSG M;//������� 
#pragma comment(lib,"Winmm.lib") // ���� Windows Multimedia API,���ڲ������� 
#pragma warning (disable: 4996)//��ֹvs��c4996����
typedef struct
{
	char name[20];
	float english;
	float math;
	float computer;
	float sum;
	float pj;
}student;//�ļ�ѧ���ṹ��
typedef struct {
	char type;
	char time[3];
	int  num;
	short head_size;
	short jilu_size;
	char kong[20];
}Head;//�ļ�ͷ�ṹ��
typedef struct {
	char name[10];
	char emtyc;
	char type;
	int start;
	char kd;
	char xs;
	char kong[14];
}Field;//���ļ�
int l = 0, n;//go������ȷ��ֵ,nΪѧ������
long fly;//�ļ�ͷ����+n����¼�ĳ���
student stu[20] = { 0 };
student s;//�����ųɼ�ʱ����ʱ����
int StartPage_Mouse();//��ʼҳ���
void StartPage();//��ʼҳ
void sector();//������ͼ
void DealFiles();//���ڶ�ȡ�ļ��������ļ�������
void searchpage(char *p, int I);//��ʼ������
                                                         //char *p�ļ���ָ�� int l�����ļ����Ƿ���ȷ
void EndPage();//ĩβҳ ��Ļ����
void MUSICE();//������
int MouseAndKeyboard(int a);//���ڻ�ȡ���̻������Ϣ
														//int a�жϵڼ�ҳ
void mouse_style_blue()
{
	HMODULE hmod = GetModuleHandle(NULL);  // ��ȡ��ǰ���̵ľ��
	HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("BLUE.cur")
		, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	HWND hwnd = GetHWnd();							// ��ȡ��ͼ���ھ��
	SetClassLong(hwnd, GCL_HCURSOR, (long)hcur);	// ���ô�����������ʽ
	SetWindowText(hwnd, _T("��ɭɭ 2018213499"));//���ñ���
} 
void mouse_style_red()
{
	HMODULE hmod = GetModuleHandle(NULL);  // ��ȡ��ǰ���̵ľ��
	HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("RED.cur")
		, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	HWND hwnd = GetHWnd();							// ��ȡ��ͼ���ھ��
	SetClassLong(hwnd, GCL_HCURSOR, (long)hcur);	// ���ô�����������ʽ
}
void mouse_style_green()
{
	HMODULE hmod = GetModuleHandle(NULL);  // ��ȡ��ǰ���̵ľ��
	HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("GREEN.cur")
		, IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	HWND hwnd = GetHWnd();							// ��ȡ��ͼ���ھ��
	SetClassLong(hwnd, GCL_HCURSOR, (long)hcur);	// ���ô�����������ʽ
}
//����������������tchar�����Լ�char����ת�� charתΪtchar��Ӧunicode����
void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//��ȡ�ֽڳ���   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//WideCharToMultiByte�÷� 
        https://baike.baidu.com/item/WideCharToMultiByte/8794019?fr=aladdin
	//��tcharֵ����_char    
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
	FlushMouseMsgBuffer();//ˢ�������Ϣ

	char ch;
	while (1)
	{
		
		if (_kbhit())
		{
			ch = _getch();
			return ch;
		}
		if (MouseHit())//���������κβ���
		{
			mouse_style_blue();
			M = GetMouseMsg();//��ȡ�����Ϣ
			putimage(0, 0, &img);
			//���Ϸ�ҳ
			if (M.x > 14 && M.x < 39 && M.y>438 && M.y < 462 && a != 1 && a != 4)//a=1 last  ���½�
			{
				mouse_style_green();
				setfillstyle(BS_SOLID);
				setfillcolor(RGB(211, 211, 211));//����ɫ ��LIGHTGRAY��ɫ��
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

			if (M.x > 39 && M.x < 64 && M.y>438 && M.y < 462)//a = 2  pass   a=4Ϊ���κ��� ��ҳ �����м�
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

			if (M.x > 64 && M.x < 89 && M.y>438 && M.y < 462 && a != 2 && a != 4)//a = 2 next a=4Ϊ���κ��� ���·�ҳ
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

			if (M.x > 601 && M.x < 626 && M.y>438 && M.y < 462)//�˳� ����
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
			if (M.uMsg == WM_MOUSEWHEEL&&a!=4)//�����������Ϣ
			{
				if (M.wheel > 0)//��������
				{
					Sleep(50);
					return 'l';
				}
				if (M.wheel < 0)//��������
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
	setlinestyle(PS_SOLID, 1);//���û��� ʵ�ֿ��һ������
	mouse_style_blue();
	char ch;
	wchar_t Name[20];//���ļ��е�char����תΪUnicode�Ŀ��ַ� �������
	int a,k = 0, j, i = 0, m = 80, l;
	if (x == -1)
		j = 0;
	else
		j = x;
	settextstyle(20, 0, _T("����"));//�������� �߶�Ϊ20 �������Ӧ ������ʽΪ����
	for (; j <= (n / 3 - 1); )
	{
		Sleep(10);
		a = 100;
		setfillstyle(BS_SOLID);
		setfillcolor(WHITE);
		bar(0, 0, 640, 480);//������
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);//�������͸��
		settextstyle(30, 0, _T("����"));
		outtextxy(20, 20, L"ѧ���ɼ�ֱ��ͼ");//����ҳ�����
		settextstyle(20, 0, _T("����"));
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
			outtextxy(530, 70, L"Ӣ��");
			setfillstyle(BS_SOLID);
			setfillcolor(RED);
			bar(470, 70, 500, 80);

			setfillstyle(BS_SOLID);
			setfillcolor(BROWN);
			outtextxy(530, 95, L"��ѧ");
			bar(470, 95, 500, 105);

			setfillstyle(BS_SOLID);
			setfillcolor(YELLOW);
			outtextxy(530, 120, L"�����");
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
		if (j != 0)//���ǵ�һҳ
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
			ch = MouseAndKeyboard(a);//��ȡ���������Ϣ
			if (ch == 32)
			{
				cleardevice();
				sector();
			}
			if (ch == 27)
				exit(1);//���Ϊesc�� �˳�����
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
		settextstyle(30, 0, _T("����"));
		outtextxy(20, 20, L"ѧ���ɼ�ֱ��ͼ");
		settextstyle(20, 0, _T("����"));
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
			outtextxy(530, 70, L"Ӣ��");
			setfillstyle(BS_SOLID);
			setfillcolor(RED);
			bar(470, 70, 500, 80);

			setfillstyle(BS_SOLID);
			setfillcolor(BROWN);
			outtextxy(530, 95, L"��ѧ");
			bar(470, 95, 500, 105);

			setfillstyle(BS_SOLID);
			setfillcolor(YELLOW);
			outtextxy(530, 120, L"�����");
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
		settextstyle(30, 0, _T("����"));
		outtextxy(20, 20, L"ѧ��ƽ�������α�״ͼ");
		settextstyle(20, 0, _T("����"));

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
				settextstyle(20, 0, _T("����"));
				setfillstyle(BS_SOLID);
				setfillcolor(RGB(65, 105, 225));
				POINT pts[] = { {98,86}, {113, 86}, {113, 80} ,{130,90},{113, 100},{113,94},{98,94} };
				polygon(pts, 7);
				outtextxy(140, 80, L"�������(�س�)");
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
				outtextxy(150, 80 + i, L"����˵��(h)");
				if (M.uMsg == WM_LBUTTONDOWN || M.uMsg == WM_LBUTTONUP)
				{
					setfillstyle(BS_SOLID);
					setfillcolor(RGB(255, 228, 196));
					bar(0, 0, 600, 330);
					setbkmode(0);
					settextstyle(20, 0, _T("����"));
					settextcolor(RGB(186, 85, 211));
					outtextxy(10, 20, L"1.'n'���Լ��������½ǵ�������Ϊ���·�ҳ.");
					outtextxy(10, 40, L"2.'l'���Լ��������½ǵ�������Ϊ��ǰ��ҳ.");
					outtextxy(10, 60, L"3.�ո���Լ�����м䰴�»�������½ǵ�");
					outtextxy(30, 80, L"�ڿ�Ϊ����");
					outtextxy(10, 100, L"4.��껬�����»��������·�ҳ");
					outtextxy(40, 140, L"�ó������ʾѧ���ɼ�ֱ��ͼ��ѧ���ɼ�");
					outtextxy(10, 160, L"�ֶ�����ͼ");
					
					while (1)
					{
						settextcolor(RGB(255, a  % 228, 196));
						outtextxy(80, 200, L"����������������˳�");//��˸����
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
				setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);//���� ʵ�� ������ΪԲͷ ���Ϊ3
				line(111 + 4.2, 80 + 2 * i + 10 - 4.2, 111 - 4.2, 80 + 2 * i + 10 + 4.2);
				line(111 - 4.2, 80 + 2 * i + 10 - 4.2, 111 + 4.2, 80 + 2 * i + 10 + 4.2);
				outtextxy(160, 80 + 2 * i, L"�˳�(ESC)");
				if (M.uMsg == WM_LBUTTONDOWN || M.uMsg == WM_LBUTTONUP)
					exit(1);
			}
		}
	}
	
}//��ʼҳ���   
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
		settextstyle(30, 0, _T("����"));
		settextcolor(BLACK);
		outtextxy(100, 20, L"����ʵ����ҵ");

		settextstyle(20, 0, _T("����"));
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(65, 105, 225));
		POINT pts[] = { {98,86}, {113, 86}, {113, 80} ,{130,90},{113, 100},{113,94},{98,94} };
		fillpolygon(pts, 7);
		outtextxy(140, 80, L"�������(�س�)");

		POINT pts1[] = { {98,86 + i}, {113, 86 + i}, {113, 80 + i} ,{130,90 + i},{113, 100 + i},{113,94 + i},{98,94 + i} };
		fillpolygon(pts1, 7);
		outtextxy(150, 80 + i, L"����˵��(h)");

		setfillcolor(RGB(255, 64, 64));//����
		fillcircle(110, 80 + 2 * i + 10, 11);
		setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);
		line(111 + 4.2, 80 + 2 * i + 10 - 4.2, 111 - 4.2, 80 + 2 * i + 10 + 4.2);
		line(111 - 4.2, 80 + 2 * i + 10 - 4.2, 111 + 4.2, 80 + 2 * i + 10 + 4.2);
		outtextxy(160, 80 + 2 * i, L"�˳�(ESC)");
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
				settextstyle(20, 0, _T("����"));
				settextcolor(RGB(186, 85, 211));
				outtextxy(10, 20, L"1.'n'���Լ��������½ǵ�������Ϊ���·�ҳ.");
				outtextxy(10, 40, L"2.'l'���Լ��������½ǵ�������Ϊ��ǰ��ҳ.");
				outtextxy(10, 60, L"3.�ո���Լ�����м䰴�»�������½ǵ�");
				outtextxy(30, 80, L"�ڿ�Ϊ����");
				outtextxy(10, 100, L"4.��껬�����»��������·�ҳ");
				outtextxy(40, 140, L"�ó������ʾѧ���ɼ�ֱ��ͼ��ѧ���ɼ�");
				outtextxy(10, 160, L"�ֶ�����ͼ");
				xx = 0;
				while (1)
				{
					settextcolor(RGB(255, a % 228, 196));
					outtextxy(80, 200, L"����������������˳�");
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
	wcscpy(ch, L"δ�ҵ����ļ�");
	setfillstyle(BS_SOLID);
	setfillcolor(CYAN);
	bar(0, 0, 640, 160);
	setfillcolor(RGB(118,238,198));
	bar(0, 160, 640, 480);
	setfillcolor(RGB(176,224,230));
	bar(0, 320, 640, 480);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("����"));
	outtextxy(180, 40, L"�ļ���������");
	settextstyle(25, 0, _T("����"));
	settextcolor(RGB(255,69,0));
	outtextxy(80, 340, L"1.�ļ�����ʡ�Ի����.dbf");
	outtextxy(80, 370, L"2.��ȡ����ť��ESC��ֱ������س��˳�����");
	settextstyle(20, 0, _T("����"));
	if (I == 0)
		x = InputBox(s, 10, _T("δ�ҵ����ļ�,����������"), L"�ļ�������", NULL, 0, 0, false);
	//����� ��һ������������ �ڶ�������Ϊ������� 
	else
	x=InputBox(s, 10, _T("�������ļ���"), L"�ļ�������", NULL, 0, 0, false);
	if (x == false)//������ȡ��
		exit(1);
	TcharToChar(s, ss);
	strcpy(p, ss);

}
void MUSICE()
{
	mciSendString(_T("open \"end1.mp3\" alias mymusic"), NULL, 0, NULL);// ������
	mciSendString(_T("play mymusic"), NULL, 0, NULL);
	////MCI�����ַ���  MCI�����ַ���һ��ΪNULL  �����ַ����Ĵ�С �ص����ھ��
}
void EndPage()
{
	MUSICE();
	initgraph(640, 480);
	mouse_style_blue();
	int  i, j = 0, k = 0,x=0,a=0;
	wchar_t Wame[200] = { L"�˳���ΪC���������ҵ,�ڶ���һ���������ɳ�ɭ���.���,��л����ʦ��ָ����̵�" };
	setfillstyle(BS_SOLID);
	setfillcolor(CYAN);
	bar(0, 0, 217, 480);
	setfillcolor(RGB(118, 238, 198));
	bar(217, 0, 430, 480);
	setfillcolor(RGB(176, 224, 230));
	bar(430, 0, 640, 480);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("����"));
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
		outtextxy(80, 500, L"��������˳�");
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
		if (strcmp(field[0].name, "����") == 0)
			k = 1;
		else if (strcmp(field[0].name, "Ӣ��") == 0)
			k = 2;
		else if (strcmp(field[0].name, "��ѧ") == 0)
			k = 3;
		else if (strcmp(field[0].name, "�����") == 0)
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
			else if (stu[j].sum == stu[max].sum)//����ɼ���ͬ Ӣ��õ���ǰ��
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