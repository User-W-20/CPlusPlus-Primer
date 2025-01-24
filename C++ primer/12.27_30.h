#include<string>
#include<vector>
#include<memory>
#include<iostream>
#include<fstream>
#include<set>
#include<map>

using std::string; using std::vector; using std::shared_ptr;

class QueryResult;
class TextQuery {

public:
	using LineNo = vector<string>::size_type;
	TextQuery(std::ifstream& );
	QueryResult query(const string&)const;

private:
	shared_ptr<vector<string>>input;
	std::map<string, shared_ptr<std::set<LineNo>>>result;
};

class QueryResult {
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);

	QueryResult(const string &s,shared_ptr<std::set<TextQuery::LineNo>>set,shared_ptr<vector<string>>v):word(s),nos(set),input(v){}

private:
	string word;
	shared_ptr<std::set<TextQuery::LineNo>>nos;
	shared_ptr<vector<string>>input;
};