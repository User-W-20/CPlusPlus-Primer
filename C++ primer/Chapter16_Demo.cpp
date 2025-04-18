#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<memory>
#include<unordered_set>
using namespace std;
//16.1 ����ģ��

//�������ֵ��ȣ�����0�����v1С����-1�����v2С����1
int compare(const string& v1, const string& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

int compare(const double& v1, const double& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

//16.1.1 ����ģ��
template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

//template���ģ������б� �ö��ŷָ���һ������ģ�������<>

//Note:��ģ�嶨���У�ģ��������б���Ϊ��

//ʹ��ģ��ʱ������ʽ����ʽ�أ�ָ��ģ��ʵ�Σ�����󶨵�ģ�������

//ʵ��������ģ��
cout << compare(1, 0) << endl;//TΪint

//���������ƶϳ���ģ�����ʵ����һ���ض��汾�ĺ�����

//ʵ������int compare(const int&,const int&)
cout << compare(1, 0) << endl;
//ʵ������int compare(const vector<int>&,const vector<int>&)
vector<int>vec1{ 1,2,3 }, vec2{ 4,5,6 };
cout << compare(vec1, vec2) << endl;//T vector<int>

int compare(const int& v1, const int& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

//ģ�����Ͳ���
//��ȷ���������������������ͬ
template <typename T>T foo(T* p)
{
	T tmp = *p;//tmp��������ָ��pָ�������
	//...
	return tmp;
}

//����U֮ǰ�������class��typename
template<typename T, U>T calc(const T&, const U&);

//��ģ������б��У�class��typenameû����
template<typename T, class U>T calc(const T&, const U&);

//������ģ�����
template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2[M])
{
	return strcmp(p1, p2);
}
compare("hi", "mom");
int compare(const char(&p1)[3], const char(&p2)[4]);

//Note:������ģ�����ʵ�α����ǳ������ʽ

//��ʹ����ָ��Ҳ��ȷ��compare�汾
template<typename T>int comapre(const T& v1, const T& v2)
{
	if (less<T>()(v1, v2))return -1;
	if (less<T>()(v2, v1))return 1;
	return 0;
}

//ģ�����Ӧ�þ������ٶ�ʵ�����͵�Ҫ��

//ģ�����
//Note:����ģ�����ģ���Ա�����Ķ���ͨ������ͷ�ļ���

//��������������ʵ�����ڼ䱨��
	//��һ���׶��Ǳ���ģ�屾��ʱ��
	//�ڶ����׶��Ǳ���������ģ��ʹ��ʱ��
	//�������׶���ģ��ʵ����ʱ��

if (v1 < v2)return -1;//Ҫ������T�Ķ���֧��<����
if (v2 < v1)return 1;//Ҫ������T�Ķ���֧��<����
return 0;//����int����������T

Sales_data data1, data2;
cout << comapre(data1, data2) << endl;//����Sales_dataΪ����<  ʵ����ʱ�ŷ���

//warning����֤���ݸ�ģ���ʵ��֧��ģ����Ҫ��Ĳ������Լ���Щ������ģ��������ȷ�������ǵ����ߵ����Ρ�

//16.1.2 ��ģ��
	//�������������ͼ�� <>���ṩ������Ϣ

//������ģ��
template <typename T>class Blob
{
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T>il);

	size_type size()const { return data->size(); }
	bool empty()const { return data->element_type(); }

	void push_back(const T& t) { data->push_back(t); }

	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back();

	T& back();
	T& operator[](size_type i);

private:
	shared_ptr<vector<T>>data;
	void check(size_type i, const string& msg)const;
};

//ʵ������ģ��
//������Ϣ����ʽģ��ʵ���б����󶨵�ģ�����

Blob<int> ia;//��Blob<int>
Blob<int> ia2 = { 0,1,2,3,4 };//5��Ԫ�ص�Blob<int>

template <> class Blob<int>
{
	typedef typename std::vector<int>::size_type size_type;
	Blob();
	Blob(std::initializer_list<int>il);
	//...
	int& operator[](size_type i);

private:
	shared_ptr<vector<int>>data;
	void check(size_type i, const string& msg)const;
};

Blob<string>names;//����string��blob
Blob<double>prices;//��ͬ��Ԫ������

//Note:һ����ģ���ÿ��ʵ�����γ�һ���������ࡣ����Blob<string>���κ�����Blob���Ͷ�û�й�����Ҳ������κ�����Blob���͵ĳ�Ա��������ʵ�Ȩ�ޡ�

//��ģ��������������ģ������
shared_ptr<vector<T>>data;
shared_ptr<vector<string>>data;//string
shared_ptr<vector<int>>data;//int

//��ģ��ĳ�Ա����
ret - type StrBlob::member - name(pram - list);

template <typename T>
ret - type Blob<T>::member - name(parm - list);

//check��Ԫ�ط��ʳ�Ա
template <typename T>
void Blob<T>::check(size_type i, const string & msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back()
{
	check(0, " back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

//Blob���캯��
template<typename T>
Blob<T>::Blob() :data(make_shared<vector<T>>()) {}

template <typename T>
Blob<T>::Blob(initializer_list<T>il) : data(make_shared<vector<T>>(il)) {}

Blob<string> articles = { "a","an","the" };

//��ģ���Ա������ʵ����
//ʵ����Blob<int>�ͽ���initializer_list<int>�Ĺ��캯��
Blob<int>squares = { 0,1,2,3,4,5,6,7,8,9 };

//ʵ����Blob<int>::size() const
for (size_t i = 0; i != squares.size(); ++i)
squares[i] = i * i;//ʵ����Blob<int>::operator[](size_t)

//Note:Ĭ������£�����һ��ʵ�����˵���ģ�壬���Աֻ����ʹ��ʱ�ű�ʵ����.��

//��������ڼ�ģ��������ʹ��
//����ģ���Լ����������У�����ֱ��ʹ��ģ���������ṩʵ��
//����ͼ����һ�������ڵ�Ԫ�أ�BlobPtr�׳�һ���쳣
template <typename T>
class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T>& a, size_t sz - 0) :wptr(a.data), curr(sz) {}
	T& operator*()const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];//(*p)Ϊ������ָ���vector
	}

	//������ݼ�
	BlobPtr& operator++();//ǰ�������
	BlobPtr& operator--();

private:
	//�����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<T>> check(size_t, const string&)const;

	//����һ��weak_ptr ����ʾ�ײ�vector���ܱ�����
	weak_ptr<vector<T>>wptr;

	size_t curr;//�����еĵ�ǰλ��
};

