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
        stage("Analyse") {
            steps {
                sh returnStatus: true, script: 'cppcheck . --enable=all --inconclusive --xml --xml-version=2 --language=c++ --suppressions-list=suppressions.txt 2> cppcheck-result.xml'
                publishCppcheck allowNoReport: true, ignoreBlankFiles: true, pattern: '**/cppcheck-result.xml'
            }
        }
        stage("Deploy") {
            steps {
                echo "Deploying..."
            }
        }
    }
}