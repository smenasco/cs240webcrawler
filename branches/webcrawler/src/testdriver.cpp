#include "testdriver.h"
#include <iostream>
#include "CS240Exception.h"
using namespace std;

int main(int argc, char * argv[]){
	printOutput();
	return 0;
}

void printOutput(){
	
	try{
		cout << "Hello make test\n";
	} catch (CS240Exception &e) {
		cout << "Exception Occurred:" << e.GetMessage() <<endl;
	}
}