#include"admin.h"
#include"showMenu.h"
//管理员登录
int adminlogin()
{
	std::string username, password;
	
	std::cout << "请输入用户名：";
	std::cin >> username;
	
	std::cout << "请输入密码：";
	std::cin >> password;
	
	if (username == "admin" && password == "123456") {
		std::cout << "登录成功！" << std::endl;
		system("pause");
		system("cls");
		showadminmenu();
	} else {
		std::cout << "用户名或密码错误，登录失败！" << std::endl;
	}
	
	return 0;
}
