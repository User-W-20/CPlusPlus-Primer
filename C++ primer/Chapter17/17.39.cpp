//#include<iostream>
//#include<string>
//#include<fstream>
//#include<iomanip>
//using namespace std;
//
//int main() {
//	fstream inOut("test.txt", fstream::ate | fstream::in | fstream::out);
//
//	if (!inOut) {
//		cerr << "Unable to open file!" << endl;
//		return EXIT_FAILURE;
//	}
//	//以ate模式打开，一开始就定义到尾部
//	auto end_mark = inOut.tellg();//记住源文件尾位置
//	inOut.seekg(0, fstream::beg);//重定位到文件开始
//
//	size_t cnt = 0;
//	string line;
//
//	while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
//		cnt += line.size() + 1;
//		auto mark = inOut.tellg();//记住读取位置
//		inOut.seekp(0, fstream::end);//将写标记移动到文件尾
//		inOut << cnt;
//
//		if (mark != end_mark) inOut << " ";
//		inOut.seekg(mark);//恢复读位置
//	}
//	inOut.seekp(0, fstream::end);
//	inOut << "\n";
//	
//	return 0;
//}