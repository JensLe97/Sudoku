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
                ctest(
                    installation: "cmake-3.22.1",
                    workingDir: 'build'                
                )
            }
        }
        stage("Deploy") {
            steps {
                echo "Deploying..."
            }
        }
    }
}