#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#define endl '\n'
using namespace std;
int main(){
	srand(time(NULL));
	string pwd,locat;
	cout<<"Input a string:";
	cin>>pwd;
	cout<<"Input file name or location:";
	cin>>locat;
	ifstream file(locat);
	ofstream cryfile("cryfile");
	string line;int r=0;
	if(file.is_open()){
		while(getline(file,line)){
			line.push_back('\n');
			for(int i=0;i<(int)line.length();i++,r++){
				if(r>=(int)pwd.length())
					r-=pwd.length();
				line[i]=(line[i]+pwd[r])%128;
				cryfile<<(int)line[i]<<" ";
				if(rand()%2)cryfile<<endl;
			}
		}
	}
	else cout<<"Unable to open file"<<endl;
	return 0;
}
