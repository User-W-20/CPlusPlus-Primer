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
////17.1 tuple类型
////类似pair的模板.
////Note:可以将tuple看作一个"快速而随意"的数据结构.
//
////17.1.1 定义和初始化tuple
////需要指出每个成员的类型
//tuple<size_t, size_t, size_t>threeD;//三个成员都设置为0
//tuple<string, vector<double>, int, list<int>>
//someVal("constants", { 3.14,2.718 }, 42, { 0,1,2,3,4,5 });
//
//tuple<size_t, size_t, size_t>threeD = { 1,2,3 };//错误
//tuple<size_t, size_t, size_t>threeD{ 1,2,3 };//正确
//
////表示书店交易记录的tuple,包含:ISBN,数量和每册书的价格
//auto item = make_tuple("0-999-7835-X", 3, 20.00);
//
////访问tuple的成员
//auto book = get<0>(item);//返回item的第一个成员
//auto cnt = get<1>(item);//返回item的第二个成员
//auto price = get<2>(item);//返回item的最后一个成员
//get<2>(item) *= 0.8;//打折20%
//
//typedef decltype(trans);//trans是一个item的类型
////返回trans的类型对象中的成员的数量
//size_t sz = tuple_size<trans>::value;//返回3
////cnt的类型与item中第二个成员相同
//tuple_element<1, trans>::type cnt = get<1>(item);//cnt是一个int
//
////关系和相等运算符
//tuple<string, string>duo("1", "2");
//tuple<size_t, size_t>twoD(1, 2);
//bool b = (duo == twoD);
//tuple<size_t, size_t, size_t >threeD(1, 2, 3);
//b = (twoD < threeD);//错误：成员数量不同
//tuple<size_t, size_t >origin(0, 0);
//b = (origin < twoD);//正确：b为true
//
////Note:由于tuple定义了<和==运算符，我们可以将tuple序列传递给算法，并且可以在无序容器中将tuple作为关键字类型。
//
////17.2.1 使用tuple返回多个值
//class Sales_data{};
////files 中的每个元素保存一家书店的销售记录
//vector<vector<Sales_data>> files;
//
////返回tuple的函数
////matches有三个成员：一家书店的索引和两个指向书店vector中元素的迭代器
//typedef tuple < vector<Sales_data>::size_type, vector <Sales_data>::const_iterator, vector<Sales_data>::const_iterator>matches;
//
////files保存每家书店的销售记录
////findBook返回一个vector，每家销售了给定书籍的书店在其中都有一项
//vector<matches>
//findBook(const vector<vector<Sales_data>>& files, const string& book)
//{
//	vector<matches>ret;//初始化为空vector
//	//对每家书店，查找给定书籍匹配的记录范围（如果存在的话）
//	for (auto it = files.cbegin(); it != files.cend(); ++it)
//	{ 
//		//查找具有相同的isbn的Sales_data范围
//		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
//		if (found.first != found.second)//此书店销售了给定书籍
//			//记住此书店的索引及匹配的范围
//			ret.push_back(make_tuple(it - files.cbegin(), found.first(), found.second()));
//	}
//	return ret;//如果未找到匹配记录的话，ret为空
//}
//
////使用函数返回的tuple
//void reportResult(istream& in, ostream& os, const vector<vector<Sales_data>>& files)
//{
//	string s;//要查找的书
//	while (cin >> s)
//	{
//		auto trans = findBook(files, s);//销售了这本书的书店
//		if (trans.empty())
//		{
//			cout << s << " not found in any stores" << endl;
//			continue;//获得下一本要查找的书
//		}
//		for (const auto& store : trans)//对每家销售了给定书籍的书店
//			//get<n>返回store中tuple的指定的成员
//			os << "store" << get<0>(store) << " sales:"
//			<< accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
//	}
//}
//
////17.2 bitset 类型
////17.2.1 定义和初始化bitset
//bitset<32>bitvec(1U);//32位；低位为1，其他位为0
////从0开始的称为低位，到31结束的称为高位
//
////用unsigned值初始化bitset
////用整型值初始化bitset时，被转换为unsigned long long，并被当作位模式来处理
//
////bitvec1比初始值小；初始值中的高位被丢弃
//bitset<13>bitvec1(0xbeef);//二进制位序列为1111011101111
////bitvec2比初始值大；它的高位被置为0
//bitset<20>bitvec2(0xbeef);//二进制位序列为00001011111011101111
////在64位机器中，long long OULL是64个0比特，因此~0ULL是64个1
//bitset<128>bitvec3(~0ULL);//0~63位为1，63-127位为0
//
////从一个string 初始化bitset
//bitset<32>bitvec4("1100");//2，3两位为1 ，剩余两位为0
////Note:string的下标编号习惯与bitset恰好相反；string中的下标最大的字符（最右字符）用来初始化bitset中的低位（下标为0的二进制位）。当用一个string初始化一个bitset时，要记住这个差别。
//
//string str("111111100000001101101");
//bitset<32>bitvec5(str, 5, 4);//从str[5]开始的四个二进制位，1100
//bitset<32>bitvec6(str, str.size() - 4);//使用最后四个字符
//
////17.2.2 bitset操作
//bitset<32>bitvec(1U);//32位；低位为1，剩余位为0
//bool is_set = bitvec.any();//true,因为有1位置位
//bool is_not_set = bitvec.none();//false,因为有1位置位了
//bool all_set = bitvec.all();//false,因为只有1位置位
//size_t onBits = bitvec.count();//返回1
//size_t sz = bitvec.size();//返回32
//bitvec.flip();//翻转bitvec中的所有位
//bitvec.reset();//将所有位复位
//bitvec.set();//将所有位置位
//
//bitvec.flip(0);//翻转第一位
//bitvec.set(bitvec.size() - 1);//置位最后一位
//bitvec.set(0, 0);//复位第一位
//bitvec.reset(i);//复位第i位
//bitvec.test(0);//返回false，因为第一位是复位的
//
//bitvec[0] = 0;//将第一位复位
//bitvec[31] = bitvec[0];//将最后一位设置为与第一位一样
//bitvec[0].flip();//翻转第一位
//~bitvec[0];//等价操作
//bool b = bitvec[0];//将bitvec[0]的值转换为bool类型
//
////提取bitset的值
//unsigned long ulong = bitvec3.to_ulong();
//cout << "ulong = " << ulong << endl;
//
////Note:如果bitset中的值不能放入给定类型中，则这两个操作会抛出一个overflow_erroe异常
//
////bitset的IO运算符
//bitset<16>bits;
//cin >> bits;//从cin读取最多16个0或1
//cout << "bits :" << bits << endl;//打印刚刚读取的内容
//
////使用bitset
//bool status;
////使用位运算符的版本
//unsigned long quizA = 0;//此值被当作位集合使用
//quizA |= 1UL << 27;//指出第27个学生通过了测验
//status = quizA & (1UL << 27);//检查第27个学生是否通过了测验
//quizA &= ~(1UL << 27);//第27个学生未通过测验
////使用标准库bitset完成等价的工作
//bitset<30> quizB;//每个学生分配一位，所有位都被初始化为0
//quizB.set(27);//指出第27个学生通过了测验
//status = quizB[27];//检查第27个学生是否通过了测验
//quizB.reset[27];//第27个学生未通过测验
//
////17.3 正则表达式
////17.3.1 使用正则表达式库
////查找不在字符c之后的字符串ei
//string pattern("[^c]ei");
////需要包含pattern的整个单词
//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//regex r(pattern);//构造一个用于查找模式的regex
//smatch results;//定义一个对象保存搜索结果
////定义一个string保存与模式匹配和不匹配的文本
//string test_str = "receipt freind theif receive";
////用r在test_str中查找与pattern匹配的子串
//if (regex_search(test_str, results, r))//如果有匹配子串
//cout << results.str() << endl;//打印匹配的单词
//
////指定regex对象的选项
////一个或多个字母或数字字符后接一个'.'再接"cpp"或"cxx"或"cc"
//regex r(R"([[:alnum:]]+\.(cpp|cxx|cc)$)", regex::icase);
//smatch results;
//string filename;
//while (cin >> filename)
//if (regex_search(filename, results, r))
//cout << results.str() << endl;//打印匹配结果
//
////指定或使用正则表达式时的错误
////Note:需要意识到的非常重要的一点是，一个正则表达式的语法是否正确是在运行时解析的。
//
//try
//{
//	//错误:alnum漏掉了右括号，构造函数会抛出异常
//	regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
//}
//catch (regex_error e)
//{
//	cout << e.what() << "\ncode: " << e.code() << endl;
//}
//
////正则表达式类和输入序列类型
//regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
//smatch results;//将匹配string输入序列，而不是char*
//if (regex_search("myfile.cc", results, r))//错误：输入为char*
//cout << results.str() << endl;
//
//cmatch results;//将匹配字符数组输入序列
//if(regex_search("mifile.cc",results,r))
//cout << results.str() << endl;//打印当前匹配
//
////17.3.2 匹配与Regex迭代器类型
//
////使用sregex_iterator
//
////查找前一个字符不是c的字符串ei
//string pattern("[^c]ei");
////我们想要包含的pattern的单词的全部内容
//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//regex r(pattern, regex::icase);//在进行匹配的时候将忽略大小写
////它将反复调用regex_search来寻找文件中的所有匹配
//for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
//cout << it->str() << endl;//匹配的单词
//
////使用匹配数据
////循环头与之前一样
//for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
//{
//	auto pos = it->prefis().length();//前缀的大小
//	pos = pos > 40 ? pos - 40 : 0;//想要最多40个字符
//	cout << it->prefix().str().substr(pos)//前缀的最后一部分
//		<< "\n\t\t" << it->str() << "<<<\n"//匹配的单词
//		<< it->suffix().str().substr(0, 40)//后缀的第一部分
//		<< endl;
//}
//
////17.3.3 使用子表达式
////r有俩个子表达式，第一个是点之前表示文件名的部分，第二个表示文件的扩展名
//regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
//
//if (regex_search(filename, results, r))
//cout << results.str(1) << endl;//打印第一个子表达式
//
////子表达式用于数据验证
////常用用途：验证必须匹配特定格式的数据。
//
////整个正则表达式包含七个子表达式：(ddd)分隔符ddd分隔符dddd
////子表达式1、3、4和6是可选的，2、5、和7保存号码
//"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
//
//string phone= "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
//regex r(phone);//regex对象，用于查找模式
//smatch m;
//string s;
////从输入文件中读取每条记录
//while (getline(cin, s))
//{
////对每个匹配的电话号码
//for (sregex_iterator it(s.begin(), s.end(), r), end_it;
//	it != end_it; ++it)
//	//检查号码的格式是否合法
//	if (valid(*it))
//		cout << "valid:" << it->str() << endl;
//	else
//		cout << " not valid: " << it->str() << endl;
//}
//
////使用子匹配操作
//bool valid(const smatch & m)
//{
//	//如果区号前有一个左括号
//	if (m[1].matched)
//		//则区号后必须有一个右括号，之后紧跟剩余号码或一个空格
//		return m[3].matched
//		&& (m[4].mathced == 0 || m[4].str() == " ");
//	else
//		//否则，区号后不能有右括号
//		//另两个组成部分的分隔符必须匹配
//		return !m[3].matched
//		&& m[4].str() == m[6].str();
//}
//
////17.3.4 使用regex_replace
//string fmt = "$2.$5.$7";//将号码格式改为ddd.ddd.dddd
//regex r(phone);//用来寻找模式的regex对象
//string number = "(908) 555 -1800";
//cout << regex_replace(number, r, fmt) << endl;
//
////只替换输入序列的一部分
//int main()
//{
//	string phone =
//		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
//	regex r(phone);//寻找模式所用的regex对象
//	smatch m;
//	string s;
//	string fmt = "$2.$5.$7";//将号码格式改为ddd.ddd.dddd
//	//从输入文件中读取每条记录
//	while (getline(cin, s))
//		cout << regex_replace(s, r, fmt) << endl;
//	return 0;
//}
//
////用来控制匹配和格式的标志
//using std::regex_constants::format_no_copy;
//
//using namespace std::regex_constants;
//
////使用格式标志
////只生成电话号码，使用新的格式字符串
//string fmt2 = "$2.$5.$7 ";//在最后一部分号码后放置空格作为分隔符
////通知regex_replace只拷贝它替换的文本
//cout << regex_replace(s, r, fmt2, format_no_copy) << endl;
//
////17.4 随机数
////随机数源
//
////随机数引擎类和随机数分布类
//
////C++程序不应该使用库函数rand，而应该使用default_random_engine类和恰当的分布类对象。
//
////17.4.1 随机数引擎和分布
//default_random_engine e;//生成随机无符号数
//for (size_t i = 0; i < 10; ++i)
//	//e()“调用”对象来生成下一个随机数
//	cout << e() << endl;
//
////分布类型和引擎
////生成0-9之间（包含）均布分布的随机数
//uniform_int_distribution<unsigned>u(0, 9);
//default_random_engine e;//生成随机无符号数
//for (size_t i = 0; i < 10; ++i)
//	//将u作为随机数源
//	//每个调用返回在指定范围内并服从均匀分布的值
//	cout << u(e) << " ";
//
////Note:当我们说随机数发生器时，是指分布对象和引擎对象的组合。
//
////比较随机数引擎和rand函数
//cout << "min: " << e.min() << " max: " << e.max() << endl;
//
////引擎生成一个数值序列
////序列不变
//
////几乎肯定是发生随机整数vector的错误方法
////每次调用这个函数都会生成相同的100个数！
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
////将打印"equal"
//cout << ((v1 == v2) ? "equal" : "not equal") << endl;
//
////返回一个vector，包含100个均匀分布的随机数
//vector<unsigned >good_randVec()
//{
//	//由于希望引擎和分布对象保持状态，因此应该将它们
//	//定义为static的，从而每次调用都生成新的数
//	static default_random_engine e;
//	static uniform_int_distribution<unsigned>u(0, 9);
//	vector<unsigned>ret;
//	for (size_t i = 0; i < 100; ++i)
//		ret.push_back(u(e));
//	return ret;
//}
//
////Warning:一个给定的随机数发生器一直会生成相同的随机数序列。一个函数如果定义了局部的随机数发生器，应该将其（包括引擎和分布对象）定义为static的。否则，每次调用都会生成相同的序列。
//
////设置随机数发生器种子
////在创建引擎对象时提供种子或者调用引擎的seed成员
//
//default_random_engine e1;//使用默认种子
//default_random_engine e2(21234231321);//使用给定的种子值
////e3和e4将生成相同的序列，因为它们使用了相同的种子
//default_random_engine e3;//使用默认种子
//e3.seed(3232);//调用seed设置一个新种子值
//default_random_engine e4(3232);//将种子值设置为3232
//for (size_t i = 0; i != 100; ++i)
//{
//	if (e1() == e2())
//		cout << "unseeded match at iteration: " << i << endl;
//	if (e3() == e4())
//		cout << "seeded differs at iteration: " << i << endl;
//}
//
//default_random_engine e1(time(0));//稍微随机些的种子
////Warning:如果程序作为一个自动过程的一部分反复运行，将time的返回值作为种子的方式就无效了；它可能多次使用的都是相同的种子。
//
////17.4.2 其他随机数分布
////生成随机实数
//
//default_random_engine e;//生成随机无符号数
////0-1(包含)的均匀分布
//uniform_real_distribution<double>u(0, 1);
//for (size_t i = 0; i < 10; ++i)
//	cout << u(e) << " ";
//
////使用分布的默认结果类型
////分布类型都是模板，具有单一的模板类型参数，表示分布生成的随机数的类型
//
////空<>表示希望使用默认结果类型
//uniform_real_distribution<>u(0, 1);//默认生成double值
//
////生成非均匀分布的随机数
//default_random_engine e;
//normal_distribution<>n(4, 1.5);//均值4，标准差1.5
//vector<unsigned>vals(9);//9个元素均为0
//for (size_t i = 0; i != 200; ++i)
//{
//	unsigned v = lround(n(e));//舍入到最接近的整数
//	if (v < vals.size())//如果结果在范围内
//		++vals[v];//统计每个数出现了多少次
//}
//for (size_t j = 0; j != vals.size(); ++j)
//cout << j << ": " << string(vals[j], '*') << endl;
//
////bernoulli_distribution类
//
//string resp;
//default_random_engine e;//e应保持状态，所以必须在循环外定义！
//bernoulli_distribution b;//默认是50/50的机会
//do
//{
//	bool first = b(e);//如果为true，则程序先行
//	cout << (first ? "We go first" : "You get to go first") << endl;
//	//传递谁先行的指示，进行游戏
//	cout < ((play(first)) ? "sorry,you lost" : "congrats,you won") << endl;
//	cout << "play again? Enter 'yes' or 'no'  "<< endl;
//} while (cin >> resp && resp[0] == 'y')
//
////Warning:由于引擎返回相同的随机数序列，所以我们必须在循环外声明引擎对象。否则，每步循环都会创建一个新引擎，从而每步循环都会生成相同的值。类似的，分布对象也要保持状态，因此也应该在循环外定义。
//
//bernoulli_distribution b(.55);//给程度一个微小的优势
//
////17.5 IO库再探
////格式控制、未格式化IO、随机访问
//
////17.5.1 格式化输入与输出
//
////操纵符 修改流的格式状态
////操纵符是函数或对象，会影响流的状态，并能用作输入或输出运算符的运算对象。
//
////很多操纵符改变格式状态
////两大类输出控制：控制数值的输出形式、控制补白的数量和位置
//
////Warning:当操纵符改变流的格式状态时，通常改变后的状态对所有后续IO都生效。
//
////操纵符对格式状态的改变是持久的。
//
////控制布尔值的格式
//cout << "default bool value: " << true << " " << false
//<< "\nalpha bool values: " << boolalpha
//<< true << " " << false << endl;
//
//bool bool_val = get_status();
//cout << boolalpha//设置cout的内部状态
//<< bool_val
//<< noboolalpha;//将内部状态恢复为默认格式
//
////指定整型类型的进制
//cout << "default: " << 20 << " " << 1024 << endl;
//cout << "octdal:  " << oct << 20 << " " << 1024 << endl;
//cout << "hex: " << hex << 20 << " " << 1024 << endl;
//cout<<"decimal: "<<dec << 20 << " " << 1024 << endl;
//
////Note:操纵符hex、oct和dec只影响整型运算对象，浮点值的表示形式不会影响。
//
////在输出中指出进制
//cout << showbase;//当打印整型值时显示进制
//cout << "default: " << 20 << " " << 1024 << endl;
//cout << "in octdal:  " << oct << 20 << " " << 1024 << endl;
//cout << "in hex: " << hex << 20 << " " << 1024 << endl;
//cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
//cout << noshowbase;//恢复流状态
//
//cout << uppercase << showbase << hex
//<< "printed in hexadecimal: " << 20 << " " << 1024
//<< nouppercase << noshowbase << dec << endl;
//
////控制浮点数格式
////以多高精度打印浮点值
////数值是打印十六进制、定点十进制还是科学计数法形式
////对于没有小数部分的浮点值是否打印小数点
//
////指定打印精度
////Note:操纵符setprecision和其他接受参数的操纵符都定义在头文件iomanip中。
//
////cout.precision返回当前精度值
//cout << "Precision: " << cout.precision()
//<< ",Value: " << sqrt(2.0) << endl;
//
////cout.precision(12)将打印精度设置为12位数字
//cout.precision(12);
//cout << "Precision: " << cout.precision()
//<< ",Value: " << sqrt(2.0) << endl;
//
////另一种设置精度的方法是使用setprecision操纵符
//cout << setprecision(3);
//cout << "Precision: " << cout.precision()
//<< ",Value: " << sqrt(2.0) << endl;
//
////指定浮点记数法
////除非需要控制浮点数的表示形式（如：按列打印数据或打印表示金额或百分比的数据），否则由标准库选择记数法是最好的方式。
//
//cout << "default format: " << 100 * sqrt(2.0) << '\n'
//<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
//<< "fixed decimal " << fixed << 100 * sqrt(2.0) << '\n'
//<< "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
//<< "use  defaults" << defaultfloat << 100 * sqrt(2.0) << "\n\n";
//
////打印小数点
//cout << 10.0 << endl;//打印10
//cout << showpoint << 10.0 //打印10.0000
//<< noshowpoint << endl;//恢复小数点的默认格式
//
////输出补白
////Note:setw类型endl，不改变输出流的内部状态。它只决定下一个输出的大小。
//
//int i = -16;
//double d = 3.14159;
////补白第一列，使用输出中最小12个位置
//cout << "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n';
//
////补白第一列，左对齐所有类
//cout << left
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n'
//<< right;//恢复正常对齐
//
////补白第一列，右对齐所有类
//cout << right
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n';
//
////补白第一列，但补在域内部
//cout<<internal
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n';
//
////补白第一列，用#作为补白字符
//cout << setfill('#')
//<< "i: " << setw(12) << i << "next col" << '\n'
//<< "d:" << setw(12) << d << "next col" << '\n'
//<< setfill(' ');//恢复正常的补白字符
//
////控制输入格式
//char ch;
//while (cin >> ch)
//cout << ch;
//
//cin >> noskipws;//设置cin读取空字符
//while (cin >> ch)
//cout << ch;
//cin >> skipws;//将cin恢复到默认状态，从而丢弃空白符
//
////17.5.2 未格式化的输入/输出操作
//
////单字节操作
//char ch;
//while (cin.get(ch))
//cout.put(ch);
//
////将字符放回输入流
//
////peek返回输入流中下一个字符的副本，但不会将它从流中删除，peek的值仍然留在流中。
////unget 使得输入流向后移动，从而最后读取的值又回到流中。即使不知道最后从流中读取到什么值，仍然可以调用unget。
////putback是更特殊版本的unget，它退回从流中读取的最后一个值，但它接受一个参数，此参数必须与最后读取的值相同。
//
////标准库不保证在中间不进行读取操作的情况下能连续调用putback和unget。
//
////从输入操作返回的int值
//int ch;//使用一个int，而不是一个char来保存get()的返回值
////循环读取并输出输入中的所有数据
//while ((ch = cin.get()) != EOF)
//cout.put(ch);
//
////多字节操作
////Warning:一个常见的错误是本想从流中删除分隔符，但却忘了做。
//
////确定读取了多少个字符
////如果在调用gcount之前调用了peek、unget或putback，则gcount的返回值为0
//
//char ch;//此处使用char就是引入灾难
////从cin.get()返回的值被转换为char，然后与一个int比较
//while ((ch = cin.get()) != EOF)
//cout.put(ch);
//
////17.5.3 流随机访问
//// seek tell
////Note:随机IO本质上是依赖于系统的。为了理解如何使用这些特性，必须查询系统文档。
//
////Warning:由于istream和ostream类型通常不支持随机访问，所以本节剩余内容只适用于fstream和sstream类型。
//
////seek和tell函数
////一个函数通过将标记seek到一个给定位置来重定位它
////另一个函数tell我们标记的当前位置
//
////区别：g版本表示输入流，p版本表示输出流
//
////只有一个标记
////Note:由于只有单一的标记，因此只要我们在读写操作间切换，就必须进行seek操作来重定位标记。
//
////重定位标记
////将标记移动到一个固定位置
//seekg(new_position);//将读标记移动到指定的pos_type类型的位置
//seekp(new_position);//将写标记移动到指定的pos_type类型的位置
//
////移动到给定起始点之前或之后指定的偏移位置
//seekg(offset, from);//将读标记移动到距from偏移量为offset的位置
//seekp(offset, from);//将写标记移动到距from偏移量为offset的位置
//
////off_type可以是正的也可以是负的。
////可以在文件中向前移动或向后移动
//
////访问标记
////记住当前写位置
//ostringstream writesStr;//输出stringstream
//ostringstream::pos_type mark = writesStr.tellp();//保存当前写位置
////...
//if(cancelEntry)
//   //回到刚才记住的位置
//	wirteStr.seekp(mark);
//
////读写同一个文件
//int main()
//{
//	//以读写的方式打开文件，并定位到文件尾
//	fstream intOut("copyOut", fstream::ate | fstream::in | fstream::out);
//
//	if (!intOut)
//	{
//		cerr << "Unable to open the file!" << endl;
//		return EXIT_FAILURE;
//	}
//
//	//inOut以ate模式打开，因此一开始就定位到其文件尾
//	auto end_mark = inOut.tellg();//记住原文件尾位置
//	inOut.seekg(0, fstream::beg);//重定位到文件开始
//	size_t cnyt = 0;//字节数累积器
//	string line;//保存输入中的每行
//
//	//继续读取的条件：还未遇到错误且还在读取原数据
//	while (inOut && intOut.tellg() != end_mark && getline(inOut, line))//且还可以获取一行输入
//	{
//		cnt += line.size() + 1;//加1表示换行符
//		auto mark = inOut.tellg();//记住当前读位置
//		inOut.seekp(0, fstream::end);//将写标记移动到文件尾
//		inOut << cnt;//输出累计的长度
//
//		//如果不是最后一行，打印一个分隔符
//		if (mark != end_mark)inOut << " ";
//		inOut.seek(mark);//恢复读位置
//	}
//	inOut.seekp(0, fstream::end);//定位到文件尾
//	inOut << "\n";//在文件尾输出一个换行符
//	return 0;
//}