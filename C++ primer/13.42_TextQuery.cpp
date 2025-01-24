#include"13.42_TextQuery.h"
#include<sstream>
#include<algorithm>

using std::string;

TextQuery::TextQuery(std::ifstream& ifs) :input(new StrVec)
{
	size_t lineNo = 0;
	for (string line; std::getline(ifs, line); ++lineNo) {
		input->push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()) {
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);

			auto& nos = result[word];
			if (!nos)nos.reset(new std::set<size_t>);
			nos->insert(lineNo);
		}
	}
}


QueryResult TextQuery::query(const string& str)const
{
	static std::shared_ptr<std::set<size_t>>nodata(new std::set<size_t>);
	auto found = result.find(str);
	if (found == result.end())return QueryResult(str, nodata, input);
	else return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream& out, const QueryResult& qr)
{
	out << qr.word << "occurs" << qr.nos->size() << (qr.nos->size() > 1 ? "times" : "time") << std::endl;
	for (auto i : *qr.nos)
		out << "\t(line" << i + 1 << ")" << qr.input->at(i) << std::endl;
	return out;
}