BlobPtr<T>& operator++();
BlobPtr<T>& operator--();

//����ģ����ʹ����ģ����

//���ã�����/�ݼ����󵫷���ԭֵ
template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	//�����飬����ǰ�õ���ʱ����м��
	BlobPtr ret = *this;//���浱ǰֵ
	++*this;//�Ƽ�һ��Ԫ�أ�ǰ��++�������Ƿ�Ϸ�
	return ret;//���ر����״̬
}

BlobPtr<T>ret = *this;

//Note:��һ����ģ����������ڣ�����ֱ��ʹ��ģ����������ָ��ģ��ʵ�Ρ�

//��ģ�����Ԫ
//�����ģ���������ģ����Ԫ������Ԫ����Ȩ���Է�������ģ��ʵ����  
//�����Ԫ������ģ�壬�������Ȩ��������Ԫģ��ʵ����Ҳ����ֻ��Ȩ���ض�ʵ����

//һ��һ�Ѻù�ϵ
//������Ӧʵ���Լ�����Ԫ����Ѻù�ϵ��

//ǰ����������Blob��������Ԫ����Ҫ��
template <typename >class BlobPtr;
template<typename>class Blob;//==�еĲ�������Ҫ��
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>class Blob
{
	//ÿ��Blobʵ��������Ȩ����������ͬ����ʵ������BlobPtr����������
	friend class BlobPtr<T>;
	friend bool operator==<T> (const Blob<T>&, const Blob<T>&);

};

Blob<char>ca;//BlobPtr<char>��operator==<char>���Ǳ��������Ԫ
Blob<int>ia;//BlobPtr<int>��operator==<int>���Ǳ��������Ԫ

//ͨ�ú��ض���ģ���Ѻù�ϵ
//ǰ���������ڽ�ģ���һ���ض�ʵ������Ϊ��ԪʱҪ�õ�
template <typename T>class Pal;
class C//��ͨ�ķ�ģ����
{
	friend class Pal<C>;//����Cʵ������Pal��C��һ����Ԫ
	//Pal2������ʵ������C����Ԫ������ǰ������
	template<typename T>friend class Pal2;

};

template<typename T>class C2//C2������һ����ģ��
{
	//C2��ÿ��ʵ������ͬʵ������Pal����Ϊ��Ԫ
	friend class Pal<T>;//Pal��ģ������������������֮��
	//Pal2������ʵ������C2��ÿ��ʵ������Ԫ������Ҫǰ������
	template<typename X>friend class Pal2;
	//Pal3��һ����ģ���࣬��C2����ʵ������Ԫ
	friend class Pal3;//����ҪPal��ǰ������
};

//��ģ���Լ������Ͳ�����Ϊ��Ԫ
template <typename Type>class Par
{
	friend Type;//������Ȩ����������ʵ����Bar������
};

