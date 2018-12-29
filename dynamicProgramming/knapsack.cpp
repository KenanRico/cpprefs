

int items[20][2] = {

};
int size = 100;

void maxValue(int*, int*);

int main(){
	int optimal = 0;
	int size = 0;
	maxValue(&optimal, &size);
	std::cout<<"max amount of value you can get is "<<optimal<<" using "<<size<<" slots in the sack \n";
	return 0;
}

void maxValue(int* optimal, int* size){


}


//optimal(size) = max(optimal(size-item0_space)+item0_value, optimal(size-item1_space)+item1_value, ...)
