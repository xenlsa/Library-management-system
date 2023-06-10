#include"libadmin.h"
#include"showMenu.h"
int libadminlogin()
{
	ifstream inputFile("libadmin.txt");
	if (!inputFile)
	{
		cerr << "无法打开文件进行读取。" << endl;
		return 1;
	}

	string inputUsername, inputPassword;
	cout << "请输入账户：";
	cin >> inputUsername;
	cout << "请输入密码：";
	cin >> inputPassword;

	string username, password;
	bool loginSuccessful = false;
	while (inputFile >> username >> password)
	{
		if (username == inputUsername && password == inputPassword)
		{
			loginSuccessful = true;
			break;
		}
	}

	inputFile.close();

	if (loginSuccessful)
	{
		cout << "登录成功！" << endl;
		system("pause");
		system("cls");
		showlibadminmenu();
		return 1;
	}
	else
	{
		cout << "登录失败，请检查账户和密码。" << endl;
		return libadminlogin();
	}

	return 0;
}