//ģ�����ͱ���
typedef Blob<string>strBlob;
//�޷�����һ��typedef����Blob<T>

template <typename T>using twin = pair<T, T>;
twin<string>authors;//authors��һ��pair<string,string>

twin<int>win_loss;//pair<int,int>
twin<double>area;

template<typename T>using partNo = pair<T, unsigned>;
partNo<string>books;//pair<string,unsigned>
partNo<Vehicle>cars;//pair<Vehicle,unsigned>
partNo<Student>kids;//pair<Student,unsigned>

//��ģ���static��Ա
template<typename T>class Foo
{
public:
	static std::size_t count() { return ctr; }
	//Foo<X>::count
private:
	static std::size_t ctr;
	//Foo<X>::ctr
};

//ʵ����static��ԱFoo<string>::ctr��Foo<string>::count
Foo<string>fs;
//����������������ͬ��Foo<int>::ctr��Foo<int>::count��Ա
Foo<int>fi, fi2, fi3;

template <typename T>
size_t Foo<T>::ctr = 0;//���岢��ʼ��ctr

Foo<int>fi;//ʵ����Foo<int>���static���ݳ�Աctr
auto ct = Foo<int>::count();//ʵ����Foo<int>::count
ct = fi.count();//ʹ��Foo<int>::count
ct = Foo::count();//����ʹ���ĸ�ģ��ʵ����count��
//static��Ա����ֻ����ʹ��ʱ��ʵ����

//16.1.3 ģ�����
template <typename Foo>Foo calc(const Foo & a, const Foo & b)
{
	Foo tmp = a;//tmp������������ͷ�������һ��

	return tmp;//�������ͺͲ�������һ��
}

//ģ�������������
typedef double A;
template <typename A, typename B>void f(A a, B b)
{
	A tmp = a;//tmp������Ϊģ�����A�����ͣ�����double
	double B;//����������ģ�����B
}

//���󣺷Ƿ�����ģ�������V
template <typename V, typename V>{/**/}//...

//ģ������
//������������compare��Blob
template<typename T>int compare(const T&, const T&);
template<typename T>class Blob;

//3��calc��ָ����ͬ�ĺ���ģ��
template <typename T>T calc(const T&, const T&);//����
template <typename U>U calc(const U&, const U&);//����

//ģ��Ķ���
template<typename Type>
Type calc(const Type & a, const Type & b) {/**/ }

//һ���ض��ļ�����Ҫ������ģ�������ͨ��һ��������ļ���ʼλ�á��������κ�ʹ����Щģ��Ĵ���֮ǰ��

//ʹ��������ͳ�Ա
template <typename T>
typename T::value_type top(const T & c)
{
	if (!c.empty())
		return c.back();
	else
		return typename T::value_type();
}

//Note:������ϣ��֪ͨ������һ�����ֱ�ʾ����ʱ������ʹ�ùؼ���typename��������ʹ��class��

//Ĭ��ģ��ʵ��
//compare��һ��Ĭ��ģ��ʵ��less<T>��һ��Ĭ�Ϻ���ʵ��F()
template <typename T, typename F = less<T>>
int compare(const T & v1, const T & v2, F f = F())
{
	if (f(v1, v2))return -1;
	if (f(v2, v1))return 1;
	return 0;
}

bool i = compare(0, 42);//ʹ��less;iΪ-1
//���������item1��item2�е�isbn
Sales_data item1(cin), item2(cin);
bool j = compare(item1, item2, compreIsbn);

//ģ��Ĭ��ʵ������ģ��
template <class T = int >class Numbers//Ĭ��Ϊint
{
public:
	Numbers(T v = 0) :val(v) {}

private:
	T val;
};

Numbers<long double> lots_of_precision;
Numbers<> average_precision;

//16.1.4��Աģ��
//һ���ࣨ������ͨ������ģ�壩���԰���������ģ��ĳ�Ա������ ��Աģ�岻�����麯����

//��ͨ����ģ�壩��ĳ�Աģ��
//���������࣬�Ը���ָ��ִ��delete
class DebugDelete
{
public:
	DebugDelete(ostream& s = cerr) :os(s) {}
	//T�������ɱ������ƶ�
	template<typename T>void operator()(T* p)const
	{
		os << "deleting unique_ptr" << endl;
		delete p;
	}
private:
	ostream& os;
};

double* p = new double;
DebugDelete d;//����delete���ʽһ��ʹ�õĶ���
d(p);//����DebugDelete::operator()(double *p),�ͷ�p
int* ip = new int;
//��һ����ʱDebugDelete�����ϵ���operator()(int *)
DebugDelete()(ip);

