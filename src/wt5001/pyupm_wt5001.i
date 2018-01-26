%module pyupm_wt5001

%rename("getVolumeNoParam")  getVolume();
%rename("getPlayStateNoParam") getPlayState();
%rename("getNumFilesOneParam")  getNumFiles(WT5001_PLAYSOURCE_T psrc);
%rename("getCurrentFileNoParam") getCurrentFile();

%include "common.i"
