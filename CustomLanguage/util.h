#include <tuple>

#ifdef UTIL_H
#define UTIL_H
template <typename T>
class Obj{
	private:
		std::string key;
		T value;
	public:
		Obj(std::string, T);
		std::tuple<std::string, T> info();
		std::string getKey();
		T getValue();
		Obj() = delete;
		Obj(const Obj&) = delete;
		Obj& operator=(const Obj&) = delete;
};

class Func{
	private:
		std::vector<Obj> arguments;
	public:
		Func(std::ifstream&);
		void operator()(//arbitrary number of arguments based on code);





#endif