//����pָ��Ķ���
//ʵ����DebugDelete::operator()<int>(int *)
unique_ptr<int, DebugDelete>p(new int, DebugDelete());
//����spָ��Ķ���
//ʵ����DebugDelete::operator()<string>(string*)
unique_ptr<string, DebugDelete>sp(new string, DebugDelete());

//DebugDelete�ĳ�Աģ��ʵ��������
void DebugDelete::operator()(int* p)const { delete p; }
void DebugDelete::operator()(string * p)const { delete p; }

//��ģ��ĳ�Աģ��
template<typename T>class Blob
{
	template<typename It>Blob(It b, It e);
};

template<typename T>//������Ͳ���
template<typename It>//���캯�������Ͳ���
Blob<T>::Blob(It b, It e) :
	data(make_shared<vector<T>>(b, e)) {
}

//ʵ�������Աģ��
int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
vector<long>vi = { 0,1,2,3,4,5,6,7,8,9 };
list<const char*>w = { "now","is","the","time" };
//ʵ����Blob<int>�༰���������int*�����Ĺ��캯��
Blob<int>a1(begin(ia), end(ia));
//ʵ����Blob<int>��Ľ�������vector<long>::iterator�Ĺ��캯��
Blob<int>a2(vi.begin(), vi.end());
//ʵ����Blob<string>�༰���������list<const char*>::iterator�Ĺ��캯��
Blob<string>a3(w.begin(), w.end());

Blob<int>::Blob(int*, int*);

//16.1.5 ����ʵ����
//����ʽʵ�������⿪����
extern template declaration;//ʵ��������
template declaration;//ʵ��������

//ʵ���������붨��
extern template class Blob<string>;//����
template int compare(const int&, const int&);//����

//���ڸ�����ʵ�����汾�������ж��extern������������ֻ��һ������

//Application.cc
//��Щģ�����ͱ����ڳ�������λ�ý���ʵ����
extern template class Blob<string>;
extern template int compare(const int&, const int&);
Blob<string>sa1, sa2;//ʵ���������������λ��
//Blob<int>�������initializer_list�Ĺ��캯���ڱ��ļ���ʵ����
Blob<int>a1 = { 0,1,2,3,4,5,6,7,8,9 };
Blob<int>a2(a1);//�������캯���ڱ��ļ���ʵ����
int i = comapre(a1[0], a2[0]);//ʵ��������������λ��

//templateBuild.cc
//ʵ�����ļ�����Ϊÿ���������ļ�������Ϊextern�����ͺͺ����ṩһ������extern���Ķ���
template int compare(const int&, const int&);
template class Blob<string>;//ʵ������ģ������г�Ա

//warning:��ÿ��ʵ�����������ڳ�����ĳ��λ�ñ���������ʽ��ʵ�������塣

//ʵ���������ʵ�������г�Ա

//Note:��һ����ģ���ʵ���������У��������ͱ���������ģ������г�Ա������

//16.1.6 Ч���������

//������ʱ��ɾ����
//ɾ�������뱣��һ��ָ���һ����װ��ָ�����

//del��ֵֻ������ʱ��֪����ͨ��һ��ָ����������
del ? del(p) : delete p;//del(p)��Ҫ����ʱ��ת��del�ĵ�ַ

//�ڱ���ʱ��ɾ����
//del�ڱ���ʱ�󶨣�ֱ�ӵ���ʵ������ɾ����
del(p);//������ʱ���⿪��

//unique_ptr �����ӵ���ɾ����������ʱ����
//shared_ptr ʹ�û�����ɾ������Ϊ����

//16.2 ģ��ʵ���ƶ� 
//�Ӻ���ʵ����ȷ��ģ��ʵ�εĹ���

//16.2.1 ����ת����ģ�����Ͳ���
//����const�������βλ���ʵ�Σ����ᱻ����
//constת��
//�������ָ��ת��

template <typename T>T fobj(T, T);//ʵ�α�����
template<typename T>T fref(const T&, const T&);//����
string s1("a value");
const string s2("another value");
fobj(s1, s2);// ����fobj(string, string);const ������
fref(s1, s2);//����fref(const string&,const string&)
//��s1ת��Ϊconst�������
int a[10], b[42];
fobj(a, b);//����f(int*,int*)
fref(a, b);//�����������Ͳ�ƥ��

//Note:��ʵ�δ��ݸ���ģ�����͵ĺ����β�ʱ���ܹ��Զ�Ӧ�õ�����ת��ֻ��constת�������������ָ���ת����

//ʹ����ͬģ��������͵ĺ����β�
//һ��ģ�����Ͳ�������������������βε����͡�

long lng;
compare(lng, 1024);//���󣺲���ʵ����compare(long,int)

