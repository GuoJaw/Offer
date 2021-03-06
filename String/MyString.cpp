
#include "MyString.h"
MyString::MyString()
{
	this->len = 0;
	this->str = NULL;
}
MyString::MyString(int len)
{
	this->len = len;
	this->str = new char[len + 1];
	memset(this->str, 0, sizeof(this->str));
}
MyString::MyString(const char* str)
{
	if (str == NULL)
	{
		this->len = 0;
		this->str = new char[0 + 1];
		this->str = '\0';
	}
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
}
MyString::MyString(const MyString& another)
{
	this->len = another.len;
	if (this->len == 0)
	{
		this->str = new char[0 + 1];
		this->str = '\0';
	}
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}
MyString::~MyString()
{
	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
		this->len = 0;
	}
}
MyString& MyString::operator=(const MyString& another)
{
	//判断拷贝自身
	if (this == &another)
		return *this;
	//释放自身垃圾
	if (this->str != NULL)
	{
		delete[] this->str;
		this->str = NULL;
		this->len = 0;
	}
	//深拷贝
	this->str = new char[another.len + 1];
	strcpy(this->str, another.str);
	this->len = another.len;
	//返回对象本身
	return *this;
}
MyString MyString::operator+(const MyString& another)
{
	MyString tmp;
	tmp.len = this->len + another.len;
	tmp.str = new char[tmp.len + 1];
	strcpy(tmp.str, this->str);
	strcat(tmp.str, another.str);
	return tmp;
}
MyString& MyString::operator+=(const MyString& another)
{
	char* tmp = this->str; //临时变量指向this
	this->len += another.len;
	this->str = new char[this->len + 1];

	strcpy(this->str, tmp);
	strcat(this->str, another.str); 
	if (tmp != NULL)
	{
		delete tmp;
		tmp = NULL;
	}
	return *this;
}
bool MyString::operator==(const MyString& another)
{
	return strcmp(this->str, another.str);
}
bool MyString::operator!=(const MyString& another)
{
	return !strcmp(this->str, another.str);
}
char& MyString::operator[](int index)//注意返回值char&
{
	if (index > this->len)//索引越界判断
		exit(-1);
	else
		return this->str[index];
}
ostream& operator<<(ostream& cout, const MyString& myStr)
{
	cout << myStr.str;
	return cout;
}
istream& operator>>(istream& cin, MyString& myStr)
{
	//1.释放myStr之前的字符串
	if (myStr.str != NULL)
	{
		delete[] myStr.str;
		myStr.str = NULL;
		myStr.len = 0;
	}
	//2.通过cin添加新的字符串
	char buf[4096] = { 0 };
	cin >> buf;
	myStr.len = strlen(buf);
	myStr.str = new char[myStr.len + 1];
	strcpy(myStr.str, buf);
	return cin;
}

int main()
{
	MyString s1("");
	MyString s2("11100");
	MyString s = s1 + s2;
	s += s2;
	system("pause");
}
  
 