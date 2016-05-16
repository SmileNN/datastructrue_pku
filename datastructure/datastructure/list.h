template<class T>
class list{
public:
	list();
	~list();
	void clear();
	bool is_empty();
	bool append(const T val);
	bool insert(const int p, const T val);
	bool delete(const int p);
	bool get_val(const int p, T& val);
	bool set_val(const int p, const T val);
	bool get_pos(int & p, const T val);
private:

};
