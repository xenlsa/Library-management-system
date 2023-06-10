#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include"student.h"
#include"showMenu.h"
#include"teacher.h"
#include"book.h"
#include"libadmin.h"
using namespace std;
int main()
{
	switch (mainMenu())
	{
		case 1://学生模块
		{
			switch (mainMenu2())
			{
				case 1:
				{
//					cout << studentsSize() << endl;
					if (Studentlogin() == 1)
					{

						showStudentMenu();

					}
					break;
				}

				case 2:
				{
					studentRegistration();
					break;
				}
			}
		}
		case 2://教师模块
		{
			switch (mainMenu2())
			{
				case 1:
				{
					if (teacherLogin() == 1)
					{
						showStudentMenu();
					}
					break;
				}
				case 2:
				{
					teacherRegistration();
					break;
				}
			}
		}
		case 3:
		{
		 libadminlogin();
		}
	}
	return 0;
}

