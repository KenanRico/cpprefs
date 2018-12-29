#include "processmanager.h"
#include "process.h"

#include <vector>
#include <iostream>
#include <string>

#include <dirent.h>

bool isNum(std::string);

bool isNum(std::string file_name){
	bool result = true;
	for(std::string::iterator iter=file_name.begin(); iter!=file_name.end(); ++iter){
		if((int)'0'<=*iter && *iter<=(int)'9'){
			//keep goin
		}else{
			result = false;
			break;
		}
	}
	return result;
}


ProcessManager::ProcessManager(){
	//insert all currently running processes
	DIR* proc_dir_stream = opendir("/proc");
	dirent* proc_file = nullptr;
	while((proc_file=readdir(proc_dir_stream))!=nullptr){
		if(isNum(std::string(proc_file->d_name))){
			//explore this file and use appropriate content in it to create "Process" object and insert to "processes"
		}else{
			//do nothing if current dir does not represent a process
		}
	}
	closedir(proc_dir_stream);
}


ProcessManager::~ProcessManager(){
	for(std::vector<Process*>::iterator iter=processes.begin(); iter!=processes.end(); ++iter){
		delete *iter;
	}
}

void ProcessManager::printAllProcessInfo() const{
	for(std::vector<Process*>::const_iterator iter=processes.begin(); iter!=processes.end(); ++iter){
		(*iter)->printProcessInfo();
	}
}
