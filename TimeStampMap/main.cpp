
class TVP;
class TimeMap;

int main(){
	TimeMap map;

	map.set("key1", "val1", 0);
	map.set("key1", "val2", 4);
	map.set("key1", "val3", 8);
	map.set("key2", "val11", 9);
	map.set("key2", "val18", 47);
	map.set("key3", "val21", 11);
	map.set("key4", "val31", 19);
	map.set("key4", "val39", 28);

	std::cout<<map.get("key1", 6)<<" "<<map.get("key4", 29)<<"\n"; //should print "val2 val39"

	return 0;
}


class TVP{
	
}

class TimeMap{
	private:
		std::map<std::string, std::priority_queue<TVP>> map;
	public:
		TimeMap();
		~TimeMap();
	private:
		TimeMap(const TimeMap&) = delete;
		TimeMap& operator=(const TimeMap&) = delete;
	public:
		void set(const std::string&, const std::string&, int);
		std::string get(const std::string&, int) const;
};

void TimeMap::set(const std::string& key, const std::string& val, int time){
	std::map<std::string, std::priority_queue<TVP>>::iterator entry = map.find(key);
	if(entry==map.end()){
		map.insert(std::make_pair(key, std::priority_queue{TVP(time, val)}));
	}else{
		map[key].push_back(TVP(time, val));
	}
}

std::string TimeMap::get(const std::string& key, int time) const{
	std::string str = "";
	const std::priority_queue<>& q = map[key];
	for(std::priority_queue<TVP>::const_iterator i=q.begin(); i!=q.end(); ++i){
		if(*i.time>time){
			if(i!=q.begin()){
				str = *(i-1).value;
			}
			break;
		}
	}
	return str;
}

