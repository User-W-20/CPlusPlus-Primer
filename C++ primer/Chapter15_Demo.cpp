//#include<string>
//#include<iostream>
//#include<vector>
//#include<memory>
//#include<set>
//#include<algorithm>
////15.1 OOP:����
////������������ƣ����ݳ��󡢼̳кͶ�̬�󶨡�
//
////�̳�
////���ࡪ�̳С�������
////�麯�� virtual
//
//class Quote
//{
//public:
//	std::string isbn()const;
//	virtual double net_price(std::size_t n)const;
//};
//
////�������б� class xx:base{};
//
//class Bulk_quote:public Quote
//{
//public:
//	double net_price(std::size_t)const override;
//};
////��ʽע��ʹ���ĸ���Ա������д�˻�����麯����override
//
////��̬��:������ʱѡ�����İ汾��Ҳ������ʱ��
//
////���㲢��ӡ���۸�����ĳ���鼮���õķ���
//double print_total(std::ostream& os, const Quote& item, std::size_t n)
//{
//	//���ݴ����item�βεĶ������͵���Quote::net_price
//	//����Bulk_quote::net_price
//	double ret = item.net_price(n);
//	os << "ISBN" << item.isbn() << "# sold: " << n << "total due" << ret << std::endl;
//	return ret;
//}
//
////Note:��c++�����У�������ʹ�û�������ã���ָ�룩����һ���麯��ʱ��������̬��
//
////15.2 ��������������
////15.2.1 �������
//
//class  Quote
//{
//public:
//	Quote() = default;
//	Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price){}
//	std::string isbn()const { return bookNo; }
//
//	//���ظ��������鼮�������ܶ�
//	//�����ฺ���д��ʹ�ò�ͬ���ۿۼ����㷨
//	virtual double net_price(std::size_t n)const { return n * price; }
//	
//	virtual ~Quote() = default;//�������������ж�̬��
//private:
//	std::string bookNo;//�鼮ISBN���
//protected:
//	double price = 0.0;//��ͨ״̬�²����۵ļ۸�
//};
//
////Note:����ͨ����Ӧ�ö���һ����������������ʹ�ú�����ִ���κ�ʵ�ʲ���Ҳ����ˡ�
//
////��Ա������̳�
////��������Ҫ�ṩ�Լ����¶����Ը��Ǵӻ���̳ж����ľɶ���.
//
////1������ϣ�������า�ǵĺ�����ͨ�����䶨��Ϊ�麯��
////2������ϣ��������ֱ�Ӽ̳ж����ı�ĺ�����
//
////�κι��캯������ķǾ�̬�������������麯����
//
////���ʿ�����̳�
////��������Ȩ���ʣ������û���ֹ���ʡ�protected
//
////15.2.2 ����������
////�������б� class xx:public/private/protected base
//
//class Bulk_quote :public Quote
//{
//public:
//	Bulk_quote() = default;
//	Bulk_quote(const std::string&, double, std::size_t, double);
//	//���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
//	double net_price(std::size_t)const override;
//private:
//	std::size_t min_qty = 0;//�����ۿ����ߵ���͹�����
//	double discount = 0.0;//��С����ʾ���ۿ۶�
//};
//
////������඼ֻ�̳���һ���࣬�����̳С�
//
////�������е��麯��
////��������ʽ��ע����ʹ��ĳ����Ա�������������̳е��麯����const���override��
//
////�������������������������ת��
////�������к��л������ɲ��֣��ܰ�������������������ʹ�á�Ҳ�ܰѻ����ָ������ð󶨵�����������еĻ��ಿ�֡��������ൽ���������ת������  ��ʽִ��
//
////Note:������������к���������Ӧ����ɲ��֣���һ��ʵ�Ǽ̳еĹؼ�
//
////�����๹�캯��
////Note:ÿ����������Լ��ĳ�Ա��ʼ������
//
////Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc){};
//
////Note:���ȳ�ʼ�����ಿ�֣�Ȼ����˵����˳�����γ�ʼ��������ĳ�Ա
//
////������ʹ�û���ĳ�Ա
//
////��������˹����鼮��ĳ���������ֵ���Ϳ��������ۿۼ۸���
//double Bulk_quote::net_price(std::size_t cnt)const
//{
//	if (cnt >= min_qty)
//		return cnt * (1 - discount) * price;
//	else
//		return cnt * price;
//}
//
////�̳��뾲̬��Ա
//
//class Base
//{
//public:
//	static void statmen();
//};
//class Derived :public Base
//{
//	void f(const Derived&);
//};
//
//void Derived::f(const Derived& derived_obj)
//{
//	Base::statmen();//��ȷ��Base������statmen
//	Derived::statmen();//��ȷ��Derived�̳���statmem
//	//��ȷ��������Ķ����ܷ��ʻ���ľ�̬��Ա
//	derived_obj.statmen();//ͨ��Derived�������
//	statmen;//ͨ��this�������
//}
//
////�����������
////class Bulk_quote :public Quote;//���������б��ܳ���������
////class Bulk_quote;//��ȷ���������������ȷ��ʽ
//
////�������������
////class Quote;//������δ����
//////����Quote���뱻����
////class Bulk_quote:public Quote{/**/ };
//
////һ�����ǻ��࣬ͬʱ��Ҳ������һ��������
////class Base{/**/ };
////class D1:public Base{/**/};
////class D2:public D1{/**/};
////Base��D1��ֱ�ӻ��࣬Ҳ��D2�ļ�ӻ���
//
////��ֹ�̳еķ���
////�������final
////class NoDerived final{/**/};//������Ϊ����
////class Base{/**/};
//////Last��final�ģ����ܼ̳�
////class Last final:Base{};//Last������Ϊ����
////class Bad:NoDerived{};//NoDerived��final��
////class Bad2:Last{};//Last��final��
//
////15.2.3 ����ת����̳�
//
////���Խ������ָ������ð󶨵������������.
//
////Note:������ָ��һ��������ָ����Ҳ֧������������������ת��������ζ�����ǿ��Խ�һ������������ָ��洢��һ�����������ָ���ڡ�
//
////��̬�����붯̬����
////��̬���ͱ���ʱ��֪����̬��������ʱ��֪
//
////������ʽ�Ȳ�������Ҳ����ָ�룬�����Ķ�̬������Զ�뾲̬����һ�¡�
//
////Note:�����ָ������õľ�̬���Ϳ������䶯̬���Ͳ�һ�¡�
//
////�����ڴӻ��������������ʽ����ת��
////һ������Ķ���������������һ���֣�Ҳ���ܲ��ǣ����Բ����ڴӻ�������������Զ�����ת��
//
////Quote base;
////Bulk_quote* bulkP = &base;//���ܽ�����ת����������
////Bulk_quote& bulkP = base;//���ܽ�����ת����������
//
////��ʹһ������ָ������ð󶨵�һ������������ϣ�Ҳ����ִ�дӻ������������ת��
////Bulk_quote bulk;
////Quote* itemP = &bulk;//��ȷ����̬������BUlk_quote
////Bulk_quote* bulkP = itemP;//���󣺲��ܽ�����ת����������
//
////������ຬһ�������麯����ʹ��dynamic_cast����һ������ת������ת���İ�ȫ��齫������ʱִ�С� 
////�����֪�������������ת���ǰ�ȫ�ģ�������static_cast��ǿ�Ƹ��ǵ��������ļ�鹤����
//
////�ڶ���֮�䲻��������ת��
////�е�
////Note:������ʹ��һ�����������Ϊһ����������ʼ����ֵʱ��ֻ�и�����������еĻ��ಿ�ֻᱻ�������ƶ��͸�ֵ�����������ಿ�ֽ������Ե���
//
////15.3 �麯��
////����Ϊÿһ���麯�����ṩ���壬�����Ƿ��õ�
//
////���麯���ĵ��ÿ���������ʱ�ű�����
////Quote base("0-201-82470-1", 50);
////print_total(std::cout, base, 10);//����Quote::net_price
////Bulk_quote derived("0-201-82470-1", 50, 5, .19);
////print_total(std::cout, derived, 10);//����Bulk_quote::net_price
//
////��̬��ֻ�е�ͨ��ָ��������õ����麯��ʱ�ŷ�����
////base = derived;//��derived��Quote���ֿ�����base
////base.net_price(20);//����Quote::net_price
//
////Note:���ҽ�����ͨ��ָ������õ����麯��ʱ���Ż�������ʱ�����õ��ã�Ҳֻ������������¶���Ķ�̬���Ͳ��п����뾲̬���Ͳ�ͬ��
//
////�������е��麯��
////���������麯���ķ�������Ҳ��������ຯ��ƥ�䡣
////���ǵ�����麯��������������ı����ָ���������ʱ������������Ч
//
////Note:�����е��麯������������������Ҳ��һ���麯�����������า����ĳ���麯��ʱ���ú����ڻ����е��βα������������е��β��ϸ�ƥ��
//
////final��override˵����
//struct B
//{
//	virtual void f1(int)const;
//	virtual void f2();
//	void f3();
//};
//
//struct D1:B
//{
//	void f1(int)const override;//��ȷ��f1������е�f1ƥ��
//	void f2(int)override;//���� Bû������f2(int)�ĺ���
//	void f3()override;//���� f3�����麯��
//	void f4()override;//���� Bû����Ϊf4�ĺ���
//};
//
//struct D2:B
//{
//	//��B�м̳�f2()��f3(),����f1(int)
//	void f1(int)const final;//����������������า��f1(int)
//};
//
//struct D3:D2
//{
//	void f2();//��ȷ�����ǴӼ�ӻ���B�̳ж�����f2
//	void f1(int)const;//����D2�Ѿ���f2������final
//};
//
////�麯����Ĭ��ʵ��
////����麯��ʹ��Ĭ��ʵ�Σ��������������ж����Ĭ��ʵ�����һ�¡�
//
////�ر��麯���Ļ���
////ǿ�е��û����ж���ĺ����汾������baseP�Ķ�̬���͵�����ʲô
////double undiscounted = baseP->Quote::net_price(42);
//
////Note:ͨ������£�ֻ�г�Ա����������Ԫ���еĴ������Ҫʹ����������������ر��麯���Ļ��ơ�
//
////���һ���������麯����Ҫ�������Ļ���汾������û��ʹ�����������������������ʱ�õ��ý�������Ϊ��������汾����ĵ��ã��Ӷ��������޵ݹ顣
//
////15.4 �������
//
////���麯��
////���麯�����붨��  �������ķֺ�֮ǰ��д=0
//
////�û������ۿ�ֵ�͹��������࣬������ʹ����Щ���ݿ���ʵ�ֲ�ͬ�ļ۸����
//class Disc_quote :public Quote
//{
//public:
//	Disc_quote() = default;
//	Disc_quote(const std::string&book,double price,std::size_t qty,double disc):Quote(book,price),quantity(qty),discount(disc){}
//	double net_price(std::size_t)const = 0;
//protected:
//	std::size_t quantity = 0;//�ۿ����õĹ�����
//	double discount = 0.0;//��ʾ�ۿ۵�С��ֵ
//};
//
////���д��麯�������ǳ������
////���У�����δ������ֱ�Ӽ̳У����麯�������ǳ������.
//
////Disc_quote �����˴��麯������Bulk_quote �����Ǹú���
////Disc_quote discounted;//���󣺲��ܶ���Disc_quote �Ķ���
////Bulk_quote bulk;//��ȷ��Bulk_quote��û�д��麯��
//
////Note:���ܴ����������Ķ���.
//
////�����๹�캯��ֻ��ʼ������ֱ�ӻ���
////��ͬһ�鼮������������ĳ��ֵʱ�����ۿ�
////�ۿ۵�ֵ��һ��С��1������С��ֵ���Դ��������������ۼ۸�
//
//class Bulk_quote :public Disc_quote
//{
//public:
//	Bulk_quote() = default;
//	Bulk_quote(const std::string&book,double price,std::size_t qty,double disc):Disc_quote(book,price,qty,disc){}
//	//���ǻ����еĺ����汾��ʵ��һ���µ��ۿ۲���
//	double net_price(std::size_t)const override;
//};
//
////�ع�����������������ϵ�Ա㽫������/�����ݴ�һ�����ƶ�����һ�����С�
//
////15.5 ���ʿ�����̳�
//
////�ܱ����ĳ�Ա
//class Base
//{
//protected:
//	int prot_mem;
//};
//class Sneaky :public Base
//{
//	friend void clobber(Sneaky&);//���Է���Sneraky::prot_mem
//	friend void clobber(Base&);//���ܷ���Base::prot_mem
//	int j;//Ĭ��˽��
//};
////��ȷ��clobber�ܷ���Sneaky�����private��protected��Ա
////void clobber(Sneaky& s) { s.j = s.prot_mem = 0; }
////����clobber���ܷ���Base��protected��Ա
////void clobber(Base& b) { b.prot_mem = 0; }
//
////������ĳ�Ա����Ԫֻ�ܷ�������������еĻ��ಿ�ֵ��ܱ�����Ա��
//
////���С�˽�к��ܱ����̳�
//class Base
//{
//public:
//	void pub_mem();
//private:
//	char priv_mem;
//protected:
//	int prot_mem;
//};
//
//struct Pub_Derv :public Base
//{
//	int f() { return prot_mem; }//��ȷ�����Է���protected��Ա
//	//char g() { return priv_mem; }//����private��Ա�����������ǲ��ɷ��ʵ�
//};
//
//struct Priv_Derv :private Base
//{
//	int f1()const { return prot_mem; }//private��Ӱ��������ķ���Ȩ��
//};
//
//struct  Derived_from_Public:public Pub_Derv
//{
//	int use_base() { return prot_mem; }
//	//��ȷ��Base::prot_mem��Pub_Derv����Ȼ��protected��
//};
//
//struct  Derived_from_Private:public Priv_Derv
//{
//	int use_base() { return prot_mem; }
//	//����Base::prot_mem��Priv_Derv����private��
//};
//
////�����������ת���Ŀɷ�����
////���ڴ����е�ĳ�������ڵ���˵����������ǹ��г�Ա���Է��ʵģ�������������������ת��Ҳ�ǿ��Է��ʵģ���֮���С�
//
////��Ԫ��̳�
//class Base
//{
//	friend class Pal;//Pal�ڷ���Base��������ʱ������������
//
//	public:
//	void pub_mem();
//private:
//	char priv_mem;
//protected:
//	int prot_mem;
//};
//
//class Pal
//{
//public:
//	int f(Base b) { return b.prot_mem; }//��ȷ��Pal��Base����Ԫ
//	int f2(Sneaky s) { return s.j; }//����Pal����Sneaky����Ԫ
//	//�Ի���ķ���Ȩ���ɻ��౾����ƣ���ʹ����������Ļ��ಿ��Ҳ�����
//	int f3(Sneaky s) { return s.prot_mem; }//��ȷ��Pal��Base����Ԫ
//};
//
////D2��Base��protected��private��Ա����������ķ�������
//class D3 :public Pal
//{
//public:
//	int mem(Base b)
//	{
//		return b.prot_mem;//������Ԫ��ϵ���ܼ̳�
//	}
//};
//
////���ܼ̳���Ԫ��ϵ��ÿ���ฺ����Ƹ���Ա�ķ���Ȩ��
//
////�ı�����Ա�Ŀɷ����� ͨ��using
//class Base
//{
//public:
//	std::size_t size()const { return n; }
//protected:
//	std::size_t n;
//};
//class Derived :private Base
//{
//public:
//	//���ֶ���ߴ���صĳ�Ա���ʼ���
//	using Base::size;
//protected:
//	using Base::n;
//};
//
////Note:������ֻ��Ϊ��Щ�����Է��ʵ������ṩusing������
//
////Ĭ�ϵļ̳б�������
//class Base{};
//struct D1:Base{};//Ĭ��public�̳�
//class D2:Base{};//Ĭ��private�̳�
//
////Note:һ��˽����������������ʽ�ؽ�private��������������Ҫ����������Ĭ�ϵ����á���ʽ�����ĺô��ǿ�����˽�м̳й�ϵ�������ˣ������ڲ�����ᡣ
//
////15.6 �̳��е���������
//
////�ڱ���ʱ�������ֲ���
//class Disc_quote :public Quote
//{
//public:
//	Disc_quote() = default;
//	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) {}
//	double net_price(std::size_t)const = 0;
//	std::pair <size_t ,double>discount_policy()const
//	{
//		return { quantity,discount };
//	}
//
//	protected:
//		std::size_t quantity = 0;//�ۿ����õĹ�����
//		double discount = 0.0;//��ʾ�ۿ۵�С��ֵ
//};
//
//Bulk_quote bulk;
//Bulk_quote* bulkP = &bulk;//��̬���ͺͶ�̬����һ��
//Quote* itemP = &bulk;//��̬���ͺͶ�̬���Ͳ�һ��
//bulkP->discount_policy();//��ȷ��bulkP��������Bulk_quote*
//itemP->discount_policy();//����itemP��������Quote*
//
////���ֳ�ͻ��̳�
//struct Base
//{
//	Base() :mem(0){}
//protected:
//	int mem;
//};
//
//struct Derived :Base
//{
//	Derived(int i):mem(i){}//��i��ʼ��Derived::mem
//							//Base::mem����Ĭ�ϳ�ʼ��
//	int get_mem(){ return mem; }//����Derived::mem
//
//protected:
//	int mem;//���ػ����е�mem
//};
//
//Derived d(42);
//std::cout << d.get_mem() << std::endl;
//
////Note:������ĳ�Ա������ͬ���Ļ����Ա��
//
////ͨ���������������ʹ�����صĳ�Ա
//struct Derived :Base
//{
//	Derived(int i) :mem(i) {}//��i��ʼ��Derived::mem
//	//Base::mem����Ĭ�ϳ�ʼ��
//	int get_mem() { return Base::mem; }//����Derived::mem
//
//protected:
//	int mem;//���ػ����е�mem
//};
//
////���˸��Ǽ̳ж������麯��֮�⣬��������ò�Ҫ�������������ڻ����е����֡�
//
////һ�����������ֲ����������ͼ��
//struct Base
//{
//	int memfcn();
//}; 
//struct Dervied:Base
//{
//	int memfcn(int);//���ػ����е�memfcn
//};
//Derived d; Base b;
//b.memfcn();//����Base::memfcn
//d.memfcn(10);//����Derived::memfcn
//d.memfcn();//���󣺲����б�Ϊ�յ�memfcn��������
//d.Base::memfcn();//��ȷ������Base::memfcn
//
////�麯����������
//class Base
//{
//public:
//	virtual int fcn();
//};
//class D1 :public Base
//{
//public:
//	//���ػ����fcn�����fcn�����麯��
//	//D1�̳���Base::fcn�����ĺ���
//	int fcn(int);//�β��б���Base�е�fcn��һ��
//	virtual void f2();//��һ���µ��麯������Base�в�����
//};
//class D2 :public D1
//{
//public:
//	int fcn(int);//��һ�����麯����������D1::fcn(int)
//	int fcn();//������Base���麯��fcn
//	void f2();//������D1���麯��f2
//};
//
////ͨ������������ص��麯��
//Base bobj; D1 d1obj; D2 d2obj;
//Base* bp1 = &bobj, * bp2 = &d1obj, * bp3 = &d2obj;
//bp1->fcn();//����ã���������ʱ����Base::fcn
//bp2->fcn();//����ã���������ʱ����Base::fcn
//bp3->fcn();//����ã���������ʱ����D2::fcn
//
//D1* d1p = &d1obj; D2* d2p = &d2obj;
//bp2->f2();//����Baseû����Ϊf2�ĳ�Ա
//b1p->f2();//����ã���������ʱ����D1::f2
//b2p->f2();//����ã���������ʱ����D2::f2
//
//Base* p1 = &d2obj; D1* p2 = &d2obj; D2* p3 = &d2obj;
//p1->fcn(42);//����Base��û�н���һ��int��fcn
//p2->fcn(42);//��̬�󶨣�����D1::fcn(int)
//p3->fcn(42);//��̬�󶨣�����D2::fcn(int)
//
////�������صĺ���
////Ϊ���صĳ�Ա�ṩһ��using�������.
//
////15.7 ���캯���뿽������
//
////15.7.1 ����������
//class Quote
//{
//public:
//	//�������ɾ������һ��ָ�����������Ļ���ָ�룬����Ҫ����������
//	virtual ~Quote() = default;//��̬����������
//};
//
//Quote* itemP = new Quote;//��̬�����붯̬����һ��
//delete itemP;//����Quote����������
//itemp = new Bulk_quote;//��̬�����붯̬���Ͳ�һ��
//delete itemP;//����Bulk_quote����������
//
////warning�����������������������麯������deleteһ��ָ�����������Ļ���ָ�뽫����δ�������Ϊ��
//
////��������������ֹ�ϳ��ƶ�����
////��ʹͨ��=defaultʹ���˺ϳɵİ汾��
//
////15.7.2 �ϳɿ���������̳�
////���ۻ����Ա�Ǻϳɵİ汾�����Զ���İ汾��û��̫���Ӱ�졣ΨһҪ�������Ӧ��ԱӦ�ÿ��Է��ʲ��Ҳ���һ����ɾ���ĺ�����
//
////��������ɾ���Ŀ������������Ĺ�ϵ
//class B
//{
//public:
//	B();
//	B(const B&) = delete;
//	//������Ա���������ƶ����캯��
//};
//class D :public B
//{
//	//û�������κι��캯��
//};
//D d;//��ȷ��D�ĺϳ�Ĭ�Ϲ��캯��ʹ��b��Ĭ�Ϲ��캯��
//D d2(d);//����D�ĺϳɿ������캯���Ǳ�ɾ����
//D d3(std::move(d));//������ʽ��ʹ��D�ı�ɾ���Ŀ������캯��
//
////�ƶ�������̳�
//class Quote
//{
//public:
//	Quote() = default;//�Գ�Ա���ν���Ĭ�ϳ�ʼ��
//	Quote(const Quote&) = default;//�Գ�Ա���ο���
//	Quote(Quote&&) = default;//�Գ�Ա���ο���
//	Quote& operator=(const Quote&) = default;//������ֵ
//	Quote& operator=(Quote&&) = default;//�ƶ���ֵ
//	virtual ~Quote() = default;
//};
//
////15.7.3 ������Ŀ������Ƴ�Ա
////warning���������ඨ���˿������ƶ�����ʱ���ò������𿽱����ƶ��������ಿ�ֳ�Ա���ڵ���������
//
////����������Ŀ������ƶ����캯��
//class Base{};
//class D :public Base
//{
//public:
//	//Ĭ������£������Ĭ�Ϲ��캯����ʼ������Ļ��ಿ��
//	//Ҫ��ʹ�ÿ������ƶ����캯���������ڹ��캯����ʼֵ�б���
//	//��ʽ�ĵ��øù��캯��
//	D(const D& d) :Base(d)//���������Ա
//		/*D�ĳ�Ա��ʼֵ*/ {}
//	D(D&&d):Base(std::move(d))//�ƶ������Ա
//		/*D�ĳ�Ա��ʼֵ*/ {}
//};
//
////D��������������ܿ����ǲ���ȷ�Ķ���
////���ಿ�ֱ�Ĭ�ϳ�ʼ�������ǿ���
//D(const D&d)/* ��Ա��ʼֵ������û���ṩ�����ʼֵ*/
//{ }
//
////warning����Ĭ������£�����Ĭ�Ϲ��캯����ʼ�����������Ļ��ಿ�֡���������뿽�������ƶ������ಿ�֣��������������Ĺ��캯����ʼֵ�б�����ʽ��ʹ�û���Ŀ��������ƶ������캯����
//
////�����ำֵ�����
////Base::operator=(const Base&) ���ᱻ�Զ�����
//D& operator=(const D& rhs)
//{
//	Base::operator=(rhs);//Ϊ���ಿ�ָ�ֵ
//	//���չ�ȥ�ķ�ʽΪ������ĳ�Ա��ֵ
//	//���鴦���Ը�ֵ���ͷ�������Դ�����
//	return *this;
//}
//
////��������������
//class D :public Base
//{
//public:
//	//Base::~Base���Զ�����ִ��
//	~D(){}
//};
////����˳���봴���෴�����������������ٻ������������ż̳���ϵ�ķ�����ֱ�����
//
////�ڹ��캯�������������е����麯��
////Note:������캯������������������ĳ���麯����������Ӧ��ִ���빹�캯�����������������������Ӧ���麯���汾��
//
////15.7.4 �̳еĹ��캯��
//class Bulk_quote :public Disc_quote
//{
//public:
//	using Disc_quote::Disc_quote;//�̳�Disc_quote�Ĺ��캯��
//	double net_price(std::size_t)const;
//};
//
//derived(parms):base(args){}
//
////��ͬ��
//Bulk_quote(const std::string&book,double price,std::size_t qty,double disc):Disc_quote(book,price,qty,disc){}
//
////�̳еĹ��캯�����ص�
////���캯����using��������ı�ù��캯���ķ��ʼ���
//
////using������䲻��ָ��explicit��constexpr
//
////������ຬ�м������캯���������������⣬�����ʱ���������̳�������Щ���캯��
//
////��һ�����⣺��������Լ̳�һ���ֹ��캯������Ϊ�������캯�������Լ��İ汾��
//
////�ڶ������⣺Ĭ�ϡ��������ƶ����첻�ᱻ�̳С�
//
////15.8 �����ͼ̳�  ��Ӵ洢
//
//std::vector<Quote>basket;
//basket.push_back(Quote("0-201-82470-1", 50));//��ȷ������ֻ�ܰѶ����Quote���ֿ�����basket
//std::cout << basket.back().net_price(15) << std::endl;//����Quote����İ汾����ӡ750����15*$50
//
////warning������������󱻸�ֵ���������ʱ�����е������ಿ�ֽ������е�������������ʹ��ڼ̳й�ϵ�������޷����ݡ�
//
////�������з��ã����ܣ�ָ����Ƕ���
//std::vector < std::shared_ptr<Quote> >basket;
//basket.push_back(std::make_shared<Quote>("0-201-82470-1", 50));
//basket.push_back{ std::make_shared<Bulk_quote>("0-201-82470-1", 50 ,10,.25) )};
//std::cout << basket.back()->net_price(15) << std::endl;//����Quote����İ汾����ӡ562.5������15*$50�п۳��ۿ۽��
//
////15.8.1 ��дBasket��
//class Basket
//{
//public:
//	//Basketʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
//	void add_item(const std::shared_ptr<Quote>& sale) { items.insert(sale); }
//	//��ӡÿ������ܼۺ͹���������������ܼ�
//	double total_receipt(std::ostream&)const;
//private:
//	//�ú������ڱȽ�shared_ptr��multiset��Ա���õ���
//	static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) { return lhs->isbn() < rhs->isbn(); }
//	//multiset���������ۣ�����compare��Ա����
//	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>items{ compare };
//};
//
////����Basket�ĳ�Ա
//double Basket::total_receipt(std::ostream& os)const
//{
//	double sum = 0.0;//����ʵʱ��������ܼ۸�
//	//iterָ��ISBN��ͬ��һ��Ԫ���еĵ�һ��
//	//upper_bound����һ�����������õ�����ָ������Ԫ�ص�β��λ��
//	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
//	{
//		//����֪���ڵ�ǰBasket��������һ���ùؼ��ֵ�Ԫ��
//		//��ӡ���鼮��Ӧ����Ŀ
//		sum += print_total(os, **iter, items.count(*iter));
//	}
//	os << "Total Sale:" << sum << std::endl;//��ӡ�����ܼ۸�
//	return sum;
//}
//
////����ָ��
//Basket bsk;
//bsk.add_item(std::make_shared<Quote>("123", 45));
//bsk.add_item(std::make_shared<Bulk_quote>("345", 45,3,.15));
//
//void add_item(const Quote& sale);//���������Ķ���
//void add_item( Quote&& sale);//�ƶ������Ķ���
//
////ģ���鿽��
//class Quote
//{
//public:
//	//�ú������ص�ǰ�����һ�ݶ�̬����Ŀ���
//	//��Щ����ʹ�������޶���
//	virtual Quote* clone()const& { return new Quote(*this); }
//	virtual Quote* clone()&& { return new Quote(std::move(*this)); }
//};
//
//class Bulk_quote :public Quote
//{
//	Bulk_quote* clone()const& { return new Bulk_quote(*this); }
//	Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }
//};
//
//class Basket
//{
//public:
//	void add_item(const Quote&sale)//���������Ķ���
//	{
//		items.insert(std::shared_ptr<Quote>(sale.clone()));
//	}
//	void add_item(Quote&&sale)//�ƶ������Ķ���
//	{
//		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
//	}
//};
//
////15.9 �ı���ѯ������̽
//
////15.9.1 �������Ľ������
////�������������Ӧ�ÿ��������κ���Ҫ�������ĵط�
//
////15.9.2 Query_base���Query��
////������࣬����Ĳ�ѯ���ʹ������������г�Ա����private��
//class Query_base
//{
//	friend class Query;
//protected:
//	using line_no = TextQuery::line_no;//����eval����
//	virtual ~Query_base() = default;
//private:
//	//eval�����뵱ǰQueryƥ���QueryResult
//	virtual QueryResult eval(const TextQuery&)const = 0;
//	//rep�Ǳ�ʾ��ѯ��һ��string
//	virtual std::string rep()const = 0;
//};
//
////Query��
////����Query_base�̳���ϵ�Ľӿ���
//class Query
//{
//	//��Щ�������Ҫ���ʽ���shared_ptr�Ĺ��캯�������ú�����˽�е�
//	friend Query operator~(const Query&);
//	friend Query operator|(const Query&, const Query&);
//	friend Query operator&(const Query&, const Query&);
//public:
//	Query(const std::string&);//����һ���µ�WordQuery
//	//�ӿں��������ö�Ӧ��Query_base����
//	QueryResult eval(const TextQuery&t)const
//	{
//		return q->eavl(t);
//	}
//
//	std::string rep()const { return q->rep(); }
//private:
//	Query(std::shared_ptr<Query_base>query):q(query){}
//	std::shared_ptr<Query_base>q;
//};
//
////Query����������
//std::ostream&
//operator<<(std::ostream& os, const Query& query)
//{
//	//Query::repͨ������Query_baseָ���rep���������������
//	return os << query.rep();
//}
//
//Query andq = Query(sought1) & Query(sought2);
//std::cout << andq << std::endl;
//
////15.9.3 ������
////WordQuery��
//class WordQuery :public Query_base
//{
//	friend class Query;//Query ʹ��WordQuery�Ĺ��캯��
//	WordQuery(const std::string& s) :query_word(s){}
//	//������ࣺWordQuery���������м̳ж����Ĵ��麯��
//	QueryResult eval(const TextQuery& t)const { return t.query(query_word); }
//	std::string rep()const { return query_word; }
//		std::string query_word;//Ҫ���ҵĵ���
//};
//
//inline
//Query::Query(const std::string &s):q(new WordQuery(s)){}
//
////NotQuery�༰~�����
//class NotQuery :public Query_base
//{
//	friend Query operator~(const Query&);
//	NotQuery(const Query& q) :query(q){}
//
//	//������ࣺNotQuery���������м̳ж����Ĵ��麯��
//	std::string rep()const { return "~(" + query.rep() + ")"; }
//	QueryResult eval()(const TextQuery&)const;
//	Query query;
//};
//
//inline Query operator~(const Query& operand)
//{
//	return std::shared_ptr<Query_base>(new NotQuery(operand));
//}
//
////����һ���µ�NotQuery����
////�����õ�NotQueryָ��󶨵�һ��shared_ptr<Query_base>
//std::shared_ptr<Query_base>tmp(new NotQuery(expr));
//return Query(tmp);//ʹ�ý���һ��shared_ptr��Query���캯��
//
////BinaryQuery�� �������
//class BinaryQuery :public Query_base
//{
//protected:
//	BinaryQuery(const Query&l,const Query&r,std::string s):lhs(l),rhs(r),opSym(s){}
//
//	//�����ࣺBinaryQuery������eval
//	Query lhs, rhs;//�����Ҳ��������
//	std::string opSym;//�����������
//
//	std::string rep()const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
//};
//
////Note:BinaryQuery������eval�����Ǽ̳��˸ô��麯������ˣ�BinaryQueryҲ��һ���������û�����ܴ���BinaryQuery���͵Ķ���
//
////AndQuery�ࡢOrQuery�༰��Ӧ�������
//class AndQuery :public BinaryQuery
//{
//	friend Query operator&(const Query&, const Query&);
//	AndQuery(const Query&left, const Query& right):BinaryQuery(left,right,"&"){}
//	//������ࣺAndQuery�̳���rep���Ҷ������������麯��
//	QueryResult eval(const TextQuery&)const;
//};
//
//inline Query operator&(const Query& lhs, const Query& rhs)
//{
//	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
//}
//
//class OrQuery :public BinaryQuery
//{
//	friend Query operator|(const Query&, const Query&);
//	OrQuery(const Query&left, const Query& right):BinaryQuery(left,right,"&"){}
//	QueryResult eval(const TextQuery&)const;
//};
//
//inline Query operator|(const Query& lhs, const Query& rhs)
//{
//	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
//}
//
////15.9.4 eval����
////OrQuery::eval
////������������ѯ���set�Ĳ���
//QueryResult OrQuery::eval(const TextQuery& text)const
//{
//	//ͨ��Query��Ա lhs��rhs���������
//	//ͨ��eval����ÿ����������QueryResult
//	auto right = rhs.eval(text), left = lhs.eval(text);
//	//��������������кſ��������set��
//	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
//	//�����Ҳ�����������õ��к�
//	ret_lines->insert(right.begin(), right.end());
//	//����һ���µ�QueryResult����ʾlhs��rhs�Ĳ���
//	return QueryResult(rep(), ret_lines, left.get_file();
//}
//
////AndQuery::eval
////������������ѯ���set�Ľ���
//QueryResult AndQuery::eval(const TextQuery& text)const
//{
//	//ͨ��Query��������������ã��Ի���������Ĳ�ѯ���set
//	auto left = lhs.eval(text), right = rhs.eval(text);
//	//����left��right������set
//	auto ret_lines = std::make_shared<std::set<line_no>>();
//	//��������Χ�Ľ���д��һ��Ŀ�ĵ�������
//	//���ε��õ�Ŀ�ĵ�������ret���Ԫ��
//	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
//	return QueryResult(rep(), ret_lines, left.get_file());
//}
//
////NotQuery::eval
////�����������Ľ��set�����ڵ���
//QueryResult NotQuery::eval(const TextQuery& text)const
//{
//	//ͨ��Query��������eval���������
//	auto result = query.eval(text);
//	//��ʼʱ���setΪ��
//	auto ret_lines = std::make_shared<std::set<line_no>>();
//	//���������������ֵ��������н��е���
//	auto beg = result.begin(), end = result.end();
//	//���������ļ���ÿһ�У�������в���result���У�������ӵ�ret_lines
//	auto sz = result.get_file()->size();
//	for (size_t n = 0; n != sz; ++n)
//	{
//		//�����û�д�����result��������
//		//��鵱ǰ���Ƿ����
//		if (beg == end || *beg != n)
//		{
//			ret_lines->inesert(n);//�������result�У������һ��
//		}
//		else if (beg != end)
//		{
//			++beg;//���������ȡresult����һ�У�����еĻ���
//		}
//	}
//	return QueryResult(rep(), ret_lines, result.get_file());
//}