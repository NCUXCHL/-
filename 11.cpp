//#undef UNICODE
//#undef _UNICODE
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include <windows.h>
#include <mmsystem.h>//��������ͷ�ļ�
#pragma comment(lib,"Winmm.lib")

#define PI 3.1415926528   //��

struct JET
{
	int x, y;     //����
	int hx,hy;    //��ߵ������
	int height;   //�߶� y-hy
	bool shoot;    //�Ƿ���Է���

	unsigned long t1, t2, dt;   //����ʱ��  �������������ٶ�
	IMAGE img[2];       //��������ͼƬ����������
	byte  n:1;			//λ�� n���� ֻ��Ҫһ��λ�����  int a; a �м���λ���ĸ��ֽ� 8��λ 32
}jet[13];         //����13���̻���

void Shoot();
void Mul();
void ChoiceJet(DWORD &t1);
void Init(int i)
{
	//��ʼ���̻���
	jet[i].x=0;
	jet[i].y=0;
	jet[i].hx=0;
	jet[i].hy=0;
	jet[i].height=0;
	jet[i].n=0;

	jet[i].shoot=false;     //��ʱû�з����
	jet[i].t1=timeGetTime();//��ȡϵͳʱ��
	jet[i].dt=rand()%10;		//0-9
}

void Welcome()
{
	int i;
	int x1,y1;
	settextcolor(YELLOW);
	
	outtextxy(200,100,"�������˽�");
	outtextxy(500,160,"�׸�ĳĳĳ");
	
	for(i=0;i<50;i++)//��ʮ����
	{
		//system("cls");//����̨����
		cleardevice();//����cleardevice��һ�����������������ͼ����Ļ��
		x1=600+(180*sin(PI*2*i/60));
		y1=200+(180*cos(PI*2*i/60));
		settextstyle(i,0,"����");
		outtextxy(x1,y1,"����Ԫ��");
		outtextxy(x1+50,y1+100,"�׸�***ͬѧ");
		Sleep(25);
	}
		Sleep(5000);
		//getchar();//�ȴ����̲��������»س�������
		cleardevice();
		settextstyle(25,0,"����");
		outtextxy(400,200,"ʱ�䲻����д�˽�֣�");
		outtextxy(400,250,"��û���ü�˵�ټ���");
		outtextxy(400,300,"ʱ�䲻����д�˿�ʼ��");
		outtextxy(400,350,"��û�µ�Ҫ��˭�����");
		outtextxy(400,400,"ʱ�䲻����д��ףԸ��");
		outtextxy(400,450,"ף��Ԫ��һ��ƽƽ������");
		outtextxy(600,500,"----xchlͬѧ");	
		Sleep(5000);
}
/*�̻���*/


