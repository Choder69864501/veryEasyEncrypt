#include<iostream>
#include<fstream>
#define endl '\n'
using namespace std;
string line;
int main(){
	string pwd,locat;
	cout<<"Input the pwd:";
	cin>>pwd;
	cout<<"Input file name or location:";
	cin>>locat;
	ifstream file(locat);
	ofstream cryfile("normalFile");
	int r=0;
	if(file.is_open()){
		while(getline(file,line)){
			for(int i=0;i<(int)line.length();i++,r++){
				if(r>=(int)pwd.length())
					r-=pwd.length();
				line[i]-=pwd[r];
				if(line[i]<0)line[i]+=128;
			}
			cryfile<<line;
		}
	}
	else cout<<"Unable to open file"<<endl;
	return 0;
}
