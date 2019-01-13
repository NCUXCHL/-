//#undef UNICODE
//#undef _UNICODE
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include <windows.h>
#include <mmsystem.h>//导入声音头文件
#pragma comment(lib,"Winmm.lib")

#define PI 3.1415926528   //π

struct JET
{
	int x, y;     //坐标
	int hx,hy;    //最高点的坐标
	int height;   //高度 y-hy
	bool shoot;    //是否可以发射

	unsigned long t1, t2, dt;   //三个时间  控制他上升的速度
	IMAGE img[2];       //定义两张图片，明暗交错
	byte  n:1;			//位段 n变量 只需要一个位来存放  int a; a 有几个位？四个字节 8个位 32
}jet[13];         //定义13个烟花弹

void Shoot();
void Mul();
void ChoiceJet(DWORD &t1);
void Init(int i)
{
	//初始化烟花弹
	jet[i].x=0;
	jet[i].y=0;
	jet[i].hx=0;
	jet[i].hy=0;
	jet[i].height=0;
	jet[i].n=0;

	jet[i].shoot=false;     //暂时没有发射的
	jet[i].t1=timeGetTime();//获取系统时间
	jet[i].dt=rand()%10;		//0-9
}

void Welcome()
{
	int i;
	int x1,y1;
	settextcolor(YELLOW);
	
	outtextxy(200,100,"浪漫情人节");
	outtextxy(500,160,"献给某某某");
	
	for(i=0;i<50;i++)//五十个点
	{
		//system("cls");//控制台清屏
		cleardevice();//清屏cleardevice是一个计算机术语，用于清除图形屏幕。
		x1=600+(180*sin(PI*2*i/60));
		y1=200+(180*cos(PI*2*i/60));
		settextstyle(i,0,"楷体");
		outtextxy(x1,y1,"欢快元旦");
		outtextxy(x1+50,y1+100,"献给***同学");
		Sleep(25);
	}
		Sleep(5000);
		//getchar();//等待键盘操作，按下回车键继续
		cleardevice();
		settextstyle(25,0,"楷体");
		outtextxy(400,200,"时间不经意写了结局，");
		outtextxy(400,250,"还没来得及说再见，");
		outtextxy(400,300,"时间不经意写了开始，");
		outtextxy(400,350,"还没猜到要和谁相见，");
		outtextxy(400,400,"时间不经意写了祝愿，");
		outtextxy(400,450,"祝你元旦一切平平安安。");
		outtextxy(600,500,"----xchl同学");	
		Sleep(5000);
}
/*烟花弹*/