//ʵ�����Ϳ��Բ�ͬ�����������
template<typename A, typename B>
int flexibleCompare(const A & v1, const B & v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

long lng;
flexibleCompare(lng, 1024);//��ȷ������flexibleCompare(long,int)

//��������ת��Ӧ������ͨ����ʵ��
//���漰ģ�����Ͳ���������
template<typename T>ostream& print(ostream & os, const T & obj)
{
	return os << obj;
}

print(cout, 42);//ʵ����print(ostream&,int)
ofstream f("output");
print(f, 10);//ʹ��print(ostream&,int);��fת��Ϊostream&

//Note:��������������Ͳ���ģ����������ʵ�ν�������������ת����

//16.6.2 ����ģ����ʽʵ��

//ָ����ʽģ��ʵ��
	//�������޷��ƶ�T1,��δ�����ں����б���
template<typename T1, typename T2, typename T3>
T1 sum(T2, T3);

//T1����ʽָ���ģ�T2��T3�ǴӺ���ʵ�������ƶ϶�����
auto val3 = sum<long long>(i, lng);//long long sum(int,long)

//������ƣ��û�����ָ����������ģ�����
template<typename T1, typename T2, typename T3>
T3 alternative_sum(T2, T1);

//���󣺲����ƶ�ǰ����ģ�����
auto val3 = alternative_sum<long long>(i, lng);

//��ȷ����ʽָ����������������
auto val2 = alternative_sum<long long, int, long>(i, lng);

//��ȷ����ת��Ӧ������ʽָ����ʵ��
long lng;
compare(lng, 1024);//����ģ�������ƥ��
comapre<long>(lng, 1024);//��ȷ��ʵ����compare(long,long)
comapre<int>(lng, 1024);//��ȷ��ʵ����compare(int,int)

//16.2.3 β�÷�������������ת��
template<typename It>
? ? ? &fcn(It beg, It end)
{
	//��������
	return *beg;//����������һ��Ԫ�ص�����
}

vector<int>v1 = { 1,2,3 };
Blob<string>ca = { "hi","bye" };
auto& i = fcn(vi.begin(), vi.end());//fcnӦ�÷���int&
auto& s = fcn(ca.begin(), ca.end());//fcnӦ�÷���string&

//β�÷������������ڲα��б�֮��������������
template<typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
	//��������
	return *beg;//����������һ��Ԫ�ص�����
}

//��������ת���ı�׼��ģ����
	//type_traits
remove_reference<decltype(*beg)>::type

//Ϊ��ʹ��ģ������࣬����ʹ��typename
template<typename It>
auto fcn2(It beg, It end) ->
typename remove_reference<decltype(*beg)>::type
{
	//��������
	return *beg;//����������һ��Ԫ�ص�����
}

//16.2.4 ����ָ���ʵ���ƶ�
template<typename T>int compare(const T&, const T&);
//pf1ָ��ʵ��int compare(const int&, const int&);
int(*pf1)(const int&, const int&) = compare;

//func �����ذ汾��ÿ���汾����һ����ͬ�ĺ���ָ������
void func(int(*))(const string&, const string&);
void func(int(*))(const int&, const int&);
func(compare);//����ʹ��compare���ĸ�ʵ����

//��ȷ����ʽָ��ʵ�����ĸ�compare�汾
func(compare<int>);//����compare(const int&, const int&);

//Note:��������һ������ģ��ʵ���ĵ�ַʱ�����������ı������㣺��ÿ��ģ���������Ψһȷ�������ͻ�ֵ��

//16.2.5 ģ��ʵ���ƶϺ�����
template<typename T>void f(T & p);
//��������Ӧ����ȷ�����ð󶨹���const�ǵײ�ģ����Ƕ����

//����ֵ���ú��������ƶ�����
template<typename T>void f1(T&);//ʵ�α�����һ����ֵ
//��f1�ĵ���ʹ��ʵ�������õ�������Ϊģ���������
f1(i);//i int,T��int
f1(ci);//ci  const int ,T��const int
f1(5);//���󣺴��ݸ�һ��&������ʵ�α�����һ����ֵ

template<typename T>void f2(const T&);//���Խ���һ����ֵ
//f2�еĲ�����const &;ʵ���е�const���޹ص�
//��ÿ�������У�f2�ĺ������������ƶ�Ϊconst int&
f2(i);//i int,T��int
f2(ci);//ci  const int ,T��const int
f2(5);//һ��const & �������԰󶨵�һ����ֵ;T��int

//����ֵ���ú��������ƶ�����
template<typename T>void f3(T&&);
f3(42);//ʵ����һ��int���͵���ֵ��ģ�����T��int

//�����۵�����ֵ���ò���
	//X& &,X& &&��X&& &�����۵�������X&
	//����X&& &&�۵���X&&

//Note:�����۵�ֻ��Ӧ���ڼ�Ӵ��������õ����ã������ͱ�����ģ�����

