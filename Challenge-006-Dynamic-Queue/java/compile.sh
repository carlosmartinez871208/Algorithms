#!/bin/bash

# Remove all compiled files (*.class)
rm -f *.class

# Compile all .java files
javac *.java

# Execute main class (assuming Project_name contains the main method)
java Project_name
