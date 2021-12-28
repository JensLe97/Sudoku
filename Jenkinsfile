pipeline {
    agent any

    stages {
        stage("Build") {
            steps {
                echo "Building..."
                cmakeBuild(
                    installation: "cmake-3.22.1",
                    buildDir: 'build',
                    cleanBuild: true,
                    steps: [[withCmake: true]]
                )
            }
        }
        stage("Test") {
            steps {
                echo "Testing..."
                ctest "cmake-3.22.1"
            }
        }
        stage("Deploy") {
            steps {
                echo "Deploying..."
            }
        }
    }
}