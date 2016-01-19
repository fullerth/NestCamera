#!/bin/bash

if [ -z "$1" ]
then
    hostname = $1
else
    hostname = "pisquanch"
fi

if [ ! -d "/mnt/pisquanch" ]
then
    sudo mkdir /mnt/pisquanch
fi

sudo sshfs -o IdentityFile=~/.ssh/id_rsa pi@192.168.1.16:/ /mnt/pisquanch/
