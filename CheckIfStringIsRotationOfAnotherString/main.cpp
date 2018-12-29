
bool checkForRotation(const std::string&, const std::string&);

int main(){
	std::string aString = "";
	std::string aNewString = "";
	if(checkForRotation(aString, aNewString)){
		std::cout<<"Yes"<<std::endl;
	}else{
		std::cout<<"No"<<std::endl;
	}
	return 0;
}

bool checkForRotation(const std::string& s1, const std::string& s2){
	std::string* table1[256];
	constructTable(table1,256,s1);
	std::string* table2[256];
	constructTable(table2,256,s2);
	return compareTables(table1,table2);
	
}

void constructTable(std::string** t, int size, const std::string& s){
	for(std::string::const_iterator iter=s.begin(); iter<s.end(); ++iter){
		std::string* current = t[hash(*iter)];
		if(*current==(std::string*)0){
			current = new std::string();
		}else{
			if(iter+1!=s.end()){
				*current.push_back(*(iter+1));
			}else{
				*current.push_back(*(s.begin()));
			}
		}
	}



}
