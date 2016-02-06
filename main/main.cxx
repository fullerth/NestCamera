#include <ctime>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include "cameraAdapter/cameraAdapter.h"

using namespace std;

int main(int argc, char **argv) {
	raspicam::RaspiCam Camera; //Cmaera object
    CameraAdapter adapter(&Camera);
	//Open camera 
	cout << "Opening Camera..." << endl; 
	if ( !(adapter.openCamera())) {
		cerr << "Error opening camera" << endl;
		return - 1;
	} 
	//wait a while until camera stabilizes 
	cout<<"Sleeping for 3 secs"<<endl; 
	sleep(3);
	//capture
	adapter.grab();
	//allocate memory
	unsigned char *data = new unsigned char[adapter.getImageSize()];
	//extract the image in rgb format
	adapter.retrieve(data);

	std::ofstream outFile("raspicam_image.ppm",std::ios::binary);
	outFile << "P6\n" << Camera.getWidth() << " " << Camera.getHeight() << " 255\n";
	outFile.write((char*) data, adapter.getImageSize());
	cout << "Image saved at raspicam_image.ppm" << endl;
	//free resources    
	delete data;
	return 0;
}


