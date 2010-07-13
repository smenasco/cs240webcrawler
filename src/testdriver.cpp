#include "testdriver.h"
#include <iostream>
#include <string>
#include "HTMLParser.h"

using namespace std;



int main(int argc, char * argv[]){
	std::string path = "http://apple.com/";
	HTMLParser * p = new HTMLParser();
	p->SetPath(path);
	if (p->Parse())
		cout << "success\n";
	else 
		cout << "failure\n";
	/*path = "http://www.byu.edu";
	p->SetPath(path);
	if (p->Parse())
		cout << "success\n";
	else 
		cout << "failure\n";*/
	return 0;
}

