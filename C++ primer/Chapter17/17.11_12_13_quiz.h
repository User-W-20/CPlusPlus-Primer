//#pragma once
//#include<iostream>
//#include<bitset>
//#include<utility>
//#include<string>
//
//template<std::size_t M>
//class Quiz;
//
//template<std::size_t M>
//std::size_t grade(Quiz<M> const&, Quiz<M> const&);
//
//template<std::size_t M>
//std::ostream& operator<<(std::ostream&, Quiz<M> const&);
//
//template<std::size_t N>
//class Quiz
//{
//public:
//	Quiz() = default;
//	Quiz(std::string& s) :bitquiz(s) {}
//
//
//	friend  std::size_t grade<N>(Quiz<N>const&, Quiz<N>const&);
//
//	friend std::ostream& operator<< <N> (std::ostream&, Quiz<N>const&);
//
//	void update(std::pair<std::size_t, bool>);
//
//private:
//	std::bitset<N>bitquiz;
//};
//
//template<std::size_t N>
//void Quiz<N>::update(std::pair<std::size_t, bool>pair)
//{
//	bitquiz.set(pair.first, pair.second);
//}
//
//template<std::size_t M>
//std::ostream& operator<<(std::ostream& os, Quiz<M> const& quiz)
//{
//	os << quiz.bitquiz;
//	return os;
//}
//
//template<std::size_t M>
//std::size_t grade(Quiz<M>const& corAns, Quiz<M>const& stuAns)
//{
//	auto result = stuAns.bitquiz ^ corAns.bitquiz;
//	result.flip();
//	return result.count();
//}