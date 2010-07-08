#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdliba.h>

using namespace std;
const int SIZE = 1024;
char lines[SIZE][SIZE];

class Line{
public: 
	Line(){
	}
	Line(char * tline, char * tsortitem){
		strcpy(line,tline);
		strcpy(sortitem,tsortitem);
		//cout << "item: " << sortitem << endl << "Line: " << line << endl;
	}
	char * printLine(){
		return line;
	}
	char * printItem(){
		return sortitem;
	}
private:
	char line[SIZE];
	char sortitem[SIZE];
};


Line db[SIZE]; 
int cnt;
bool compcase = false;
bool compnum = false;
bool compdec = false;

bool Load(ifstream & input, int column) {
	if (!input) {
		//cout << "returned false from Load" << endl;
		return false;
	}
	cnt = 0;
	char * token;
	while (input) {
		input.getline(lines[cnt],SIZE);
		
		const char * delims = " \t\r\n";
		//cout << bigLine << endl;
		char tmp[SIZE];
		char tmpitem[SIZE];
		strcpy(tmp,lines[cnt]);
		token = strtok(lines[cnt],delims);
		int i = 0;
		while ((token != NULL) && (i != column-1)) {
			token = strtok(NULL,delims);
			i++;
		}
		
		if (token != NULL){
			strcpy(tmpitem,token);
			db[cnt] = Line(tmp,tmpitem);
			cnt++;
		}
		
		//cout << "token: " << token << endl;
		//cout << lines[cnt] << endl;
		//cout << token << endl;
		//cout << "cnt: " << cnt << endl;
		//cout << sizeof(Line)<< endl;
		
		
	}
	//cout << "did I reach here? YES!" << endl;
	return true;
}
int compareNoCase(const void * a, const void * b){  //Case insensitive
	char * x = ((Line *)a)->printItem();
	char * y = ((Line *)b)->printItem();
	char * line= x;
	char * line2= y;
	
	for(int i = 0; i < strlen(x);i++){
		line[i] = tolower(x[i]);
	}
	for(int i = 0; i < strlen(x);i++){
		line2[i] = tolower(y[i]);
	}
	//cout << x->printItem() << "item" << endl;
	int i;
	if (!compdec){
		i = strcmp(line,line2);
	} else
		i = strcmp(line2,line);
	
	return i;
}
int compareNum(const void * a, const void * b){		//Compare by numeric value using atof()
	Line * x = (Line *)a;
	Line * y = (Line *)b;
	double aa = atof(x->printItem());
	double bb = atof(y->printItem());
	//cout << "aa: "<< aa << endl << "bb: " << bb << endl; 
	if (aa > bb)
		return 1;
	else if (bb > aa)
		return -1;
	else
		return 0;
}
int compareDecending(const void * a, const void * b){  //big top to small bottom
	Line * x = (Line *)a;
	Line * y = (Line *)b;
	int i = strcmp(y->printItem(),x->printItem());
	if (compnum){
		double aa = atof(x->printItem());
		double bb = atof(y->printItem());
		//cout << "aa: "<< aa << endl << "bb: " << bb << endl; 
		if (bb > aa)
			i= 1;
		else if (aa > bb)
			i= -1;
		else
			return 0;
	}
	return i;
}
int compareDefault(const void * a,const void * b){  //ascending from little to big, case Sensitive
	//cout <<  "test" << endl;
	Line * x = (Line *)a;
	Line * y = (Line *)b;
	
	//cout << x->printItem() << "item" << endl;
	int i= strcmp(x->printItem(),y->printItem());
	//cout << i << endl;
	return i;
}
void parseCommandLine(int argc, char * arg[]){
	for (int i = 1; i < argc -1;i++ ){
		if ( compdec && compnum && compdec){
			i = argc;
			continue;
		}
		
		if (strchr(arg[i],'n') != NULL){
			compnum = true;
			//cout << "N = true"<< endl;
		}
		if (strchr(arg[i],'i') != NULL){
			compcase = true;
			//cout << "I = true"<< endl;
		}
		if (strchr(arg[i],'r') != NULL){
			compdec = true;
			//cout << "R = true"<< endl;
		}
	} 
}
int main(int argc, char * argv[]){
	if (argc >= 3) 
	{
		//cout << "Number of args: " << argc << endl;
		ifstream file(argv[(argc-1)]);
		
		if (file) 
		{
			int column = atoi(argv[argc-2]);
			
			if (Load(file,column)) {
				/*cout << "Unsorted: " << endl;
				 for (int i = 0; i < cnt;i++){
				 cout << db[i].printLine() << endl;// << db[i]->printItem() << endl;
				 
				 }*/
				parseCommandLine(argc, argv);
				if (compcase){
					qsort(db,cnt,sizeof(Line),compareNoCase);
				} 
				else if(compnum){
					qsort(db,cnt,sizeof(Line),compareNum);
				}
				if (compdec){
					qsort(db,cnt,sizeof(Line),compareDecending);
				}
				if (!compdec && !compnum && !compcase)
					qsort(db,cnt,sizeof(Line),compareDefault);
				//cout << "Sorted: " << endl;
				for (int i = 0; i < cnt;i++){
					cout << db[i].printLine()<< endl;
					
				}
			}
			
			file.close();
			
			return 0;
		}
		else 
		{
			cout << "Could not open file " << argv[1] << endl;
		}
		
	}
	else 
	{
		cout << "Invalid arguments" << endl;
	}
	
	return 8;
}