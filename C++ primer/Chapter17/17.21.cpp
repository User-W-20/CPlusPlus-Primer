//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <regex>
//
//using std::cerr;
//using std::cout;
//using std::cin;
//using std::endl;
//using std::istream;
//using std::ostream;
//using std::ifstream;
//using std::ofstream;
//using std::istringstream;
//using std::ostringstream;
//using std::string;
//using std::vector;
//using std::regex;
//using std::sregex_iterator;
//using std::smatch;
//
//struct PersonInfo
//{
//	string name;
//	vector<string>phones;
//}; 
//
//bool valid(const smatch& m);
//bool read_record(istream& is, vector<PersonInfo>& people);
//void format_record(ostream& os, const vector<PersonInfo>& people);
//
//string format(const string& num) { return num; }
//
//int main() {
//	vector<PersonInfo>people;
//
//	string filename;
//	cout << "Please input a record file name: ";
//	cin >> filename;
//	cout << endl;
//
//	ifstream fin(filename);
//	if (read_record(fin, people)) {
//		ofstream fout("result.txt", ofstream::trunc);
//		format_record(fout, people);
//	}
//	else {
//		cout << "Fail to open file " << filename << endl;
//	}
//	return 0;
//}
//
//bool valid(const smatch& m)
//{
//	if (m[1].matched)
//		return m[3].matched && (m[4].str().empty() || m[4].str() == " ");
//	else
//		return !m[3].matched && m[4].str() == m[6].str();
//
//}
//
//bool read_record(istream& is, vector<PersonInfo>& people)
//{
//	if (is) {
//		string line, word;
//		while (std::getline(is, line)) {
//			PersonInfo info;
//			istringstream record(line);
//			record >> info.name;
//			while (record >> word)
//				info.phones.push_back(word);
//			people.push_back(info);
//		}
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//void format_record(ostream& os, const vector<PersonInfo>& people)
//{
//	try {
//		string phone = R"((\()?(\d{3})(\))?([-. ])?(\d{3})([-. ]?)(\d{4}))";
//		regex r(phone);
//		smatch m;
//
//		for (const auto& entry : people) {
//			ostringstream formatted, badnums;
//			for (const auto& nums : entry.phones) {
//				for (sregex_iterator it(nums.begin(), nums.end(), r), end_it; it != end_it; ++it) {
//					if (!valid(*it))
//						badnums << " " << nums;
//					else
//						formatted << " " << format(nums);
//				}
//			}
//			if (badnums.str().empty())
//				os << entry.name << " "
//				<< formatted.str() << endl;
//			else
//				cerr << "input error: " << entry.name
//				<< " invalid number(s) " << badnums.str() << endl;
//		}
//	}
//	catch(const std::regex_error& e){
//		cerr << "regex exception: " << e.what() << endl;
//	}
//
//	
//}