//#include"12.22.h"
//#include<iostream>
//#include<fstream>
//#include<map>
//#include<set>
//#include<unordered_map>
//using std::shared_ptr;
//
//class QueryResult;
//class TextQuery {
//public:
//	TextQuery(std::ifstream&);
//	QueryResult query(const string&)const;
//private:
//	StrBlob file;
//	std::unordered_map<string, shared_ptr<std::set<StrBlob::size_type>>>result;
//};
//
//class QueryResult {
//public:
//	friend std::ostream& print(std::ostream&, const QueryResult&);
//
//	QueryResult(const string&s,shared_ptr<std::set<StrBlob::size_type>> set,const StrBlob&f):word(s),nos(set),file(f){}
//
//
//private:
//	string word;
//	shared_ptr<std::set<StrBlob::size_type>>nos;
//	StrBlob file;
//};
