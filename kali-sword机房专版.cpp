#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include <userenv.h>
#include <lmcons.h>
#include <cctype>
#include <memory>
using namespace std;

int pw();
int options();
int show_logo();
int shell();
int loadcmd();
int wintop();//no input and output,put window to top
int winuntop();
int fread();//fast read,int i;i=fread();
void strtochar();//copy: charusrname,usrname;chardoname,doname
void cprint(const char*,int);//colorful print not c++ print,only print char,you can change it but i suggest dont do that;
void ready();//some loading process;
void getpcname(std::string&,std::string&);
void toLowerCase(std::string &, std::string &);
void cutpth(string,const char);//has something with cmd"cd" and "cd..".It is already shit so dont touch it.
bool directoryExists(const std::string&);//input a output a bool.
string getCmdResult(const string&);//get cmd result.Need a command in string'
string usrname;
string cmdpth[100]={"C:","Windows","System32"};
int cmdpthtop=2;
char charusrname[20];
string doname;
char chardoname[20];
string usrlist[15][2];
int usraut[15];
int usrlisttop=2;
int cmdnumber=50;
//string usrenter;
string nowcmd;
string cmdpara;
string nowopt;
DWORD hostnamesize;
string cmd[50];
string strcmd[50];
string strre;
string lchostname;
string lcusrname;
char hostname[256]="localhost";
int usrnumber;
int donumber;

int wintop() {
    HWND hWnd = GetConsoleWindow(); // 获取控制台窗口句柄
    if (hWnd != NULL) {
        // 将窗口置顶
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }
    return 0;
}
int winuntop() {
    HWND hWnd = GetConsoleWindow(); // 获取控制台窗口句柄
    if (hWnd != NULL) {
        // 取消窗口置顶
        SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }
    return 0;
}
int fread()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < 48 || ch > 57)
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= 48 && ch <= 57)
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
int main()
{
	wintop();
//	system("mode con cols=140 lines=40");
	ready();
	int tmp;
	tmp=pw();
	if (tmp!=100);
	else exit(0);
 	usrname=usrlist[tmp][0];
	doname=usrlist[tmp][0];
	donumber=tmp;
	usrnumber=tmp;
	system("cls");

	show_logo();
//	options();
	loadcmd();
	shell();
	return 0;
}
bool directoryExists(const std::string& path) {
    DWORD attrib = GetFileAttributesA(path.c_str());
    return (attrib != INVALID_FILE_ATTRIBUTES && (attrib & FILE_ATTRIBUTE_DIRECTORY));
}
void ready()
{
	//usrlist[usrname][usrpassword],usraut[usrnumber] ,0~10=max~min.
	usrlist[0][0]="Admin";
	usrlist[1][0]="User 1";
	usrlist[2][0]="User 2";
	usrlist[2][2]="Pwd2";
	usrlist[0][1]="Admin";
	usrlist[1][1]="Pwd1";
	usraut[0]=0;usraut[1]=1;usraut[2]=8;
	strcmd[1]="icacls C:\\windows\\system32\\sethc.exe /setowner Administrator /c && icacls C:\\Windows\\System32\\sethc.exe /grant Administrator:F /t";
	strcmd[2]="taskkill /f /t /im explorer.exe";
	strcmd[3]="icacls C:\\Windows\\explorer.exe /grant Administrator:F /t && icacls C:\\Windows\\system32\\taskmgr.exe /grant Administrator:F /t && cd c:\\windows && ren explorer.exe explorer1.exe && cd c:\\windows\\system32 && ren taskmgr.exe taskmgr1.exe";
	strcmd[4]="c:\\script\\1.bat";
 	strcmd[5]="c:\\script\\2.bat";
	strcmd[6]="c:\\script\\3.bat";
	strcmd[7]="c:\\script\\4.bat";
	strcmd[8]="c:\\script\\5.bat";
	strcmd[9]="c:\\script\\6.bat";
	strcmd[10]="c:\\script\\7.bat";
	strcmd[11]="c:\\script\\8.bat";
}
int pw()
{
	string password;
	char ch;
    printf("Enter password:");
//	scanf("%s", password);

	int i = 0;
	bool flag=1;
	while (flag)
	{
		ch=getch();
		switch((int)ch)
		{
			case 8:
				if(password.empty())
				  break;
				password.erase(password.end()-1);
				putchar('\b');
				putchar(' ');
				putchar('\b');
				break;
			case 27:
				exit(0);
				break;
			case 13:
				flag=0;
				break;
			default :password+=ch;putchar('*');break;
		}
        
		
	}
    if (password==usrlist[1][1]){
		return 1;}
    if (password==usrlist[0][1]){
		return 0;}
	if (password==usrlist[2][1]){
		return 2;}
	else return 100;
}

