#include <iostream>
#include <string>
using namespace std;

class MHS {
	public:
		void printname(string name) {
			MHSname = name;
			cout << "MHSname is " << MHSname;
		}		
	private:
		string MHSname;
};

int main() {
	MHS mhs1;
	
	mhs1.printname("Rodi");
	return 0;
}
