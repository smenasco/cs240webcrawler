#include "main.h"
#include <iostream>
#include "CS240Exception.h"
#include <string>
#include <cassert>
#include "WebCrawler.h"
#include "URL.h"


int main(int argc, char * argv[]){
	assert(argc ==4);
	if (argc != 4) {
		std::cout << "USAGE: webcrawler <start-url> <output-file> <stopwords-file>\n";
	}
	WebCrawler * wc = new WebCrawler(argv[1],argv[2],argv[3]);
	// to test use file:///Users/smenasco/Desktop/cs240/project1/webcrawler/file/student/index.html
	
	
	//URL * url = new URL(argv[1],"sammy#b.html#thefragment");
	//delete url;
	//std::cout << url->GetURL() << std::endl;
	wc->Crawl();
	delete wc;
	return 0;
}


