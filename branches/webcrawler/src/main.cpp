#include "main.h"
#include <iostream>
#include "CS240Exception.h"

using namespace std;

int main(int argc, char * argv[]){
	printOutput();
	return 0;
}

void printOutput(){
	
	try{
		cout << "Hello Make\n";
	} catch (CS240Exception &e) {
		cout << "Exception Occurred:" << e.GetMessage() <<endl;
	}
}