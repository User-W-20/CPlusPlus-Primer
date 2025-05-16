//#include<iostream>
//#include<string>
//#include<tuple>
//#include<vector>
//#include<list>
//#include<algorithm>
//#include<numeric>
//#include<cmath>
//#include<bitset>
//#include<regex>
//#include<random>
//#include<iomanip>
//#include<fstream>
//using namespace std;
//
////17.1 tuple����
////����pair��ģ��.
////Note:���Խ�tuple����һ��"���ٶ�����"�����ݽṹ.
//
////17.1.1 ����ͳ�ʼ��tuple
////��Ҫָ��ÿ����Ա������
//tuple<size_t, size_t, size_t>threeD;//������Ա������Ϊ0
//tuple<string, vector<double>, int, list<int>>
//someVal("constants", { 3.14,2.718 }, 42, { 0,1,2,3,4,5 });
//
//tuple<size_t, size_t, size_t>threeD = { 1,2,3 };//����
//tuple<size_t, size_t, size_t>threeD{ 1,2,3 };//��ȷ
//
////��ʾ��꽻�׼�¼��tuple,����:ISBN,������ÿ����ļ۸�
//auto item = make_tuple("0-999-7835-X", 3, 20.00);
//
////����tuple�ĳ�Ա
//auto book = get<0>(item);//����item�ĵ�һ����Ա
//auto cnt = get<1>(item);//����item�ĵڶ�����Ա
//auto price = get<2>(item);//����item�����һ����Ա
//get<2>(item) *= 0.8;//����20%
//
//typedef decltype(trans);//trans��һ��item������
////����trans�����Ͷ����еĳ�Ա������
//size_t sz = tuple_size<trans>::value;//����3
////cnt��������item�еڶ�����Ա��ͬ
//tuple_element<1, trans>::type cnt = get<1>(item);//cnt��һ��int
//
////��ϵ����������
//tuple<string, string>duo("1", "2");
//tuple<size_t, size_t>twoD(1, 2);
//bool b = (duo == twoD);
//tuple<size_t, size_t, size_t >threeD(1, 2, 3);
//b = (twoD < threeD);//���󣺳�Ա������ͬ
//tuple<size_t, size_t >origin(0, 0);
//b = (origin < twoD);//��ȷ��bΪtrue
//
////Note:����tuple������<��==����������ǿ��Խ�tuple���д��ݸ��㷨�����ҿ��������������н�tuple��Ϊ�ؼ������͡�
//
////17.2.1 ʹ��tuple���ض��ֵ
//class Sales_data{};
////files �е�ÿ��Ԫ�ر���һ���������ۼ�¼
//vector<vector<Sales_data>> files;
//
////����tuple�ĺ���
////matches��������Ա��һ����������������ָ�����vector��Ԫ�صĵ�����
//typedef tuple < vector<Sales_data>::size_type, vector <Sales_data>::const_iterator, vector<Sales_data>::const_iterator>matches;
//
////files����ÿ���������ۼ�¼
////findBook����һ��vector��ÿ�������˸����鼮����������ж���һ��
//vector<matches>
//findBook(const vector<vector<Sales_data>>& files, const string& book)
//{
//	vector<matches>ret;//��ʼ��Ϊ��vector
//	//��ÿ����꣬���Ҹ����鼮ƥ��ļ�¼��Χ��������ڵĻ���
//	for (auto it = files.cbegin(); it != files.cend(); ++it)
//	{ 
//		//���Ҿ�����ͬ��isbn��Sales_data��Χ
//		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
//		if (found.first != found.second)//����������˸����鼮
//			//��ס������������ƥ��ķ�Χ
//			ret.push_back(make_tuple(it - files.cbegin(), found.first(), found.second()));
//	}
//	return ret;//���δ�ҵ�ƥ���¼�Ļ���retΪ��
//}
//
////ʹ�ú������ص�tuple
//void reportResult(istream& in, ostream& os, const vector<vector<Sales_data>>& files)
//{
//	string s;//Ҫ���ҵ���
//	while (cin >> s)
//	{
//		auto trans = findBook(files, s);//�������Ȿ������
//		if (trans.empty())
//		{
//			cout << s << " not found in any stores" << endl;
//			continue;//�����һ��Ҫ���ҵ���
//		}
//		for (const auto& store : trans)//��ÿ�������˸����鼮�����
//			//get<n>����store��tuple��ָ���ĳ�Ա
//			os << "store" << get<0>(store) << " sales:"
//			<< accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
//	}
//}
//
////17.2 bitset ����
////17.2.1 ����ͳ�ʼ��bitset
//bitset<32>bitvec(1U);//32λ����λΪ1������λΪ0
////��0��ʼ�ĳ�Ϊ��λ����31�����ĳ�Ϊ��λ
//
////��unsignedֵ��ʼ��bitset
////������ֵ��ʼ��bitsetʱ����ת��Ϊunsigned long long����������λģʽ������
//
////bitvec1�ȳ�ʼֵС����ʼֵ�еĸ�λ������
//bitset<13>bitvec1(0xbeef);//������λ����Ϊ1111011101111
////bitvec2�ȳ�ʼֵ�����ĸ�λ����Ϊ0
//bitset<20>bitvec2(0xbeef);//������λ����Ϊ00001011111011101111
////��64λ�����У�long long OULL��64��0���أ����~0ULL��64��1
//bitset<128>bitvec3(~0ULL);//0~63λΪ1��63-127λΪ0
//
////��һ��string ��ʼ��bitset
//bitset<32>bitvec4("1100");//2��3��λΪ1 ��ʣ����λΪ0
////Note:string���±���ϰ����bitsetǡ���෴��string�е��±������ַ��������ַ���������ʼ��bitset�еĵ�λ���±�Ϊ0�Ķ�����λ��������һ��string��ʼ��һ��bitsetʱ��Ҫ��ס������
//
//string str("111111100000001101101");
//bitset<32>bitvec5(str, 5, 4);//��str[5]��ʼ���ĸ�������λ��1100
//bitset<32>bitvec6(str, str.size() - 4);//ʹ������ĸ��ַ�
//
////17.2.2 bitset����
//bitset<32>bitvec(1U);//32λ����λΪ1��ʣ��λΪ0
//bool is_set = bitvec.any();//true,��Ϊ��1λ��λ
//bool is_not_set = bitvec.none();//false,��Ϊ��1λ��λ��
//bool all_set = bitvec.all();//false,��Ϊֻ��1λ��λ
//size_t onBits = bitvec.count();//����1
//size_t sz = bitvec.size();//����32
//bitvec.flip();//��תbitvec�е�����λ
//bitvec.reset();//������λ��λ
//bitvec.set();//������λ��λ
//
//bitvec.flip(0);//��ת��һλ
//bitvec.set(bitvec.size() - 1);//��λ���һλ
//bitvec.set(0, 0);//��λ��һλ
//bitvec.reset(i);//��λ��iλ
//bitvec.test(0);//����false����Ϊ��һλ�Ǹ�λ��
//
//bitvec[0] = 0;//����һλ��λ
//bitvec[31] = bitvec[0];//�����һλ����Ϊ���һλһ��
//bitvec[0].flip();//��ת��һλ
//~bitvec[0];//�ȼ۲���
//bool b = bitvec[0];//��bitvec[0]��ֵת��Ϊbool����
//
////��ȡbitset��ֵ
//unsigned long ulong = bitvec3.to_ulong();
//cout << "ulong = " << ulong << endl;
//
////Note:���bitset�е�ֵ���ܷ�����������У����������������׳�һ��overflow_erroe�쳣
//
////bitset��IO�����
//bitset<16>bits;
//cin >> bits;//��cin��ȡ���16��0��1
//cout << "bits :" << bits << endl;//��ӡ�ոն�ȡ������
//
////ʹ��bitset
//bool status;
////ʹ��λ������İ汾
//unsigned long quizA = 0;//��ֵ������λ����ʹ��
//quizA |= 1UL << 27;//ָ����27��ѧ��ͨ���˲���
//status = quizA & (1UL << 27);//����27��ѧ���Ƿ�ͨ���˲���
//quizA &= ~(1UL << 27);//��27��ѧ��δͨ������
////ʹ�ñ�׼��bitset��ɵȼ۵Ĺ���
//bitset<30> quizB;//ÿ��ѧ������һλ������λ������ʼ��Ϊ0
//quizB.set(27);//ָ����27��ѧ��ͨ���˲���
//status = quizB[27];//����27��ѧ���Ƿ�ͨ���˲���
//quizB.reset[27];//��27��ѧ��δͨ������
//
////17.3 ������ʽ
////17.3.1 ʹ��������ʽ��
////���Ҳ����ַ�c֮����ַ���ei
//string pattern("[^c]ei");
////��Ҫ����pattern����������
//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//regex r(pattern);//����һ�����ڲ���ģʽ��regex
//smatch results;//����һ�����󱣴��������
////����һ��string������ģʽƥ��Ͳ�ƥ����ı�
//string test_str = "receipt freind theif receive";
////��r��test_str�в�����patternƥ����Ӵ�
//if (regex_search(test_str, results, r))//�����ƥ���Ӵ�
//cout << results.str() << endl;//��ӡƥ��ĵ���
//
////ָ��regex�����ѡ��
////һ��������ĸ�������ַ����һ��'.'�ٽ�"cpp"��"cxx"��"cc"
//regex r(R"([[:alnum:]]+\.(cpp|cxx|cc)$)", regex::icase);
//smatch results;
//string filename;
//while (cin >> filename)
//if (regex_search(filename, results, r))
//cout << results.str() << endl;//��ӡƥ����
//
////ָ����ʹ��������ʽʱ�Ĵ���
////Note:��Ҫ��ʶ���ķǳ���Ҫ��һ���ǣ�һ��������ʽ���﷨�Ƿ���ȷ��������ʱ�����ġ�
//
//try
//{
//	//����:alnum©���������ţ����캯�����׳��쳣
//	regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
//}
//catch (regex_error e)
//{
//	cout << e.what() << "\ncode: " << e.code() << endl;
//}
//
////������ʽ���������������
//regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
//smatch results;//��ƥ��string�������У�������char*
//if (regex_search("myfile.cc", results, r))//��������Ϊchar*
//cout << results.str() << endl;
//
//cmatch results;//��ƥ���ַ�������������
//if(regex_search("mifile.cc",results,r))
//cout << results.str() << endl;//��ӡ��ǰƥ��
//
////17.3.2 ƥ����Regex����������
//
////ʹ��sregex_iterator
//
////����ǰһ���ַ�����c���ַ���ei
//string pattern("[^c]ei");
////������Ҫ������pattern�ĵ��ʵ�ȫ������
//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//regex r(pattern, regex::icase);//�ڽ���ƥ���ʱ�򽫺��Դ�Сд
////������������regex_search��Ѱ���ļ��е�����ƥ��
//for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
//cout << it->str() << endl;//ƥ��ĵ���
//
////ʹ��ƥ������
////ѭ��ͷ��֮ǰһ��
//for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
//{
//	auto pos = it->prefis().length();//ǰ׺�Ĵ�С
//	pos = pos > 40 ? pos - 40 : 0;//��Ҫ���40���ַ�
//	cout << it->prefix().str().substr(pos)//ǰ׺�����һ����
//		<< "\n\t\t" << it->str() << "<<<\n"//ƥ��ĵ���
//		<< it->suffix().str().substr(0, 40)//��׺�ĵ�һ����
//		<< endl;
//}
//
////17.3.3 ʹ���ӱ��ʽ
////r�������ӱ��ʽ����һ���ǵ�֮ǰ��ʾ�ļ����Ĳ��֣��ڶ�����ʾ�ļ�����չ��
//regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
//
//if (regex_search(filename, results, r))
//cout << results.str(1) << endl;//��ӡ��һ���ӱ��ʽ
//
////�ӱ��ʽ����������֤
////������;����֤����ƥ���ض���ʽ�����ݡ�
//
////����������ʽ�����߸��ӱ��ʽ��(ddd)�ָ���ddd�ָ���dddd
////�ӱ��ʽ1��3��4��6�ǿ�ѡ�ģ�2��5����7�������
//"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
//
//string phone= "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
//regex r(phone);//regex�������ڲ���ģʽ
//smatch m;
//string s;
////�������ļ��ж�ȡÿ����¼
//while (getline(cin, s))
//{
////��ÿ��ƥ��ĵ绰����
//for (sregex_iterator it(s.begin(), s.end(), r), end_it;
//	it != end_it; ++it)
//	//������ĸ�ʽ�Ƿ�Ϸ�
//	if (valid(*it))
//		cout << "valid:" << it->str() << endl;
//	else
//		cout << " not valid: " << it->str() << endl;
//}
//
////ʹ����ƥ�����
//bool valid(const smatch & m)
//{
//	//�������ǰ��һ��������
//	if (m[1].matched)
//		//�����ź������һ�������ţ�֮�����ʣ������һ���ո�
//		return m[3].matched
//		&& (m[4].mathced == 0 || m[4].str() == " ");
//	else
//		//�������ź�����������
//		//��������ɲ��ֵķָ�������ƥ��
//		return !m[3].matched
//		&& m[4].str() == m[6].str();
//}
//
////17.3.4 ʹ��regex_replace
//string fmt = "$2.$5.$7";//�������ʽ��Ϊddd.ddd.dddd
//regex r(phone);//����Ѱ��ģʽ��regex����
//string number = "(908) 555 -1800";
//cout << regex_replace(number, r, fmt) << endl;
//
////ֻ�滻�������е�һ����
//int main()
//{
//	string phone =
//		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
//	regex r(phone);//Ѱ��ģʽ���õ�regex����
//	smatch m;
//	string s;
//	string fmt = "$2.$5.$7";//�������ʽ��Ϊddd.ddd.dddd
//	//�������ļ��ж�ȡÿ����¼
//	while (getline(cin, s))
//		cout << regex_replace(s, r, fmt) << endl;
//	return 0;
//}
//
////��������ƥ��͸�ʽ�ı�־
//using std::regex_constants::format_no_copy;
//
//using namespace std::regex_constants;
//
////ʹ�ø�ʽ��־
////ֻ���ɵ绰���룬ʹ���µĸ�ʽ�ַ���
//string fmt2 = "$2.$5.$7 ";//�����һ���ֺ������ÿո���Ϊ�ָ���
////֪ͨregex_replaceֻ�������滻���ı�
//cout << regex_replace(s, r, fmt2, format_no_copy) << endl;
//
////17.4 �����
////�����Դ
//
////������������������ֲ���
//
////C++����Ӧ��ʹ�ÿ⺯��rand����Ӧ��ʹ��default_random_engine���ǡ���ķֲ������
//
////17.4.1 ���������ͷֲ�
//default_random_engine e;//��������޷�����
//for (size_t i = 0; i < 10; ++i)
//	//e()�����á�������������һ�������
//	cout << e() << endl;
//
////�ֲ����ͺ�����
////����0-9֮�䣨�����������ֲ��������
//uniform_int_distribution<unsigned>u(0, 9);
//default_random_engine e;//��������޷�����
//for (size_t i = 0; i < 10; ++i)
//	//��u��Ϊ�����Դ
//	//ÿ�����÷�����ָ����Χ�ڲ����Ӿ��ȷֲ���ֵ
//	cout << u(e) << " ";
//
////Note:������˵�����������ʱ����ָ�ֲ����������������ϡ�
//
////�Ƚ�����������rand����
//cout << "min: " << e.min() << " max: " << e.max() << endl;
//
////��������һ����ֵ����
////���в���
//
////�����϶��Ƿ����������vector�Ĵ��󷽷�
////ÿ�ε��������������������ͬ��100������
//vector<unsigned>bad_randVec()
//{
//	default_random_engine e;
//	uniform_int_distribution<unsigned>u(0, 9);
//	vector<unsigned>ret;
//	for (size_t i = 0; i < 100; ++i)
//		ret.push_back(u(e));
//	return ret;
//}
//
//vector<unsigned>v1(bad_randVec());
//vector<unsigned>v2(bad_randVec());
////����ӡ"equal"
//cout << ((v1 == v2) ? "equal" : "not equal") << endl;
//
////����һ��vector������100�����ȷֲ��������
//vector<unsigned >good_randVec()
//{
//	//����ϣ������ͷֲ����󱣳�״̬�����Ӧ�ý�����
//	//����Ϊstatic�ģ��Ӷ�ÿ�ε��ö������µ���
//	static default_random_engine e;
//	static uniform_int_distribution<unsigned>u(0, 9);
//	vector<unsigned>ret;
//	for (size_t i = 0; i < 100; ++i)
//		ret.push_back(u(e));
//	return ret;
//}
//
////Warning:һ�������������������һֱ��������ͬ����������С�һ��������������˾ֲ����������������Ӧ�ý��䣨��������ͷֲ����󣩶���Ϊstatic�ġ�����ÿ�ε��ö���������ͬ�����С�
//
////�������������������
////�ڴ����������ʱ�ṩ���ӻ��ߵ��������seed��Ա
//
//default_random_engine e1;//ʹ��Ĭ������
//default_random_engine e2(21234231321);//ʹ�ø���������ֵ
////e3��e4��������ͬ�����У���Ϊ����ʹ������ͬ������
//default_random_engine e3;//ʹ��Ĭ������
//e3.seed(3232);//����seed����һ��������ֵ
//default_random_engine e4(3232);//������ֵ����Ϊ3232
//for (size_t i = 0; i != 100; ++i)
//{
//	if (e1() == e2())
//		cout << "unseeded match at iteration: " << i << endl;
//	if (e3() == e4())
//		cout << "seeded differs at iteration: " << i << endl;
//}
//
//default_random_engine e1(time(0));//��΢���Щ������
////Warning:���������Ϊһ���Զ����̵�һ���ַ������У���time�ķ���ֵ��Ϊ���ӵķ�ʽ����Ч�ˣ������ܶ��ʹ�õĶ�����ͬ�����ӡ�
//
////17.4.2 ����������ֲ�
////�������ʵ��
//
//default_random_engine e;//��������޷�����
////0-1(����)�ľ��ȷֲ�
//uniform_real_distribution<double>u(0, 1);
//for (size_t i = 0; i < 10; ++i)
//	cout << u(e) << " ";
//
////ʹ�÷ֲ���Ĭ�Ͻ������
////�ֲ����Ͷ���ģ�壬���е�һ��ģ�����Ͳ�������ʾ�ֲ����ɵ������������
//
////��<>��ʾϣ��ʹ��Ĭ�Ͻ������
//uniform_real_distribution<>u(0, 1);//Ĭ������doubleֵ
//
////���ɷǾ��ȷֲ��������
//default_random_engine e;
//normal_distribution<>n(4, 1.5);//��ֵ4����׼��1.5
//vector<unsigned>vals(9);//9��Ԫ�ؾ�Ϊ0
//for (size_t i = 0; i != 200; ++i)
//{
//	unsigned v = lround(n(e));//���뵽��ӽ�������
//	if (v < vals.size())//�������ڷ�Χ��
//		++vals[v];//ͳ��ÿ���������˶��ٴ�
//}
//for (size_t j = 0; j != vals.size(); ++j)
//cout << j << ": " << string(vals[j], '*') << endl;
//
////bernoulli_distribution��
//
//string resp;
//default_random_engine e;//eӦ����״̬�����Ա�����ѭ���ⶨ�壡
//bernoulli_distribution b;//Ĭ����50/50�Ļ���
//do
//{
//	bool first = b(e);//���Ϊtrue�����������
//	cout << (first ? "We go first" : "You get to go first") << endl;
//	//����˭���е�ָʾ��������Ϸ
//	cout < ((play(first)) ? "sorry,you lost" : "congrats,you won") << endl;
//	cout << "play again? Enter 'yes' or 'no'  "<< endl;
//} while (cin >> resp && resp[0] == 'y')
//
////Warning:�������淵����ͬ����������У��������Ǳ�����ѭ��������������󡣷���ÿ��ѭ�����ᴴ��һ�������棬�Ӷ�ÿ��ѭ������������ͬ��ֵ�����Ƶģ��ֲ�����ҲҪ����״̬�����ҲӦ����ѭ���ⶨ�塣
//
//bernoulli_distribution b(.55);//���̶�һ��΢С������
//
////17.5 IO����̽
////��ʽ���ơ�δ��ʽ��IO���������
//
////17.5.1 ��ʽ�����������
//
////���ݷ� �޸����ĸ�ʽ״̬
////���ݷ��Ǻ�������󣬻�Ӱ������״̬��������������������������������
//
////�ܶ���ݷ��ı��ʽ״̬
////������������ƣ�������ֵ�������ʽ�����Ʋ��׵�������λ��
//
////Warning:�����ݷ��ı����ĸ�ʽ״̬ʱ��ͨ���ı���״̬�����к���IO����Ч��
//
////���ݷ��Ը�ʽ״̬�ĸı��ǳ־õġ�
//
////���Ʋ���ֵ�ĸ�ʽ
//cout << "default bool value: " << true << " " << false
//<< "\nalpha bool values: " << boolalpha
//<< true << " " << false << endl;
//
//bool bool_val = get_status();
//cout << boolalpha//����cout���ڲ�״̬
//<< bool_val
//<< noboolalpha;//���ڲ�״̬�ָ�ΪĬ�ϸ�ʽ
//
////ָ���������͵Ľ���
//cout << "default: " << 20 << " " << 1024 << endl;
//cout << "octdal:  " << oct << 20 << " " << 1024 << endl;
//cout << "hex: " << hex << 20 << " " << 1024 << endl;
//cout<<"decimal: "<<dec << 20 << " " << 1024 << endl;
//
////Note:���ݷ�hex��oct��decֻӰ������������󣬸���ֵ�ı�ʾ��ʽ����Ӱ�졣
//
////�������ָ������
//cout << showbase;//����ӡ����ֵʱ��ʾ����
//cout << "default: " << 20 << " " << 1024 << endl;
//cout << "in octdal:  " << oct << 20 << " " << 1024 << endl;
//cout << "in hex: " << hex << 20 << " " << 1024 << endl;
//cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
//cout << noshowbase;//�ָ���״̬
//
//cout << uppercase << showbase << hex
//<< "printed in hexadecimal: " << 20 << " " << 1024
//<< nouppercase << noshowbase << dec << endl;
//
////���Ƹ�������ʽ
////�Զ�߾��ȴ�ӡ����ֵ
////��ֵ�Ǵ�ӡʮ�����ơ�����ʮ���ƻ��ǿ�ѧ��������ʽ
////����û��С�����ֵĸ���ֵ�Ƿ��ӡС����
//
////ָ����ӡ����
////Note:���ݷ�setprecision���������ܲ����Ĳ��ݷ���������ͷ�ļ�iomanip�С�
//
////cout.precision���ص�ǰ����ֵ
//cout << "Precision: " << cout.precision()
//<< ",Value: " << sqrt(2.0) << endl;
//
////cout.precision(12)����ӡ��������Ϊ12λ����
//cout.precision(12);
//cout << "Precision: " << cout.precision()
//<< ",Value: " << sqrt(2.0) << endl;
//
////��һ�����þ��ȵķ�����ʹ��setprecision���ݷ�
//cout << setprecision(3);
//cout << "Precision: " << cout.precision()
//<< ",Value: " << sqrt(2.0) << endl;
//
////ָ�����������
////������Ҫ���Ƹ������ı�ʾ��ʽ���磺���д�ӡ���ݻ��ӡ��ʾ����ٷֱȵ����ݣ��������ɱ�׼��ѡ�����������õķ�ʽ��
//
//cout << "default format: " << 100 * sqrt(2.0) << '\n'
//<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
//<< "fixed decimal " << fixed << 100 * sqrt(2.0) << '\n'
//<< "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
//<< "use  defaults" << defaultfloat << 100 * sqrt(2.0) << "\n\n";
//
////��ӡС����
//cout << 10.0 << endl;//��ӡ10
//cout << showpoint << 10.0 //��ӡ10.0000
//<< noshowpoint << endl;//�ָ�С�����Ĭ�ϸ�ʽ
//
////�������
////Note:setw����endl�����ı���������ڲ�״̬����ֻ������һ������Ĵ�С��
//
//int i = -16;
//double d = 3.14159;
////���׵�һ�У�ʹ���������С12��λ��
//cout << "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n';
//
////���׵�һ�У������������
//cout << left
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n'
//<< right;//�ָ���������
//
////���׵�һ�У��Ҷ���������
//cout << right
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n';
//
////���׵�һ�У����������ڲ�
//cout<<internal
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n';
//
////���׵�һ�У���#��Ϊ�����ַ�
//cout << setfill('#')
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n'
//<< setfill(' ');//�ָ������Ĳ����ַ�
//
////���������ʽ
//char ch;
//while (cin >> ch)
//cout << ch;
//
//cin >> noskipws;//����cin��ȡ���ַ�
//while (cin >> ch)
//cout << ch;
//cin >> skipws;//��cin�ָ���Ĭ��״̬���Ӷ������հ׷�
//
////17.5.2 δ��ʽ��������/�������
//
////���ֽڲ���
//char ch;
//while (cin.get(ch))
//cout.put(ch);
//
////���ַ��Ż�������
//
////peek��������������һ���ַ��ĸ����������Ὣ��������ɾ����peek��ֵ��Ȼ�������С�
////unget ʹ������������ƶ����Ӷ�����ȡ��ֵ�ֻص����С���ʹ��֪���������ж�ȡ��ʲôֵ����Ȼ���Ե���unget��
////putback�Ǹ�����汾��unget�����˻ش����ж�ȡ�����һ��ֵ����������һ���������˲�������������ȡ��ֵ��ͬ��
//
////��׼�ⲻ��֤���м䲻���ж�ȡ���������������������putback��unget��
//
////������������ص�intֵ
//int ch;//ʹ��һ��int��������һ��char������get()�ķ���ֵ
////ѭ����ȡ����������е���������
//while ((ch = cin.get()) != EOF)
//cout.put(ch);
//
////���ֽڲ���
////Warning:һ�������Ĵ����Ǳ��������ɾ���ָ�������ȴ��������
//
////ȷ����ȡ�˶��ٸ��ַ�
////����ڵ���gcount֮ǰ������peek��unget��putback����gcount�ķ���ֵΪ0
//
//char ch;//�˴�ʹ��char������������
////��cin.get()���ص�ֵ��ת��Ϊchar��Ȼ����һ��int�Ƚ�
//while ((ch = cin.get()) != EOF)
//cout.put(ch);
//
////17.5.3 ���������
//// seek tell
////Note:���IO��������������ϵͳ�ġ�Ϊ��������ʹ����Щ���ԣ������ѯϵͳ�ĵ���
//
////Warning:����istream��ostream����ͨ����֧��������ʣ����Ա���ʣ������ֻ������fstream��sstream���͡�
//
////seek��tell����
////һ������ͨ�������seek��һ������λ�����ض�λ��
////��һ������tell���Ǳ�ǵĵ�ǰλ��
//
////����g�汾��ʾ��������p�汾��ʾ�����
//
////ֻ��һ�����
////Note:����ֻ�е�һ�ı�ǣ����ֻҪ�����ڶ�д�������л����ͱ������seek�������ض�λ��ǡ�
//
////�ض�λ���
////������ƶ���һ���̶�λ��
//seekg(new_position);//��������ƶ���ָ����pos_type���͵�λ��
//seekp(new_position);//��д����ƶ���ָ����pos_type���͵�λ��
//
////�ƶ���������ʼ��֮ǰ��֮��ָ����ƫ��λ��
//seekg(offset, from);//��������ƶ�����fromƫ����Ϊoffset��λ��
//seekp(offset, from);//��д����ƶ�����fromƫ����Ϊoffset��λ��
//
////off_type����������Ҳ�����Ǹ��ġ�
////�������ļ�����ǰ�ƶ�������ƶ�
//
////���ʱ��
////��ס��ǰдλ��
//ostringstream writesStr;//���stringstream
//ostringstream::pos_type mark = writesStr.tellp();//���浱ǰдλ��
////...
//if(cancelEntry)
//   //�ص��ղż�ס��λ��
//	wirteStr.seekp(mark);
//
////��дͬһ���ļ�
//int main()
//{
//	//�Զ�д�ķ�ʽ���ļ�������λ���ļ�β
//	fstream intOut("copyOut", fstream::ate | fstream::in | fstream::out);
//
//	if (!intOut)
//	{
//		cerr << "Unable to open the file!" << endl;
//		return EXIT_FAILURE;
//	}
//
//	//inOut��ateģʽ�򿪣����һ��ʼ�Ͷ�λ�����ļ�β
//	auto end_mark = inOut.tellg();//��סԭ�ļ�βλ��
//	inOut.seekg(0, fstream::beg);//�ض�λ���ļ���ʼ
//	size_t cnyt = 0;//�ֽ����ۻ���
//	string line;//���������е�ÿ��
//
//	//������ȡ����������δ���������һ��ڶ�ȡԭ����
//	while (inOut && intOut.tellg() != end_mark && getline(inOut, line))//�һ����Ի�ȡһ������
//	{
//		cnt += line.size() + 1;//��1��ʾ���з�
//		auto mark = inOut.tellg();//��ס��ǰ��λ��
//		inOut.seekp(0, fstream::end);//��д����ƶ����ļ�β
//		inOut << cnt;//����ۼƵĳ���
//
//		//����������һ�У���ӡһ���ָ���
//		if (mark != end_mark)inOut << " ";
//		inOut.seek(mark);//�ָ���λ��
//	}
//	inOut.seekp(0, fstream::end);//��λ���ļ�β
//	inOut << "\n";//���ļ�β���һ�����з�
//	return 0;
//}