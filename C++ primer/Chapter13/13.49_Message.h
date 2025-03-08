//#include<string>
//#include<set>
//
//#ifndef _MSC_VER
//#define NOEXCEPT	noexcept
//#else
//#define NOEXCEPT
//
//#endif // !_MSC_VER
//
//
//class Folder;
//
//class Message {
//	friend void swap(Message&, Message&);
//	friend void swap(Folder&, Folder&);
//	friend class Folder;
//public:
//	explicit Message(const std::string &str=" "):contents(str){}
//
//	Message(const Message&);
//	Message& operator=(const Message&);
//
//	Message(Message&& m);
//	Message& operator=( Message&&);
//	~Message();
//
//	void save(Folder&);
//	void remove(Folder&);
//
//	const std::string& msg()const { return contents; }
//	void print_debug();
//private:
//	std::string contents;
//	std::set<Folder*>folders;
//
//	void add_to_Folders(const Message&);
//	void remove_from_Folders();
//
//	void addFldr(Folder* f) { folders.insert(f); }
//	void remFldr(Folder* f) { folders.erase(f); }
//
//	void move_Folders(Message*);
//};
//
//void swap(Message&, Message&);
//
//class Folder {
//	friend void swap(Message&, Message&);
//	friend void swap(Folder&, Folder&);
//	friend class Message;
//public:
//	explicit Folder(const std::string &str=" "):name(str){}
//
//	Folder(const Folder&);
//	Folder& operator=(const Folder&);
//
//	Folder(Folder&& f);
//	Folder& operator=( Folder&&);
//	~Folder();
//
//	const std::string& fldr()const { return name; }
//	void print_debug();
//private:
//	std::string name;
//	std::set<Message*>msgs;
//
//	void add_to_Message(const Folder&);
//	void remove_from_Message();
//
//	void addMsg(Message* m) { msgs.insert(m); }
//	void remMsg(Message* m) { msgs.erase(m); }
//
//	void move_Message(Folder*);
//
//
//};
//
//void swap(Folder&, Folder&);