int gethost()
{
    hostnamesize = sizeof(hostname);
    GetComputerName(hostname, &hostnamesize);
}
//int options()
//{
//	cout<<"1 Admin CMD"<<endl;
//	cout<<"2 Taskmgr"<<endl;
//	cout<<"3 Windowsmgr"<<endl;
//	cout<<"4 About"<<endl;
//	cout<<"0 Exit"<<endl;
//}
int show_logo()
{
cprint("====================Kali Sword V1.3 Edu Version=====================",87);
cout<<endl;
cout<<"Special support for computer class.Usb device needed."<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<<"~~~~~~~~~~";cprint("KKKKKKK",87);cout<<"~~";cprint("KKKKKK",87);cout<<"~~~~~~~~~~~~~~~~~";cprint("KKKKKKK",87);cout<<"~~~~~";cprint("KKKKKKK",87);cout<<"~~~~~"<<endl;
cout<<"~~~~~~~~~~";cprint("KKKKKKK",87);cout<<"~~";cprint("KKKKKK",87);cout<<"~~~~~~~";cprint("KK",87);cout<<"~~~~~~~~~~";cprint("KKKKK",87);cout<<"~~~~~";cprint("KKKKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~~~~";cprint("KK",87);cout<<"~~~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~~~";cprint("KK",87);cout<<"~~~~~~~~~~~";cprint("KKKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~";cprint("KKK",87);cout<<"~~~~~~~~~~~~";cprint("K",87);cout<<"~";cprint("KKK",87);cout<<"~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKKKKK",87);cout<<"~~~~~~~~~~~~";cprint("KK",87);cout<<"~~";cprint("KK",87);cout<<"~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKKKKK",87);cout<<"~~~~~~~~~~~~";cprint("KKKKKK",87);cout<<"~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~";cprint("KKK",87);cout<<"~~~~~~~~~~~";cprint("KKKKKKK",87);cout<<"~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~~";cprint("KKK",87);cout<<"~~~~~~~~~";cprint("KK",87);cout<<"~~~~";cprint("KK",87);cout<<"~~~~~~~";cprint("KKK",87);cout<<"~~~~~~";cprint("K",87);cout<<"~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~~~~";cprint("KKK",87);cout<<"~~~~~~~";cprint("K",87);cout<<"~~~~~";cprint("KKK",87);cout<<"~~~~~~";cprint("KKK",87);cout<<"~~~~~~";cprint("K",87);cout<<"~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~";cprint("KKK",87);cout<<"~~~~~";cprint("KK",87);cout<<"~~~~~~";cprint("KK",87);cout<<"~~~~~~";cprint("KKK",87);cout<<"~~~~~";cprint("KK",87);cout<<"~~";cprint("KKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~";cprint("KKK",87);cout<<"~~~~~";cprint("KKKK",87);cout<<"~~~~";cprint("KKKK",87);cout<<"~~~~";cprint("KK",87);cout<<"~~~~~~";cprint("KKKKKKKKKKKKKKK",87);cout<<"~~~~~~~";cout<<endl;
cout<<"~~~~~~~~~~";cprint("KKKKKKK",87);cout<<"~~";cprint("KKKKKKKKKKKKK",87);cout<<"~~";cprint("KKKKKK",87);cout<<"~~";cprint("KKKKKKKKKKKKKKKKKKK",87);cout<<"~~~~~";cout<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";cout<<endl;
}
void cprint(const char* s, int color)
{
 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
 cout<<s;
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}
void getpcname(std::string &lchostname, std::string &lcusrname) {
    // 获取计算机名
    TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName) / sizeof(computerName[0]);
    if (GetComputerName(computerName, &size)) {
        lchostname = computerName;
    } else {
        lchostname = "Unknown";
    }

    // 获取当前用户名称
    TCHAR username[UNLEN + 1];
    size = sizeof(username) / sizeof(username[0]);
    if (GetUserName(username, &size)) {
        lcusrname = username;
    } else {
        lcusrname = "Unknown";
    }
}
void strtochar()
{
	strcpy(charusrname,usrname.c_str());
	strcpy(chardoname,doname.c_str());
}
string getCmdResult(const string &strCmd)
{
    char buf[102400] = {0};
    FILE *pf = NULL;

    if( (pf = popen(strCmd.c_str(), "r")) == NULL )
    {
        return "";
    }

    string strResult;
    while(fgets(buf, sizeof buf, pf))
    {
        strResult += buf;
    }

    pclose(pf);

    unsigned int iSize =  strResult.size();
    if(iSize > 0 && strResult[iSize - 1] == '\n')  
    {
        strResult = strResult.substr(0, iSize - 1);
    }

    return strResult;
}
int loadcmd()
{
	cmd[1]="cmd";
	cmd[2]="taskmgr";
	cmd[3]="help";
	cmd[4]="whoami";
	cmd[5]="time";
	cmd[6]="switchuser";
	cmd[7]="runas";
	cmd[8]="sethc";
	cmd[9]="cd";
	cmd[10]="winuntop";
	cmd[11]="clear";
	cmd[12]="script";
	cmd[13]="about";
	cmd[14]="setpth";
	cmd[15]="exit";
	cmd[16]="top";
	cmd[17]="class";
}
void toLowerCase(std::string &nowcmd, std::string &cmdpara) {
    for (size_t i = 0; i < nowcmd.length(); ++i) {
    nowcmd[i] = std::tolower(static_cast<unsigned char>(nowcmd[i]));}
    for (size_t i = 0; i < cmdpara.length(); ++i) {
    cmdpara[i] = std::tolower(static_cast<unsigned char>(cmdpara[i]));}
}
int jiyu() {
    // 创建一个安全属性，允许继承句柄
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    // 命令行参数，例如在CMD中执行 "echo Hello World"
    std::wstring commandLine = L"cmd /c x:\\kswordrc\\class\\1.exe";

    STARTUPINFOW startupInfo = { sizeof(STARTUPINFOW) };
    PROCESS_INFORMATION processInfo;

    if (!CreateProcessW(
        NULL,               // 应用程序名称
        const_cast<LPWSTR>(commandLine.c_str()), // 命令行参数
        &sa,               // 进程安全性属性
        &sa,               // 线程安全性属性
        TRUE,               // 继承句柄
        0,                  // 根据CREATE_NEW_CONSOLE创建新控制台
        NULL,               // 使用父进程的环境块
        NULL,               // 用当前目录启动
        &startupInfo,      // 启动信息
        &processInfo       // 接收新创建的进程信息
    )) {
        std::cerr << "CreateProcess failed: " << GetLastError() << std::endl;
        return 1;
    }

    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);

    std::cout << "The command has been sent to the new CMD window." << std::endl;
    return 0;
}
void cutpth(string str,const char split)
{
	istringstream iss(str);
	string token;
	
	for (int i=0;i<=cmdpthtop;i++)
	{
	cmdpth[i]="";
	}
	cmdpthtop=0;
	while (getline(iss, token, split))
	{
		cmdpth[cmdpthtop++]=token;
	}
	cmdpthtop--;
}
int shell()
{
	shellstart:strtochar();
	getpcname(lchostname,lcusrname);
	if(doname!=usrname)
	{
	cout<<"┌";
	cout<<"[";
	cprint(charusrname,70);
	cout<<"=>";
	cprint(chardoname,60);
	cout<<"@";
	cout<<lchostname;
	cout<<"]";
	}
	else
	{
	cout<<"┌";
	cout<<"[";
	cprint(charusrname,70);
	cout<<"@";
	cout<<lchostname;
	cout<<"]";
	}

	cout<<"~[";
	if(lcusrname=="SYSTEM")
	cprint("System",70);
	else cout<<lcusrname;
	cout<<'@'<<lchostname<<']';
	cout<<endl;
	cout<<"└";
	for(int i=0;i<=cmdpthtop;i++)
	{
	cout<<cmdpth[i];
	cout<<"\\";
	}
	cout<<">";
	getline(cin,nowcmd);
 	size_t spacePos = nowcmd.find(' ');
    if (spacePos != std::string::npos)
	{ 
		cmdpara = nowcmd.substr(spacePos + 1);
		nowcmd = nowcmd.substr(0, spacePos);
    }
    toLowerCase(nowcmd, cmdpara);
	if (nowcmd=="cd..")
	{
		if(cmdpthtop>=1)
		{
			cmdpth[cmdpthtop]="";
			cmdpthtop--;
		}
		else
		{
			cprint("[ x ]",4);
			cout<<"Already reach root!"<<endl;
		}
	}
	else if (nowcmd==cmd[1])
	{
		if (usraut[donumber]>=6){
		cprint("[ ! ]",6);
		cout<<"Insufficient authority"<<endl;
		cprint("[ x ]",4);
		cout<<"The operation did not complete successfully!"<<endl;
		}
		cprint("[ ! ]",6);
		cout<<"type exit to quit."<<endl;
		system("c:\\windows\\system32\\cmd.exe");
	}
	else if (nowcmd==cmd[2])
	{
		if (usraut[donumber]>=6){
		cprint("[ ! ]",6);
		cout<<"Insufficient authority"<<endl;
		cprint("[ x ]",4);
		cout<<"The operation did not complete successfully!"<<endl;
		}
		system("c:\\windows\\system32\\taskmgr.exe");
	}
	else if (nowcmd==cmd[3])
	{
		cout<<"Help:all the commands are as following:";
		for(int i=0;i<=cmdnumber;i++)
		cout<<cmd[i]<<' ';
		cout<<"."<<endl;cout<<"Enter the command name that you want to learn about:(c for cancel)";
		string helpcmd;
		getline(cin,helpcmd);
		if (helpcmd==cmd[1]){cout<<"Enter cmd so that we'll start a cmd.exe for you with system privileges."<<endl;}
		else if (helpcmd==cmd[2]){cout<<"Enter to run taskmgr.exe."<<endl;}
		else if (helpcmd==cmd[3]){cout<<"How can you even don't know how to use help command?"<<endl;}
		else if (helpcmd==cmd[4]){cout<<"This command has been deprecated, and typing this command now gives the console program execution permission."<<endl;}
		else if (helpcmd==cmd[5]){cout<<"Just to get the time."<<endl;}
		else if (helpcmd==cmd[6]){cout<<"Switch user of Kali-sword.This requires that user's password.You can try runas if you don't have theirs."<<endl;}
		else if (helpcmd==cmd[7]){cout<<"A user with higher permissions can operate as a lower user without entering a password. The reverse is required. This changes the recorded results in the log."<<endl;}
		else if (helpcmd==cmd[8]){cout<<"Replace the sethc.exe(shift*5) with Kali-sword.This command may doesn't work."<<endl;}
		else if (helpcmd==cmd[9]){cout<<"Use it like on Windows cmd or linux shell.We support \"cd..\"and\"cd <dir>"<<endl;}
		else if (helpcmd==cmd[10]){cout<<"Untop your window."<<endl;}
		else if (helpcmd==cmd[11]){cout<<"Clean all output."<<endl;}
		else if (helpcmd==cmd[12]){cout<<"Run user script.You can copy your scripts(only *.bat supported) to C:\\script(Create one if there's not one) and renamed it with the number 1~10."<<endl;}
		else if (helpcmd==cmd[13]){cout<<"Show something about the Developer."<<endl;}
		else if (helpcmd==cmd[14]){cout<<"set cmd path.If you enter a command that is not included in Kali-sword,we will use cmd to run it.And it will reset the cmd path to C:\\Windows\\system32 every time when you enter a new command.This will change it.Make sure the path you enter is available!"<<endl;}
		else if (helpcmd==cmd[15]){cout<<"Log out and stop Kali-sword."<<endl;}
		else if (helpcmd==cmd[16]){cout<<"top your window."<<endl;}
		else if (helpcmd==cmd[17]){cout<<"Helper for your computer class."<<endl;}
		else if (helpcmd=="c");
		else 	{cprint("[ x ]",4);cout<<"command not found!"<<endl;}
	}
//		else if (nowcmd==cmd[4])
//		{
//			cprint("[ ! ]",6);
//			cout<<"You are "<<usrname<<"@";
//			cprint(hostname,4);
//			cout<<endl;
//			continue;
//		}
	else if (nowcmd==cmd[5])
	{
   		time_t timep;
   		time(&timep);
   		printf("%s", ctime(&timep));
	}
	else if (nowcmd==cmd[6])
	{
		int tmp;
		tmp=pw();
		if (tmp!=100)
		{usrname=usrlist[tmp][0];
		doname=usrlist[tmp][0];
		donumber=tmp;
		usrnumber=tmp;
		system("cls");
		}
		else {
		cprint("[ ! ]",6);
		cout<<"password incorrect!"<<endl;
		cprint("[ x ]",4);
		cout<<"login failed!"<<endl;
			}
	}
	else if (nowcmd==cmd[7])
	{
		int tmp,tmp1;
		cprint("[ ! ]",6);
		cout<<"choose a user(number):"<<endl;
		for(int i=0;i<=usrlisttop;i++)
		cout<<usrlist[i][0]<<endl;
		tmp=fread();
		if (tmp>usrlisttop)
		{cprint("[ x ]",4);cout<<"user not found!"<<endl;}
		else if (usraut[tmp]<usraut[usrnumber])
		{
  		cprint("[ ! ]",6);
		cout<<"Migration to higher level permissions is not allowed,but you can change it by entering their passwords."<<endl;
		tmp1=pw();
		cout<<endl;
		if (tmp1!=100)
		{
			doname=usrlist[tmp1][0];
			donumber=tmp1;
		}
		else
		{cprint("[ x ]",4);
		cout<<"Password incorrect!"<<endl;
		}
		}
		else
		{doname=usrlist[tmp][0];
		donumber=tmp;
		cprint("[ * ]",9);cout<<"Operation completed successfully!"<<endl;}
	}
	else if (nowcmd==cmd[8])
	{
		int tmp;
		cprint("[ ! ]",6);
		cout<<"This command is broken.Continur?(0/1):";
		cin>>tmp;cout<<endl;if (tmp==0);else if(tmp!=1){cprint("[ ! ]",6);
		cout<<"Wrong input!please try this command later."<<endl;}
		cprint("[ ! ]",6);
		cout<<"This will distroy original sethc.exe!Continue?(0/1):";
		cin>>tmp;cout<<endl;if (tmp==0);else if(tmp!=1){cprint("[ ! ]",6);
		cout<<"Wrong input!please try this command later."<<endl;
		}
		strre=getCmdResult(strcmd[1]);
		cout << strre << endl;
		strre="";
	}
	else if (nowcmd==cmd[9])
	{
		int tmp;
		string newDir;
		for (int i=0;i<=cmdpthtop;i++)
		{newDir += cmdpth[i] + "\\";}
		newDir+=cmdpara;
    	if (directoryExists(newDir)) {
        // 如果存在，更新cmdpth
		if (cmdpara.find('\\') != std::string::npos){
		size_t startPos = 0; // 初始位置
    	size_t endPos = cmdpara.find_first_of('\\');
    	while (endPos != std::string::npos) {
        // 将找到的部分添加到数组中
        cmdpth[++cmdpthtop] = cmdpara.substr(startPos, endPos - startPos);
        // 更新起始位置，继续查找下一个反斜杠
        startPos = endPos + 1;
        endPos = cmdpara.find_first_of('\\', startPos);
    	}
    	// 添加最后一个部分
    	cmdpth[++cmdpthtop] = cmdpara.substr(startPos);
		}
    	// 将最后一个部分添加到数组中
  		else{
		cmdpth[++cmdpthtop]+=cmdpara;
		}
		}
		else cout<<"系统找不到指定的文件或路径。"<<endl;
	}
	else if (nowcmd==cmd[10])
	{
		winuntop();
	}
	else if (nowcmd==cmd[11])
	{
		system("cls");}
	else if (nowcmd==cmd[12])
	{
		if (usraut[donumber]>=6){
		cprint("[ ! ]",6);
		cout<<"Insufficient authority"<<endl;
		cprint("[ x ]",4);
		cout<<"The operation did not complete successfully!"<<endl;
		}
		int tmp;
		cprint("[ ! ]",6);
		cout<<"Enter your script number:";
		cin>>tmp;
		strre=getCmdResult(strcmd[tmp+3]);
		cout << strre << endl;
		strre="";
    }
    else if (nowcmd==cmd[13])
    {
		cprint("This Program is KALI_SWORD",113);cout<<endl;
		cprint("Developed by WangWei_CM.",23);cout<<endl;
		cprint("Welcome to visit my website:159.75.66.16",56);cout<<endl;
		cprint("Kali-Weidows ICS is available!",74);cout<<endl;
		system("start https://ylhcwwtx.icoc.vc");
	}
	else if (nowcmd==cmd[14])
	{
		string tmp;
		cprint("[ ! ]",6);
		cout<<"Enter default cmd path:";
		getline(cin,tmp);
		cutpth(tmp,'\\');
		}
	else if (nowcmd==cmd[16])
	{
		wintop();
	}
	else if (nowcmd==cmd[17])
	{
		int nextshell=1,fileexist=0;
		FILE *file = fopen("x:\\kswordrc\\class\\1.exe", "r");//1.exe是jiyu杀手，2是机房小助手杀手。
    		if (file != NULL) {fileexist=1;fclose(file);} else {fileexist=0;cprint("[ x ]",4);cout<<"File not exist!"<<endl;}
		while(nextshell)
		{
			cout<<"ClassHelper >";
			getline(cin,nowcmd);
 			size_t spacePos = nowcmd.find(' ');
   		 	if (spacePos != std::string::npos)
			{
				cmdpara = nowcmd.substr(spacePos + 1);
				nowcmd = nowcmd.substr(0, spacePos);
    		}
			if(fileexist==1){
			if(nowcmd=="jiyu"){if (cmdpara=="-s"){system("x:\\kswordrc\\class\\1.exe -hidden");continue;}else if(cmdpara=="-k"){system("x:\\kswordrc\\class\\1.exe -killst");continue;}else{jiyu();continue;}}
			if(nowcmd=="jifang"){system("x:\\kswordrc\\class\\2.exe");continue;}}
			if(nowcmd=="help"){cout<<"jiyu:Run JiyuTrainer(-s:silence;-k:kill jiyu)"<<endl<<"jifang:Run JifangZhushou-killer,F4 to kill kifangzhushou,F6 to kill Jiyu"<<endl<<"exit:quit"<<endl;continue;}
			if(nowcmd=="exit"){nextshell=0;break;}
			if(nowcmd=="")continue;
			cprint("[ x ]",4);
			cout<<"Command not found!"<<endl;
		}
	}
	else if (nowcmd=="")
	{
		goto shellstart;
	}
	else if (nowcmd!=cmd[15])
	{
		string cmdcmd="cd ";
		for(int i=0;i<=cmdpthtop;i++){cmdcmd+=cmdpth[i];
		cmdcmd+="\\";}
		cmdcmd=cmdcmd+" && "+nowcmd+' '+cmdpara;
		strre=getCmdResult(cmdcmd);
		cout<<strre<<endl;
	}
	else if (nowcmd==cmd[15])
	{
	cprint("[ ! ]",6);
	cout<<"System is about to close..."<<endl;
	cprint("[ * ]",9);
	cout<<"Logging out..."<<endl;
	usrname="";
	memset(charusrname,'\0',sizeof(charusrname));
	usrname="";
	memset(charusrname,'\0',sizeof(charusrname));
	system("cls");
	return 0;
	}
	goto shellstart;
}

