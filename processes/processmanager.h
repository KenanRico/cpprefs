#include "process.h"

#include <vector>


#ifndef PROCESS_MANAGER_H
#define PROCESS_MANAGER_H

class ProcessManager{
	private:
		std::vector<Process*> processes;
	public:
		ProcessManager();
		~ProcessManager();
	private:
		ProcessManager(const ProcessManager&) = delete;
		ProcessManager& operator=(const ProcessManager&) = delete;
	public:
		void printAllProcessInfo() const;
};

#endif
