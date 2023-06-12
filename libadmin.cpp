#include"libadmin.h"
#include"showMenu.h"

struct LibAdmin {
	std::string account;
	std::string password;
};

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




// 添加图书管理员
int addlibadmin() {
	std::string account, password;
	
	std::cout << "请输入图书管理员账户：";
	std::cin >> account;
	std::cout << "请输入密码：";
	std::cin >> password;
	
	std::ofstream outputFile("libadmin.txt", std::ios::app);
	if (!outputFile) {
		std::cerr << "无法打开文件进行写入。" << std::endl;
		return 1;
	}
	
	outputFile << account << " " << password << std::endl;
	outputFile.close();
	
	std::cout << "图书管理员信息添加成功。" << std::endl;
	
	return 0;
}



// 修改图书管理员
int resetlibadmin() {
	std::ifstream inputFile("libadmin.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	std::vector<LibAdmin> admins;
	LibAdmin admin;
	while (inputFile >> admin.account >> admin.password) {
		admins.push_back(admin);
	}
	
	inputFile.close();
	
	std::string updateAccount;
	std::cout << "请输入要修改的图书管理员账户：";
	std::cin >> updateAccount;
	
	bool found = false;
	for (auto& admin : admins) {
		if (admin.account == updateAccount) {
			std::cout << "请输入修改后的密码：";
			std::cin >> admin.password;
			
			found = true;
			break;
		}
	}
	
	if (found) {
		std::ofstream outputFile("libadmin.txt");
		if (!outputFile) {
			std::cerr << "无法打开文件进行写入。" << std::endl;
			return 1;
		}
		
		for (const auto& admin : admins) {
			outputFile << admin.account << " " << admin.password << std::endl;
		}
		
		outputFile.close();
		
		std::cout << "图书管理员信息修改成功。" << std::endl;
	} else {
		std::cout << "未找到指定的图书管理员账户，修改失败。" << std::endl;
	}
	
	return 0;
}


// 删除图书管理员
int deletelibadmin() {
	std::ifstream inputFile("libadmin.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	std::vector<LibAdmin> admins;
	LibAdmin admin;
	while (inputFile >> admin.account >> admin.password) {
		admins.push_back(admin);
	}
	
	inputFile.close();
	
	std::string deleteAccount;
	std::cout << "请输入要删除的图书管理员账户：";
	std::cin >> deleteAccount;
	
	bool found = false;
	for (auto it = admins.begin(); it != admins.end(); ++it) {
		if (it->account == deleteAccount) {
			admins.erase(it);
			found = true;
			break;
		}
	}
	
	if (found) {
		std::ofstream outputFile("libadmin.txt");
		if (!outputFile) {
			std::cerr << "无法打开文件进行写入。" << std::endl;
			return 1;
		}
		
		for (const auto& admin : admins) {
			outputFile << admin.account << " " << admin.password << std::endl;
		}
		
		outputFile.close();
		
		std::cout << "图书管理员信息删除成功。" << std::endl;
	} else {
		std::cout << "未找到指定的图书管理员账户，删除失败。" << std::endl;
	}
	
	return 0;
}

//展示图书管理员

int showlibadminlist() {
	std::ifstream inputFile("libadmin.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	std::vector<LibAdmin> admins;
	LibAdmin admin;
	while (inputFile >> admin.account >> admin.password) {
		admins.push_back(admin);
	}
	
	inputFile.close();
	
	// 显示图书管理员信息
	std::cout << "图书管理员信息：" << std::endl;
	for (const auto& admin : admins) {
		std::cout << "账户：" << admin.account << "\t密码：" << admin.password << std::endl;
	}
	
	return 0;
}
