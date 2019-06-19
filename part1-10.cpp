/*10 文件读写
定义学生类数组，有N个人（N=5），包括姓名和语数外三名课的成绩，
通过重载<<和>>运算符实现学生数组的文件读写。*/
#include<iostream>
#include<fstream> //ofstream与ifstream的头文件
using namespace std;

class Student
{
private:
	char name[50];
	float chinese;
	float math;
	float english;
public:
	char *getname()        //需要返回name 
	{
		return name;//返回字符串首地址 
	}
	float getC()
	{
		return chinese;
	}
	float getM()
	{
		return math;
	}
	float getE()
	{
		return english;
	}
	friend ostream & operator <<(ostream &os,Student &s) //友元函数输出流 
	{
	    cout<<"------------------------------------------"<<endl;
		os<<"student's name:"<<s.name<<endl;
		os<<"student's chinese:"<<s.chinese<<endl;
		os<<"student's math:"<<s.math<<endl;
		os<<"student's english:"<<s.english <<endl;
	    cout<<"------------------------------------------"<<endl;
		return os;
	}
	friend istream & operator >>(istream &is,Student &s)  //友元函数输入流，在主函数中输入信息时会调用 
	{
		cout<<"input the student information:"<<endl;
		is>>s.name>>s.chinese>>s.math>>s.english;
		return is;
	}
};
int main()
{
	Student s[10];
	int i;
	const int num=5; //定义常数据num 
	
	for(i=0;i<num;i++)
		cin>>s[i];
	ofstream ofs;//定义输出流对象
	
	//将学生信息写入student.dat文件中
	ofs.open("d:\\student.txt",ios::binary|ios::app);
	if(ofs)//如果不为空
	{
	  for(i=0;i<num;i++)
		  ofs.write(reinterpret_cast<char*>(&s[i]),sizeof(s[i]));//将数据写入Student.txt文件中 
	  ofs.close();
	}

	Student ts[10];
	ifstream ifs;
    ifs.open("d:\\student.txt",ios::binary);
    if(ifs)
	{ 
		i=0;
		while(!ifs.eof())//没到文件末位
		{
			ifs.read(reinterpret_cast<char*>(&ts[i]),sizeof(ts[i]));//从中读出多本书的信息，存入到ts[i]数组中
			i++;
		}
		ifs.close();
	}

	for(i=0;i<num;i++)
		cout<<ts[i];
	cout<<endl;

	return 0;

}