// ������
int main()
{
	int n;
	
	// ��ͼ������ʼ��
	initgraph(1200, 1000);

	// ��ȡͼƬ����ͼ����
	//loadimage(NULL, _T("C:\\Users\\������XCHL\\Pictures\\WIN_20181122_11_58_43_Pro.jpg"),1200, 1000);

	// ��������˳�
	//_getch();


	//����
	 PlaySound(TEXT("Debug\\WAV-��С����--����硷DTS-2018�ܻ�ӭŮ����2CD.wav"),NULL,SND_FILENAME | SND_ASYNC);
	
	 //���� ������ɫ ���ֵĸ�ʽ
	Welcome();
	/*setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	 outtextxy(1,300,"������xchl");//�����λ��*/
	//PlaySound(TEXT("Debug\\WAV-��С����--����硷DTS-2018�ܻ�ӭŮ����2CD.wav"),NULL, SND_RESOURCE | SND_ASYNC |SND_LOOP);
	
	system("cls");
	for(n=0;n<3;n++)
	{
	 Mul();
	}
	 // ��ͼ������ʼ��
	//initgraph(1200, 1000);

	Sleep(10000);
	PlaySound(NULL,NULL,NULL); //ֹͣ����*/
	// ��ȡͼƬ����ͼ����
	PlaySound(TEXT("Debug\\�кβ��� - ����.wav"),NULL,SND_FILENAME | SND_ASYNC);
	loadimage(NULL, _T("C:\\Users\\������XCHL\\Desktop\\picture-Word\\fire\\iali53.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	outtextxy(100,250,"һ�������ж���Ԫ�����:");
	 outtextxy(100,300,"xchl love ������");//�����λ��*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali63.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(150,100,"��ȥ����һֱ��һ������������Ź¶���Ҳ���Ű��顣");//�����λ��*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali35.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,130,"һ���˵ĳ���");//�����λ��*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali6.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,550,"һ���˵�ɽ��");//�����λ��*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali60.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,100,"������Ȼ�ֹۣ�΢Ц�ţ��ȴ���");//�����λ��*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali60.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"���������з������");//�����λ��*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali51.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"�������ܹ����ɵ�Ӧ��");//�����λ��*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali5.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,120,"����������⡢���ŵ�Ц��");//�����λ��*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali24.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,120,"����Ҳ��������һ����˳");//�����λ��*/
	Sleep(2000);loadimage(NULL, _T("fire\\iali46.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,130,"����ÿ�ζ����¸ҵ����");//�����λ��*/
	Sleep(2000);loadimage(NULL, _T("fire\\iali45.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(150,150,"���ⲻ������Ҫ������������Ҫһ����ֿ�İ���");//�����λ��*/
	Sleep(2000);
	loadimage(NULL, _T("fire\\iali60.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,150,"������Ȼ�ֹۣ�΢Ц�ţ��ȴ���");//�����λ��*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali16.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,100,"ֱ����һ������������");//�����λ��*/
	Sleep(2000);
	Mul();
		loadimage(NULL, _T("fire\\iali16.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(200,100,"��ϲ���㣬�ǳ��ǳ���ϲ������Ϊ��ĳ��֣��ҵ��������˸��Ӳ��õ�Ц��");//�����λ��*/
	Sleep(2000);
	Mul();
		loadimage(NULL, _T("fire\\iali37.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫiali11.jpg
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,100,"�ü���ʧ�ߵ�����");//�����λ��*/
	Sleep(2000);
	Mul();
		loadimage(NULL, _T("fire\\iali11.jpg"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"�Ժ���һֱ������Ŀɰ�������");//�����λ��*/
	Sleep(2000);
	Mul();
	loadimage(NULL, _T("fire\\iali10.gif"),1200,800);

	Sleep(5000);
	setbkmode(0);
	 settextcolor(RED);        //GREENΪ�ֵ���ɫ��Ϊ��ɫ
	 settextstyle(30,0,"����");//300������߶ȣ�10������Ŀ�ȣ�0ΪĬ��ֵ�������塱Ϊ����
	 //outtextxy(midx, midy, "This is a test.");
	
	 outtextxy(100,120,"������ҵı�׵ģ��������һ����δ����·");
	// ��������˳�
	//_getch();
	while(1);
	return 0;
	
}
void Mul()
{
	int n=0;
	srand(time(NULL));
	unsigned long t1=timeGetTime(); //xѡ���̻�����ʱ��
	
	int i;
	for(i=0; i<13; i++)
	{
		Init(i);
	}
	IMAGE jetimg;
	loadimage(&jetimg,_T("fire\\����.PNG"),200,50);
	//putimage(0,0,&jetimg);
	//system("pause");
	SetWorkingImage(&jetimg);//set���� working �����ڹ����ģ�image��ͼƬ����
	for(i=0;i<13;i++)
	{
		int n=rand()%5;    //0-4
		getimage(&jet[i].img[0],n*20,0,20,50); //��ȡͼƬ
		getimage(&jet[i].img[0],(n+5)*20,0,20,50); //��ȡͼƬ
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
							//ѡ�� �̻�������һ���ܿ��ٵĹ���
void ChoiceJet(unsigned long &t1)  //ʱ���� ��ȷ��ʲôʱ������µ��̻���
{
	unsigned long t2 = timeGetTime();
	if(t2-t1>100)
	{
		int n=rand()%20;
		if(n<13 && jet[n].shoot==false)
		{
			//�����̻���������
			jet[n].x=rand()%1200;
			jet[n].y=rand()%100+600;
			jet[n].hx=jet[n].x;
			jet[n].hy=rand()%400;
			jet[n].height =jet[n].y-jet[n].hy;
			jet[n].shoot=true;
			putimage(jet[n].x,jet[n].y,&jet[n].img[jet[n].n]);//0Ϊ��ɫ<-->1Ϊ��ɫ
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
			   jet[i].y-=5;    //y����ı仯 �����̻��������Ĺ���
			   jet[i].n++;      //0 1 0 1 0 1 0 1 0 1 0 
		   }
		   putimage(jet[i].x,jet[i].y,&jet[i].img[jet[i].n],SRCINVERT);
			jet[i].t1=jet[i].t2;
		}
	}

}

