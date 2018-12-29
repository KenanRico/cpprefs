

int main(){
	Queue MyQ;
	while(true){
		std::string line{""};
		std::cout<<"Do: ";
		getline(cin,line);
		std::stringstream ss(line);
		std::string token{""};
		ss>>token;
		if(token=="push"){
			int key = 0;
			if(ss>>key){
				MyQ.push(key);
				std::cout<<"Pushed new key to queue"<<std::endl;
			}else{
				std::cerr<<"Invalid key type"<<std::endl;
			}
		}
		}else if(token=="pop"){
			std::cout<<"Popped "<<MyQ.pop()<<std::endl;
		}else if(token=="print"){
			MyQ.print();
		}else if(token=="quit"){
			break;
		}
	}
	return 0;