// 主函数
int main()
{
	int n;
	
	// 绘图环境初始化
	initgraph(1200, 1000);

	// 读取图片至绘图窗口
	//loadimage(NULL, _T("C:\\Users\\爱牙的XCHL\\Pictures\\WIN_20181122_11_58_43_Pro.jpg"),1200, 1000);

	// 按任意键退出
	//_getch();


	//音乐
	 PlaySound(TEXT("Debug\\WAV-《小幸运--田馥甄》DTS-2018受欢迎女歌手2CD.wav"),NULL,SND_FILENAME | SND_ASYNC);
	
	 //文字 文字颜色 文字的格式
	Welcome();
	/*setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	 outtextxy(1,300,"爱牙的xchl");//字体的位置*/
	//PlaySound(TEXT("Debug\\WAV-《小幸运--田馥甄》DTS-2018受欢迎女歌手2CD.wav"),NULL, SND_RESOURCE | SND_ASYNC |SND_LOOP);
	
	system("cls");
	for(n=0;n<3;n++)
	{
	 Mul();
	}
	 // 绘图环境初始化
	//initgraph(1200, 1000);

	Sleep(10000);
	PlaySound(NULL,NULL,NULL); //停止播放*/
	// 读取图片至绘图窗口
	PlaySound(TEXT("Debug\\有何不可 - 许嵩.wav"),NULL,SND_FILENAME | SND_ASYNC);
	loadimage(NULL, _T("C:\\Users\\爱牙的XCHL\\Desktop\\picture-Word\\fire\\iali53.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	outtextxy(100,250,"一个工科男对你元旦表白:");
	 outtextxy(100,300,"xchl love 大明星");//字体的位置*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali63.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(150,100,"过去的我一直是一个人生活，享受着孤独，也憧憬着爱情。");//字体的位置*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali35.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,130,"一个人的长廊");//字体的位置*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali6.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,550,"一个人的山岗");//字体的位置*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali60.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,100,"但他依然乐观，微笑着，等待着");//字体的位置*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali60.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"生活难免有风风雨雨");//字体的位置*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali51.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"他总是能够轻松的应对");//字体的位置*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali5.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,120,"并且面带阳光、自信的笑容");//字体的位置*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali24.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,120,"生活也不会总是一帆风顺");//字体的位置*/
	Sleep(2000);loadimage(NULL, _T("fire\\iali46.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,130,"但他每次都能勇敢的面对");//字体的位置*/
	Sleep(2000);loadimage(NULL, _T("fire\\iali45.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(150,150,"但这不是他想要的人生，他需要一份真挚的爱情");//字体的位置*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali60.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,150,"但他依然乐观，微笑着，等待着");//字体的位置*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali16.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,100,"直到有一天与你相遇了");//字体的位置*/
	Sleep(2000);
	Mul();
		loadimage(NULL, _T("fire\\iali16.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,100,"我喜欢你，非常非常的喜欢，因为你的出现，我的脸上有了更加灿烂的笑容");//字体的位置*/
	Sleep(2000);
	Mul();
		loadimage(NULL, _T("fire\\iali37.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色iali11.jpg
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,100,"好几次失眠到很晚");//字体的位置*/
	Sleep(2000);
	Mul();
		loadimage(NULL, _T("fire\\iali11.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"脑海里一直浮现你的可爱的脸庞");//字体的位置*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali10.gif"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREEN为字的颜色，为绿色
	 settextstyle(30,0,"宋体");//300是字体高度，10是字体的宽度，0为默认值，“宋体”为字体
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"你接受我的表白的？我想和你一起走未来的路");
	// 按任意键退出
	//_getch();
	while(1);
	return 0;
	
}
void Mul()
{
	int n=0;
	srand(time(NULL));
	unsigned long t1=timeGetTime(); //x选择烟花弹的时候
	
	int i;
	for(i=0; i<13; i++)
	{
		Init(i);
	}
	IMAGE jetimg;
	loadimage(&jetimg,_T("fire\\捕获.PNG"),200,50);
	//putimage(0,0,&jetimg);
	//system("pause");
	SetWorkingImage(&jetimg);//set设置 working （正在工作的）image（图片对象）
	for(i=0;i<13;i++)
	{
		int n=rand()%5;    //0-4
		getimage(&jet[i].img[0],n*20,0,20,50); //获取图片
		getimage(&jet[i].img[0],(n+5)*20,0,20,50); //获取图片
	}

	SetWorkingImage(NULL);
	//printf("1\n");
	//putimage(0,0,&jet[1].img[0]);
	//system("pause");
	while(n<5000000)
	{
		n++;

		ChoiceJet(t1);
		Shoot();
		
	}

}
							//选择 烟花弹是有一个很快速的过程
void ChoiceJet(unsigned long &t1)  //时间间隔 来确定什么时候出现新的烟花弹
{
	unsigned long t2 = timeGetTime();
	if(t2-t1>100)
	{
		int n=rand()%20;
		if(n<13 && jet[n].shoot==false)
		{
			//重载烟花弹的数据
			jet[n].x=rand()%1200;
			jet[n].y=rand()%100+600;
			jet[n].hx=jet[n].x;
			jet[n].hy=rand()%400;
			jet[n].height =jet[n].y-jet[n].hy;
			jet[n].shoot=true;
			putimage(jet[n].x,jet[n].y,&jet[n].img[jet[n].n]);//0为暗色<-->1为亮色
		}
	}
}

void Shoot()
{
	for(int i=0;i<13;i++)
	{
		jet[i].t2=timeGetTime();
		if(jet[i].t2-jet[i].t1>jet[i].dt&&jet[i].dt&&jet[i].shoot==true)
		{
			putimage(jet[i].x,jet[i].y,&jet[i].img[jet[i].n],SRCINVERT);
		   if(jet[i].y>=jet[i].hy)
		   {
			   jet[i].y-=5;    //y坐标的变化 控制烟花弹上升的过程
			   jet[i].n++;      //0 1 0 1 0 1 0 1 0 1 0 
		   }
		   putimage(jet[i].x,jet[i].y,&jet[i].img[jet[i].n],SRCINVERT);
			jet[i].t1=jet[i].t2;
		}
	}

}

