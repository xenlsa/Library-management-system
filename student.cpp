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




struct Student
{
	std::string studentID;
	std::string password;
};

const std::string studentFileName = "student.txt";
const int studentsPerPage = 5;

void displayStudents(const std::vector<Student>& students, int startIdx, int endIdx)
{
	for (int i = startIdx; i <= endIdx; ++i)
	{
		std::cout << "Student ID: " << students[i].studentID << std::endl;
		std::cout << "Password: " << students[i].password << std::endl;
		std::cout << std::endl;
	}
}




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


// 展示学生信息
int showstudentinfor()
{
	std::ifstream inputFile(studentFileName);
	if (!inputFile)
	{
		std::cerr << "打开文件错误: " << studentFileName << std::endl;
		return 1;
	}

	std::vector<Student> students;
	std::string line;
	while (std::getline(inputFile, line))
	{
		Student student;
		std::istringstream iss(line);
		if (!(iss >> student.studentID >> student.password))
		{
			std::cerr << "解析文件错误: " << studentFileName << std::endl;
			return 1;
		}
		students.push_back(student);
	}

	inputFile.close();

	int totalPages = (students.size() - 1) / studentsPerPage + 1;
	int currentPage = 1;
	char input;
	do
	{
		int startIdx = (currentPage - 1) * studentsPerPage;
		int endIdx = startIdx + studentsPerPage - 1;
		if (endIdx >= students.size())
			endIdx = students.size() - 1;
		system("cls");
		displayStudents(students, startIdx, endIdx);


		std::cout << "第 " << currentPage << " 页共 " << totalPages << "页" << std::endl;
		std::cout << "输入“n”下一页，输入“p”上一页，输入“q”退出: ";
		std::cin >> input;

		if (input == 'n' && currentPage < totalPages)
		{
			system("cls");
			currentPage++;
		}
		else if (input == 'p' && currentPage > 1)
		{
			system("cls");
			currentPage--;
		}
	}
	while (input != 'q');

	return 0;
}


//删除学生
int deletestudent()
{
	std::ifstream inputFile(studentFileName);
	if (!inputFile)
	{
		std::cerr << "打开文件错误: " << studentFileName << std::endl;
		return 1;
	}

	std::vector<Student> students;
	std::string line;
	while (std::getline(inputFile, line))
	{
		Student student;
		std::istringstream iss(line);
		if (!(iss >> student.studentID >> student.password))
		{
			std::cerr << "解析文件错误: " << studentFileName << std::endl;
			return 1;
		}
		students.push_back(student);
	}

	inputFile.close();

	std::cout << "当前学生:" << std::endl;
	for (const auto& student : students)
	{
		std::cout << "学号: " << student.studentID << std::endl;
		std::cout << "密码: " << student.password << std::endl;
		std::cout << std::endl;
	}

	std::string studentIDToDelete;
	std::cout << "输入要删除的学生号: ";
	std::cin >> studentIDToDelete;

	students.erase(std::remove_if(students.begin(), students.end(),
	                              [&](const Student & student)
	{
		return student.studentID == studentIDToDelete;
	}),
	students.end());

	if (!students.empty())
	{
		std::ofstream outputFile(studentFileName);
		if (!outputFile)
		{
			std::cerr << "打开文件错误: " << studentFileName << std::endl;
			return 1;
		}

		for (const auto& student : students)
		{
			outputFile << student.studentID << " " << student.password << std::endl;
		}

		outputFile.close();

		std::cout << "学号为： " << studentIDToDelete << " 的学生已被删除" << std::endl;
	}
	else
	{
		std::cout << "学号为： " << studentIDToDelete << " 的学生没有找到" << std::endl;
	}

	return 0;
}

// 添加学生-直接调用注册


//修改学生
int resetstudent()
{
	std::ifstream inputFile(studentFileName);
	if (!inputFile)
	{
		std::cerr << "打开文件错误: " << studentFileName << std::endl;
		return 1;
	}

	std::vector<Student> students;
	std::string line;
	while (std::getline(inputFile, line))
	{
		Student student;
		std::istringstream iss(line);
		if (!(iss >> student.studentID >> student.password))
		{
			std::cerr << "解析文件错误: " << studentFileName << std::endl;
			return 1;
		}
		students.push_back(student);
	}

	inputFile.close();

	std::cout << "当前学生:" << std::endl;
	for (const auto& student : students)
	{
		std::cout << "学号: " << student.studentID << std::endl;
		std::cout << "密码: " << student.password << std::endl;
		std::cout << std::endl;
	}

	std::string studentIDToUpdate;
	std::cout << "输入新的学号: ";
	std::cin >> studentIDToUpdate;

	bool studentFound = false;
	for (auto& student : students)
	{
		if (student.studentID == studentIDToUpdate)
		{
			std::cout << "输入该学生的新密码 " << student.studentID << ": ";
			std::cin >> student.password;
			studentFound = true;
			break;
		}
	}

	if (studentFound)
	{
		std::ofstream outputFile(studentFileName);
		if (!outputFile)
		{
			std::cerr << "打开文件错误: " << studentFileName << std::endl;
			return 1;
		}

		for (const auto& student : students)
		{
			outputFile << student.studentID << " " << student.password << std::endl;
		}

		outputFile.close();

		std::cout << "学生资料更新成功." << std::endl;
	}
	else
	{
		std::cout << "学号为 " << studentIDToUpdate << " 的学生没找到." << std::endl;
	}

	return 0;
}

