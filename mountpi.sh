#!/bin/bash

if [ "$1" = "mount" ] ; then
    if [ ! -d "/mnt/pisquanch" ] ; then
        sudo mkdir /mnt/pisquanch
    fi
    sudo sshfs -o IdentityFile=~/.ssh/id_rsa pi@10.1.10.132:/ /mnt/pisquanch/
elif [ "$1" = "unmount" ] ; then
    sudo umount -d /mnt/pisquanch
else
    echo "Use mount or unmount"
fi

