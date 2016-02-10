#include <ctime>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <memory>
#include "cameraAdapter/cameraAdapter.h"

using namespace std;

int main(int argc, char **argv) {
	shared_ptr<raspicam::RaspiCam> pCamera(new raspicam::RaspiCam); //Cmaera object
    CameraAdapter adapter(pCamera);
	//Open camera 
	cout << "Opening Camera..." << "\n"; 
	if ( !(adapter.openCamera())) {
		cerr << "Error opening camera" << "\n";
		return - 1;
	} 
	//wait a while until camera stabilizes 
	cout<<"Sleeping for 3 secs"<<"\n"; 
	sleep(3);
	//capture
	adapter.grab();
	//allocate memory
	unsigned char *data = new unsigned char[adapter.getImageSize()];
	//extract the image in rgb format
	adapter.retrieve(data);

	std::ofstream outFile("raspicam_image.ppm",std::ios::binary);
	outFile << "P6\n" << adapter.getWidth() << " " << adapter.getHeight() << " 255\n";
	outFile.write((char*) data, adapter.getImageSize());
	cout << "Image saved at raspicam_image.ppm" << "\n";
	//free resources    
	delete data;
	return 0;
}


