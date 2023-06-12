// 菜单 书籍浏览 借还书
#include"showMenu.h"
#include"book.h"
#include"student.h"
#include"admin.h"
#include"libadmin.h"
#include"teacher.h"

struct Book
{
	string number;
	string name;
	string author;
	string publisher;
	double price;
	string status;// 未借出 借出
};

// 主菜单
int mainMenu()
{
	cout << "=============================" << endl;
	cout << "        菜单界面          " << endl;
	cout << "=============================" << endl;
	cout << "        1, 学生" << endl;
	cout << "        2，教师" << endl;
	cout << "        3，图书管理员" << endl;
	cout << "        4，系统管理员" << endl;
	cout << "        0,退出" << endl;
	cout << "=============================" << endl;
	int ret;
	cout << "请选择:";
	cin >> ret;
	system("cls");
	return ret;

}

// 注册登录菜单
int mainMenu2()
{
	cout << "=============================" << endl;
	cout << "        菜单界面          " << endl;
	cout << "=============================" << endl;
	cout << "        1,登录" << endl;
	cout << "        2,注册" << endl;
	cout << "        0,返回" << endl;
	cout << "=============================" << endl;
	int ret;
	cout << "请选择:";
	cin >> ret;
	system("cls");
	return ret;

}

// 学生菜单
void showStudentMenu()
{
	cout << "=============================" << endl;
	cout << "    欢迎来到图书馆系统！" << endl;

	cout << "    请选择要执行的操作：" << endl;

	cout << "    1. 浏览书籍" << endl;

	cout << "    2. 借书" << endl;

	cout << "    3. 还书" << endl;

	cout << "    0. 退出系统" << endl;
	cout << "=============================" << endl;
	int ret;
	cin >> ret;
	switch (ret)
	{

		case 1:// 列出书籍列表
		{
			showBooklist();
			break;
		}

		case 2:// 借书
		{
			borrowBook();
			break;

		}

		case 3: // 还书
		{
			returnBook();
			break;
		}




	}

}

// 图书管理员菜单
void showlibadminmenu()
{
	cout << "=============================" << endl;
	cout << "    欢迎图书管理员登录！" << endl;

	cout << "    请选择要执行的操作：" << endl;

	cout << "    1. 浏览书籍" << endl;

	cout << "    2. 修改书籍" << endl;

	cout << "    3. 添加书籍" << endl;

	cout << "    4. 删除书籍" << endl;

	cout << "    0. 退出系统" << endl;
	cout << "=============================" << endl;
	int ret;
	cout << "选择要执行的操作：" << endl;
	cin >> ret;
	switch (ret)
	{
		case 1:
			showBooklist();
			break;
		case 2:
			updateBookData();
			//TODO
			break;
		case 3:
			addbook();
		case 4:
			deletebook();
		default:

			break;
	}

}


void showadminmenu()
{
	cout << "=============================" << endl;
	cout << "    欢迎管理员登录！" << endl;
	cout << "    请选择要执行的操作：" << endl;
	cout << "    1. 书籍管理" << endl;
	cout << "    2. 学生管理" << endl;
	cout << "    3. 教师管理" << endl;
	cout << "    4. 图书管理员管理" << endl;
	cout << "    0. 退出系统" << endl;
	cout << "=============================" << endl;
	cout << "选择要执行的操作：" << endl;
	int ret;
	cin >> ret;
	switch (ret)
	{
		case 1:
			system("cls");
			showbookadmin();
			break;
		case 2:
			system("cls");
			showstudentadmin();
			break;
		case 3:
			system("cls");
			showteacheradmin();
		case 4:
			system("cls");
			showlibadmin();
		default:
			showadminmenu();
			break;
	}

}



void showstudentadmin()
{
	cout << "=============================" << endl;
	cout << "    1. 浏览学生" << endl;
	cout << "    2. 添加学生" << endl;
	cout << "    3. 删除学生" << endl;
	cout << "    4. 修改学生" << endl;
	cout << "    0. 返回上级" << endl;
	cout << "=============================" << endl;
	cout << "选择要执行的操作：" << endl;
	int ret;
	cin >> ret;
	switch (ret)
	{
		case 1:
			showstudentinfor();
			system("cls");
			return showstudentadmin();
			break;
		case 2:
			studentRegistration();
			system("cls");
			return showstudentadmin();
			break;
		case 3:
			deletestudent();
			system("cls");
			return showstudentadmin();
			break;
		case 4:
			resetstudent();
			system("cls");
			return showstudentadmin();
		default:
			return showadminmenu();
			break;
	}

}



void showteacheradmin()
{
	cout << "=============================" << endl;
	cout << "    1. 浏览教师" << endl;
	cout << "    2. 添加教师" << endl;
	cout << "    3. 删除教师" << endl;
	cout << "    4. 修改教师" << endl;
	cout << "    0. 返回上级" << endl;
	cout << "=============================" << endl;
	cout << "选择要执行的操作：" << endl;
	int ret;
	cin >> ret;
	switch (ret)
	{
		case 1:
			showteacher();
			return showteacheradmin();
			break;
		case 2:
			teacherRegistration();
			return showteacheradmin();
			//TODO
			break;
		case 3:
			deleteteacher();
			return showteacheradmin();
		case 4:
			resetteacher();
			return showteacheradmin();
		default:
			//TODO
			break;
	}

}





void showlibadmin()
{
	cout << "=============================" << endl;
	cout << "    1. 浏览图书管理员" << endl;
	cout << "    2. 添加图书管理员" << endl;
	cout << "    3. 删除图书管理员" << endl;
	cout << "    4. 修改图书管理员" << endl;
	cout << "    0. 返回上级" << endl;
	cout << "=============================" << endl;
	cout << "选择要执行的操作：" << endl;
	int ret;
	cin >> ret;
	switch (ret)
	{
		case 1:
			//TODO
			showlibadminlist();
			return showlibadmin();
			break;
		case 2:
			//TODO
			addlibadmin();
			return showlibadmin();
			break;
		case 3:
			deletelibadmin();
			return showlibadmin();
		case 4:
			resetlibadmin();
			return showlibadmin();
		default:
			//TODO
			break;
	}
}


void showbookadmin()
{
	showlibadminmenu();// 直接调用图书管理员菜单

}



