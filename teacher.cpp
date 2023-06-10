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
