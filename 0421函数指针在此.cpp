
template<typename _ValT, int dim>
class Vec
{
public:
	_ValT v[dim];
};

typedef Vec<float,3> Vec3f;
typedef Vec<double,3>  Vec3d;

typedef Vec<float, 5> Vec5f;
typedef Vec<double, 8> Vec8d;

class Vec3
{
	//int x, y, z;
	//float x, y, z;
	float v[3];
public:
	/*float operator[](int i)
	{
		return v[i];
	}*/
	float& operator[](int i)
	{
		return v[i];
	}
	//float operator[](int i) const
	const float& operator[](int i) const
	{
		return v[i];
	}
	//void operator[][]()
};

void func(const Vec3 &v)
{
	float val = v[0];
	const float *p = &v[0];
}

int main1()
{
	Vec3 v;
	for (int i = 0; i < 3; ++i)
	{
		//float val=v[i];
		v[i] = 0;
	}

	Vec3 m[4];
	float val = m[0][1];

	return 0;
}

class Rational
{
	int b, a; // b/a
public:
	Rational()
	{}
	//Rational(int _b) //��int�͵�Rational��ת������
	//	:b(_b),a(1)
	//{}
	explicit Rational(int _b, int _a=1) //��int�͵�Rational��ת������
		:b(_b),a(_a)
	{}
	//ת��������
	operator double() const
	{
		return double(b) / a;
	}
	operator float() const
	{
		return float(b) / a;
	}

	friend Rational operator+(const Rational &r, int i)
	{
		return Rational(r.b + i*r.a, r.a);
	}
	Rational& operator+=(int i)
	{
		//(*this) = (*this) + i;
		b += i*a;
		return *this;
	}
	Rational& operator++()//ǰ++
	{
		(*this) += 1;
		return *this;
	}
	Rational operator++(int) //��++
	{
		Rational temp(*this);
		(*this) += 1;
		return temp;
	}
	Rational operator-() const
	{
		return Rational(-b, a);
	}
	bool operator!() const
	{
		return b == 0;
	}
};

int main()
{
	//Rational r = 1;
	Rational r(1); //����ת����������

	double f = r; //ת��Ϊ������������operator double()
	float  f2 = r; //����operator float()

	return 0;
}

#include<vector>

int main2()
{
	Rational r(1, 3);
	//Rational y = r + Rational(1,1);
	Rational y = r + 1;
	y += 1;
	y++;
	++y;

	/*for(int i=0; i<100; ++i)
	{ 
	}*/
	//std::vector<int>::iterator itr;

	/*int i = 0, j;
	j = (i += 1);*/
	return 0;
}

class Student
{
public:
	int id;
	int age;
};

bool compareWithID(const Student &a, const Student &b)
{
	return a.id < b.id;
}
bool compareWithAge(const Student &a, const Student &b)
{
	return a.age < b.age;
}

typedef bool (*compareFuncT)(const Student &, const Student &);

void sortStudents(Student *v, int count, compareFuncT compare)
{
	//...
	compare(v[1], v[2]); //�ص�����
}



template<typename _CompareT>
void sortStudents(Student *v, int count, _CompareT compare)
{
	//...
	compare(v[1], v[2]); //�ص�����
}

class CompareStudentWithID
{
public:
	bool operator()(const Student &a, const Student &b)
	{
		return a.id < b.id;
	}
};

CompareStudentWithID id;

class CompareStudentWithAge
{
public:
	bool operator()(const Student &a, const Student &b)
	{
		return a.age < b.age;
	}
};

#include<algorithm>
int main3()
{
	//����ָ��
	Student v[100];

	//��ѧ������
	sortStudents(v, 100, compareWithID);
	//����������
	sortStudents(v, 100, compareWithAge);

	//�Ѷ�����Ϊ����������
	CompareStudentWithID compare;
	compare(v[0], v[1]);

	//��ѧ������
	sortStudents(v, 100, CompareStudentWithID());
	//����������
	sortStudents(v, 100, CompareStudentWithAge());
	sortStudents(v,100, id);

	//lambda���ʽ��C++11��
	sortStudents(v, 100, [](const Student &a, const Student &b) {
		return a.age < b.age;
	});

	//���ñ�׼���sort
	std::sort(v, v + 100, CompareStudentWithID());

	return 0;
}

