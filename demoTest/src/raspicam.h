#ifndef _RaspiCam_H_
#define _RaspiCam_H_

#include <cstdio>
#include <string>
#include "rpicamtypes.h"

using namespace std;


namespace raspicam{

    namespace _private{
        class Private_Imp1;
    }

    class Raspicam
    {
    public:
        Raspicam(/* args */);
        ~Raspicam();
    };

    bool open (bool StartCapture=true);
    bool startCapture;

    void setUserCallback(void (*userCallback) (void*), void* data=0);

    bool isOpened(); const;
    bool grab();

    void retrieve(unsigned char *data, RASPICAM_FORMAT type=RASPICAM_FORMAT_IGNORE);

    unsigned char *getImageBufferData() const;

    size_t getImageufferSize() const;

    void release();
    void setFormat(RASPICAM_FORMAT fmt);
    void setWidth(unsigned int width);
    void setHeight(unsigned int height);
    void setCaptureSize(unsigned int width, unsigned int height);
    void setBrightness(unsigned int brightness);
    void setSahrpness(int sharpness);
    void setContrast(int contrast);
    void setISO(int iso);
    void setSaturation(int saturation);
    void setVideoStabilization(bool v);
    void setExposureCompensasation(int val);
    void setRotation(int rotation);
    void setExposure(RASPICAM_EXPOSURE exposure);
    void setSShutterSpeed(unsigned int ss);

    void setAWB ( RASPICAM_AWB awb );
    // et specific values for whitebalance. Requires to set seAWB in OFF mode first
    void setAWB_RB ( float r,float b );//range is 0-1.
    void setImageEffect ( RASPICAM_IMAGE_EFFECT imageEffect );
    void setMetering ( RASPICAM_METERING metering );
    void setHorizontalFlip ( bool hFlip );
    void setVerticalFlip ( bool vFlip );
    void setFrameRate ( int frames_per_second );
    void setSensorMode ( int mode );

    //Accessors
    RASPICAM_FORMAT getFormat(); const;
    unsigned int getWidth(); const;
    unsigned int getHeight(); const;
    unsigned int getBrightness(); const;
    unsigned int getRotation(); const;
    int getISO(); const;
    int getSharpness(); const;
    int getContrast(); const;
    int getSaturation(); const;
    unsigned int getShutterSpeed(); const;
    RASPICAM_EXPOSURE getExposure(); const ;
    RASPICAM_AWB getAWB(); const;
    float getAWBG_red(); const;
    float getAWBG_blue(); const;
    RASPICAM_IMAGE_EFFECT getImageEffect(); const ;
    RASPICAM_METERING getMetering(); const;
    int getFrameRate(); const;
    bool isHorizontallyFlipped(); const ;
    bool isVerticallyFlipped(); const ;

    string getId(); const;

    size_t getImageTypeSize ( RASPICAM_FORMAT type ) const;
    private:
    _private::Private_Impl *_impl;
};
}
}
#endif
