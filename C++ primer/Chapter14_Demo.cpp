#include<iostream>
#include"Sales_data.h"
//14.2.1 ������������<<
//Sales_data����������


//std::ostream& operator<<(std::ostream& os, const Sales_data& item)
//{
//	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
//	return os;
//}

//��������Ӧ����Ҫ�����ӡ��������ݶ��ǿ��Ƹ�ʽ������������Ӧ�ô�ӡ���з�

//14.2.2�������������>>
//Sales_data�����������

//note:������������봦���������ʧ�ܵ��������������������Ҫ

//std::istream& operator>>(std::istream& is, Sales_data& item)
//{
//	double price;//����Ҫ��ʼ�����ȶ������ݵ�price��֮���ʹ����
//	is >> item.bookNo >> item.units_sold >> price;
//	if (is)//�������Ƿ�ɹ�
//		item.revenue = item.units.sold * price;
//	else
//		item = Sales_data();//����ʧ�ܣ����󱻸���Ĭ��״̬
//	return is;
//}

//����ȡ������������ʱ�����������Ӧ�ø���Ӵ����лָ�

//14.3 �����͹�ϵ�����

//Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
//{
//	Sales_data sum = lhs;//��lhs�����ݳ�Ա������sum
//	sum += rhs;//��rhs�ӵ�sum��
//	return sum;
//
//}

//Tip:�����ͬʱ�������������������صĸ��ϸ�ֵ���������ͨ�������Ӧ��ʹ�ø��ϸ�ֵ�������ʵ�����������

//14.3.1��������

//bool operator==(const Sales_data& lhs, const Sales_data& rhs)
//{
//	return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
//}
//
//bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
//{
//	return !(lhs == rhs);
//}

//���ĳ�������߼���������Եĺ��壬�����Ӧ�ö���operator==������������ʹ���û�������ʹ�ñ�׼���㷨�����������

//14.4 ��ֵ�����
//class StrVec {
//public:
//	StrVec& operator=(std::initializer_list<std::string>);
//private:
//	void	alloc_n_copy();
//};


//Note:�������ظ�ֵ������������β�������ʲô����ֵ����������붨��Ϊ��Ա����
//StrVec& StrVec::operator=(std::initializer_list<std::string>il)
//{
//	//alloc_n_copy�����ڴ�ռ䲢�Ӹ�����Χ�ڿ���Ԫ��
//	auto data = alloc_n_copy(il.begin(), il.end());
//	free();	//���ٶ����е�Ԫ�ز��ͷ��ڴ�ռ�
//	elements = data.first();//�������ݳ�Աʹ��ָ���¿ռ�
//	first_free = cap = data.second;
//	return *this;
//}

//���ϸ�ֵ�����
//��Ϊ��Ա�Ķ�Ԫ�����������������󶨵���ʽ��thisָ��
//�ٶ����������ʾͬһ����
//Sales_data& Sales_data::operator+=(const Sales_data& rhs)
//{
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}

//��ֵ��������붨�����ĳ�Ա�����ϸ�ֵ�����ͨ�������ҲӦ����ô�����������������Ӧ�÷����������������á�

//14.5 �±������

//Note:�±�����������ǳ�Ա����

//���һ��������±������������ͨ���ᶨ�������汾��һ��������ͨ���ã���һ������ĳ�����Ա���ҷ��س�������

//class StrVec {
//public:
//	std::string& operator[](std::size_t n) { return elements[n]; }
//
//	const std::string& operator[](std::size_t n)const { return elements[n]; }
//private:
//	std::string* elements;//ָ��������Ԫ�ص�ָ��
//};

//����svec��һ��StrVec����
/*const StrVec cvec = svec;*///��svec��Ԫ�ؿ�����cvec��

//���svec�к���Ԫ�أ��Ե�һ��Ԫ������string ��empty����
//if (svec.size() && svec[0].empty()) {
//	svec[0] = "zero";//��ȷ���±����������string������
//	cvec[0] = "Zip";//���󣺶�cvecȡ�±귵�ص����ǳ�������
//}

//14.6 �����͵ݼ������

//��������͵ݼ����������Ӧ��ͬʱ����ǰ�ð汾�ͺ��ð汾����Щ�����Ӧ�ñ��������ĳ�Ա

//����ǰ�õ���/�ݼ������

//class StrBlobPtr {
//public:
//	//�����͵ݼ������ 
//	StrBlobPtr& operator++();//ǰ�������
//	StrBlobPtr& operator--();
//};

