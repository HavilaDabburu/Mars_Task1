#!/bin/bash
#shebang
mkdir rover_mission
#creating a directory
ls
cd rover_mission
#entered into it
pwd
touch log{1..3}.txt
#craeting multiple files at once
ls
mv rog1.txt mission_log.txt
ls
find -name "*.log"
#to find all files having log extension
cat mission_log.txt
#to display contents in a file without opening
grep -n "ERROR" mission_log.txt
#to count the number of lines in mission_log.txt
date
#to show the systems date and time
top
#to display cpu usage,memory usage,and running time processes in real time
sudo shutdouwn -h +10
#to schedule shutdown in 10 minutes
