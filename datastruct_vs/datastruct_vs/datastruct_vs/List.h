#pragma once
template<class> class List{
public:
	List();
	~List();
	void clear();
	bool is_empty();
	bool append(const T value);
	bool insert(const int p, const T value);
	bool delete(const int p);
	bool get_post(int & p, T & value);
	bool get_value(const int p, T & value);
	bool set_value(const int p, const T value);
};

