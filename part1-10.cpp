/*10 �ļ���д
����ѧ�������飬��N���ˣ�N=5�������������������������εĳɼ���
ͨ������<<��>>�����ʵ��ѧ��������ļ���д��*/
#include<iostream>
#include<fstream> //ofstream��ifstream��ͷ�ļ�
using namespace std;

class Student
{
private:
	char name[50];
	float chinese;
	float math;
	float english;
public:
	char *getname()        //��Ҫ����name 
	{
		return name;//�����ַ����׵�ַ 
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
	friend ostream & operator <<(ostream &os,Student &s) //��Ԫ��������� 
	{
	    cout<<"------------------------------------------"<<endl;
		os<<"student's name:"<<s.name<<endl;
		os<<"student's chinese:"<<s.chinese<<endl;
		os<<"student's math:"<<s.math<<endl;
		os<<"student's english:"<<s.english <<endl;
	    cout<<"------------------------------------------"<<endl;
		return os;
	}
	friend istream & operator >>(istream &is,Student &s)  //��Ԫ����������������������������Ϣʱ����� 
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
	const int num=5; //���峣����num 
	
	for(i=0;i<num;i++)
		cin>>s[i];
	ofstream ofs;//�������������
	
	//��ѧ����Ϣд��student.dat�ļ���
	ofs.open("d:\\student.txt",ios::binary|ios::app);
	if(ofs)//�����Ϊ��
	{
	  for(i=0;i<num;i++)
		  ofs.write(reinterpret_cast<char*>(&s[i]),sizeof(s[i]));//������д��Student.txt�ļ��� 
	  ofs.close();
	}

	Student ts[10];
	ifstream ifs;
    ifs.open("d:\\student.txt",ios::binary);
    if(ifs)
	{ 
		i=0;
		while(!ifs.eof())//û���ļ�ĩλ
		{
			ifs.read(reinterpret_cast<char*>(&ts[i]),sizeof(ts[i]));//���ж����౾�����Ϣ�����뵽ts[i]������
			i++;
		}
		ifs.close();
	}

	for(i=0;i<num;i++)
		cout<<ts[i];
	cout<<endl;

	return 0;

}









