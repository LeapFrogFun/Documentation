#include <iostream>
#include "../bonelib-code/include/bonelib/gpio.hpp"

using namespace std;

int main() {

  BeagleBone::gpio* IN = BeagleBone::gpio::P8(5);
	BeagleBone::gpio* OUT = BeagleBone::gpio::P8(4);
	BeagleBone::gpio* CLK = BeagleBone::gpio::P8(5);
	
	IN->configure(BeagleBone::pin::IN);
	OUT->configure(BeagleBone::pin::OUT);
	CLK->configure(BeagleBone::pin::OUT);

	while(1) {
		cout << "Receiving " << IN->get() << " at pin 2." << endl;
//		if( OUT->get() ) {
			if( OUT->set(1) ) {
				cout << "Set output to 1." << endl;
			}
//		}
//		if( !OUT->get() ) {
			if( OUT->set(0) ) {
				cout << "Set output to 0." << endl;
			}
//		}
		CLK->set(1);
		CLK->set(0);
	}

	return 0;
}
