#include "testdriver.h"
#include <iostream>
#include <string>
#include "HTMLParser.h"

using namespace std;

int main(int argc, char * argv[]){
	
/*	if (argc !=2){
		cout << "USAGE: testdriver <stopwords-file>\n";
		return -1
	}
	string swfilename = argv[1]
*/	
	bool success = true;
	
	if (!URL::Test(cout)) success = false;
	if (!URLFilter::Test(cout)) success = false;
	if (!StopWords::Test(cout)) success = false;
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

