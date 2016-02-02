#include "gmock/gmock.h"
#include "raspicam/raspicam.h"

namespace raspicam {

    class MockRaspiCam : public RaspiCam {
        public:
            MOCK_METHOD1(open,
                    bool(bool));
            MOCK_METHOD0(startCapture,
                    bool());
            MOCK_CONST_METHOD0(isOpened,
                    bool());
            MOCK_METHOD0(grab,
                    bool());
            MOCK_METHOD2(retrieve,
                    void(char, RASPICAM_FORMAT));
            MOCK_CONST_METHOD0(getImageBufferData,
                    unsigned char*());
            MOCK_METHOD1(setWidth,
                    void(unsigned int));
            MOCK_METHOD1(setHeight,
                    void(unsigned int));
            MOCK_METHOD1(setHorizontalFlip,
                    void(bool));
            MOCK_METHOD1(setVerticalFlip,
                    void(bool));
            //RASPICAM_FORMAT is depreciated, so not mocking that method 
            //signature for retrieve
            MOCK_METHOD1(retrieve,
                    void(unsigned char *));
                    

    };

}  // namespace raspicam

