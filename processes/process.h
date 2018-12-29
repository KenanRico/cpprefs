
#include <string>


#ifndef PROCESS_H
#define PROCESS_H

class Process{
	private:
		int process_ID;
		std::string process_name;
		float memory_usage;
	public:
		Process();
		~Process();
	private:
		Process(const Process&) = delete;
		Process& operator=(const Process&) = delete;
	public:
		void printProcessInfo() const;

};

#endif