//Ϊ�������ð汾����һ�£�ǰ�������Ӧ�÷��ص�����ݼ�����������

////ǰ�ð汾�����ص���/�ݼ����������
//StrBlobPtr& StrBlobPtr::operator++()
//{
//	//���curr�Ѿ�ָ��������β��λ�ã����޷�������
//	check(curr, "increment past end of StrBlobPtr");
//	++curr;//��curr�ڵ�ǰ״̬��ǰ���ƶ�һ��Ԫ��
//	return *this;
//}

//StrBlobPtr& StrBlobPtr::operator--()
//{
//	//���curr��0��������ݼ���������һ����Ч�±�
//	--curr;//��curr�ڵ�ǰ״̬������ƶ�һ��Ԫ��
//	check(curr, "decrement past beging of StrBlobStr");
//	return *this;
//}

//����ǰ�úͺ��������
//class StrBlobPtr {
//public:
//	//�����͵ݼ������
//	StrBlobPtr operator++(int);//���������
//	StrBlobPtr operator--();
//};

//Ϊ�������ð汾����һ�£����������Ӧ���ض����ԭֵ��������ݼ�֮ǰ��ֵ�������ص���ʽ��һ��ֵ�������á�

//���ð汾������/�ݼ������ֵ���Ƿ���ԭֵ

//Note:��Ϊ�����õ�int�βΣ���������Ϊ������
//StrBlobPtr StrBlobPtr::operator++(int)
//{
//	//�˴���������Ч�ԣ�����ǰ�õ������������Ҫ���
//	StrBlobPtr ret = *this;//��¼��ǰ��ֵ
//	++*this;//��ǰ�ƶ�һ��Ԫ�أ�ǰ��++��Ҫ����������Ч��
//	return ret;//����֮ǰ��¼��״̬
//}

//StrBlobPtr StrBlobPtr::operator--(int)
//{
//	//�˴���������Ч�ԣ�����ǰ�õݼ����������Ҫ���
//	StrBlobPtr ret = *this;//��¼��ǰ��ֵ
//	--*this;//����ƶ�һ��Ԫ�أ�ǰ��--��Ҫ���ݼ�����Ч��
//	return ret;//����֮ǰ��¼��״̬
//}

//14.7��Ա���������

//Note:��ͷ�������������ĳ�Ա�������������ͨ��Ҳ����ĳ�Ա�����ܲ��Ǳ�����ˡ�

//class StrBlobPtr {
//public:
//	std::string& operator*()const
//	{
//		auto p = check(curr, "dereference past end");
//		return (*p)[curr];//(*p)�Ƕ�����ָ��vector
//	}
//	std::string* operator->()const
//	{
//		//��ʵ�ʹ���ί�и������������
//		return &this->operator*();
//	}
//};

//Note:���صļ�ͷ��������뷵�����ָ������Զ����˼�ͷ�������ĳ����Ķ���

//14.8 �������������
//struct absInt
//{
//	int operator()(int val)const {
//		return val < 0 ? -val : val;
//	}
//};

//Note:������������������ǳ�Ա������һ������Զ�������ͬ�汾�ĵ�����������໥֮��Ӧ���ڲ�����������������������

//����״̬�ĺ���������
//class PrintString {
//public:
//	PrintString(std::ostream& o = std::cout, char c = ' ') :
//		os(o), sep(c){}
//	void operator()(const std::string& s)const { os << s << sep; }
//private:
//	std::ostream& os;//����д���Ŀ����
//	char sep;//���ڽ���ͬ����������ַ�
//};

//14.8.1 lambda�Ǻ�������

//���ݵ��ʵĳ��ȶ���������򣬶��ڳ�����ͬ�ĵ��ʰ�����ĸ��˳������
//class stable_sort {
//public:
//	stable_sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {return a.size() < b.size(); });
//
//};
//
//class ShoterString {
//public:
//	bool operator()(const std::string& s1, const std::string& s2)const { return s1.size() < s2.size(); }
//};

//��ʾlambda����Ӧ������Ϊ����

//��õ�һ��ָ����������Ԫ�صĵ���������Ԫ������size���� is>=sz
//auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string& a) {return a.size() >= sz; });

//class SizeComp {
//public:
//	SizeComp(size_t n):sz(n){}//���βζ�Ӧ����ı���
//	//�õ���������ķ������ͣ��βκͺ�������lambdaһ��
//	bool operator()(const std::string& s)const { return s.size() >= sz; }
//private:
//	size_t sz;//�����ݳ�Ա��Ӧͨ��ֵ����ı���
//};

