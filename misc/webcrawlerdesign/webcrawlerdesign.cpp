/*
 *  webcrawlerdesign.c
 *  
 *
 *  Created by Sam on 7/9/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

class webcrawler{
	string startURL;
	method to begin crawling: the driver for the whole shebang
}
class URLFilter{
	//these members may just be in webcrawler class
	IsInScope?
	IsHTML?
	URLAlreadyIndexed?
	
}
class URL{
/* This class would:
	parse URLs
	store URL components
	resolve relative URLs
 */
	resolveURL(){
		
	}
	
}
class HTMLParser{
method to parse
		will give him html in some form
		will have to know where he is ... am i in the <body> or not etc.
	
Finds:
	Description
	Words
	Links
}
class Page{
	stores URL
	URL
	Description
}
class WordIndex{
	//Data structure that contains:
Map:
	(word=key,value = map(page,count)), use BST
	
	each node would have an object hanging off of it containing a word and a OccurenceSet, with its own tree
		the key would be a word for the first map 
		the key would be a url for the second map
		
add(page,word)
iterator
}
class OccurenceSet{
	Map(Page,Count)
	
}
class stopwords{
	would load stopwords file 
	check isStopWord?
	they are sorted so i would use binary search, they would have to be loaded into an array
}
class outPutGenerator{
	write XML
	iterates over word index
	
}
class PageIndex{
	BST
	all pages we have seen, visted or unvisted
}
class pageQueue{
	pages we still need to visit
	if all:
		its not in the page index
		its in scope
		its HTML
}
class pageDownloader{
	wrapper class for the dakine class the utils give us to download webpages
}