#!/bin/bash

# Remove all compiled files (*.class)
rm -f *.class

# Compile all .java files
javac *.java

# Execute main class
java Project_Queue
