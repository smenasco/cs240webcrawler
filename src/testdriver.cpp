#include "testdriver.h"
#include <iostream>
#include <string>
#include "HTMLParser.h"

using namespace std;

int main(int argc, char * argv[]){
	bool success = true;
	
	if (!URL::Test(cout)) success = false;
	
	//if (!Target::Test(cout)) success = false;
	//if (!Command::Test(cout)) success = false;
	//if (!MakeFileParser::Test(cout)) success = false;
	//if (!DependencyGraph::Test(cout)) success = false;
	
	if (success) {
		cout << "Tests Succeeded!" << endl;
	}
	else {
		cout << "Tests Failed!" << endl;
	}
	
	return 0;
}

