#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//封装函数来实现菜单功能void showMenu()
void showMenu() 
{
	cout << "*****1，添加联系人*****" << endl;
	cout << "*****2，显示联系人*****" << endl;
	cout << "*****3，删除联系人*****" << endl;
	cout << "*****4，查找联系人*****" << endl;
	cout << "*****5，修改联系人*****" << endl;
	cout << "*****6，清空联系人*****" << endl;
	cout << "*****0，退出通讯录*****" << endl;
}
//联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};
//通讯录结构体
struct Addressbooks
{
	//通讯录中保存联系人的数组
	//这是结构体数组
	struct Person personArray[MAX];
	//通讯录中当前记录的联系人的个数
	int m_Size;
};
//1，添加联系人函数定义
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否还有空间
	if (abs->m_Size==MAX)
	{
		cout << "通讯录已满，无法继续添加联系人!" << endl;
		return;
	}
	//如果没满则继续添加
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请选择性别男/女" << endl
			<< "1--男" << endl << "2--女" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2) 
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
			//输入的是字母则需要清空缓冲区
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 150) 
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				cin.clear();
			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			
		}
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "添加联系人成功" << endl;

		system("pause");
		system("cls");
	}
}
//2，显示所有的联系人
void showPerson(Addressbooks* abs)
{
	//判断有没有可以显示的联系人
	if (abs->m_Size == 0)
	{
		cout << "当前的记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << i + 1 << " ";
			cout << "姓名：" << abs->personArray[i].m_Name <<"  ";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女") << "  ";
			cout << "年龄：" << abs->personArray[i].m_Age << "  ";
			cout << "电话：" << abs->personArray[i].m_Phone << "  ";
			cout << "住址：" << abs->personArray[i].m_Addr << "  "<<endl;
		}
		system("pause");
		system("cls");
	}
}
//搜索联系人是否存在
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//3，删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for(int i=ret;i<abs->m_Size;i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功";
	}
	system("pause");
	system("cls");
}
//4，查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您想查找的联系人" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "您要查找的联系人是第" << ret+1 << "号" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5，修改指定联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	//姓名
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex=0;
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

		}
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改联系人成功" << endl;

	}
	else
	{
		cout << "未找到联系人" << endl;
	}
	system("pause");
	system("cls");
}
//6，清空所有联系人
void cleanAllPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "联系人已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;

	while(true)
	{
		showMenu();
		cin >> select;
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			continue;
			
		}
		
		switch (select)
		{
		case 1://1，添加联系人
			addPerson(&abs);//地址传递可以修饰实参
			break;
		case 2://2，显示联系人
			showPerson(&abs);
			break;
		case 3://3，删除联系人
			deletePerson(&abs);
			break;
		case 4://4，查找联系人
			findPerson(&abs);
			break;
		case 5://5，修改联系人
			modifyPerson(&abs);
			break;
		case 6://6，清空联系人
			cleanAllPerson(&abs);
			break;
		case 0://0，退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "  请输入数字1-6  " << endl;
			system("pause");
			system("cls");
			break;
		
		}
	}
	

	system("pause");
	return 0;
}
