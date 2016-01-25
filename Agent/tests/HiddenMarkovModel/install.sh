#!/bin/bash

host=$1
if [ "$host" == "" ]; then echo 'Usage: '$0' host'; exit 1; fi

targetdir=/opt/users/$USER/Work/PHPCPP/${PWD##*/}

#--------
ping -c1 -W5 $host > /dev/null
if [ "$?" != "0" ] 
then
  echo $host offline!
  exit 1
fi

echo '--- Copying extension to server in : '$targetdir' ---'
rsync -r --exclude install.sh ./* $USER@$host:$targetdir

#ssh-keygen -R $host

echo '--- Compile & install extension ---'
echo '-----------------------------------'
echo 'Execute on server:'
echo 'cd /opt/users/'$USER'/Work/PHPCPP/'${PWD##*/}
echo 'sudo make'
echo 'sudo make install'
echo 'sudo cp [file].php /var/www/html/...'
echo 'sudo service apache2 restart'
echo 'exit'
echo '-----------------------------------'
ssh $USER@$host
