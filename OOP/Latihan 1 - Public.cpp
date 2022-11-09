#include <iostream>
#include <string>
using namespace std;

class MHS {
	public:
		string MHSname;
		void printname() {
			cout << "MHSname is " << MHSname;
		}		
};

int main() {
	MHS mhs1;
	
	mhs1.MHSname = "Rodi";
	mhs1.printname();
	return 0;
}
