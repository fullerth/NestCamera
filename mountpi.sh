#!/bin/bash

if [ ! -d "/mnt/pisquanch" ]
then
    sudo mkdir /mnt/pisquanch
fi

sudo sshfs -o IdentityFile=~/.ssh/id_rsa pi@pisquanch:/ /mnt/pisquanch/
