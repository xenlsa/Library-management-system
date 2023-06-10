#include"book.h"
#include"showMenu.h"
const int MAX_BOOKS = 100;

// 书本结构体
struct Book
{
	string number;
	string name;
	string author;
	string publisher;
	double price;
	string status;// 未借出 借出
};

// 展示书籍列表
void  showBooklist() {

	ifstream inputFile("book.txt");
	string line;
	vector<Book> books;
	
	while (getline(inputFile, line))
	{
		Book book;
		istringstream iss(line);
		iss >> book.number >> book.name >> book.author >> book.publisher >> book.price >> book.status;
		books.push_back(book);
	}
	
	inputFile.close();
	
	// 打印读取到的图书信息
	for (const auto& book : books)
	{
		cout <<  book.number << " " ;
		cout << book.name << " " ;
		cout << book.author << " " ;
		cout <<  book.publisher << " "  ;
		cout << book.price << " ";
		cout << book.status ;
		cout << endl;
	}
	system("pause");
	system("cls");
	return showStudentMenu();
}

// 借书
void borrowBook(){
	
	std::ifstream inputFile("book.txt");
	std::string line;
	std::vector<Book> books;
	
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		Book book;
		iss >> book.number >> book.name >> book.author >> book.publisher >> book.price >> book.status;
		books.push_back(book);
	}
	
	inputFile.close();
	
	std::string userInput;
	std::cout << "请输入要借的图书名称: ";
	std::cin >> userInput;
	
	bool bookFound = false;
	for (auto& book : books)
	{
		if (book.name == userInput)
		{
			bookFound = true;
			if (book.status == "借出")
			{
				std::cout << "借出失败，该图书已经被借出。" << std::endl;
			}
			else
			{
				book.status = "借出";
				std::cout << "借书成功！" << std::endl;
			}
			system("pause");
			system("cls");
			return showStudentMenu();
			break;
		}
	}
	
	if (!bookFound)
	{
		std::cout << "未找到该图书。" << std::endl;
	}
	
	// 将更改后的图书信息写回文件
	std::ofstream outputFile("book.txt");
	if (outputFile.is_open())
	{
		for (const auto& book : books)
		{
			outputFile << book.number << " " << book.name << " " << book.author << " " << book.publisher << " " << book.price << " " << book.status << "\n";
		}
		outputFile.close();
	}
	else
	{
		std::cout << "无法打开文件用于写入。" << std::endl;
	}
	system("pause");
	system("cls");
	return showStudentMenu();
	
}

// 还书
void returnBook()
{
	
	std::ifstream inputFile("book.txt");
	std::string line;
	std::vector<Book> books;
	
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		Book book;
		iss >> book.number >> book.name >> book.author >> book.publisher >> book.price >> book.status;
		books.push_back(book);
	}
	
	inputFile.close();
	std::string userInput;
	std::cout << "请输入要还的图书名称: ";
	std::cin >> userInput;
	
	bool bookFound = false;
	for (auto& book : books)
	{
		if (book.name == userInput)
		{
			bookFound = true;
			if (book.status == "未借出")
			{
				std::cout << "该书未被借出。" << std::endl;
			}
			else
			{
				book.status = "未借出";
				std::cout << "还书成功！" << std::endl;
			}
			system("pause");
			system("cls");
			return showStudentMenu();
			break;
		}
	}
	
	if (!bookFound)
	{
		std::cout << "未找到该图书。" << std::endl;
	}
	
	// 将更改后的图书信息写回文件
	std::ofstream outputFile("book.txt");
	if (outputFile.is_open())
	{
		for (const auto& book : books)
		{
			outputFile << book.number << " " << book.name << " " << book.author << " " << book.publisher << " " << book.price << " " << book.status << "\n";
		}
		outputFile.close();
	}
	else
	{
		std::cout << "无法打开文件用于写入。" << std::endl;
	}
	system("pause");
	system("cls");
	return showStudentMenu();
	
}