f3(i);//ʵ����һ����ֵ��ģ�����T��һ��int&
f3(ci);//ʵ����һ����ֵ��ģ�����T��һ��const int&

void f3<int&>(int&&&);//��T��int&ʱ�����������۵�Ϊint& &&

void f3<int&>(int&);//��T��int&ʱ�����������۵�Ϊint&

//Note:���һ������������ָ��ģ��������͵���ֵ���ã��磬T&&��������Դ��ݸ����������͵�ʵ�Ρ������һ����ֵ���ݸ������Ĳ���������������ʵ����Ϊһ����ͨ����ֵ���ã�T&����

//��д������ֵ���ò�����ģ�庯��
template<typename T>
void f3(T && val)
{
	T t = val;//�������ǰ�һ�����ã�
	t = fcn(t);//��ֵֻ�ı�t���Ǽȸı�t�ָı�val��
	if (val == t) {/* ... */ }//��T���������ͣ���һֱΪtrue
}

template<typename T>void f(T&&);//�󶨵���const��ֵ
template<typename T>void f(const T&);//��ֵ��constֵ

//16.2.6 ���std::move
//ǿ��ת��Ϊ��ֵ

//std::move����ζ����
	//�ڷ������ͺ�����ת����ҲҪ�õ�typename
	//remove_reference
template<typename T>
typename remove_reference<T>::type&& move(T && t)
{
	//static_cast
	return static_cast<typename remove_reference<T>::type&&>(t);
}

string s1("hi!"), s2;
s2 = std::move(string("bye!"));//��ȷ����һ����ֵ�ƶ�����
s2 = std::move("s1");//��ȷ�����ڸ�ֵ֮��s1��ֵ�ǲ�ȷ����

//std::move����ι�����
string&& move(string && t);

string&& move(string & t);

//��һ����ֵstatic_cast��һ����ֵ�����������

//16.2.7 ת��
	//����һ���ɵ��ö������������������ģ��
	//�ԡ���ת���Ĳ������ø����Ŀɵ��ö���
	//flip1��һ����������ʵ�֣�����const�����ö�ʧ��
template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}

void f(int v1, int& v2)//v2��һ������
{
	cout << v1 << " " << ++v2 << endl;
}

f(42, i);//f�ı���ʵ��i
flip1(f, j, 42);//ͨ��flip1����f����ı�j

void flip1(void(*fcn)(int, int&), int t1, int t2);

//�����ܱ���������Ϣ�ĺ�������
template<typename F, typename T1, typename T2>
void flip2(F f, T1 && t1, T2 && t2)
{
	f(t2, t1);
}

//Note:���һ������������ָ��ģ�����Ͳ�������ֵ���ã�T&&��������Ӧ��ʵ�ε�const���Ժ���ֵ/��ֵ���Խ��õ����֡�

	//�������ڽ�����ֵ���õĲ����ĺ���
void g(int&& i, int& j)
{
	cout << i << " " << j << endl;
}

flip2(g, i, 42);//���󣺲��ܴ���ֵʵ����int&&

//�ڵ�����ʹ��std::forward ����������Ϣ
template<typename Type>intermediary(Type && arg)
{
	finalFcn(std::forward<Type>(arg));
}

//Note:����һ��ָ��ģ��������͵���ֵ���ú�������(T&&)ʱ��forward�ᱣ��ʵ�����͵�����ϸ�ڡ�

