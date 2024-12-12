pipeline {
    agent any
    stages {
        stage('Clone Repository') {
            steps {
                git 'https://github.com/justsearch78/TEST.git'
            }
        }
        stage('Build Docker Image') {
            steps {
                sh 'docker build -t cpp-hello-world .'
            }
        }
        stage('Run Application') {
            steps {
                sh 'docker run cpp-hello-world'
            }
        }
    }
}