// 图书管理员修改图书信息
int updateBookData() {
	std::ifstream inputFile("book.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	Book books[MAX_BOOKS];
	int numBooks = 0;
	
	while (numBooks < MAX_BOOKS && inputFile >> books[numBooks].number >> books[numBooks].name
		>> books[numBooks].author >> books[numBooks].publisher >> books[numBooks].price
		>> books[numBooks].status) {
		numBooks++;
	}
	
	inputFile.close();
	
	std::string bookName;
	std::cout << "请输入要修改的图书名称：";
	std::getline(std::cin >> std::ws, bookName);
	
	bool bookFound = false;
	for (int i = 0; i < numBooks; i++) {
		if (books[i].name == bookName) {
			bookFound = true;
			std::cout << "请输入新的图书编号：";
			std::getline(std::cin >> std::ws, books[i].number);
			std::cout << "请输入新的图书作者：";
			std::getline(std::cin >> std::ws, books[i].author);
			std::cout << "请输入新的图书出版社：";
			std::getline(std::cin >> std::ws, books[i].publisher);
			std::cout << "请输入新的图书单价：";
			std::cin >> books[i].price;
			std::cout << "请输入新的图书状态（借出/未借出）：";
			std::cin >> books[i].status;
			
			std::ofstream outputFile("book.txt");
			if (!outputFile) {
				std::cerr << "无法打开文件进行写入。" << std::endl;
				return 1;
			}
			
			for (int j = 0; j < numBooks; j++) {
				outputFile << books[j].number << " "
				<< books[j].name << " "
				<< books[j].author << " "
				<< books[j].publisher << " "
				<< books[j].price << " "
				<< books[j].status << std::endl;
			}
			
			outputFile.close();
			
			std::cout << "图书数据已成功修改。" << std::endl;
			
			break;
		}
	}
	
	if (!bookFound) {
		std::cout << "找不到对应的图书。" << std::endl;
	}
	
	return 0;
}



//添加图书
int addbook() {
	std::string bookNumber, bookName, bookAuthor, bookPublisher, bookStatus;
	double bookPrice;
	
	std::cout << "请输入图书编号：";
	std::getline(std::cin >> std::ws, bookNumber);
	std::cout << "请输入图书名称：";
	std::getline(std::cin >> std::ws, bookName);
	std::cout << "请输入图书作者：";
	std::getline(std::cin >> std::ws, bookAuthor);
	std::cout << "请输入图书出版社：";
	std::getline(std::cin >> std::ws, bookPublisher);
	std::cout << "请输入图书单价：";
	std::cin >> bookPrice;
	std::cout << "请输入图书状态（借出/未借出）：";
	std::cin >> bookStatus;
	
	Book newBook;
	newBook.number = bookNumber;
	newBook.name = bookName;
	newBook.author = bookAuthor;
	newBook.publisher = bookPublisher;
	newBook.price = bookPrice;
	newBook.status = bookStatus;
	
	std::ofstream outputFile("book.txt", std::ios::app);
	if (!outputFile) {
		std::cerr << "无法打开文件进行写入。" << std::endl;
		return 1;
	}
	
	outputFile << newBook.number << " "
	<< newBook.name << " "
	<< newBook.author << " "
	<< newBook.publisher << " "
	<< newBook.price << " "
	<< newBook.status << std::endl;
	
	outputFile.close();
	
	std::cout << "图书添加成功。" << std::endl;
	
	return 0;
}

// 删除图书
int deletebook() {
	std::string bookName;
	std::cout << "请输入要删除的图书名称：";
	std::getline(std::cin >> std::ws, bookName);
	
	std::ifstream inputFile("book.txt");
	if (!inputFile) {
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 1;
	}
	
	std::vector<Book> books;
	Book book;
	while (inputFile >> book.number >> book.name >> book.author >> book.publisher >> book.price >> book.status) {
		if (book.name != bookName) {
			books.push_back(book);
		}
	}
	
	inputFile.close();
	
	std::ofstream outputFile("book.txt");
	if (!outputFile) {
		std::cerr << "无法打开文件进行写入。" << std::endl;
		return 1;
	}
	
	for (const auto& book : books) {
		outputFile << book.number << " "
		<< book.name << " "
		<< book.author << " "
		<< book.publisher << " "
		<< book.price << " "
		<< book.status << std::endl;
	}
	
	outputFile.close();
	
	std::cout << "图书删除成功。" << std::endl;
	
	return 0;
}
