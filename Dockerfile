FROM jenkins/jenkins:lts-jdk11

USER root
RUN apt-get update && apt-get install -y build-essential cppcheck=2.3-1
USER jenkins