//14.8.3 �ɵ��ö�����function

//���صĺ�����function
//Note:�°汾��׼���е�function����ɰ汾�е�unary_function��binary_functionû�й��������������Ѿ�����ͨ�õ�bind���������

//14.9.1 ����ת�������
//Note:һ������ת��������������ĳ�Ա�����������������������ͣ��β��б�Ҳ����Ϊ�ա�����ת������ͨ��Ӧ����const

//���庬������ת�����������
//class SmallInt {
//public:
//	SmallInt(int i = 0) :val(i)
//	{
//		if (i < 0 || i>255)
//			throw std::out_of_range("Bad SmallInt value");
//	}
//	operator int() const { return val; }
//private:
//	std::size_t val;
//};

//��ʽ������ת�������
//class SmallInt {
//public:
//	//�����������Զ�ִ����һ����ת��
//	explicit operator int()const { return val; }
//};

//ת��Ϊbool
//��bool������ת��ͨ�������������֣����operator boolһ�㶨���explicit�ġ�

//14.9.2�����ж����Ե�����ת��
//ͨ������£���ҪΪ�ඨ����ͬ������ת����Ҳ��Ҫ�����ж�����������������ת��Դ��ת��Ŀ�����������͵�ת����

//ʵ��ƥ�����ͬ������ת��

//��ò�Ҫ��������֮�乹����ͬ������ת��
//struct B;
//struct A {
//	A() = default;
//	A(const B&);//��һ��Bת����A
//};
//
//struct B {
//	operator A()const;//Ҳ�ǰ�һ��Bת����A
//};
//A f(const A&);
//B b;
//A a = f(b);//�����Դ��󣺺�����f(B::operator A())
//			//����f(A::A(const B&))?

//��������ת��Ŀ��Ϊ�������͵Ķ�������ת��

//struct A
//{
//	A(int = 0);//��ò�Ҫ��������ת��Դ�����������͵�����ת��
//	A(double);
//	operator int()const;//��ò�Ҫ��������ת��Դ�����������͵�����ת��
//	operator double()const;
//
//};

//void f2(long double);
//A a;
//f2(a);//�����Դ��󣺺�����f(A::operator int())
//		//����f(A::operator double())?
//
//long lg;
//A a2(lg);//�����Դ��󣺺�����A::A(int)����A::A(double)?

//Note:��ʹ�������û����������ת��ʱ�����ת������֮ǰ��֮����ڱ�׼����ת�������׼����ת�����������ƥ�䵽�����ĸ���

////���غ�����ת�����캯��
//struct C
//{
//	C(int);
//};
//
//struct D
//{
//	D(int);
//};
//
//void mainp(const C&);
//void mainp(const D&);
//mainp(10);//�����Դ���mainp��c(10)��or mainp(D(10������
//mainp(C(10));//��ʾ��������������


//����ڵ������غ���ʱ������Ҫʹ�ù��캯������ǿ������ת�����ı�ʵ�ε����ͣ�����ͨ����ζ�ų������ƴ��ڲ��㡣

//���غ������û����������ת��
//struct E
//{
//	E(double);
//};
//
//void manip2(const C&);
//void manip2(const E&);
////�����Դ���������ͬ�û����������ת���������ڴ˴�
//mainp2(10);//mainp2(C(10))or mainp2(E(double 10))?

//Note:�ڵ������غ���ʱ�������Ҫ����ı�׼����ת�������ת���ļ���ֻ�е����п��к���������ͬһ���û����������ת��ʱ�ſ��á����������û����������ת����ֹһ������õ��þ��ж�����

//14.9.3 ����ƥ�������������

//Note:���ʽ��������ĺ�ѡ��������Ӧ�ð�����Ա������ҲӦ�ð����ǳ�Ա����

//class SmallInt {
//	friend SmallInt operator+(const SmallInt&, const SmallInt&);
//
//public:
//	SmallInt(int = 0);//ת��ԴΪint������ת��
//	operator int() const { return val; }//
//
//private:
//	size_t val;
//};
//
//SmallInt s1, s2;
//SmallInt s3 = s1 + s2;//ʹ�����ص�operator+
//int i = s3 + 0;//�����Դ���

//������Ƕ�ͬһ������ṩ��ת��Ŀ�����������͵�����ת����Ҳ�ṩ�����ص���������򽫻��������������������������Ķ��������⡣