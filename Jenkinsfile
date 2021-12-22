pipeline {
    agent any

    stages {
        stage("Build") {
            steps {
                echo "Building..."
                cmakeBuild(
                    installation: "cmake-3.22.1",
                    buildDir: 'build',
                    cleanBuild: true
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