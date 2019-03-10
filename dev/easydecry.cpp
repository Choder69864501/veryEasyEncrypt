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
	int temp,r=0;
	if(file.is_open()){
		while(file>>temp){
			if(r>=(int)pwd.length())r-=pwd.length();
			temp-=pwd[r];
			if(temp<0)temp+=128;
			cryfile<<(char)temp;
			r++;
		}
	}
	else cout<<"Unable to open file"<<endl;
	return 0;
}
