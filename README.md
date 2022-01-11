# Sudoku
A Sudoku Generator combined with a Solver using backtracking algorithm in C++.

## Build the the Docker Image and run the container with Jenkins
After having installed Docker from the [Docker Website](https://docs.docker.com/get-docker/)
you can build the image using in the root directory where the Dockerfile is located:
```
docker build -t jenkins:1.0 .
```
Then, you can run the container by typing:
```
docker run -d -v jenkins_home:/var/jenkins_home -p 8080:8080 -p 50000:50000 jenkins:1.0
```

## Setup Jenkins
Jenkins will run on http://localhost:8080/

This project can be used with a Jenkins pipeline and the [CMake Plugin](https://www.jenkins.io/doc/pipeline/steps/cmakebuilder/).
You need to specify your cmake installation under Global Tool Configuration according to the Jenkinsfile.