template<typename F, typename T1, typename T2>
void filp(F f, T1 && t1, T2 && t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

//Note:��std::move��ͬ����std::forward��ʹ��using������һ�������⡣

//16.3 ������ģ��
//warning:��ȷ����һ�����صĺ���ģ����Ҫ�����ͼ�Ĺ�ϵ��ģ�庯����������޵�ʵ������ת������̵���⡣

//��д����ģ��
	//��ӡ�κ����ǲ��ܴ��������
template<typename T>string debug_rep(const T & t)
{
	ostringstream ret;
	ret << t;//ʹ��T������������ӡt��һ����ʾ��ʽ
	return ret.str();//����ret�󶨵�string��һ������
}

//��ӡָ���ֵ�����ָ��ָ��Ķ���
//ע�⣺�˺�����������char*
template<typename T>string debug_rep(T * p)
{
	ostringstream ret;
	ret << "pointer: " << p;//��ӡָ�뱾���ֵ
	if (p)
		ret << " " << debug_rep(*p);//��ӡpָ���ֵ
	else
		ret << " null pointer";//��ָ��pΪ��
	return ret.str();//����ret�󶨵�string��һ������
}

string s("hi");
cout << debug_rep(s) << endl;

cout << debug_rep(&s) << endl;

//�������ģ��
const string* sp = &s;
cout << debug_rep(sp) << endl;

//Note:���ж������ģ���һ�������ṩ��ͬ�õ�ƥ��ʱ��Ӧ��ѡ���������İ汾��

//��ģ���ģ������
	//��ӡ˫���Ű�Χ��string
string debug_rep(const string & s)
{
	return '"' + s + '"';
}

string s("hi");
cout << debug_rep(s) << endl;

//Note:����һ�����ã����һ���Ǻ���ģ����һ������ģ���ṩͬ���õ�ƥ�䣬��ѡ���ģ��汾��

//����ģ�������ת��
cout << debug_rep("hi world") << endl;//����debug_rep(T*)

//���ַ�ָ��ת��Ϊstring��������string�汾��debug_rep
string debug_rep(char* p)
{
	return debug_rep(string(p));
}

string debug_rep(const char* p)
{
	return debug_rep(string(p));
}

//ȱ���������ܵ��³�����Ϊ�쳣
template<typename T>string debug_rep(const T & t);
template<typename T>string debug_rep(T * p);
//Ϊ��ʹdebug_rep(char* )�Ķ�����ȷ���������������Ҳ��������������
string debug_rep(const string&);
string debug_rep(char* p)
{
	//�������һ��const string& �İ汾����������������
	//������佫����debug_rep(const T&)��Tʵ����Ϊstring�İ汾
	return debug_rep(string(p));
}

//�ڶ����κκ���֮ǰ���ǵ������������صĺ����汾�������Ͳ��ص��ı���������δ����ϣ�����õĺ�����ʵ����һ����������İ汾��

//16.4 �ɱ����ģ��
	//���ܿɱ���Ŀ������ģ�庯����ģ���ࡣ
	//�ɱ���Ŀ�Ĳ�����������
	//ģ����������������ģ�����
	//���������������������������

	//Args��һ��ģ���������rest��һ������������
	//Args��ʾ�������ģ�����Ͳ���
	//rest��ʾ���������������
template<typename T, typename ... Args>
void foo(const T & t, const Args&...rest) {/**/ }

int i = 0; double d = 3.14; string s = " how now brown cow";
foo(i, s, 42, d);//��������������
foo(s, 42, "hi");//�����ж�������
foo(d, s);//������һ������
foor("hi");//�հ�

void foo(const int&, const string&, const int&, const double&);
void foo(const string&, const int&, const char[3] &);
void foo(const double&, const string&);
void foo(const char[3] &);

//sizeof...�����
template<typename ...Args>
void g(Args...args)
{
	cout << sizeof...(Args) << endl;//���Ͳ�������Ŀ
	cout << sizeof...(args) << endl;//�������͵���Ŀ
}

//16.4.1 ��д�ɱ��������ģ��
		//������ֹ�ݹ鲢��ӡ���һ��Ԫ�صĺ���
		//�˺��������ڿɱ�����汾��print����֮ǰ����
template<typename T>
ostream& print(ostream & os, const T & t)
{
	return os << t;//�������һ��Ԫ��֮�󲻴�ӡ�ָ���
}
//���г������һ��Ԫ��֮�������Ԫ�ض����������汾��print
template<typename T, typename...Args>
ostream& print(ostream & os, const T & t)
{
	return os << t;//�������һ��Ԫ��֮�󲻴�ӡ�ָ���
}
//���г������һ��Ԫ��֮�������Ԫ�ض����������汾��print
template<typename T, typename... Args>
ostream& print(ostream & os, const T & t, const Args...rest)
{
	os << t << " ,";//��ӡ��һ��ʵ��
	return print(os, rest...);//�ݹ���ã���ӡ����ʵ��
}

//warning:������ɱ�����汾��printʱ���ǿɱ�����汾�������������С����򣬿ɱ�����汾�����޵ݹ顣

//16.4.2 ����չ
template<typename T, typename... Args>
ostream& print(ostream & os, const T & t, const Args...rest)//��չArgs
{
	os << t << " ,";
	return print(os, rest...);//��չrest
}

print(cout, i, s, 42);//��������������
ostream& print(ostream & os, const int&, const string&, const int&);
print(os, s, 42);

//������չ
		//��print�����ж�ÿ��ʵ�ε���debug_rep
template<typename...Args>
ostream& errorMsg(ostream & os, const Args&...rest)
{
	//print(os,debug_rep(a1),debug_rep(a2),...,debug_rep(an)
	return print(os, debug_rep(rest)...);
}

errorMsg(cerr, fcnName, code.num(), otherData, "other", item);

print(cerr, debug_rep(fcnName), debug_rep(code.num()), debug_rep(otherData), debug_rep("other"), debug_rep(item));

//�������ݸ�debug_rep;print(os,debug_rep(a1,a2,...,an))
print(os, debug_rep(rest)...);//���󣺴˵�����ƥ�亯��
print(cerr, debug_rep(fcnName, code.num(), otherData, "other", item));

//Note:��չ�е�ģʽ�������Ӧ���ڰ��е�ÿ��Ԫ�ء�

//16.4.3 ת��������
class StrVec
{
public:
	template<class...Args>void emplace_back(Args&&...);
};

template<class...Args>
inline
void StrVec::emplace_back(Args&&...args)
{
	chk_n_alloc();//�����Ҫ�Ļ����·���StrVec�ڴ�ռ�
	alloc.construct(first_free++, std::forward<Args>(args)...);
}
svec.empalce_back(10, 'c');//��cccccccccc���Ϊ�µ�βԪ��
std::forward<int>(10), std::forward<char>(c)

svec.empalce_back(s1 + s2);//ʹ���ƶ����캯��
std::forward<string>(string("the end"));

//16.5 ģ��������
//��һ���汾�����ԱȽ�������������
template<typename T>int compare(const T&, const T&);

//�ڶ����汾�����ַ������泣��
template<size_t N,size_t M>
int compare(const char(&)[N], const char(&)[M]);

const char* p1 = "hi", * p2 = "mom";
compare(p1, p2);//���õ�һ��ģ��
compare("hi", "mom");//���������������Ͳ����İ汾

//һ���������汾����ģ���һ�������Ķ��壬������һ������ģ�������ָ��Ϊ�ض������͡�

//���庯��ģ��������
//compare������汾�������ַ������ָ��
template<>
int compare(const char* const& p1, const char* const& p2)
{
	return strcmp(p1, p2);
}

template<typename T>int compare(const T&, const T&);

//����������ģ��������
//Note:�������ı�����ʵ����һ��ģ�壬��������������ˣ���������Ӱ�캯��ƥ�䡣

//ģ�弰���������汾Ӧ��������ͬһ��ͷ�ļ��С�����ͬ��ģ�������Ӧ�÷���ǰ�棬Ȼ������Щģ����������汾��

//��ģ��������
//��std�����ռ䣬�Ա�������std::hash
namespace std
{

}//�ر�std�����ռ䣻�һ�����֮��û�зֺ�

//��std�����ռ䣬�Ա�������std::hash
namespace std
{
	template<>//����һ���������汾��ģ�����ΪSales_data
	struct hash<Sales_data>
	{
		//����ɢ��һ���������������ͱ���Ҫ������������
		typedef size_t result_type;
		typedef Sales_data argument_type;//Ĭ������£���������Ҫ==
		size_t operator()(const Sales_data& s)const;
		//ʹ�úϳɵĿ������Ƴ�Ա��Ĭ�Ϲ��캯��
	};
}
size_t
hash<Sales_data>::operator(const Sales_data& s)const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^
		hash<double>()(s.revenue);
}

