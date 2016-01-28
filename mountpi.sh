#!/bin/bash

if [ "$1" = "mount" ] ; then
    if [ ! -d "/mnt/pisquanch" ] ; then
        sudo mkdir /mnt/pisquanch
    fi
    sudo sshfs -o IdentityFile=~/.ssh/id_rsa pi@pisquanch:/ /mnt/pisquanch/
elif [ "$1" = "unmount" ] ; then
    sudo umount -d /mnt/pisquanch
else
    echo "Use mount or unmount"
fi

