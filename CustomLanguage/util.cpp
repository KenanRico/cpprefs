#include "util.h"

template <typename T>
Obj::Obj(std::string key, T value)
:Key(key),Value(value){;}

template <typename T>
std::tuple<std::string,T> Obj::info(){
	return std::make_tuple<this->Key,this->Value>;
}

std::string Obj::getKey(){
	return this->Key;
}

template <typename T>
T Obj::getValue(){
	return this->Value;
}

Func::Func(ifstream& ifstrm){
	std::string line("");
	while(ifstrm>>line){
		if(line=="}"){
			break;
		}else{
			
		}
	}

}