//ʹ��hash<Sales_data>��Sales_data��operator==
unordered_multiset<Sales_data>Sdset;

template<class T>class std::hash;//��Ԫ��������Ҫ��
class Sales_data
{
	friend class std::hash<Sales_data>;
};

//Note:Ϊ����Sales_data���û���ʹ��hash���������汾��Ӧ����Sales_data��ͷ�ļ��ж�����������汾��

//��ģ�岿��������
//Note:ֻ�ܲ�����������ģ�壬�����ܲ�������������ģ�塣

//ԭʼ�ġ���ͨ�õİ汾
template<class T>struct  remove_reference
{
	typedef T type;
};

//�����������汾����������ֵ���ú���ֵ����
template <class T>struct remove_reference<T&>//��ֵ����
{
	typedef T type;
};
template <class T>struct remove_reference<T&&>//��ֵ����
{
	typedef T type;
};

int i;
//decltype(42)Ϊint��ʹ��ԭʼģ��
remove_reference<decltype(42)>::type a;

//decltype(i)Ϊint&,ʹ�õ�һ��(T&)�����������汾
remove_reference<decltype(i)>::type b;

//decltype(std::move(i))Ϊint&&,ʹ�õڶ���(T&&)�����������汾
remove_reference<decltype(std::move(i))>::type c;

//��������Ա��������
template<typename T>struct Foo
{
	Foo(const T&t=T()):mem{}
	void Bar(){/**/}
	T mem;
};
template<>//������һ��ģ��
void Foo<int>::Bar()//������Foo<int>�ĳ�ԱBar
{
	//����Ӧ����int������������
}

Foo<string>fs;//ʵ����Foo<string>::Foo()
fs.Bar();//ʵ����Foo<string>::Bar()
Foo<int>fi;//ʵ����Foo<int>::Foo()
fi.Bar();//ʹ���������汾��Foo<int>::Bar()