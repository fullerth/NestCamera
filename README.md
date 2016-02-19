# Overview
A program to run on a raspberry pi and help me collect interesting data at
flat track roller derby bouts for the [Rat City Rollergirls](http://ratcityrollergirls.com/) and [Jet City Rollergirls](http://www.jetcityrollergirls.com/)

# Requirements
Requires the [RaspiCam library](http://www.uco.es/investiga/grupos/ava/node/40) from Rafael Muñoz Salinas
to be compiled for the Raspberry Pi and installed on the building machine
SSHFS is required to install remote tests

# Cross Compiling
Build and test cycles are slow on the pi, so cross compiling is recommended. The
author was successful at building a toolchain using crosstool-ng. Pass the
location of a toolchain file using `-DCMAKE_TOOLCHAIN_FILE` when building.

# Testing
Tests are run remotely on the pi. The variables to configure the install path
and mountpoint are in three files.

## LocalPiInfo.sh
Sets Bash variables for use in mountpi.sh
`pi_username` - Username for ssh/sshfs to the pi

`pi_hostname` - Hostname for the pi

## LocalPiInfo.txt
Sets CMAKE variables
`SET PI_USERNAME` - Username for ssh/sshfs to the pi

`SET PI_HOSTNAME` - Hostname for the pi

## CMakeLists.txt
`SET HOST_MOUNTPOINT` - Local sshfs mountpoint for the pi

`SET PI_INSTALL_PATH` - Full path on the pi to install the main application

`SET PI_TEST_INSTALL_PATH` - Full path on the pi to install test applications
