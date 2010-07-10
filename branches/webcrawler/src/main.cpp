#include "main.h"
#include <iostream>
#include "CS240Exception.h"
#include <string>
#include <cassert>
#include "WebCrawler.h"

using namespace std;

int main(int argc, char * argv[]){
	assert(argc ==4);
	if (argc < 4) {
		cout << "USAGE: webcrawler <start-url> <output-file> <stopwords-file>\n";
	}
	WebCrawler * wc = new WebCrawler();
	
	return 0;
}


