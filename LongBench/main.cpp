/*A group of people, some of whom are beefing with others, are to sit on a long bench. Arrange the seatings so that no one sits beside their rivals*/


#include <iostream>
#include <vector>
#include <algorithm>

#define COUNT 6


struct Person{
	std::vector<int> friends;
	int friend_count;
	Person(): friend_count(0){}
};


void GetFriendships(bool[][COUNT], std::vector<Person*>*);
bool GetSeatingArrangements(std::vector<Person*>*, int*);
std::ostream& operator<<(std::ostream&, const Person&);
bool PopulateBench(std::vector<Person*>*, int*, int);
bool AllVisited(const std::vector<Person*>&);

int main(){
	//input: beef map
	bool beef_map[COUNT][COUNT]{
		{0,0,1,0,0,1},
		{0,0,0,1,1,1},
		{1,0,0,1,0,0},
		{0,1,1,0,0,0},
		{0,1,0,0,0,1},
		{1,1,0,0,1,0}
	};
	//get friendship relation info by reversing beef map
	std::vector<Person*> relations;
	GetFriendships(beef_map, &relations);
	for(std::vector<Person*>::const_iterator p=relations.begin(); p!=relations.end(); ++p){
		std::cout<<**p;
	}
	//get seating arrangement
	int seatings[COUNT];
	if(GetSeatingArrangements(&relations, seatings)){
		for(int i=0; i<COUNT; ++i){
			std::cout<<seatings[i]<<" ";
		}
		std::cout<<"\n";
	}else{
		std::cout<<"Unable to find an arrangement\n";
	}
	return 0;
}

void GetFriendships(bool beef_map[][COUNT], std::vector<Person*>* relations){
	for(int i=0; i<COUNT; ++i){
		Person* p = new Person;
		for(int j=0; j<COUNT; ++j){
			if(!beef_map[i][j] && i!=j){
				p->friends.push_back(j);
				++p->friend_count;
			}
		}
		relations->push_back(p);
	}
}

bool GetSeatingArrangements(std::vector<Person*>* relations, int* seatings){
	bool possible = false;
	int lonewolves = 0;
	int onefriendwonders = 0;
	int pos = 0;
	for(std::vector<Person*>::const_iterator p=relations->begin(); p!=relations->end(); ++p){
		if((*p)->friend_count==0){
			++lonewolves;
		}else if((*p)->friend_count==1){
			++onefriendwonders;
			pos = p-relations->begin();
			std::cout<<pos<<" ";
		}
	}
	std::cout<<"\n\n\n\n";
	if(lonewolves==0 && onefriendwonders<=2){
		possible = PopulateBench(relations, seatings, pos);
	}
	return possible;
}

std::ostream& operator<<(std::ostream& os, const Person& p){
	os<<"This boy has "<<p.friend_count<<" friends, they are";
	for(std::vector<int>::const_iterator i=p.friends.begin(); i!=p.friends.end(); ++i){
		os<<" "<<*i;
	}
	os<<"\n";
}

bool PopulateBench(std::vector<Person*>* relations, int* seatings, int start){
	bool possible = true;
	int pos = start;
	while(!AllVisited(*relations)){

		*(seatings++) = pos;

		Person*& person = relations->at(pos);
		if(person->friend_count==0 || person==nullptr){
			possible = false;
			break;
		}
		//update all person's friends so that they erase person as friends, and have 1 less friend
		unsigned int fc = (unsigned int)(-1);
		const std::vector<int>& pfriends = person->friends;
		for(int i=0; i<person->friend_count; ++i){
			int friend_ID = pfriends.at(i);
			Person* f = relations->at(friend_ID);
			if(f!=nullptr){
				f->friends.erase(std::find(f->friends.begin(), f->friends.end(), pos));
				if(--(f->friend_count) < fc){
					fc = f->friend_count;
					pos = friend_ID;
				}
			}
		}
		//update relations
		delete person;
		person = nullptr;
	}
	return possible;
}

bool AllVisited(const std::vector<Person*>& relations){
	bool result = true;
	for(std::vector<Person*>::const_iterator p=relations.begin(); p!=relations.end(); ++p){
		if(*p!=nullptr){
			result = false;
			break;
		}
	}
	return result;
}

