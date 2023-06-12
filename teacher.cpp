#include "teacher.h"

//教师结构体
struct Teacher {
	std::string id;
	std::string password;
	std::string name;
	std::string gender;
	int age;
	std::string email;
};


// 教师登录
int teacherLogin() {
		std::ifstream inputFile("teacher.txt");
		if (!inputFile) {
			std::cerr << "无法打开文件进行读取。" << std::endl;
			return 1;
		}
		
		std::vector<Teacher> teachers;
		std::string line;
		while (std::getline(inputFile, line)) {
			std::istringstream iss(line);
			Teacher teacher;
			iss >> teacher.id >> teacher.password >> teacher.name >> teacher.gender >> teacher.age >> teacher.email;
			teachers.push_back(teacher);
		}
		
		inputFile.close();
		
		// 获取教师工号和密码
		std::string inputID, inputPassword;
		std::cout << "请输入工号：";
		std::cin >> inputID;
		std::cout << "请输入密码：";
		std::cin >> inputPassword;
		
		bool loginSuccessful = false;
		for (const auto& teacher : teachers) {
			if (teacher.id == inputID && teacher.password == inputPassword) {
				loginSuccessful = true;
				break;
			}
		}
		
		if (loginSuccessful) {
			std::cout << "登录成功！" << std::endl;
			system("pause");
			system("cls");
			return 1;
		} else {
			std::cout << "登录失败，请检查工号和密码。" << std::endl;
		}
		
		return 0;
	}
	



// 教师注册
void teacherRegistration()
{
	std::ofstream outputFile("teacher.txt", std::ios::app); // 打开文件进行追加写入
	if (!outputFile) {
		std::cerr << "无法打开文件用于写入。" << std::endl;
		
	}
	
	// 获取教师信息
	std::string teacherID, password, name, gender, age, email;
	std::cout << "请输入工号：";
	std::cin >> teacherID;
	std::cout << "请输入密码：";
	std::cin >> password;
	std::cin.ignore(); // 忽略之前输入的换行符
	std::cout << "请输入姓名：";
	std::getline(std::cin, name);
	std::cout << "请输入性别：";
	std::cin >> gender;
	std::cout << "请输入年龄：";
	std::cin >> age;
	std::cout << "请输入邮箱：";
	std::cin >> email;
	
	// 将教师信息写入文件
	outputFile << teacherID << " " << password << " " << name << " " << gender << " " << age << " " << email << "\n";
	outputFile.close();
	
	std::cout << "注册成功！已将教师信息保存到文件中。" << std::endl;
	
}

// 展示教师列表
int showteacher() {
	std::ifstream inputFile("teacher.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	std::vector<Teacher> teachers;
	Teacher teacher;
	while (inputFile >> teacher.id >> teacher.password >> teacher.name >> teacher.gender >> teacher.age >> teacher.email) {
		teachers.push_back(teacher);
	}
	
	inputFile.close();
	
	int pageSize = 5;
	int totalPages = (teachers.size() + pageSize - 1) / pageSize;
	
	int page;
	std::cout << "请输入要展示的页码（1-" << totalPages << "）：";
	std::cin >> page;
	
	if (page < 1 || page > totalPages) {
		std::cout << "无效的页码。" << std::endl;
		return 0;
	}
	
	int startIndex = (page - 1) * pageSize;
	int endIndex = startIndex + pageSize;
	
	std::cout << "教师信息 - 第 " << page << " 页：" << std::endl;
	for (int i = startIndex; i < endIndex && i < teachers.size(); ++i) {
		std::cout << "工号： " << teachers[i].id << std::endl;
		std::cout << "姓名： " << teachers[i].name << std::endl;
		std::cout << "性别： " << teachers[i].gender << std::endl;
		std::cout << "年龄： " << teachers[i].age << std::endl;
		std::cout << "邮箱： " << teachers[i].email << std::endl;
		std::cout << std::endl;
	}
	system("pause");
	
	return 0;
}


int deleteteacher() {
	std::ifstream inputFile("teacher.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	std::vector<Teacher> teachers;
	Teacher teacher;
	while (inputFile >> teacher.id >> teacher.password >> teacher.name >> teacher.gender >> teacher.age >> teacher.email) {
		teachers.push_back(teacher);
	}
	
	inputFile.close();
	
	std::string deleteId;
	std::cout << "请输入要删除的教师工号：";
	std::cin >> deleteId;
	
	bool found = false;
	auto it = teachers.begin();
	while (it != teachers.end()) {
		if (it->id == deleteId) {
			it = teachers.erase(it);
			found = true;
		} else {
			++it;
		}
	}
	
	if (found) {
		std::ofstream outputFile("teacher.txt");
		if (!outputFile) {
			std::cerr << "无法打开文件进行写入。" << std::endl;
			return 1;
		}
		
		for (const auto& teacher : teachers) {
			outputFile << teacher.id << " " << teacher.password << " " << teacher.name << " "
			<< teacher.gender << " " << teacher.age << " " << teacher.email << std::endl;
		}
		
		outputFile.close();
		
		std::cout << "教师信息删除成功。" << std::endl;
	} else {
		std::cout << "未找到指定的教师工号，删除失败。" << std::endl;
	}
	
	return 0;
}


int resetteacher() {
	std::ifstream inputFile("teacher.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	std::vector<Teacher> teachers;
	Teacher teacher;
	while (inputFile >> teacher.id >> teacher.password >> teacher.name >> teacher.gender >> teacher.age >> teacher.email) {
		teachers.push_back(teacher);
	}
	
	inputFile.close();
	
	std::string updateId;
	std::cout << "请输入要修改的教师工号：";
	std::cin >> updateId;
	
	bool found = false;
	for (auto& teacher : teachers) {
		if (teacher.id == updateId) {
			std::cout << "请输入修改后的信息：" << std::endl;
			std::cout << "密码：";
			std::cin >> teacher.password;
			std::cout << "姓名：";
			std::cin >> teacher.name;
			std::cout << "性别：";
			std::cin >> teacher.gender;
			std::cout << "年龄：";
			std::cin >> teacher.age;
			std::cout << "邮箱：";
			std::cin >> teacher.email;
			
			found = true;
			break;
		}
	}
	
	if (found) {
		std::ofstream outputFile("teacher.txt");
		if (!outputFile) {
			std::cerr << "无法打开文件进行写入。" << std::endl;
			return 1;
		}
		
		for (const auto& teacher : teachers) {
			outputFile << teacher.id << " " << teacher.password << " " << teacher.name << " "
			<< teacher.gender << " " << teacher.age << " " << teacher.email << std::endl;
		}
		
		outputFile.close();
		
		std::cout << "教师信息修改成功。" << std::endl;
	} else {
		std::cout << "未找到指定的教师工号，修改失败。" << std::endl;
	}
	
	return 0;
}


