#!/bin/bash

#Local file must define pi_username and pi_hostname
source LocalPiInfo.sh

if [ "$1" = "mount" ] ; then
    if [ ! -d "/mnt/pisquanch" ] ; then
        sudo mkdir /mnt/pisquanch
    fi
    sudo sshfs -o IdentityFile=~/.ssh/id_rsa ${pi_username}@${pi_hostname}:/ /mnt/pisquanch/
elif [ "$1" = "unmount" ] ; then
    sudo umount -d /mnt/pisquanch
elif [ "$1" = "clean" ] ; then
    sudo rm -r /mnt/pisquanch
else
    echo "Use mount, unmount or clean"
fi

