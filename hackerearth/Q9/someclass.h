


#ifndef SOMECLASS_H
#define SOMECLASS_H
class Someclass{
	private:
		bool* arr;
		unsigned int size;
	public:
		Someclass() = delete;
		Someclass(const Someclass&);
		Someclass& operator=(const Someclass&);
		~Someclass();
		Someclass(int);
		int count();
		void print();
	private:
		void parse();
		void changeBit();	

};
#endif




