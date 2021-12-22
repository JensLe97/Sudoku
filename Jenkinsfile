pipeline {
    agent any

    stages {
        stage("Build") {
            steps {
                echo "Building..."
                cmakeBuild(
                    installation: "InSearchPath"
                )
            }
        }
        stage("Test") {
            steps {
                echo "Testing..."
            }
        }
        stage("Deploy") {
            steps {
                echo "Deploying..."
            }
        }
    }
}