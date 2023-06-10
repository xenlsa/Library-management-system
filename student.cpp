// 学生登录注册
#include "student.h"

//学生结构体
struct studentsSize
{
	string id;
	string passWord;

};
struct studentsSizes
{
	struct studentsSize studentArray[10];
};




// 学生登录
int Studentlogin()
{
	struct studentsSizes abs;

	string getin[2];
	cout << "输入学号" << endl;
	cin >> getin[0];
	cout << "输入密码" << endl;
	cin >> getin[1];


	ifstream file("student.txt");
	string line;
	string id, password;
	if (file.is_open())
	{

		for (int i = 0 ; i < 10 ; i++)
		{

			getline(file, line);
			istringstream iss(line);
			if (iss >> id >> password)
			{
//				cout << "学号： " << id << " 密码： " << password << endl;
				abs.studentArray[i].id = id;
				abs.studentArray[i].passWord = password;


				if (getin[0] == abs.studentArray[i].id && getin[1] == abs.studentArray[i].passWord )
				{
					cout << "登录成功" << endl;
					system("pause");
					system("cls");
					return 1;
					break;
				}
			}
			else
			{
				cout << "输入格式错误" << endl;
				break;
			}
		}
		file.close();
	}
	else
	{
		cout << "无法打开文件" << std::endl;
	}

	// return 0;
}

// 学生注册
void studentRegistration()
{
	std::ofstream outputFile("student.txt", std::ios::app); // 打开文件进行追加写入
	if (!outputFile)
	{
		std::cerr << "无法打开文件用于写入。" << std::endl;
	}

	// 获取学生信息
	std::string studentID, password;
	std::cout << "请输入学号：";
	std::cin >> studentID;
	std::cout << "请输入密码：";
	std::cin >> password;

	// 将学生信息写入文件
	outputFile << studentID << " " << password << "\n";
	outputFile.close();

	std::cout << "注册成功！已将学号和密码保存到文件中。" << std::endl;
}
